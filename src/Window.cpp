#include "Window.h"

#include <iostream>

void Window::Init(string const& windowTitle, unsigned int windowWidth, unsigned int windowHeight, unsigned int windowPositionX, unsigned int windowPositionY) {
	
//Init API and Create window
	glfwInit();
	m_window = glfwCreateWindow(windowWidth, windowHeight, windowTitle.c_str(), NULL, NULL);

//Macro Parameter to configure GLFW
	glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
	glfwWindowHint(GLFW_FOCUSED, GLFW_TRUE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);


//######## BGFX_INIT_GRAPHIC_RENDERING ############

// select platform to launch bgfx
	bgfx::PlatformData dp;
	dp.nwh = glfwGetWin32Window(m_window);
	bgfx::setPlatformData(dp);


	bgfx::Init bgfxInit;
	bgfxInit.type = bgfx::RendererType::Count;
	bgfxInit.resolution.width = windowWidth;
	bgfxInit.resolution.height = windowHeight;
	bgfxInit.resolution.reset = BGFX_RESET_VSYNC;
	bgfx::init(bgfxInit);


//########## RENDER ############

	bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x443355FF, 1.0f, 0);
	bgfx::setViewRect(0, 0, 0, windowWidth, windowHeight);


}

void Window::Update() {
	
	glfwSwapBuffers(m_window);
}

void Window::Shutdown() {
	
	glfwDestroyWindow(m_window);
	glfwTerminate();
}