#pragma once
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <iostream>
#include <sstream>

#include "Gravity.h"
#include "RigidBody.h"
#include "Transform.h"
#include "Renderable.h"
#include "Coordinator.h"
#include "PhysicSystem.h"
#include "RenderSystem.h"
#include "ControlSystem.h"
#include "Camera.h"
#include "Time.h"

Coordinator gCoordinator;
static bool quit = false;

void QuitHandler(Event& event) {
	quit = true;
}

void LevelLoader() {

	gCoordinator.Init();

	gCoordinator.AddEventListener(FUNCTION_LISTENER(Events::Window::QUIT, QuitHandler));

	gCoordinator.RegisterComponent<Gravity>();
	gCoordinator.RegisterComponent<RigidBody>();
	gCoordinator.RegisterComponent<Transform>();
	gCoordinator.RegisterComponent<Renderable>();
	gCoordinator.RegisterComponent<Camera>();

	auto physicsSystem = gCoordinator.RegisterSystem<PhysicsSystem>();
	{
		Signature signature;
		signature.set(gCoordinator.GetComponentType<Gravity>());
		signature.set(gCoordinator.GetComponentType<RigidBody>());
		signature.set(gCoordinator.GetComponentType<Transform>());
		gCoordinator.SetSystemSignature<PhysicsSystem>(signature);
	}

	physicsSystem->Init();

	auto controlSystem = gCoordinator.RegisterSystem<ControlSystem>();
	{
		Signature signature;
		signature.set(gCoordinator.GetComponentType<Transform>());
		signature.set(gCoordinator.GetComponentType<Camera>());
		gCoordinator.SetSystemSignature<ControlSystem>(signature);
	}
	controlSystem->Init();

	auto renderSystem = gCoordinator.RegisterSystem<RenderSystem>();
	{
		Signature signature;
		signature.set(gCoordinator.GetComponentType<Renderable>());
		signature.set(gCoordinator.GetComponentType<Transform>());
		gCoordinator.SetSystemSignature<RenderSystem>(signature);
	}
	renderSystem->Init();


	std::ifstream file("../../assets/level.txt");
	if (!file) {
		std::cout << "File not found" << '\n';
		std::cout << "../assets/level.h" << '\n';

		return;
	}

	float nbRow = 0;
	float nbColumn = 0;
	std::string line;

	while (std::getline(file, line)) {
		std::cout << "line" << " " << std::to_string(nbRow) << "\n";

		for (std::string::iterator it = line.begin(); it != line.end(); ++it) {
			std::cout << *it;

			switch (*it) {
				case 'X' :
					Entity wall = gCoordinator.CreateEntity();
					float basevelocity[3] = { 0.0f, 0.0f, 0.0f };
					float baseacceleration[3] = { 0.0f, 0.0f, 0.0f };
					gCoordinator.AddComponent(wall,
						RigidBody{
						   *basevelocity,
						   *baseacceleration
						}
					);

					float baseposition[3] = { nbColumn * 2, 0.0f, nbRow * 2};
					float baserotation[3] = { 0.0f, 0.0f, 0.0f };
					float basescale[3] = { 1.0f, 1.0f, 1.0f };
					gCoordinator.AddComponent(wall,
						Transform{
							baseposition[0], baseposition[1], baseposition[2],
							baserotation[0],baserotation[1], baserotation[2],
							basescale[0], basescale[1], basescale[2]
						}
					);

			}
			++nbColumn;
		}
		std::cout << "\n";
		++nbRow;
	}
}