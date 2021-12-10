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