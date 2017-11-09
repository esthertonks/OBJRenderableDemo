#include "stdafx.h"
#include "Vector3Test.h"

Vector3Test::Vector3Test()
{
	m_testPositionArray = {
		Vector3(-0.5, -0.5, 0.5),
		Vector3(0.5, -0.5, 0.5),
		Vector3(-0.5, 0.5, 0.5),
		Vector3(0.5, 0.5, 0.5),
		Vector3(-0.5, 0.5, -0.5),
		Vector3(0.5, 0.5, -0.5)
	};

	m_testIndexArray = {
		{1, 2, 3},
		{3, 2, 4},
		{3, 4, 5},
		{5, 4, 6}
	};

	m_testNormalArray = {
		Vector3(0.0, 0.0, 1.0),
		Vector3(0.0, 1.0, 0.0),
		Vector3(0.0, 0.0, -1.0),
		Vector3(0.0, -1.0, 0.0),
		Vector3(1.0, 0.0, 0.0),
		Vector3(-1.0, 0.0, 0.0)
	};
}


Vector3Test::~Vector3Test()
{
}

void Vector3Test::SetUp() {};

void Vector3Test::TearDown() {};

// TODO
TEST_F(Vector3Test, FileLoadSuceedsAndPrimitvesAreQuads) {
	//Vector3 normal;
	//normal.CalculateNormal(primitiveVertex1.m_position, primitiveVertex2.m_position, primitiveVertex3.m_position);
	//normal.Normalise();

}

