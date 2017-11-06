// OBJRenderableTests.cpp : Defines the entry point for the console application.
//

#include "OBJImportTest.h"


//using ::testing::Return;

OBJImportTest::OBJImportTest() {
	// Have qux return true by default
	//ON_CALL(m_bar, qux()).WillByDefault(Return(true));
	// Have norf return false by default
	//ON_CALL(m_bar, norf()).WillByDefault(Return(false));
}

OBJImportTest::~OBJImportTest() {};

void OBJImportTest::SetUp() {};

void OBJImportTest::TearDown() {};

TEST_F(OBJImportTest, FileLoadSuceeds) {
	OBJLoader objLoader;
	std::string filename = "Resources/cube.obj";
	EXPECT_EQ(objLoader.LoadFile(filename), true);
}

TEST_F(OBJImportTest, ImportSuceeds) {
	OBJLoader objLoader;
	std::string filename = "Resources/cube.obj";
	EXPECT_EQ(objLoader.ExtractObjFromFile(), true);
}


