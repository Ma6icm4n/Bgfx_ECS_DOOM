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
	unsigned int ProcessEvents(double& xpos, double& ypos);
	void Shutdown();

private:

	GLFWwindow* m_window;

	unsigned int m_buttons;
};