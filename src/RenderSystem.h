#pragma once

#include "System.h"
#include "bgfx/bgfx.h"
#include "bgfx/platform.h"
#include "bx/math.h"
#include <memory>

class RenderSystem : public System {
public:

	void Init();
	void Update(float dt);
    void Destroy();
private:

    bgfx::VertexBufferHandle vbh;
    bgfx::IndexBufferHandle ibh;
    bgfx::ShaderHandle vsh;
    bgfx::ShaderHandle fsh;
    bgfx::ProgramHandle program;
    bgfx::VertexLayout pcvDecl;
};