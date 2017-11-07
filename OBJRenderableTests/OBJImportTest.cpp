// OBJRenderableTests.cpp : Defines the entry point for the console application.
//

#include "OBJImportTest.h"
#include "Mesh.h"

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

TEST_F(OBJImportTest, FileIsSupportedSuceeds) {
	auto filename = "Resources/cube.obj";
	EXPECT_EQ(objLoader.FileIsSupported(filename), true);
}


TEST_F(OBJImportTest, FileIsSupportedFails) {
	auto filename = "Resources/cube.obj";
	EXPECT_EQ(objLoader.FileIsSupported(filename), true);
}

TEST_F(OBJImportTest, FileLoadSuceeds) {
	auto filename = "Resources/cube.obj";

	std::shared_ptr<Mesh> mesh = objLoader.LoadFile(filename);
	EXPECT_NE(mesh, nullptr);

	VertexBuffer vertexBuffer = mesh->GetVertexBuffer();
	IndexBuffer indexBuffer = mesh->GetIndexBuffer();
	PrimitiveCommandList primitiveCommandList = mesh->GetPrimitiveCommandList();

}




