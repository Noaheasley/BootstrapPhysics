#include "Engine.h"
#include "gl_core_4_4.h"
#include "GLFW/glfw3.h"
#include <iostream>

Engine::Engine() : Engine(1280, 720, "Graphics")
{
}

Engine::Engine(int width, int height, const char* title)
{
	m_width = width;
	m_height = height;
	m_title = title;
}

Engine::~Engine()
{
}

int Engine::run()
{
	int exitCode = 0;

	exitCode = start();
	if (exitCode) {
		return exitCode;
	}

	while (!getGameOver()) {
		exitCode = update();
		if (exitCode) {
			return exitCode;
		}
		exitCode = draw();
		if (exitCode) {
			return exitCode;
		}
	}

	//End
	exitCode = end();
	if (exitCode) {
		return exitCode;
	}
	return 0;
}

int Engine::start()
{
	if (glfwInit() == GLFW_FALSE) {
		return -1;
	}

	m_window = glfwCreateWindow(m_width, m_height, m_title, nullptr, nullptr);
	if (!m_window) {
		glfwTerminate();
		return -2;
	}

	glfwMakeContextCurrent(m_window);

	//Load OpenGl
	if (ogl_LoadFunctions() == ogl_LOAD_FAILED) {
		glfwDestroyWindow(m_window);
		glfwTerminate();
		return -3;
	}
	int majorVersion = ogl_GetMajorVersion();
	int minorVersion = ogl_GetMinorVersion();
	printf("GL: %i.%i\n", majorVersion, minorVersion);
	return 0;
}

int Engine::update()
{
	if (!m_window) return -4;

	glfwSwapBuffers(m_window);
	glfwPollEvents();
}

int Engine::draw()
{
	if (!m_window) return -5;

	glfwSwapBuffers(m_window);
	
	return 0;
}

int Engine::end()
{
	if (!m_window) return -5;
	//cleanup and exit
	glfwDestroyWindow(m_window);
	glfwTerminate();
	return 0;
}

bool Engine::getGameOver()
{
	if (!m_window) return true;

	bool condition = glfwWindowShouldClose(m_window);
	condition = condition || glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS;

	return condition;
}
