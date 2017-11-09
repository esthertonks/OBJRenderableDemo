#pragma once

#include "VertexCache.h"

class Mesh;

class Vector2;
class Vector3;

class MeshBuilder
{
public:
	MeshBuilder();
	~MeshBuilder() {};

	bool AddVertexPosition(const Vector3 &position);
	bool AddVertexNormal(const Vector3 &normal);
	bool AddVertexTextureCoords(const Vector2 &texCoords);
	bool AddTriangle(const std::array<int, 3> positionIndices, const std::array<int, 3> texCoordIndices, const std::array<int, 3> normalIndices);
	bool AddQuad(const std::array<int, 4> positionIndices, const std::array<int, 4> texCoordIndices, const std::array<int, 4> normalIndices);

	std::shared_ptr<Mesh> GetCompleteMesh();
	Vector3 CalculateTriangleNormal(const std::array<int, 3>positionIndices);
	Vector3 CalculateQuadNormal(const std::array<int, 4>positionIndices);

private:

	Vector3 CalculateNormal(const int positionIndex1, const int positionIndex2, const int positionIndex3);

	std::shared_ptr<Mesh> m_mesh;

	// Used to store vector attributes before the vertex index is known
	std::vector<Vector3> m_positionList;
	std::vector<Vector3> m_normalList;
	std::vector<Vector2> m_texCoordList;

	std::unique_ptr<VertexCache> m_vertexCache;
};

