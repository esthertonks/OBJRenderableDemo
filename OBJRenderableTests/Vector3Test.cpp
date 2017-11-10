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
		Vector3(0.5, 0.5, -0.5),
		Vector3(-41.992184f, -69.220261f, 75.606506f),
		Vector3(-43.417240f, -61.621849f, 86.381332f),
		Vector3(-54.0039027f, -60.235451f, 76.199074f),
		Vector3(-50.1543f, -66.220131f, 70.693176f)
	};
}

Vector3Test::~Vector3Test()
{
}

void Vector3Test::SetUp() {};

void Vector3Test::TearDown() {};

TEST_F(Vector3Test, VectorEqualsSucceeds) {
	Vector3 testVector(-0.578045f, 109.689575f, 112.22123f);

	EXPECT_EQ(testVector == testVector, true);
}

TEST_F(Vector3Test, DotProductIsCorrect) {
	float dotProduct = m_testPositionArray[0].DotProduct(m_testPositionArray[1]);

	EXPECT_EQ(dotProduct, 0.25f);

	dotProduct = m_testPositionArray[6].DotProduct(m_testPositionArray[7]);

	EXPECT_EQ(dotProduct, 12619.655898081f);
}

TEST_F(Vector3Test, CrossProductIsCorrect) {
	Vector3 vector;
	vector.CrossProduct(m_testPositionArray[2], m_testPositionArray[3]);

	EXPECT_EQ(vector, Vector3(0.0f, 0.5f, -0.5f));

	Vector3 vector2;
	vector2.CrossProduct(m_testPositionArray[8], m_testPositionArray[9]);

	EXPECT_EQ(vector2, Vector3(787.67732338f, -4.00381886f, 555.07863122f));
}

TEST_F(Vector3Test, VectorLengthIsCorrect) {
	
	float length = m_testPositionArray[0].Length();
	EXPECT_EQ(length, 0.8660254f);
}

TEST_F(Vector3Test, CalculateNormalIsCorrect) {
	Vector3 normal;
	normal.CalculateNormal(m_testPositionArray[0], m_testPositionArray[1], m_testPositionArray[2]);

	EXPECT_EQ(normal == Vector3(0.0f, 0.0f, 1.0f), true);
	normal.Normalise();
	EXPECT_EQ(normal == Vector3(0.0f, 0.0f, 1.0f), true);

	Vector3 normal2;
	normal2.CalculateNormal(m_testPositionArray[6], m_testPositionArray[7], m_testPositionArray[8]);

	EXPECT_EQ(normal2, Vector3(-92.3071899f, -128.579742f, 78.4661255f));

	normal2.Normalise();

	EXPECT_EQ(normal2, Vector3(-0.522500336f, -0.727819324f, 0.444153666f));

	float normailsedLength = normal2.Length();
	EXPECT_EQ(normailsedLength, 1.0f);
}

TEST_F(Vector3Test, InvalidNormalizeFails) {
	Vector3 normal(0.0f, 0.0f, 0.0f);

	normal.Normalise();
	EXPECT_EQ(normal.Normalise(), false);
}


