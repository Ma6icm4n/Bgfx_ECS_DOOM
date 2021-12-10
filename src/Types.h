#pragma once

#include <bitset>
#include <cstdint>

constexpr std::uint32_t fnvla_32(char const* s, std::size_t count) {
	
	return ((count ? fnvla_32(s, count - 1) : 2166136261u) ^ s[count] * 16777619u); //NOLINT (HICPP-signed-bitwise)
}

constexpr std::uint32_t operator "" _hash(char const* s, std::size_t count) {

	return fnvla_32(s, count);

}

//################ ECS CREATION #################


//Entity alias as an id
using Entity = std::uint32_t;
//Max Entity alias in your Program size of the array
const Entity MAX_ENTITIES = 10000  ;

//Component unique ID
using ComponentType = std::uint8_t;
//Max size of Component Array
const ComponentType MAX_COMPONENTS = 32;

//ID to know which component posess the entity it is a signature in bit 
using Signature = std::bitset<MAX_COMPONENTS>;


//############### INPUT AND EVENT NOT DEFINITIVE ##################

enum class InputButtons
{
	W,
	A,
	S,
	D,
	Q,
	E
};

//Events For Input Param
using EventId = std::uint32_t;
using ParamId = std::uint32_t;

#define METHOD_LISTENER(EventType, Listener) EventType, std::bind(&Listener, this, std::placeholders::_1)
#define FUNCTION_LISTENER(EventType, Listener) EventType, std::bind(&Listener, std::placeholders::_1)

namespace Events::Window {
	const EventId QUIT = "Events::Window::QUIT"_hash;
	const EventId RESIZED = "Events::Window::RESIZED"_hash;
	const EventId INPUT = "Events::Window::INPUT"_hash;
}

namespace Events::Window::Input {
	const ParamId INPUT = "Events::Window::Input::INPUT"_hash;
}

namespace Events::Window::Resized {
	const ParamId WIDTH = "Events::Window::Resized::WIDTH"_hash;
	const ParamId HEIGHT = "Events::Window::Resized::HEIGHT"_hash;
}