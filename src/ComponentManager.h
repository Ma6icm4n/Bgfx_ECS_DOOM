#pragma once
#include "ComponentArray.h"
#include "Types.h"
#include <any>
#include <memory>
#include <unordered_map>

class ComponentManager {

public:

	template<typename T> 
	void RegisterComponent() {

		const char* typeName = typeId(T).name();
		
		assert(m_componentTypes.find(typeName) == m_componentTypes.end() && "Registering component type more than once");

		m_componentTypes.insert({ typeName, m_nextComponentType });
		m_ComponentArrays.insert({ typeName, std::make_shared<ComponentArray<T>>() });

		++m_nextComponentType;

	}

	template<typename T>
	ComponentType GetComponentType() {

		const char* typeName = typeId(T).name();

		assert(m_componentTypes.find(typeName) != m_componentTypes.end() && "Component not registered before use ");

		return m_componentTypes[typeName];
	}

	template<typename T>
	void RemoveComponent(Entity entity) {

		GetComponentArray<T>()->RemoveData(entity);
	}

	template<typename T>
	T& GetComponent(Entity entity) {

		return GetComponentArray<T>()->GetData(entity);
	}

	void EntityDestroyed(Entity entity) {
		for (auto const& pair : m_componentArrays) {
			auto const& component = pair.second;

			component->EntityDestroyed(entity);
		}
	}


private:

	std::unordered_map<const char*, ComponentType> m_componentTypes{};
	std::unordered_map<const char*, std::shared_ptr<IComponentArray>> m_componentArrays{};
	ComponentType m_nextComponentType{};

};