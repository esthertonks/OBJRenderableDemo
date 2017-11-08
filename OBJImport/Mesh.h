#pragma once

#include "Vertex.h"
#include "PrimitiveCommand.h"

class Mesh
{
public:

	Mesh();
	~Mesh();

	std::shared_ptr<std::vector<Vertex>> GetVertexBuffer()
	{
		return m_vertexBuffer;
	}

	std::shared_ptr<std::vector<int>> GetIndexBuffer()
	{
		return m_indexBuffer;
	}

	std::shared_ptr<std::vector<PrimitiveCommand>> GetPrimitiveCommandList()
	{
		return m_primitiveCommandList;
	}

	int AddVertex(const Vertex &vertex)
	{
		m_vertexBuffer->emplace_back(vertex);
		return m_vertexBuffer->size() - 1;
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
	std::shared_ptr<std::vector<Vertex>> m_vertexBuffer;
	std::shared_ptr<std::vector<int>> m_indexBuffer;
	std::shared_ptr<std::vector<PrimitiveCommand>> m_primitiveCommandList;
};

