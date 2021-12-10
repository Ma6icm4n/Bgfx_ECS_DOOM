#pragma once

#include "System.h"

class Event;

class ControlSystem : public System {
public:
	void Init();
	void Update(float dt, unsigned int input);

private:
	std::bitset<8> m_buttons;
	void InputListener(Event& event);
};