#pragma once
#include "Shader.h"
#include "World.h"

class GLFWwindow;

class Engine
{
public:
	Engine();
	Engine(int width, int height, const char* title);
	~Engine();

	int run();

private:
	int start();
	int update();
	int draw();
	int end();
	bool getGameOver();

private:
	GLFWwindow* m_window = nullptr;
	int m_width, m_height;
	const char* m_title;

	aie::ShaderProgram m_shader;

	World* m_world;
};

