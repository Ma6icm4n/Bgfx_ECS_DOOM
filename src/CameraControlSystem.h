#pragma once

#include "System.h"

class Event;

class CameraControlSystem : public System {
public:
	void Init();

	void Update(float dt);

private:
	std::bitset<8> m_buttons;
};