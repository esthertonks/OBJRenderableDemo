#pragma once

#include "stdafx.h"

class OBJLoader
{
public:
	OBJ_DEMO_EXPORT OBJLoader();
	OBJ_DEMO_EXPORT ~OBJLoader();

	OBJ_DEMO_EXPORT bool LoadFile(std::string filename);
	OBJ_DEMO_EXPORT bool ExtractObjFromFile();
};



