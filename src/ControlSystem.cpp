#include "ControlSystem.h"

#include "Transform.h"
#include "Coordinator.h"
#include "Acceleration.h"
#include <bitset>
#include <iostream>

extern Coordinator gCoordinator;

void ControlSystem::Init() {
	gCoordinator.AddEventListener(METHOD_LISTENER(Events::Window::INPUT, ControlSystem::InputListener));
}

void ControlSystem::Update(float dt, unsigned int input) {
	for (auto& entity : m_Entities) {
		auto transform = gCoordinator.GetComponent<Transform>(entity);

		float speed = 200.0f;

		if (input == 1)
		{
			transform.position[2] -= (dt * speed);
		}
		else if (input == 2)
		{
			transform.position[2] += (dt * speed);
		}


		if (input == 3)
		{
			transform.position[1] += (dt * speed);
		}
		else if (input == 4)
		{
			transform.position[1] -= (dt * speed);
		}


		if (input == 5)
		{
			transform.position[0] -= (dt * speed);
		}
		else if (input == 6)
		{
			transform.position[0] += (dt * speed);
		}
	}
}

void ControlSystem::InputListener(Event& event) {
	//m_buttons = event.GetParam<std::bitset<8>>(Events::Window::Input::INPUT);
}



