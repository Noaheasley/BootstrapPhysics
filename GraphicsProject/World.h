#pragma once
#include "Shader.h"
#include "Camera.h"
#include"Quad.h"
#include "glm\mat4x4.hpp"
class World
{
public:
	World() {};
	World(int width, int height);
	~World() {}

	void start();
	void update();
	void draw(aie::ShaderProgram* shader);
	void end();

	glm::mat4 getProjectionView();
private:
	int m_width = 1280, m_height = 720;

	Quad m_quad = Quad(glm::vec4(0.6f, 0.2f, 0.6f, 1.0f));
	Camera m_camera = Camera();
	glm::mat4 m_projectionMatrix = glm::mat4(1.0f);
};

