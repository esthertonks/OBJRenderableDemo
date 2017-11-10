#include "stdafx.h"
#include "OBJLoader.h"
#include "Mesh.h"
#include "StringUtils.h"
#include "Vector3.h"
#include "Vector2.h"
#include "MeshBuilder.h"

#include <fstream>

OBJLoader::OBJLoader() : m_meshBuilder(nullptr)
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

	m_meshBuilder = std::unique_ptr<MeshBuilder>(new MeshBuilder());

	std::ifstream fileStream;

	fileStream = std::ifstream(filename.c_str(), std::ios_base::in);

	if (!fileStream.is_open() || !fileStream.good())
	{
		return false;
	}


	while (fileStream && !fileStream.eof())
	{
		ReadLine(fileStream);
	}

	return m_meshBuilder->GetCompleteMesh();
}

bool OBJLoader::ReadLine(std::ifstream &fileStream)
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
		m_meshBuilder->AddVertexPosition(position);
	}
	// Vertex normal
	else if(key == "vn")
	{
		auto normal = ParseNormal(stringStream);
		m_meshBuilder->AddVertexNormal(normal);
	}
	// Texture coords
	else if(key == "vt")
	{
		auto texCoords = ParseTexCoords(stringStream);
		m_meshBuilder->AddVertexTextureCoords(texCoords);
	}
	// Face indices
	else if(key == "f")
	{
		std::string faceLine;
		std::getline(stringStream, faceLine);

		// remove spaces from right hand side of data otherwise eof will not be called after data read.
		StringUtils::TrimRight(faceLine);

		std::stringstream faceStringStream;
		faceStringStream << faceLine;

		std::vector<std::array<int, 3>>faceIndices;

		while (!faceStringStream.eof()) {

			auto vertexIndices = ParseVertexIndices(faceStringStream);
			faceIndices.emplace_back(vertexIndices);
		}

		if (faceIndices.size() == 3) {

			AddTriangleData(faceIndices);
		}
		else if (faceIndices.size() == 4) {

			AddQuadData(faceIndices);
		}

	}
	// Material name
	else if(key == "usemtl")
	{
		// Load the material name. Not implemented for this exercise.
	}
	// Material library
	else if(key == "mtllib")
	{
		// Load the material library. Not implemented for this exercise.
	}
	// Smoothing group
	else if(key == "s")
	{
		// Not implemented for this exercise .
	}
	else
	{
		// Other unimplemeted type.
	}


	return true;
}

void OBJLoader::AddTriangleData(std::vector<std::array<int, 3>> &faceIndices) {
	std::array<int, 3> positionIndices;
	std::array<int, 3> normalIndices;
	std::array<int, 3> texCoordIndices;

	int index = 0;
	for (auto &indices : faceIndices) {
		positionIndices[index] = indices[0];
		texCoordIndices[index] = indices[1];
		normalIndices[index] = indices[2];
		index++;
	}

	m_meshBuilder->AddTriangle(positionIndices, texCoordIndices, normalIndices);
}

void OBJLoader::AddQuadData(std::vector<std::array<int, 3>> &faceIndices) {
	std::array<int, 4> positionIndices;
	std::array<int, 4> normalIndices;
	std::array<int, 4> texCoordIndices;

	int index = 0;
	for (auto &indices : faceIndices) {
		positionIndices[index] = indices[0];
		texCoordIndices[index] = indices[1];
		normalIndices[index] = indices[2];
		index++;
	}

	m_meshBuilder->AddQuad(positionIndices, texCoordIndices, normalIndices);
}

Vector3 OBJLoader::ParsePosition(std::stringstream &stringStream) {
	Vector3 position;

	stringStream >> position.m_x;
	stringStream >> position.m_y;
	stringStream >> position.m_z;

	return position;
}

Vector3 OBJLoader::ParseNormal(std::stringstream &stringStream) {
	Vector3 normal;

	stringStream >> normal.m_x;
	stringStream >> normal.m_y;
	stringStream >> normal.m_z;

	return normal;
}

Vector2 OBJLoader::ParseTexCoords(std::stringstream &stringStream) {
	Vector2 texCoords;

	stringStream >> texCoords.m_x;
	stringStream >> texCoords.m_y;

	return texCoords;
}

std::array<int, 3> OBJLoader::ParseVertexIndices(std::stringstream &stringStream) {
	std::array<int, 3> indices = { 0, 0, 0 };
	auto positionIndex = 0;
	auto normalIndex = 0;
	auto texCoordIndex = 0;

	stringStream >> positionIndex;
	positionIndex -= 1; // Because the indices start at 1
	indices[0] = positionIndex;

	if ('/' == stringStream.peek()){
		stringStream.ignore();

		if ('/' != stringStream.peek()) {
			stringStream >> texCoordIndex;
			texCoordIndex -= 1; // Because the indices start at 1
			indices[1] = texCoordIndex;
		}

		if ('/' == stringStream.peek()) {
			stringStream.ignore();

			stringStream >> normalIndex;
			normalIndex -= 1; // Because the indices start at 1
			indices[2] = normalIndex;
		}
	}




	return indices;
}

