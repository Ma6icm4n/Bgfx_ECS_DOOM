#include "RenderSystem.h"

#include "Renderable.h"
#include "Transform.h"
#include "Coordinator.h"

#include <cmath>

#include "bgfx/bgfx.h"
#include "bgfx/platform.h"
#include "bx/math.h"
#include <string>

struct PosColorVertex
{
    float x;
    float y;
    float z;
    uint32_t abgr;
};

static PosColorVertex cubeVertices[] =
{
    {-1.0f,  1.0f,  1.0f, 0xff000000 },
    { 1.0f,  1.0f,  1.0f, 0xff0000ff },
    {-1.0f, -1.0f,  1.0f, 0xff00ff00 },
    { 1.0f, -1.0f,  1.0f, 0xff00ffff },
    {-1.0f,  1.0f, -1.0f, 0xffff0000 },
    { 1.0f,  1.0f, -1.0f, 0xffff00ff },
    {-1.0f, -1.0f, -1.0f, 0xffffff00 },
    { 1.0f, -1.0f, -1.0f, 0xffffffff },
};

static const uint16_t cubeTriList[] =
{
    0, 1, 2,
    1, 3, 2,
    4, 6, 5,
    5, 6, 7,
    0, 2, 4,
    4, 2, 6,
    1, 5, 3,
    5, 7, 3,
    0, 4, 1,
    4, 5, 1,
    2, 3, 6,
    6, 3, 7,
};

bgfx::ShaderHandle loadShader(const char* filename) {
    const char* shaderPath = "???";

    switch (bgfx::getRendererType()) {
    case bgfx::RendererType::Noop:
    case bgfx::RendererType::Direct3D9:  shaderPath = "../../externals/bgfx/examples/runtime/shaders/dx9/";   break;
    case bgfx::RendererType::Direct3D11:
    case bgfx::RendererType::Direct3D12: shaderPath = "../../externals/bgfx/examples/runtime/shaders/dx11/";  break;
    case bgfx::RendererType::Gnm:        shaderPath = "../../externals/bgfx/examples/runtime/shaders/pssl/";  break;
    case bgfx::RendererType::Metal:      shaderPath = "../../externals/bgfx/examples/runtime/shaders/metal/"; break;
    case bgfx::RendererType::OpenGL:     shaderPath = "../../externals/bgfx/examples/runtime/shaders/glsl/";  break;
    case bgfx::RendererType::OpenGLES:   shaderPath = "../../externals/bgfx/examples/runtime/shaders/essl/";  break;
    case bgfx::RendererType::Vulkan:     shaderPath = "../../externals/bgfx/examples/runtime/shaders/spirv/"; break;
    }

    size_t shaderLen = strlen(shaderPath);
    size_t fileLen = strlen(filename);
    char* filePath = (char*)calloc(1, shaderLen + fileLen + 1);
    memcpy(filePath, shaderPath, shaderLen);
    memcpy(&filePath[shaderLen], filename, fileLen);

    FILE* file = fopen(filePath, "rb");
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    const bgfx::Memory* mem = bgfx::alloc(fileSize + 1);
    fread(mem->data, 1, fileSize, file);
    mem->data[mem->size - 1] = '\0';
    fclose(file);

    return bgfx::createShader(mem);
}

#define WIND_WIDTH 1600
#define WIND_HEIGHT 900


extern Coordinator gCoordinator;

void RenderSystem::Init()
{

    bgfx::Init bgfxInit;
    bgfxInit.type = bgfx::RendererType::Count;
    bgfxInit.resolution.width = WIND_WIDTH;
    bgfxInit.resolution.height = WIND_HEIGHT;
    bgfxInit.resolution.reset = BGFX_RESET_VSYNC;
    bgfx::init(bgfxInit);

    bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x443355FF, 1.0f, 0);
    bgfx::setViewRect(0, 0, 0, WIND_WIDTH, WIND_HEIGHT);

	pcvDecl.begin().add(bgfx::Attrib::Position, 3, bgfx::AttribType::Float)
	    .add(bgfx::Attrib::Color0, 4, bgfx::AttribType::Uint8, true)
	    .end();
	vbh = bgfx::createVertexBuffer(bgfx::makeRef(cubeVertices, sizeof(cubeVertices)), pcvDecl);
	ibh = bgfx::createIndexBuffer(bgfx::makeRef(cubeTriList, sizeof(cubeTriList)));
	vsh = loadShader("vs_cubes.bin");
	fsh = loadShader("fs_cubes.bin");
	program = bgfx::createProgram(vsh, fsh, true);

}

void RenderSystem::Destroy() {
    bgfx::destroy(ibh);
    bgfx::destroy(vbh);
    bgfx::destroy(program);
}

void RenderSystem::Update(float dt) {

    const bx::Vec3 at = { 0.0f, 0.0f,  0.0f };
    const bx::Vec3 eye = { 0.0f, 0.0f, -10.0f };
    float view[16];
    bx::mtxLookAt(view, eye, at);
    float proj[16];
    bx::mtxProj(proj, 60.0f, float(WIND_WIDTH) / float(WIND_HEIGHT), 0.1f, 100.0f, bgfx::getCaps()->homogeneousDepth);
    bgfx::setViewTransform(0, view, proj);

    for (auto const& entity : m_Entities) {

        auto const& transform = gCoordinator.GetComponent<Transform>(entity);
        float rotation[16];
        float translate[16];
        float mtx[16];
        bx::mtxRotateXY(rotation, dt, dt);
        bx::mtxTranslate(translate, transform.position[0], transform.position[1], transform.position[2]);
        mtx[0] = rotation[0] + translate[0];
        mtx[1] = rotation[1] + translate[1];
        mtx[2] = rotation[2] + translate[2];
        mtx[3] = rotation[3] + translate[3];
        mtx[4] = rotation[4] + translate[4];
        mtx[5] = rotation[5] + translate[5];
        mtx[6] = rotation[6] + translate[6];
        mtx[7] = rotation[7] + translate[7];
        mtx[8] = rotation[8] + translate[8];
        mtx[9] = rotation[9] + translate[9];
        mtx[10] = rotation[10] + translate[10];
        mtx[11] = rotation[11] + translate[11];
        mtx[12] = translate[12] + rotation[12];
        mtx[13] = translate[13] + rotation[13];
        mtx[14] = translate[14] + rotation[14];
        mtx[15] = rotation[15] + translate[15];
        bgfx::setTransform(mtx);
        bgfx::setVertexBuffer(0, vbh);
        bgfx::setIndexBuffer(ibh);
        bgfx::submit(0, program);
    }
    
}