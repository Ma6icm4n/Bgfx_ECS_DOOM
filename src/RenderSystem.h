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
	void Update(float dt, double& xpos, double& ypos);
    void Destroy();
    void GetForwardVector(float* transform, double& xpos, double& ypos, double zpos);
    void GetRightVector(float* transform, double& xpos, double& ypos, double zpos);
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