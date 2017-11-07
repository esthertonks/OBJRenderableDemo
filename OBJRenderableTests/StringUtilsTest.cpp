#include "stdafx.h"
#include "StringUtilsTest.h"
#include "gtest/gtest.h"
#include "StringUtils.h"

TEST(StringUtilsTest, GetFileExtensionReturnsExpectedExtension) {
	auto testFilename = "Test.obj";

	EXPECT_EQ(StringUtils::GetFileExtension(testFilename), "obj");
}

TEST(StringUtilsTest, ToLowerReturnsLowercase) {
	auto testFilename = "Test.OBJ";

	EXPECT_EQ(StringUtils::ToLower(testFilename), "test.obj");
}

TEST(StringUtilsTest, GetFileExtensionReturnsEmptyStringOnFailure) {
	auto testFilename = "TestOBJ";

	EXPECT_EQ(StringUtils::GetFileExtension(testFilename), "");
}
