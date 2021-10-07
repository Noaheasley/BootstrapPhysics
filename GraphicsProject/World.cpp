#include "World.h"
#include "glm\ext.hpp"
#include "GLFW//glfw3.h"

World::World(int width, int height) : World()
{
	m_width = width;
	m_height = height;
}

void World::start()
{
	m_quad.setTransform(glm::mat4(1.0f));
	m_quad.setColor(glm::vec4(0.2f, 0.8f, 0.6f, 1.0f));
	m_quad.start();
	//intialize the light
	m_light.setDirection(glm::vec3(-1.0f));
	m_light.setAmbient(glm::vec4(0.6f, 0.6f, 0.0f, 1.0f));
	m_light.setDiffuse(glm::vec4(0.6f, 0.6f, 1.0f, 1.0f));
	m_light.setSpecular(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
	m_light.setSpecularPower(1.0f);

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

void World::update(double deltaTime)
{
	int keyForward = GLFW_KEY_W;
	int keyBack = GLFW_KEY_S;
	int keyLeft = GLFW_KEY_A;
	int keyRight = GLFW_KEY_D;
	int keyUp = GLFW_KEY_E;
	int keyDown = GLFW_KEY_Q;

	float cameraSpeed = 10.0f;
	float cameraSensitivity = 1.0f;

	//Calculate the camera's forward vector
	glm::vec3 cameraForward = glm::vec3(0.0f, 0.0f, 1.0f);
	//Calculate the camera right vector
	glm::vec3 cameraRight = glm::vec3(1.0f, 0.0f, 0.0f);
	//calculate the camera up vector
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

	//Get current mouse coordinates
	double mouseX = 0, mouseY = 0;
	glfwGetCursorPos(m_window, &m_currentMouseX, &m_currentMouseY);
	
	//Rotate camera using change in mouse position
	double deltaMouseX = m_currentMouseX - m_previousMouseX;
	double deltaMouseY = m_currentMouseY - m_previousMouseY;
	if (deltaMouseX != 0.0 && deltaMouseY != 0.0) {
		glm::mat4 cameraTransform = m_camera.getTransform();
		cameraTransform = glm::rotate(cameraTransform, (float)(deltaMouseX * cameraSensitivity * deltaTime), cameraUp);
		cameraTransform = glm::rotate(cameraTransform, (float)(deltaMouseY * cameraSensitivity* deltaTime), cameraRight);
		m_camera.setTransform(cameraTransform);
	}


	//store previous mouse coordinates
	m_previousMouseX = m_currentMouseX;
	m_previousMouseY = m_currentMouseY;



	//Get input
	if (glfwGetKey(m_window, keyForward))
	{
		//Move forward
		glm::mat4 cameraTransform = m_camera.getTransform();
		cameraTransform = glm::translate(cameraTransform, cameraForward * cameraSpeed * (float)deltaTime);
		m_camera.setTransform(cameraTransform);
	}
	if (glfwGetKey(m_window, keyBack))
	{
		//Move back
		glm::mat4 cameraTransform = m_camera.getTransform();
		cameraTransform = glm::translate(cameraTransform, -cameraForward * cameraSpeed * (float)deltaTime);
		m_camera.setTransform(cameraTransform);
	}
	if (glfwGetKey(m_window, keyRight))
	{
		//Move right
		glm::mat4 cameraTransform = m_camera.getTransform();
		cameraTransform = glm::translate(cameraTransform, cameraRight * cameraSpeed * (float)deltaTime);
		m_camera.setTransform(cameraTransform);
	}
	if (glfwGetKey(m_window, keyLeft))
	{
		//Move left
		glm::mat4 cameraTransform = m_camera.getTransform();
		cameraTransform = glm::translate(cameraTransform, -cameraRight * cameraSpeed * (float)deltaTime);
		m_camera.setTransform(cameraTransform);
	}
	if (glfwGetKey(m_window, keyUp))
	{
		//Move up
		glm::mat4 cameraTransform = m_camera.getTransform();
		cameraTransform = glm::translate(cameraTransform, cameraUp * cameraSpeed * (float)deltaTime);
		m_camera.setTransform(cameraTransform);
	}
	if (glfwGetKey(m_window, keyDown))
	{
		//Move forward
		glm::mat4 cameraTransform = m_camera.getTransform();
		cameraTransform = glm::translate(cameraTransform, -cameraUp * cameraSpeed * (float)deltaTime);
		m_camera.setTransform(cameraTransform);
	}
}

void World::draw(aie::ShaderProgram* shader)
{
	shader->bindUniform("cameraPosition", glm::vec4(1.0f));
	shader->bindUniform("lightDirection", m_light.getDirection());
	shader->bindUniform("lightAmbient", m_light.getAmbient());
	shader->bindUniform("lightDiffuse", m_light.getDiffuse());
	shader->bindUniform("lightSpecular", m_light.getSpecular());
	shader->bindUniform("specularPower", m_light.getSpecularPower());
	m_quad.draw(shader);
}

void World::end()
{
}

glm::mat4 World::getProjectionView()
{
	return m_projectionMatrix * m_camera.getTransform();
}
