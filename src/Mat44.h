#pragma once

#include "Vec4.h"

class Mat44 {
public:

	float m[16];

	Mat44() {
		
		m[0] = 1.0f; 
		m[1] = 0.0f; 
		m[2] = 0.0f; 
		m[3] = 0.0f;
		m[4] = 0.0f; 
		m[5] = 1.0f; 
		m[6] = 0.0f; 
		m[7] = 0.0f;
		m[8] = 0.0f; 
		m[9] = 0.0f; 
		m[10] = 1.0f; 
		m[11] = 0.0f;
		m[12] = 0.0f; 
		m[13] = 0.0f; 
		m[14] = 0.0f; 
		m[15] = 1.0f;
		
	}

	inline void Translate(float* matrix, float x, float y, float z) {

		matrix[12] = x;
		matrix[13] = y;
		matrix[14] = z;
		matrix[15] = 1.0f;

	}

	inline void Scale(float* matrix, float x, float y, float z) {
		matrix[0] = matrix[0] * x;
		matrix[1] = matrix[1] * x;
		matrix[2] = matrix[2] * x;
		matrix[4] = matrix[4] * y;
		matrix[5] = matrix[5] * y;
		matrix[6] = matrix[6] * y;
		matrix[8] = matrix[8] * z;
		matrix[9] = matrix[9] * z;
		matrix[10] = matrix[10] * z;
		matrix[15] = 1.0f;
	}

	inline void CreateFromQuaternion(float* matrix, const Vec4& q) {
		matrix[0] = 1.0f - 2.0f * q.y * q.y - 2.0f * q.z * q.z;
		matrix[1] = 2.0f * q.x * q.y + 2.0f * q.w * q.z;
		matrix[2] = 2.0f * q.x * q.z - 2.0f * q.w * q.y;
		matrix[3] = 0.0f;

		matrix[4] = 2.0f * q.x * q.y - 2.0f * q.w * q.z;
		matrix[5] = 1.0f - 2.0f * q.x * q.x - 2.0f * q.z * q.z;
		matrix[6] = 2.0f * q.y * q.z + 2.0f * q.w * q.x;
		matrix[7] = 0.0f;

		matrix[8] = 2.0f * q.x * q.z + 2.0f * q.w * q.y;
		matrix[9] = 2.0f * q.y * q.z - 2.0f * q.w * q.x;
		matrix[10] = 1.0f - 2.0f * q.x * q.x - 2.0f * q.y * q.y;
		matrix[11] = 0.0f;

		matrix[12] = 0.0f;
		matrix[13] = 0.0f;
		matrix[14] = 0.0f;
		matrix[15] = 1.0f;
	}
};