#pragma once

#include "stdafx.h"
#include <sstream>

class Mesh;
class MeshBuilder;
class Vector2;
class Vector3;

class OBJLoader
{
public:
	OBJLoader();
	 ~OBJLoader();

	bool FileIsSupported(const std::string &filename);
	std::shared_ptr<Mesh> LoadFile(const std::string &filename);

private:
	bool ReadLine(std::ifstream &fileStream);
	void AddTriangleData(std::vector<std::array<int, 3>> &faceIndices);
	void AddQuadData(std::vector<std::array<int, 3>> &faceIndices);

	Vector3 ParsePosition(std::stringstream &stringstream);
	Vector3 ParseNormal(std::stringstream &stringstream);
	Vector2 ParseTexCoords(std::stringstream &stringstream);
	std::array<int, 3> ParseVertexIndices(std::stringstream &stringStream);

	std::unique_ptr<MeshBuilder> m_meshBuilder;
};



