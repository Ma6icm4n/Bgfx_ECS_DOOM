#pragma once

#include "Types.h"
#include <array>
#include <cassert>
#include <queue>

class EntityManager {

public:

	//call the array of entities and add new at the end
	EntityManager() {
		
		for (Entity entity = 0; entity < MAX_ENTITIES; ++entity) {
			m_availableEntities.push(entity);
		}

	}

	//Entity factory
	Entity CreateEntity() {
		
		assert(m_livingEntityCount < MAX_ENTITIES && "Too many entities in program");

		Entity id = m_availableEntities.front();
		m_availableEntities.pop();
		++m_livingEntityCount;
		
		return id;

	}

	//Trash Entity
	void DestroyEntity(Entity entity) {
		
		assert(entity < MAX_ENTITIES && "Entity out of range");

		m_signature[entity].reset();
		m_availableEntities.push(entity);
		--m_livingEntityCount;

	}

	//Attach signature to Entity
	void SetSignature(Entity entity, Signature signature) {
		
		assert(entity < MAX_ENTITIES && "Entity out of range");

		m_signature[entity] = signature;

	}

	//Find Entity Signature 
	Signature GetSignature(Entity entity) {
		
		assert(entity < MAX_ENTITIES && "Entity out of range");

		return m_signature[entity];

	}

private:
	std::queue<Entity> m_availableEntities{};
	std::array<Signature, MAX_ENTITIES> m_signature{};
	uint32_t m_livingEntityCount{};
};