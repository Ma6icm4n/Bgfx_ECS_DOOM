#pragma once

#include <GLFW/glfw3.h>
#include <bitset>
#include <string>

#include "bgfx/bgfx.h"
#include "bgfx/platform.h"
#include "bx/math.h"
#define GLFW_EXPOSE_NATIVE_WIN32
#include "GLFW/glfw3native.h"

using std::string;

class Window {

public :
	void Init(string const& windowTitle, unsigned int windowWidth, unsigned int windowHeight, unsigned int windowPositonX, unsigned int windowPositionY);

	void Update();
//plus tard	void ProcessEvents();
	void Shutdown();

private:

	GLFWwindow* m_window;

	std::bitset<8> m_buttons;
};