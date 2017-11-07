#pragma once

#include "stdafx.h"

class Mesh;

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
	bool ReadFile(const std::string &filename, std::ifstream &fileStream);
	bool ReadOBJ(std::ifstream &fileStream, std::shared_ptr<Mesh> mesh);

	bool ReadVertexPosition(std::stringstream &stringStream);
	bool ReadVertexNormal(std::stringstream &stringStream);
	bool ReadVertexTextureCoords(std::stringstream &stringStream);
	bool ReadFaceIndices(std::stringstream &stringStream);

	// Used to store vector attributes before the vertex index is known
	std::unique_ptr<std::vector<Vector3>> positionList;
	std::unique_ptr<std::vector<Vector3>> normalList;
	std::unique_ptr<std::vector<Vector3>> texCoordList;
};



