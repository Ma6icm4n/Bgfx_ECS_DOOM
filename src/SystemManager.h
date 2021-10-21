#pragma once

#include "System.h"
#include "Types.h"
#include <cassert>
#include <memory>
#include <unordered_map>


class SystemManager {

public:


	//System Factory with Type Templated
	template<typename T>
	std::shared_ptr<T> RegisterSystem() {
		//get the name of the type corresponding to the id
		const char* typeName = typeid(T).name();

		assert(m_Systems.find(typeName) == m_Systems.end() && " Registering system more than once");


		//create a pointer for the system to use it externally
		auto system = std::make_shared<T>();
		m_Systems.insert({ typeName, system });
		return system;
	}

	//Add signature to this system
	template <typename T>
	void SetSignature(Signature signature) {

		const char* typeName = typeid(T).name();

		assert(m_Systems.find(typeName) != m_Systems.end() && " System used before registered");

		m_Signatures.insert({ typeName, signature });
	}


	//Cascade destroy when entity is destroyed 
	//destroy entity in all system list
	void EntityDestroyed(Entity entity)
	{
		for (auto const& pair : m_Systems)
		{
			auto const& system = pair.second;


			system->m_Entities.erase(entity);
		}
	}


	//
	void EntitySignatureChanged(Entity entity, Signature entitySignature) {

		//notify all systems that a signature changed
		for (auto const& pair : m_Systems) {


			auto const& type = pair.first;
			auto const& system = pair.second;
			auto const& systemSignature = m_Signatures[type];
			//entity signature match system signature - insert into set
			//if not erase from set
			if ((entitySignature & systemSignature) == systemSignature) {
				system->m_Entities.insert(entity);
			}
			else {
				system->m_Entities.erase(entity);
			}
		}
	}


private :
	//map of signatures and systems to associate name with
	std::unordered_map<const char*, Signature> m_Signatures{};
	std::unordered_map<const char*, std::shared_ptr<System>> m_Systems{};

};