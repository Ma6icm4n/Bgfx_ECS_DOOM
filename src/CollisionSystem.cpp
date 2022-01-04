#include "CollisionSystem.h"
#include <iostream>

#include "RigidBody.h"
#include "Gravity.h"
#include "Transform.h"
#include "Collision.h"
#include "Coordinator.h"


extern Coordinator gCoordinator;

void CollisionSystem::Init() {}

void CollisionSystem::Update(float dt) {

	auto& cameraTransform = gCoordinator.GetComponent<Transform>(m_camera);

	float oldCameraPosition[3] = { cameraTransform.position[0], cameraTransform.position[1], cameraTransform.position[2] };
	auto& cameraCollision = gCoordinator.GetComponent<Collision>(m_camera);

	for (auto const& entity : m_Entities) {
		auto const& collisionBox = gCoordinator.GetComponent<Collision>(entity);
		if (&collisionBox == &cameraCollision) {
			continue;
		}

		float aBoxMin[3] = { collisionBox.Min[0], collisionBox.Min[1], collisionBox.Min[2] };
		float aBoxMax[3] = { collisionBox.Max[0], collisionBox.Max[1], collisionBox.Max[2] };


		float bBoxMin[3] = { cameraCollision.Min[0], cameraCollision.Min[1], collisionBox.Min[2] };
		float bBoxMax[3] = { cameraCollision.Max[0], cameraCollision.Max[1], cameraCollision.Min[2] };

		if ((aBoxMin[0] <= bBoxMax[0] && aBoxMax[1] >= bBoxMin[0]) &&
			(aBoxMin[1] <= bBoxMax[1] && aBoxMax[1] >= bBoxMin[1]) &&
			(aBoxMin[2] <= bBoxMax[2] && aBoxMax[2] >= bBoxMin[2])) {
			std::cout << "Collision Effective Between " << "aboxmin" << " and " << "bBoxMin" << "\n";
			bBoxMin[0] = cameraCollision.Min[0];
			bBoxMin[1] = cameraCollision.Min[1];
			bBoxMin[2] = cameraCollision.Min[2];
			cameraTransform.position[0] = oldCameraPosition[0];
			cameraTransform.position[1] = oldCameraPosition[1];
			cameraTransform.position[2] = oldCameraPosition[2];
		}
		else {
			continue;
		}

	}
}
