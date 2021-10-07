#include "Mesh.h"

Mesh::Mesh()
{
	m_transform = {
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f,
	};

	m_triCount = 0;
	m_vertexArrayObject = 0;
	m_vertexBufferObject = 0;
	m_indexBufferObject = 0;
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &m_vertexArrayObject);
	glDeleteBuffers(1, &m_vertexBufferObject);
	glDeleteBuffers(1, &m_indexBufferObject);
}

void Mesh::start()
{
	assert(m_vertexArrayObject == 0);

	//Generate buffers
	glGenBuffers(1, &m_vertexBufferObject);
	glGenVertexArrays(1, &m_vertexArrayObject);

	//Bind vertex array
	glBindVertexArray(m_vertexArrayObject);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObject);

	////Define the vertices for a quad
	//Vertex vertices[6];
	//
	////triangle 0
	//vertices[0].position = { -0.5f, 0.0f, 0.5f, 1.0f };
	//vertices[1].position = { 0.5f, 0.0f, 0.5f, 1.0f };
	//vertices[2].position = { -0.5f, 0.0f, -0.5f, 1.0f };
	////triangle 1
	//vertices[3].position = { 0.5f, 0.0f, 0.5f, 1.0f };
	//vertices[4].position = { -0.5f, 0.0f, -0.5f, 1.0f };
	//vertices[5].position = { 0.5f, 0.0f, -0.5f, 1.0f };
	
	//Generate the vertices
	unsigned int vertexCount;
	Vertex* vertices = generateVertices(vertexCount, m_triCount);

	//Fill vertex buffer
	glBufferData(
		GL_ARRAY_BUFFER,				//type of buffer
		sizeof(Vertex) * vertexCount,	//size in bytes of all vertices
		vertices,						//all vertices
		GL_STATIC_DRAW					//how the data will update
	);

	//Enable vertex position as first attribute
	glEnableVertexAttribArray(0);
	unsigned int memoryPosition = 0u;
	glVertexAttribPointer(
		0,						//attribute index
		4,						//number of values within attribute
		GL_FLOAT,				//type of each value
		GL_FALSE,				//whether to normalize
		sizeof(Vertex),			//size in bytes of one vertex
		(void*)memoryPosition	//memory position of this attribute
	);
	memoryPosition += sizeof(Vertex::position);
	//Enable vertex color as second attribute
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(
		1,						//attribute index
		4,						//number of values within attribute
		GL_FLOAT,				//type of each value
		GL_TRUE,				//whether to normalize
		sizeof(Vertex),			//size in bytes of one vertex
		(void*)memoryPosition//memory position of this attribute
	);
	memoryPosition += sizeof(Vertex::normal);
	//Enable vertex texture as third attribute
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(
		2,						//attribute index
		2,						//number of values within attribute
		GL_FLOAT,				//type of each value
		GL_FALSE,				//whether to normalize
		sizeof(Vertex),			//size in bytes of one vertex
		(void*)memoryPosition	//memory position of this attribute
	);
	memoryPosition += sizeof(Vertex::texCoord);
	//fourth attribute is tangent
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(
		3,						//attribute index
		4,						//number of values within attribute
		GL_FLOAT,				//type of each value
		GL_FALSE,				//whether to normalize
		sizeof(Vertex),			//size in bytes of one vertex
		(void*)memoryPosition	//memory position of this attribute
	);
	memoryPosition += sizeof(Vertex::tangent);
	//fifth attribute color
	glEnableVertexAttribArray(4);
	glVertexAttribPointer(
		4,						//attribute index
		4,						//number of values within attribute
		GL_FLOAT,				//type of each value
		GL_FALSE,				//whether to normalize
		sizeof(Vertex),			//size in bytes of one vertex
		(void*)memoryPosition	//memory position of this attribute
	);
	memoryPosition += sizeof(Vertex::color);

	//unbind buffer and array
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	delete[] vertices;
}

void Mesh::draw(aie::ShaderProgram* shader)
{
	shader->bindUniform("modelMatrix", m_transform);
	glBindVertexArray(m_vertexArrayObject);
	glDrawArrays(GL_TRIANGLES, 0, m_triCount * 3);
}

