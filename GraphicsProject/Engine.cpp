#include "Engine.h"
#include "gl_core_4_4.h"
#include "GLFW/glfw3.h"
#include "glm\ext.hpp"
#include <iostream>

Engine::Engine() : Engine(1280, 720, "Graphics")
{
}

Engine::Engine(int width, int height, const char* title)
{
	m_world = new World(width, height);
	m_width = width;
	m_height = height;
	m_title = title;

	m_shader = new aie::ShaderProgram();
}

Engine::~Engine()
{
	delete m_world;
	delete m_shader;
}

int Engine::run()
{
	int exitCode = 0;

	double currentTime = 0.0f;
	double previousTime = 0.0f;
	double deltaTime = 0.0f;

	exitCode = start();
	if (exitCode) {
		return exitCode;
	}

	while (!getGameOver()) {
		//get current time
		currentTime - glfwGetTime();
		//Find the change in time
		deltaTime = currentTime - previousTime;
		//Store the current time for the next 
		previousTime = currentTime;

		exitCode = update(deltaTime);
		if (exitCode) {
			return exitCode;
		}
		exitCode = draw(m_shader);
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

	//Initialize the screen
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	glEnable(GL_DEPTH_TEST);

	//Initialize the shader
	m_shader->loadShader(
		aie::eShaderStage::VERTEX,
		"simpleVert.shader"
	);
	m_shader->loadShader(
		aie::eShaderStage::FRAGMENT,
		"simpleFrag.shader"
	);
	if (!m_shader->link()) {
		printf("Shader Error: %s\n", m_shader->getLastError());
		return -10;
	}

	m_world->setWindow(m_window);
	m_world->start();

	return 0;
}

int Engine::update(double deltaTime)
{
	if (!m_window) return -4;

	glfwPollEvents();

	m_world->update(deltaTime);

	return 0;
}

int Engine::draw(aie::ShaderProgram* shader)
{
	if (!m_window) return -5;

	//clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	shader->bind();

	shader->bindUniform("projectionViewMatrix", m_world->getProjectionView());

	m_world->draw(shader);
	
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
