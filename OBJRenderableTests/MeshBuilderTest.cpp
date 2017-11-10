#include "stdafx.h"
#include "MeshBuilderTest.h"
#include "MeshBuilder.h"
#include "Vector3.h"
#include "Mesh.h"

MeshBuilderTest::MeshBuilderTest()
{
	m_testPositionArray = {
		Vector3(-41.992184f, -69.220261f, 75.606506f),
		Vector3(-43.417240f, -61.621849f, 86.381332f),
		Vector3(-54.0039027f, -60.235451f, 76.199074f),
		Vector3(-50.1543f, -66.220131f, 70.693176f),

		Vector3(-54.0039024f, -60.2354507f, 76.1990738f),
		Vector3(-43.4172401f, -61.6218491f, 86.3813324f),
		Vector3(-46.1389732f, -52.1872177f, 94.3361282f),
		Vector3(-58.1491585f, -51.0876007f, 82.2786102f),

		Vector3(-46.1389732f, -52.1872177f, 94.3361282f),
		Vector3(-43.4172401f, -61.6218491f, 86.3813324f),
		Vector3(-30.4940624f, -63.7362518f, 93.3937225f),
		Vector3(-32.0030632f, -53.6164703f, 102.896698f)
	};

	m_testQuadIndexArray = {
		{0, 1, 2, 3},
		{4, 5, 6, 7},
		{8, 9, 10, 11}
	};
}


MeshBuilderTest::~MeshBuilderTest()
{
}

void MeshBuilderTest::SetUp() {
	m_meshBuilder.AddVertexPosition(m_testPositionArray[0]);
	m_meshBuilder.AddVertexPosition(m_testPositionArray[1]);
	m_meshBuilder.AddVertexPosition(m_testPositionArray[2]);
	m_meshBuilder.AddVertexPosition(m_testPositionArray[3]);

	m_meshBuilder.AddVertexPosition(m_testPositionArray[4]);
	m_meshBuilder.AddVertexPosition(m_testPositionArray[5]);
	m_meshBuilder.AddVertexPosition(m_testPositionArray[6]);
	m_meshBuilder.AddVertexPosition(m_testPositionArray[7]);

	m_meshBuilder.AddVertexPosition(m_testPositionArray[8]);
	m_meshBuilder.AddVertexPosition(m_testPositionArray[9]);
	m_meshBuilder.AddVertexPosition(m_testPositionArray[10]);
	m_meshBuilder.AddVertexPosition(m_testPositionArray[11]);

	m_dummyTexIndices[0] = 0;
	m_dummyTexIndices[1] = 0;
	m_dummyTexIndices[2] = 0;
	m_dummyTexIndices[3] = 0;

	m_dummyNormalIndices[0] = 0;
	m_dummyNormalIndices[1] = 0;
	m_dummyNormalIndices[2] = 0;
	m_dummyNormalIndices[3] = 0;

	m_meshBuilder.AddQuad(m_testQuadIndexArray[0], m_dummyTexIndices, m_dummyNormalIndices);
	m_meshBuilder.AddQuad(m_testQuadIndexArray[1], m_dummyTexIndices, m_dummyNormalIndices);
	m_meshBuilder.AddQuad(m_testQuadIndexArray[2], m_dummyTexIndices, m_dummyNormalIndices);

};

void MeshBuilderTest::TearDown() {};

TEST_F(MeshBuilderTest, FileLoadSuceedsAndPrimitvesAreQuads) {

	auto primitiveCommandList = m_meshBuilder.GetCompleteMesh()->GetPrimitiveCommandList();

	auto primitiveCommand = primitiveCommandList.at(0);
	EXPECT_EQ(primitiveCommand.GetOffset(), 0);
	EXPECT_EQ(primitiveCommand.GetType(), PrimitiveType::Quad);
}

TEST_F(MeshBuilderTest, MeshBuildWithNormalGenerationSucceeds) {

	Vector3 vertexNormal1(-0.522500336f, -0.727819324f, 0.444153666f);

	auto vertexBuffer = m_meshBuilder.GetCompleteMesh()->GetVertexBuffer();
	auto indexBuffer = m_meshBuilder.GetCompleteMesh()->GetIndexBuffer();

	auto primitiveVertex1 = vertexBuffer.at(indexBuffer.at(0));
	auto primitiveVertex2 = vertexBuffer.at(indexBuffer.at(1));
	auto primitiveVertex3 = vertexBuffer.at(indexBuffer.at(2));

	EXPECT_GE(vertexNormal1.DotProduct(primitiveVertex1.m_normal), 0.99999);
	EXPECT_GE(vertexNormal1.DotProduct(primitiveVertex2.m_normal), 0.99999);
	EXPECT_GE(vertexNormal1.DotProduct(primitiveVertex3.m_normal), 0.99999);
}
