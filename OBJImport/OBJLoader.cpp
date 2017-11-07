#include "stdafx.h"
#include "OBJLoader.h"
#include "Mesh.h"
#include "StringUtils.h"
#include "Vector3.h"
#include "Vector2.h"
#include "MeshBuilder.h"

#include <fstream>

#ifdef _DEBUG
#define LOG(str)    OutputDebugStringW(str)
#else
#define LOG(str)    (void)(str)
#endif

OBJLoader::OBJLoader()
{
}


OBJLoader::~OBJLoader()
{
}

bool OBJLoader::FileIsSupported(const std::string &filename)
{
	auto extension = StringUtils::GetFileExtension(filename);
	auto lowercaseExtension = StringUtils::ToLower(extension);
	if (extension.compare("obj") == 0) {
		return true;
	}

	return false;
}

std::shared_ptr<Mesh> OBJLoader::LoadFile(const std::string &filename)
{
	if (!FileIsSupported(filename)) {
		return false;
	}

	std::unique_ptr<MeshBuilder> meshBuilder = std::unique_ptr<MeshBuilder>(new MeshBuilder());

	std::ifstream fileStream;

	fileStream = std::ifstream(filename.c_str(), std::ios_base::in);

	if (!fileStream.is_open() || !fileStream.good())
	{
		return false;
	}


	while (fileStream && !fileStream.eof())
	{
		//ReadLine(fileStream, meshBuilder);
	}

	return meshBuilder->GetMesh();
}

bool OBJLoader::ReadLine(std::ifstream &fileStream, std::unique_ptr<MeshBuilder> meshBuilder)
{
	std::string line;

	std::getline(fileStream, line);
	if(fileStream.bad()) {
		return false;
	}

	std::stringstream stringStream;
	std::string key;

	// Skip empty lines and comments.
	if(line.size() == 0 || line[0] == '#' || line[0] == '$')
	{
		return true;
	}

	stringStream << line;
	stringStream >> key;

	// Vertex
	if (key == "v")
	{
		auto position = ParsePosition(stringStream);
		meshBuilder->AddVertexPosition(position);
	}
	// Vertex normal
	else if(key == "vn")
	{
		auto normal = ParseNormal(stringStream);
		meshBuilder->AddVertexNormal(normal);
	}
	// Texture coords
	else if(key == "vt")
	{
		auto texCoords = ParseTexCoords(stringStream);
		meshBuilder->AddVertexTextureCoords(texCoords);
	}
	// Face indices
	else if(key == "f ")
	{
		std::string faceLine;
		std::getline(stringStream, faceLine);
		std::stringstream faceStringStream;
		faceStringStream << faceLine;
		std::vector<std::vector<int>>faceIndices;

		while (!faceStringStream.eof()) {

			auto vertexIndices = ParseVertexIndices(faceStringStream);
			faceIndices.emplace_back(vertexIndices);
		}

		if (faceIndices.size() == 3) {
			int positionIndices[3];
			int normalIndices[3];
			int texCoordIndices[3];

			meshBuilder->AddTriangle(&positionIndices[0], &normalIndices[0], &texCoordIndices[0]);
		}

	}
	// Material name
	else if(key == "usemtl")
	{
		// Not implemented for this exercise.
		LOG(L"usemtl");
	}
	// Material library
	else if(key == "mtllib")
	{
		// Not implemented for this exercise.
		LOG(L"mtllib");
	}
	// Smooting group
	else if(key == "s")
	{
		// Not implemented for this exercise .
		LOG(L"s");
	}
	else
	{
		// Other unimplemeted type.
		LOG(L"other");
	}


	return true;
}

Vector3 OBJLoader::ParsePosition(std::stringstream &stringStream) {
	Vector3 position;

	stringStream >> position.x;
	stringStream >> position.y;
	stringStream >> position.z;

	return position;
}

Vector3 OBJLoader::ParseNormal(std::stringstream &stringStream) {
	Vector3 normal;

	stringStream >> normal.x;
	stringStream >> normal.y;
	stringStream >> normal.z;

	return normal;
}

Vector2 OBJLoader::ParseTexCoords(std::stringstream &stringStream) {
	Vector2 texCoords;

	stringStream >> texCoords.x;
	stringStream >> texCoords.y;

	return texCoords;
}

std::vector<int> OBJLoader::ParseVertexIndices(std::stringstream &stringStream) {
	std::vector<int> indices;
	int positionIndex;
	int normalIndex;
	int texCoordIndex;

	std::string vertex;
	std::string normal;
	std::string texCoord;

	if(getline(stringStream, vertex, '/')) {
		if(vertex.size()) {
			std::stringstream vertexStream;
			vertexStream << vertex;
			vertexStream >> positionIndex;
			positionIndex -= 1; // Because the indices start at 1
		}
	}

	if(getline(stringStream, normal, '/')) {
		if(normal.size()) {
			std::stringstream normalStream;
			normalStream << normal;
			normalStream >> normalIndex;
			normalIndex -= 1; // Because the indices start at 1
		}
	}

	if(getline(stringStream, texCoord, '/')) {
		if(texCoord.size()) {
			std::stringstream texCoordStream;
			texCoordStream << texCoord;
			texCoordStream >> texCoordIndex;
			texCoordIndex -= 1; // Because the indices start at 1
		}
	}

	indices.emplace_back(positionIndex);
	indices.emplace_back(normalIndex);
	indices.emplace_back(texCoordIndex);

	return indices;
}

