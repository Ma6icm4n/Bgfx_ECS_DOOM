#pragma once

#include "System.h"

class CollisionSystem : public System {
public:

	void Init();

	void Update(float dt);
private:
	Entity m_camera;
};