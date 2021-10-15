#include <stdio.h>
#include <cstdio>
#include <vector>
#include <iostream>
#include <sstream>

#include "bgfx/bgfx.h"
#include "bgfx/platform.h"
#include "bx/math.h"
#include "GLFW/glfw3.h"
#define GLFW_EXPOSE_NATIVE_WIN32
#include "GLFW/glfw3native.h"

#include "Window.h"

#define WIND_WIDTH 1600
#define WIND_HEIGHT 900

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

//################# UTILS (will be moved in interface class) ################

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

int main(void) {

    Window window;
    window.Init("DOOM-ECS", WIND_WIDTH, WIND_HEIGHT, 0, 0);


//########## Create Cube (will be moved in component) #############
    bgfx::VertexLayout pcvDecl;
    pcvDecl.begin().add(bgfx::Attrib::Position, 3, bgfx::AttribType::Float)
        .add(bgfx::Attrib::Color0, 4, bgfx::AttribType::Uint8, true)
        .end();
    bgfx::VertexBufferHandle vbh = bgfx::createVertexBuffer(bgfx::makeRef(cubeVertices, sizeof(cubeVertices)), pcvDecl);
    bgfx::IndexBufferHandle ibh = bgfx::createIndexBuffer(bgfx::makeRef(cubeTriList, sizeof(cubeTriList)));
    bgfx::ShaderHandle vsh = loadShader("vs_cubes.bin");
    bgfx::ShaderHandle fsh = loadShader("fs_cubes.bin");
    bgfx::ProgramHandle program = bgfx::createProgram(vsh, fsh, true);

	unsigned int counter = 0;

	while (true) {
//######### CAMERA AND INSTANCIATION BUFFER #############

        const bx::Vec3 at = { 0.0f, 0.0f,  0.0f };
        const bx::Vec3 eye = { 0.0f, 0.0f, -5.0f };
        float view[16];
        bx::mtxLookAt(view, eye, at);
        float proj[16];
        bx::mtxProj(proj, 60.0f, float(WIND_WIDTH) / float(WIND_HEIGHT), 0.1f, 100.0f, bgfx::getCaps()->homogeneousDepth);
        bgfx::setViewTransform(0, view, proj);

        bgfx::setVertexBuffer(0, vbh);
        bgfx::setIndexBuffer(ibh);

        bgfx::setViewTransform(0, view, proj);
        float mtx[16];
        bx::mtxRotateXY(mtx, counter * 0.01f, counter * 0.01f);
        bgfx::setTransform(mtx);

        window.Update();

        bgfx::submit(0, program);
		bgfx::frame();
		counter++;
	}

    bgfx::destroy(ibh);
    bgfx::destroy(vbh);
    bgfx::shutdown();
    window.Shutdown();


	return 0;
}