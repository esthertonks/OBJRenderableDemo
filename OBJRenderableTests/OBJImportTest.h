#pragma once

#include "gtest/gtest.h"
#include "OBJLoader.h"

class OBJImportTest : public ::testing::Test {

protected:

	OBJImportTest();
	virtual ~OBJImportTest();

	virtual void SetUp();
	virtual void TearDown();

	OBJLoader m_objLoader;
};