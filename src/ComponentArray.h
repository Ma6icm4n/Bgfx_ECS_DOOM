#pragma once

#include "Types.h"
#include <array>
#include <cassert>
#include <unordered_map>

//PURE VIRTUAL COMPONENT ARRAY
class IComponentArray {

public:
	virtual ~IComponentArray() = default;
	virtual void EntityDestroyed(Entity entity) = 0;
};


//############# TEMPLATE TO MANAGE COMPONENT ARRAY #############
template<typename T>
class ComponentArray : public IComponentArray {

public:

	void InsertData(Entity entity, T component) {

		assert(m_entityToIndexMap.find(entity) == m_entityToIndexMap.end() && "component added to entity more than once");
		//add to array and update map values
		size_t newIndex = m_size;
		m_entityToIndexMap[entity] = newIndex;
		m_indexToEntityMap[newIndex] = entity;
		m_componentArray[newIndex] = component;
		++m_size;

	}

	void RemoveData(Entity entity) {

		assert(m_entityToIndexMap.find(entity) != m_entityToIndexMap.end() && "Removing non-existant component");
		//copy element at end into the deleted elements place to spare space and maintain density
		size_t indexOfRemovedEntity = m_entityToIndexMap[entity];
		size_t indexOfLastElement = m_size - 1;
		m_componentArray[indexOfRemovedEntity] = m_componentArray[indexOfLastElement];
		//update map to point to moved spot
		Entity entityOfLastElement = m_indexToEntityMap[indexOfLastElement];
		m_entityToIndexMap[entityOfLastElement] = indexOfRemovedEntity;
		m_indexToEntityMap[indexOfRemovedEntity] = entityOfLastElement;

		m_entityToIndexMap.erase(entity);
		m_indexToEntityMap.erase(indexOfLastElement);

		--m_size;
	}

	T& GetData(Entity entity) {

		assert(m_entityToIndexMap.find(entity) != m_entityToIndexMap.end() && "Retrieving non-existant component");

		return m_componentArray[m_entityToIndexMap[entity]];

	}
	//Remove Data from the array component where the entity is destroyed
	void EntityDestroyed(Entity entity) {

		if (m_entityToIndexMap.find(entity) != m_entityToIndexMap.end()) {
			RemoveData(entity);
		}

	}

private:
	// The packed array of components (of generic type T),
	// set to a specified maximum amount, matching the maximum number
	// of entities allowed to exist simultaneously, so that each entity
	// has a unique spot.
	std::array<T, MAX_ENTITIES> m_componentArray{};

	// Map from an entity ID to an array index.
	std::unordered_map<Entity, size_t> m_entityToIndexMap;

	// Map from an array index to an entity ID.
	std::unordered_map<size_t, Entity> m_indexToEntityMap;

	// Total size of valid entries in the array.
	size_t m_size;
};