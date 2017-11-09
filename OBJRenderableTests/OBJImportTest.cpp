// OBJRenderableTests.cpp : Defines the entry point for the console application.
//

#include "OBJImportTest.h"
#include "Mesh.h"

OBJImportTest::OBJImportTest() {
}

OBJImportTest::~OBJImportTest() {};

void OBJImportTest::SetUp() {};

void OBJImportTest::TearDown() {};

TEST_F(OBJImportTest, FileIsSupportedSuceeds) {
	auto filename = "../Assets/cube.obj";
	EXPECT_EQ(m_objLoader.FileIsSupported(filename), true);
}


TEST_F(OBJImportTest, FileIsSupportedFails) {
	auto filename = "../Assets/cube.obj";
	EXPECT_EQ(m_objLoader.FileIsSupported(filename), true);
}

TEST_F(OBJImportTest, FileLoadSuceedsAndPrimitvesAreTriangles) {
	auto cubeFilename = "../Assets/cube.obj";
	auto cubeMesh = m_objLoader.LoadFile(cubeFilename);
	EXPECT_NE(cubeMesh, nullptr);

	auto primitiveCommandList = cubeMesh->GetPrimitiveCommandList();

	auto primitiveCommand = primitiveCommandList.at(0);
	EXPECT_EQ(primitiveCommand.GetOffset(), 0);
	EXPECT_EQ(primitiveCommand.GetType(), PrimitiveType::Triangle);

	primitiveCommand = primitiveCommandList.at(3);
	EXPECT_EQ(primitiveCommand.GetOffset(), 9);
	EXPECT_EQ(primitiveCommand.GetType(), PrimitiveType::Triangle);
}

TEST_F(OBJImportTest, CubeWithNormalGenerationEqualsCubeWithSavedNormals) {

	auto normallessCubeFilename = "../Assets/normallessCube.obj";
	auto normallessCubeMesh = m_objLoader.LoadFile(normallessCubeFilename);
	EXPECT_NE(normallessCubeMesh, nullptr);

	auto cubeFilename = "../Assets/cube.obj";
	auto cubeMesh = m_objLoader.LoadFile(cubeFilename);
	EXPECT_NE(cubeMesh, nullptr);

	auto vertexBufferWithSavedNormals = cubeMesh->GetVertexBuffer();
	auto vertexBufferWithGeneratedNormals = normallessCubeMesh->GetVertexBuffer();

	ASSERT_EQ(vertexBufferWithSavedNormals.size(), vertexBufferWithGeneratedNormals.size());
	for (int vertexIndex = 0; vertexIndex < vertexBufferWithSavedNormals.size(); vertexIndex++) {
		EXPECT_EQ(vertexBufferWithSavedNormals.at(vertexIndex).m_normal, vertexBufferWithGeneratedNormals.at(vertexIndex).m_normal);
	}
}

TEST_F(OBJImportTest, DegenerateMeshFails) {
	auto filename = "../Assets/degenerateCube.obj";

	auto mesh = m_objLoader.LoadFile(filename);
	EXPECT_NE(mesh, nullptr);
}

TEST_F(OBJImportTest, FileLoadSuceedsAndMeshIsConsistent) {
	auto cubeFilename = "../Assets/cube.obj";
	auto cubeMesh = m_objLoader.LoadFile(cubeFilename);
	EXPECT_NE(cubeMesh, nullptr);

	// A cube will have 36 indices (12 triangles * 3 indices per triangle) to 24 vertexs (4 * 6) due to requiring normals at right angles on each edge.

	auto vertexBuffer = cubeMesh->GetVertexBuffer();
	EXPECT_EQ(vertexBuffer.size(), 24);


	auto indexBuffer = cubeMesh->GetIndexBuffer();
	EXPECT_EQ(indexBuffer.size(), 36);

	// Check the consistency of some of the triangles
	EXPECT_EQ(indexBuffer.at(0), 0);
	EXPECT_EQ(indexBuffer.at(1), 1);
	EXPECT_EQ(indexBuffer.at(2), 2);

	EXPECT_EQ(indexBuffer.at(3), 2);
	EXPECT_EQ(indexBuffer.at(4), 1);
	EXPECT_EQ(indexBuffer.at(5), 3);

	EXPECT_EQ(indexBuffer.at(21), 14);
	EXPECT_EQ(indexBuffer.at(22), 13);
	EXPECT_EQ(indexBuffer.at(23), 15);

	EXPECT_EQ(indexBuffer.at(24), 16);
	EXPECT_EQ(indexBuffer.at(25), 17);
	EXPECT_EQ(indexBuffer.at(26), 18);

	auto primitiveCommandList = cubeMesh->GetPrimitiveCommandList();
	EXPECT_EQ(primitiveCommandList.size(), 12); // A cube will have 12 tirangles.
}




