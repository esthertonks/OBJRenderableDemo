#pragma once

class Mesh;

class Vector2;
class Vector3;
class Vertex;

class MeshBuilder
{
public:
	MeshBuilder();
	~MeshBuilder() {};

	bool AddVertexPosition(const Vector3 &position);
	bool AddVertexNormal(const Vector3 &normal);
	bool AddVertexTextureCoords(const Vector2 &texCoords);
	bool AddTriangle(const std::array<int, 3> positionIndices, const std::array<int, 3> texCoordIndices, const std::array<int, 3> normalIndices);
	bool AddQuad(const std::array<int, 4>positionIndices, const std::array<int, 4> texCoordIndices, const std::array<int, 4> normalIndices);

	std::shared_ptr<Mesh> GetCompleteMesh();
	void GenerateNormals();

private:

	void AddIndexToCache(int oldIndex, int newIndex);
	int GetVertexIndex(int positionIndex, Vertex &vertex);

	std::shared_ptr<Mesh> m_mesh;

	// Used to store vector attributes before the vertex index is known
	std::unique_ptr<std::vector<Vector3>> m_positionList;
	std::unique_ptr<std::vector<Vector3>> m_normalList;
	std::unique_ptr<std::vector<Vector2>> m_texCoordList;

	std::multimap<int, int> m_vertexIndexCache;

};

