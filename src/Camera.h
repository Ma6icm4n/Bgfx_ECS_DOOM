#pragma once
#include "bgfx/bgfx.h"
#include "bx/math.h"
#include "Mat44.h"
#include <cmath>

struct Camera {
	float projectionTransform[16];

	static float MakeProjectionTransform(float width, float height) {
        const bx::Vec3 at = { 0.0f, 0.0f,  0.0f };
        const bx::Vec3 eye = { 10.0f, 30.0f, -80.0f };
        float view[16];
        bx::mtxLookAt(view, eye, at);
        float proj[16];
        bx::mtxProj(proj, 60.0f, float(width) / float(height), 0.1f, 100.0f, bgfx::getCaps()->homogeneousDepth);
        bgfx::setViewTransform(0, view, proj);
	}
};