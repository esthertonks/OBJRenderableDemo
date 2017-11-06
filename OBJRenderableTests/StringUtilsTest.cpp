#include "stdafx.h"
#include "StringUtilsTest.h"
#include "gtest/gtest.h"
#include "StringUtils.h"

TEST(StringUtilsTest, GetFileExtensionReturnsExpectedExtension) {
	std::string testFilename = "Test.obj";

	EXPECT_EQ(StringUtils::GetFileExtension(testFilename), "obj");
}

TEST(StringUtilsTest, ToLowerReturnsLowercase) {
	std::string testFilename = "Test.OBJ";

	EXPECT_EQ(StringUtils::ToLower(testFilename), "test.obj");
}

TEST(StringUtilsTest, GetFileExtensionReturnsEmptyStringOnFailure) {
	std::string testFilename = "TestOBJ";

	EXPECT_EQ(StringUtils::GetFileExtension(testFilename), "");
}
