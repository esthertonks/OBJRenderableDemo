#pragma once

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
	bool AddTriangle(const int positionIndices[3], const int normalIndices[3], const int texCoordIndices[3]);
	bool AddQuad(const int positionIndices[4], const int normalIndices[4], const int texCoordIndices[4]);

	std::shared_ptr<Mesh> GetMesh()
	{
		return m_mesh;
	}

private:

	std::shared_ptr<Mesh> m_mesh;

	// Used to store vector attributes before the vertex index is known
	std::unique_ptr<std::vector<Vector3>> positionList;
	std::unique_ptr<std::vector<Vector3>> normalList;
	std::unique_ptr<std::vector<Vector2>> texCoordList;

};

