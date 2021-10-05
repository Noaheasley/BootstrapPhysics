#pragma once
#include "glm/mat4x4.hpp"
class Camera
{
public:
	Camera() {}
	Camera(float fieldOfView, float nearClip, float farClip)
		: m_fieldOfView{ fieldOfView }, m_nearClip{ nearClip }, m_farClip{ farClip } {}
	~Camera() {}

	glm::mat4 getTransform() { return m_transform; }
	void setTransform(glm::mat4 transform) { m_transform = transform; }
	float getFieldOfView() { return m_fieldOfView; }
	void setFieldOfView(float fieldOfView) { m_fieldOfView = fieldOfView; }
	float getNearClip() { return m_nearClip; }
	void setNearClip(float nearClip) { m_nearClip = nearClip; }
	float getFarClip() { return m_farClip; }
	void setFarClip(float farClip) { m_farClip = farClip; }

private:
	glm::mat4 m_transform = glm::mat4(1.0f);
	float m_fieldOfView = 45.0f;
	float m_nearClip = 0.001f;
	float m_farClip = 1000.0f;
};

