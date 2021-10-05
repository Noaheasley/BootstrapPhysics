#include "World.h"
#include "glm\ext.hpp"

World::World(int width, int height) : World()
{
	m_width = width;
	m_height = height;
}

void World::start()
{
	m_quad.setTransform(glm::mat4(1.0f));
	m_quad.start();

	//Create camera transform
	m_camera.setTransform(glm::lookAt(
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f)
	));
	m_projectionMatrix = glm::perspective(
		m_camera.getFieldOfView() * glm::pi<float>() / 180.0f,
		(float)m_width / (float)m_height,
		m_camera.getNearClip(),
		m_camera.getFarClip()
	);
}

void World::update()
{
}

void World::draw(aie::ShaderProgram* shader)
{
	m_quad.draw(shader);
}

void World::end()
{
}

glm::mat4 World::getProjectionView()
{
	return m_projectionMatrix * m_camera.getTransform();
}
