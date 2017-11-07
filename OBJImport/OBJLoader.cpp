#include "stdafx.h"
#include "OBJLoader.h"
#include "Mesh.h"
#include "StringUtils.h"
#include "Vector3.h"
#include "Vector2.h"

#include <fstream>
#include <sstream>

#ifdef _DEBUG
#define LOG(str)    OutputDebugStringW(str)
#else
#define LOG(str)    (void)(str)
#endif

OBJLoader::OBJLoader()
{
	positionList = std::unique_ptr<std::vector<Vector3>>(new std::vector<Vector3>());
	normalList = std::unique_ptr<std::vector<Vector3>>(new std::vector<Vector3>());
	texCoordList = std::unique_ptr<std::vector<Vector3>>(new std::vector<Vector3>());
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

	std::ifstream fileStream;

	ReadFile(filename, fileStream);

	std::shared_ptr<Mesh> mesh;

	ReadOBJ(fileStream, mesh);


	return mesh;
}

bool OBJLoader::ReadFile(const std::string &filename, std::ifstream &fileStream)
{
	fileStream = std::ifstream(filename.c_str(), std::ios_base::in);

	if (!fileStream.is_open() || !fileStream.good())
	{
		return false;
	}

	return true;
}

bool OBJLoader::ReadOBJ(std::ifstream &fileStream, std::shared_ptr<Mesh> mesh) {
	std::string line;

	while (fileStream && !fileStream.eof())
	{
		std::getline(fileStream, line);
		if(fileStream.bad()) {
			return false;
		}

		std::stringstream stringStream;
		std::string key;

		// Skip empty lines and comments.
		if(line.size() == 0 || line[0] == '#' || line[0] == '$')
		{
			continue;
		}

		stringStream.str(line);
		stringStream >> key;

		// Vertex
		if (key == "v")
		{
			ReadVertexPosition(stringStream);
		}
		// Vertex normal
		else if(key == "vn")
		{
			ReadVertexNormal(stringStream);
		}
		// Texture coords
		else if(key == "vt")
		{
			ReadVertexTextureCoords(stringStream);
		}
		// Face indices
		else if(key == "f ")
		{
			ReadFaceIndices(stringStream);
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

	}


	return true;
}

bool OBJLoader::ReadVertexPosition(std::stringstream &stringStream)
{
	Vector3 position;

	stringStream >> position.x; 
	stringStream >> position.y;
	stringStream >> position.z;

	positionList->emplace_back(position);

	return true;
}

bool OBJLoader::ReadVertexNormal(std::stringstream &stringStream)
{


	return true;
}

bool OBJLoader::ReadVertexTextureCoords(std::stringstream &stringStream)
{


	return true;
}

bool OBJLoader::ReadFaceIndices(std::stringstream &stringStream)
{


	return true;
}


