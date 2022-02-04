#pragma once

#include "System.h"
#include "bgfx/bgfx.h"
#include "bgfx/platform.h"
#include "bx/math.h"
#include <memory>

class Event;

class RenderSystem : public System {
public:

	void Init();
	void Update(float dt);
    void Destroy();
    void GetForwardVector(float* transform, float xpos, float ypos, float zpos);
    void GetRightVector(float* transform, float xpos, float ypos, float zpos);
    void GetMax(float* position, float* scale, float* max);
    void GetMin(float* position, float* scale, float* max);
private:

    //void WindowSizeListener(Event& event);

    Entity m_camera;

    bgfx::VertexBufferHandle vbh;
    bgfx::IndexBufferHandle ibh;
    bgfx::ShaderHandle vsh;
    bgfx::ShaderHandle fsh;
    bgfx::ProgramHandle program;
    bgfx::VertexLayout pcvDecl;
};