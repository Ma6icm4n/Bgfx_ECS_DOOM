#include "RenderSystem.h"

#include "Renderable.h"
#include "Transform.h"
#include "Coordinator.h"
#include "Camera.h"
#include "Transform.h"

#include <cmath>

#include "bgfx/bgfx.h"
#include "bgfx/platform.h"
#include "bx/math.h"
#include <string>
#include <iostream>
#include <bitset>

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

void RenderSystem::GetForwardVector(float* forward, double& xpos, double& ypos, double zpos) {

    float angleY = Maths::toRadians(ypos);
    float angleX = Maths::toRadians(xpos);
    float angleZ = Maths::toRadians(zpos);

    forward[0] = Maths::cos(angleY) * Maths::sin(angleX); 
    forward[1] = -Maths::sin(angleY);
    forward[2] = Maths::cos(angleY) * Maths::cos(angleX);
}

void RenderSystem::GetRightVector(float* right, double& xpos, double& ypos, double zpos) {
    float angleX = Maths::toRadians(xpos);
    float angleY = Maths::toRadians(ypos);
    float angleZ = Maths::toRadians(zpos);

    right[0] = Maths::cos(angleX);
    right[1] = 0;
    right[2] = -Maths::sin(angleX);

}

#define WIND_WIDTH 1600
#define WIND_HEIGHT 900


extern Coordinator gCoordinator;

void RenderSystem::Init()
{

    m_camera = gCoordinator.CreateEntity();

    float rotation[3] = { 0.0f, 0.0f, 0.0f };

    gCoordinator.AddComponent(
        m_camera,
        Transform{
            0.0, 0.0f, -80.0f,
            0.0f, 0.0f, 0.0f,
            1.0f, 1.0f, 1.0f
        }
    );

    gCoordinator.AddComponent(
        m_camera,
        Camera{
            .projectionTransform = Camera::MakeProjectionTransform(WIND_WIDTH, WIND_HEIGHT),
            .forward = Camera::GetForwardVector(rotation[0], rotation[1], rotation[2]),
            .right = Camera::GetRightVector(rotation[0], rotation[1], rotation[2])
        }
    );

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

void RenderSystem::Update(float dt, double& xpos, double& ypos) {


    auto& cameraTransform = gCoordinator.GetComponent<Transform>(m_camera);
    auto& camera = gCoordinator.GetComponent<Camera>(m_camera);

    for (auto const& entity : m_Entities) {

        auto const& transform = gCoordinator.GetComponent<Transform>(entity);
        
        
        //std::cout << cameraTransform.position[0] << " , " << cameraTransform.position[1] << " , " << cameraTransform.position[2] << std::endl;;
        float forward[3] = { camera.forward[0], camera.forward[1], camera.forward[2] };
        float right[3] = { camera.right[0], camera.right[1], camera.right[2] };
        RenderSystem::GetForwardVector(forward, xpos, ypos, (double) cameraTransform.rotation[2]);
        RenderSystem::GetRightVector(right, xpos, ypos, (double)cameraTransform.rotation[2]);
        camera.forward[0] = forward[0];
        camera.forward[1] = forward[1];
        camera.forward[2] = forward[2];
        camera.right[0] = right[0];
        camera.right[1] = right[1];
        camera.right[2] = right[2];
        const bx::Vec3 eye = { cameraTransform.position[0], cameraTransform.position[1], cameraTransform.position[2] };
        const bx::Vec3 at = { eye.x + forward[0], eye.y  + forward[1], eye.z + forward[2]};
        
        float view[16];
        view[2] = -cameraTransform.position[0];
        view[5] = -cameraTransform.position[1];
        view[8] = -cameraTransform.position[2];
        bx::mtxLookAt(view, eye, at);

        float rotation[16];
        float translate[16];
        float scale[16];
        float mtx[16];
        bx::mtxRotateXY(rotation, dt * transform.rotation[0], dt* transform.rotation[1]);
        bx::mtxTranslate(translate, transform.position[0], transform.position[1], transform.position[2]);
        bx::mtxScale(scale, transform.scale[0], transform.scale[1], transform.scale[2]);
        mtx[0] = rotation[0]; //* scale[0];
        mtx[1] = rotation[1];
        mtx[2] = rotation[2];
        mtx[3] = rotation[3];
        mtx[4] = rotation[4];
        mtx[5] = rotation[5]; //*scale[5];
        mtx[6] = rotation[6];
        mtx[7] = rotation[7];
        mtx[8] = rotation[8];
        mtx[9] = rotation[9];
        mtx[10] = rotation[10]; //*scale[10];
        mtx[11] = rotation[11];
        mtx[12] = translate[12];
        mtx[13] = translate[13] * 10;
        mtx[14] = translate[14];
        mtx[15] =  1.0f;


        float projection[16];
        projection[0] = camera.projectionTransform[0];
        projection[1] = camera.projectionTransform[1];
        projection[2] = camera.projectionTransform[2];
        projection[3] = camera.projectionTransform[3];
        projection[4] = camera.projectionTransform[4];
        projection[5] = camera.projectionTransform[5];
        projection[6] = camera.projectionTransform[6];
        projection[7] = camera.projectionTransform[7];
        projection[8] = camera.projectionTransform[8];
        projection[9] = camera.projectionTransform[9];
        projection[10] = camera.projectionTransform[10];
        projection[11] = camera.projectionTransform[11];
        projection[12] = camera.projectionTransform[12];
        projection[13] = camera.projectionTransform[13];
        projection[14] = camera.projectionTransform[14];
        projection[15] = camera.projectionTransform[15];
        bgfx::setViewRect(0, 0, 0, uint16_t(WIND_WIDTH), uint16_t(WIND_HEIGHT));
        bgfx::setViewTransform(0, view, projection);


        bgfx::setTransform(mtx);
        bgfx::setVertexBuffer(0, vbh);
        bgfx::setIndexBuffer(ibh);
        bgfx::submit(0, program);
    }
    
}