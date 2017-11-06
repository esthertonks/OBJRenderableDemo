#include "stdafx.h"
#include "OBJLoader.h"
#include "Mesh.h"
#include "StringUtils.h"

OBJLoader::OBJLoader()
{
}


OBJLoader::~OBJLoader()
{
}

bool OBJLoader::FileIsSupported(std::string filename)
{
	std::string extension = StringUtils::GetFileExtension(filename);
	std::string lowercaseExtension = StringUtils::ToLower(extension);
	if (extension.compare("obj") == 0) {
		return true;
	}

	return false;
}

bool OBJLoader::LoadFile(std::string filename)
{

	return false;
}

bool OBJLoader::ExtractObjFromFile()
{

	return false;
}

