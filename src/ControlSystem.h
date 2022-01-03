#pragma once

#include "System.h"

class Event;

class ControlSystem : public System {
public:
	void Init();
	void Update(unsigned int input, double& xpos, double& ypos);

private:
	std::bitset<8> m_buttons;
};