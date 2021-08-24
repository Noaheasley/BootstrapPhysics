#include "Sphere.h"
#include "Gizmos.h"

Sphere::Sphere(glm::vec2 position, glm::vec2 velocity, float mass, float radius, glm::vec4 color)
	:RigidBody(ShapeType::SPHERE, position, velocity, 0.0f, mass)
{
	m_radius = radius;
	m_color = color;
}

Sphere::~Sphere()
{
}

void Sphere::draw()
{
	aie::Gizmos::add2DCircle(getPosition(), m_radius, m_radius * 4 + 4, m_color);
}
