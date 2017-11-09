#pragma once

#include "Vertex.h"
#include "PrimitiveCommand.h"

class Mesh
{
public:

	Mesh();
	~Mesh();

	const std::vector<Vertex> &GetVertexBuffer()
	{
		return m_vertexBuffer;
	}

	const std::vector<int> &GetIndexBuffer()
	{
		return m_indexBuffer;
	}

	std::vector<PrimitiveCommand> &GetPrimitiveCommandList()
	{
		return m_primitiveCommandList;
	}

	void AddVertex(const Vertex &vertex)
	{
		m_vertexBuffer.emplace_back(vertex);
		return;
	}

	// TODO better to make consistent with index buffer and loose the -1
	int GetCurrentVertexIndex() {
		return m_vertexBuffer.size() - 1;
	}

	int GetCurrentIndexBufferIndex() {
		return m_indexBuffer.size();
	}

	void AddIndex(const int index)
	{
		m_indexBuffer.push_back(index);
	}

	void AddPrimitive(const PrimitiveCommand &primitiveCommand)
	{
		m_primitiveCommandList.emplace_back(primitiveCommand);
	}

private:
	std::vector<Vertex> m_vertexBuffer;
	std::vector<int> m_indexBuffer;
	std::vector<PrimitiveCommand> m_primitiveCommandList;
};

