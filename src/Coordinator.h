#pragma once

#include "ComponentManager.h"
#include "EntityManager.h"
#include "SystemManager.h"
#include "EventManager.h"

#include "Types.h"
#include <memory>

class Coordinator {
public:

	void Init() {

		m_ComponentManager = std::make_unique<ComponentManager>();
		m_EntityManager = std::make_unique<EntityManager>();
		m_SystemManager = std::make_unique<SystemManager>();
		m_EventManager = std::make_unique<EventManager>();

	}

	Entity CreateEntity() {
		return m_EntityManager->CreateEntity();
	}

	void DestroyEntity(Entity entity) {

		m_EntityManager->DestroyEntity(entity);

		m_ComponentManager->EntityDestroyed(entity);

		m_SystemManager->EntityDestroyed(entity);

	}

//####################### Component Method ##################
	//we call every function to update component in their respective entity 
	template<typename T>
	void RegisterComponent() {
		m_ComponentManager->RegisterComponent<T>();
	}

	template<typename T>
	void AddComponent(Entity entity, T component) {
		
		m_ComponentManager->AddComponent<T>(entity, component);

		auto signature = m_EntityManager->GetSignature(entity);
		signature.set(m_ComponentManager->GetComponentType<T>(), true);
		m_EntityManager->SetSignature(entity, signature);
		m_SystemManager->EntitySignatureChanged(entity, signature);

	}

	template<typename T>
	void RemoveComponent(Entity entity) {

		m_ComponentManager->RemoveComponent<T>(entity);

		auto signature = m_EntityManager->GetSignature(entity);
		signature.set(m_ComponentManager->GetComponentType<T>(), false);
		m_EntityManager->SetSignature(entity, signature);

		m_SystemManager->EntitySignatureChanged(entity, signature);
	}

	template<typename T>
	T& GetComponent(Entity entity) {
		return m_ComponentManager->GetComponent<T>(entity);
	}

	template<typename T>
	ComponentType GetComponentType() {
		return m_ComponentManager->GetComponentType<T>();
	}

//################# System Method ###############

	template<typename T>
	std::shared_ptr<T> RegisterSystem() {
		return m_SystemManager->RegisterSystem<T>();
	}

	template<typename T>
	void SetSystemSignature(Signature signature) {
		m_SystemManager->SetSignature<T>(signature);
	}



//################### EVENTS METHODS ##################
	void AddEventListener(EventId eventId, std::function<void(Event&)> const& listener) {
		m_EventManager->AddListener(eventId, listener);
	}

	void SendEvent(Event& event) {
		m_EventManager->SendEvent(event);
	}

	void SendEvent(EventId eventId) {
		m_EventManager->SendEvent(eventId);
	}




private:

	//get pointer for all manager class
	std::unique_ptr<ComponentManager> m_ComponentManager;
	std::unique_ptr<EntityManager> m_EntityManager;
	std::unique_ptr<EventManager> m_EventManager;
	std::unique_ptr<SystemManager> m_SystemManager;
	
};