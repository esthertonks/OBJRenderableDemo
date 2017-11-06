#pragma once

#include "stdafx.h"

class OBJLoader
{
public:
	OBJLoader();
	 ~OBJLoader();

	bool FileIsSupported(std::string filename);
	bool LoadFile(std::string filename);
	bool ExtractObjFromFile();
};



