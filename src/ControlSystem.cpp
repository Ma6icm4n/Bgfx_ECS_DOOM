#include "ControlSystem.h"

#include "Transform.h"
#include "Camera.h"
#include "Coordinator.h"
#include "Acceleration.h"
#include <bitset>
#include <iostream>

extern Coordinator gCoordinator;

void ControlSystem::Init() {
	gCoordinator.AddEventListener(METHOD_LISTENER(Events::Window::INPUT, ControlSystem::InputListener));
}

void ControlSystem::Update(float dt, unsigned int input, double& xpos, double& ypos) {
		
	for (auto& entity : m_Entities) {
		auto& transform = gCoordinator.GetComponent<Transform>(entity);
		auto& camera = gCoordinator.GetComponent<Camera>(entity);

		float speed = 0.25f;

		if (input == 1)
		{
			transform.position[0] += camera.forward[0] *  speed;
			transform.position[1] += camera.forward[1] *  speed;
			transform.position[2] += camera.forward[2] *  speed;
		}
		else if (input == 2)
		{
			transform.position[0] -= camera.right[0] * speed;
			transform.position[1] -= camera.right[1] * speed;
			transform.position[2] -= camera.right[2] * speed;
		}


		if (input == 3)
		{
			transform.position[0] -= camera.forward[0] * speed;
			transform.position[1] -= camera.forward[1] * speed;
			transform.position[2] -= camera.forward[2] * speed;
		}
		else if (input == 4)
		{
			transform.position[0] += camera.right[0] * speed;
			transform.position[1] += camera.right[1] * speed;
			transform.position[2] += camera.right[2] * speed;
		}


		if (input == 5)
		{
			transform.position[1] -= (dt * speed);
		}
		else if (input == 6)
		{
			transform.position[1] += (dt * speed);
		}
		transform.rotation[0] += (xpos * 0.02);
		transform.rotation[1] += (ypos * 0.02);
		xpos /= 10;
		ypos /= 10;

		
	}
}

void ControlSystem::InputListener(Event& event) {
	//m_buttons = event.GetParam<std::bitset<8>>(Events::Window::Input::INPUT);
}



