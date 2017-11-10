// OBJRenderableDemo.cpp : Defines the entry point for the application.
//
#include "stdafx.h"

#include "OBJRenderableDemo.h"
#include "OBJLoader.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdline, int iCmdshow)
{
	OBJLoader objLoader;
	//auto filename = "../Assets/cube.obj";
	auto filename = "../Assets/ducky.obj";
	//auto filename = "../Assets/normallessCube.obj";
	objLoader.LoadFile(filename);

	return 0;
}