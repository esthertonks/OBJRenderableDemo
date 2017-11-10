#pragma once

#include "gtest/gtest.h"
#include "MeshBuilder.h"

class MeshBuilderTest : public ::testing::Test {

protected:

	MeshBuilderTest();
	virtual ~MeshBuilderTest();

	virtual void SetUp();
	virtual void TearDown();

	std::vector<Vector3> m_testPositionArray;
	std::vector<std::array<int, 4>> m_testQuadIndexArray;
	MeshBuilder m_meshBuilder;
	std::array<int, 4> m_dummyTexIndices;
	std::array<int, 4> m_dummyNormalIndices;
};

