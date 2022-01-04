#pragma once
#include <vector>

struct Collision {
	std::vector<float> Max;
	std::vector<float> Min;

	static std::vector<float> GetMax(float* position, float* scale) {
		std::vector<float>Max = { 0, 0, 0 };
		Max[0] = position[0] - scale[0] > position[0] + scale[0] ? 
			position[0] - scale[0] : position[0] + scale[0];
		Max[1] = position[1] - scale[1] > position[1] + scale[1] ?
			position[1] - scale[1] : position[1] + scale[1];
		Max[2] = position[2] - scale[2] > position[2] + scale[2] ?
			position[2] - scale[2] : position[2] + scale[2];

		return Max;
	}

	static std::vector<float> GetMin(float* position, float* scale) {

		std::vector<float>Min = { 0, 0, 0 };
		Min[0] = position[0] - scale[0] < position[0] + scale[0] ?
			position[0] - scale[0] : position[0] + scale[0];
		Min[1] = position[1] - scale[1] < position[1] + scale[1] ?
			position[1] - scale[1] : position[1] + scale[1];
		Min[2] = position[2] - scale[2] < position[2] + scale[2] ?
			position[2] - scale[2] : position[2] + scale[2];

		return Min;
	}
};