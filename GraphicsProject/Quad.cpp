#include "Quad.h"

Quad::Quad(glm::vec4 color) : Quad::Quad()
{
	m_color = color;
}

Quad::Vertex* Quad::generateVertices(unsigned int& vertexCount, unsigned int& triCount)
{
	Vertex* vertices = nullptr;
	vertexCount = 6;
	triCount = 2;

	//Define vertices for a quad
	vertices = new Vertex[vertexCount];

	//triangle 0
	vertices[0].position = { -0.5f, 0.0f, 0.5f, 1.0f };
	vertices[1].position = { 0.5f, 0.0f, 0.5f, 1.0f };
	vertices[2].position = { -0.5f, 0.0f, -0.5f, 1.0f };
	//triangle 1
	vertices[3].position = { 0.5f, 0.0f, 0.5f, 1.0f };
	vertices[4].position = { -0.5f, 0.0f, -0.5f, 1.0f };
	vertices[5].position = { 0.5f, 0.0f, -0.5f, 1.0f };

	for (int i = 0; i < vertexCount; i++) {
		vertices[i].color = m_color;
	}
	vertices[0].color = { 1.0f, 1.0f, 1.0f, 1.0f };
	vertices[5].color = { 1.0f, 1.0f, 1.0f, 1.0f };

	//triangle 0
	vertices[0].texCoord = { 0.0f, 1.0f };
	vertices[1].texCoord = { 1.0f, 1.0f };
	vertices[2].texCoord = { 0.0f, 0.0f };
	//triangle 1
	vertices[3].texCoord = { 1.0f, 1.0f };
	vertices[4].texCoord = { 0.0f, 0.0f };
	vertices[5].texCoord = { 1.0f, 0.0f };

	return vertices;
}
