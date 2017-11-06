#pragma once

class Vertex;
class PrimitiveCommandList;

class Mesh
{
public:
	typedef std::vector<int> IndexBuffer;
	typedef std::vector<Vertex> VertexBuffer;
	typedef std::unique_ptr<PrimitiveCommandList> PrimitiveCommandList;

	Mesh();
	~Mesh();

private:
	VertexBuffer vertexBuffer;
	IndexBuffer indexBuffer;
	PrimitiveCommandList primitiveCommandList;
};

