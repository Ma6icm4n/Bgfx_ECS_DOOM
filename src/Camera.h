#pragma once
#include "bgfx/bgfx.h"
#include "bx/math.h"
#include "Mat44.h"
#include <cmath>
#include <vector>

struct Camera {
	std::vector<float> projectionTransform;
    std::vector<float> forward;

    static std::vector<float> MakeProjectionTransform(float width, float height) {
        
        float proj[16];
        bx::mtxProj(proj, 60.0f, float(width) / float(height), 0.1f, 100.0f, bgfx::getCaps()->homogeneousDepth);
        std::vector<float> projV(std::begin(proj), std::end(proj));
        return projV;
	}

    static std::vector<float> GetForwardVector(float rotationX, float rotationY, float rotationZ) {
        float forward[3];

        float angleY = Maths::toRadians(rotationY);
        float angleX = Maths::toRadians(rotationX);
        float angleZ = Maths::toRadians(rotationZ);

        forward[0] = Maths::cos(angleY) * Maths::sin(angleZ);
        forward[1] = -Maths::sin(angleY);
        forward[2] = Maths::cos(angleY) * Maths::cos(angleZ);
        std::vector<float> forwardV(std::begin(forward), std::end(forward));
        return forwardV;
    }
};