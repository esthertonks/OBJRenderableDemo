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
	bool ReadLine(std::ifstream &fileStream, std::unique_ptr<MeshBuilder> meshBuilder);

	Vector3 ParsePosition(std::stringstream &stringstream);
	Vector3 ParseNormal(std::stringstream &stringstream);
	Vector2 ParseTexCoords(std::stringstream &stringstream);
	std::vector<int> ParseVertexIndices(std::stringstream &stringStream);
};



