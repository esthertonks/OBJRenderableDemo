#pragma once

#include "Vertex.h"
#include "PrimitiveCommand.h"

typedef std::shared_ptr<std::vector<int>> IndexBuffer;
typedef std::shared_ptr<std::vector<Vertex>> VertexBuffer;
typedef std::shared_ptr<std::vector<PrimitiveCommand>> PrimitiveCommandList;

class Mesh
{
public:

	Mesh();
	~Mesh();

	VertexBuffer GetVertexBuffer()
	{
		return m_vertexBuffer;
	}

	IndexBuffer GetIndexBuffer() 
	{
		return m_indexBuffer;
	}

	PrimitiveCommandList GetPrimitiveCommandList() 
	{
		return m_primitiveCommandList;
	}

	int AddVertex(const Vertex &vertex)
	{
		m_vertexBuffer->emplace_back(vertex);
		return m_vertexBuffer->size();
	}

	void AddIndex(const int index)
	{
		m_indexBuffer->push_back(index);
	}

	void AddPrimitive(const PrimitiveCommand &primitiveCommand)
	{
		m_primitiveCommandList->emplace_back(primitiveCommand);
	}

private:
	VertexBuffer m_vertexBuffer;
	IndexBuffer m_indexBuffer;
	PrimitiveCommandList m_primitiveCommandList;
};

