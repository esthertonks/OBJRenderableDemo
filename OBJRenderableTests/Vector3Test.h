#pragma once

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Vector3.h"

class Vector3Test : public ::testing::Test {

protected:

	Vector3Test();
	virtual ~Vector3Test();

	virtual void SetUp();
	virtual void TearDown();

	std::vector<Vector3> m_testPositionArray;
	std::vector<std::array<int, 3>> m_testIndexArray;
	std::vector<Vector3> m_testNormalArray;
};

