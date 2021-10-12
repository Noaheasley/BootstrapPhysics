#include "World.h"
#include "gl_core_4_4.h"
#include "glm/ext.hpp"

World::World(int width, int height) : World()
{
	m_width = width;
	m_height = height;
}

void World::start()
{
	//Initialize the quad
	m_quad.setTransform(glm::mat4(10.0f));
	m_quad.start();
	if (!m_earthDiffuse.load("earth_diffuse.jpg")) {
		printf("Failed to load texture.\n");
	}

	//Create camera transforms
	m_camera.setPosition(glm::vec3(1.0f, 1.0f, 1.0f));
	m_camera.setYaw(-135.0f);
	m_camera.setPitch(-35.0f);
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

void World::draw()
{
	int program = -1;
	glGetIntegerv(GL_CURRENT_PROGRAM, &program);
	if (program == -1)
		printf("No shader bound.\n");

	int diffuseTextureUniform = glGetUniformLocation(program, "diffuseTexture");
	if (diffuseTextureUniform >= 0)
		glUniform1i(diffuseTextureUniform, 0);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_earthDiffuse.getHandle());

	m_quad.draw();
}

void World::end()
{
}

glm::mat4 World::getProjectionViewModel()
{
	return m_projectionMatrix * m_camera.getViewMatrix() * m_quad.getTransform();
}
