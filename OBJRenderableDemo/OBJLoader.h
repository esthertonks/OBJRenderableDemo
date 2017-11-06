#pragma once

#include "stdafx.h"

#ifdef EXPORT_TEST_FUNCTIONS
#define OBJ_RENDERABLE_DEMO_EXPORT __declspec(dllexport) 
#else
#define OBJ_RENDERABLE_DEMO_EXPORT
#endif


class OBJLoader
{
public:
	OBJ_RENDERABLE_DEMO_EXPORT OBJLoader();
	OBJ_RENDERABLE_DEMO_EXPORT ~OBJLoader();

	OBJ_RENDERABLE_DEMO_EXPORT bool LoadFile(std::string filename);
	OBJ_RENDERABLE_DEMO_EXPORT bool ExtractObjFromFile();
};



