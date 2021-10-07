#pragma once
#include "Light.h"
#include "Shader.h"
#include "Camera.h"
#include"Quad.h"
#include "glm\mat4x4.hpp"
class GLFWwindow;

class World
{
public:
	World() {};
	World(int width, int height);
	~World() {}

	void start();
	void update(double deltaTime);
	void draw(aie::ShaderProgram* shader);
	void end();

	glm::mat4 getProjectionView();

	GLFWwindow* getWindow() { return m_window; }
	void setWindow(GLFWwindow* window) { m_window = window; }
private:
	int m_width = 1280, m_height = 720;
	Camera m_camera = Camera();
	glm::mat4 m_projectionMatrix = glm::mat4(1.0f);

	Quad m_quad = Quad(glm::vec4(0.6f, 0.2f, 0.6f, 1.0f));
	Light m_light;

	GLFWwindow* m_window = nullptr;
	double m_currentMouseX = 0.0;
	double m_currentMouseY = 0.0;
	double m_previousMouseX = 0.0;
	double m_previousMouseY = 0.0;
};

