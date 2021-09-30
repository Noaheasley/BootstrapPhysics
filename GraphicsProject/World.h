#pragma once
#include"Mesh.h"
#include "glm\mat4x4.hpp"
class World
{
public:
	World() {};
	World(int width, int height);
	~World() {}

	void start();
	void update();
	void draw();
	void end();

	glm::mat4 getProjectionViewModel();
private:
	int m_width = 1280, m_height = 720;

	Mesh m_quad;
	glm::mat4 m_viewMatrix = glm::mat4(1.0f);
	glm::mat4 m_projectionMatrix = glm::mat4(1.0f);
};

