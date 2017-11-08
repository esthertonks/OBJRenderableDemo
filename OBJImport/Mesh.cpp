#include "stdafx.h"
#include "Mesh.h"

Mesh::Mesh() : m_vertexBuffer(new std::vector<Vertex>()),
	m_indexBuffer(new std::vector<int>()),
	m_primitiveCommandList(new std::vector<PrimitiveCommand>())
{
	m_vertexBuffer;
	m_indexBuffer;
	m_primitiveCommandList;
}


Mesh::~Mesh()
{
}
