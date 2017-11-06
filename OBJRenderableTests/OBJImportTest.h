#pragma once

#include "gtest/gtest.h"
#include "OBJLoader.h"
#pragma comment(lib, "../Debug/OBJRenderableDemo.lib")

class OBJImportTest : public ::testing::Test {

protected:

	OBJImportTest();

	virtual ~OBJImportTest();

	virtual void SetUp();

	virtual void TearDown();

	OBJLoader objLoader;
};