#include "PhysicSystem.h"

#include "Gravity.h"
#include "RigidBody.h"
#include "Transform.h"
#include "Coordinator.h"

extern Coordinator gCoordinator;

void PhysicsSystem::Init() {}

void PhysicsSystem::Update(float dt) {

	for (auto const& entity : m_Entities) {

		auto& rigidBody = gCoordinator.GetComponent<RigidBody>(entity);
		auto& transform = gCoordinator.GetComponent<Transform>(entity);

		// Forces
		auto const& gravity = gCoordinator.GetComponent<Gravity>(entity);

		transform.position[0] += rigidBody.velocity[0] * dt;
		transform.position[1] += rigidBody.velocity[1] * dt;
		transform.position[2] += rigidBody.velocity[2] * dt;

		rigidBody.velocity[0] += gravity.force[0] * dt;
		rigidBody.velocity[1] += gravity.force[1] * dt;
		rigidBody.velocity[2] += gravity.force[2] * dt;

	}
}
