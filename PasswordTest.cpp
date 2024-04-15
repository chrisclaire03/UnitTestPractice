/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PracticeTest : public ::testing::Test
{
	protected:
		PracticeTest(){} //constructor runs before each test
		virtual ~PracticeTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, multi_letter_password_1_leading)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Zpassword");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, multi_letter_password_3_leading)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ZZZpassword");
	ASSERT_EQ(3, actual);
}

TEST(PasswordTest, all_repeated_character)
{
	Password my_password;
	int actual = my_password.count_leading_characters("XXXXXXXXXX");
	ASSERT_EQ(10, actual);
}

TEST(PasswordTest, empty_string)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}


TEST(PasswordTest, mixedCaseFalse)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("aaaaaaaaa");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, mixedCaseTrue_middle)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("aaaaaAaaa");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, mixedCaseTrue_end)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("aaaaaA");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, mixedCaseTrue_begin)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("Aaaaa");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, mixedCase_emptyString)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, mixedCase_singleChar)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("Z");
	ASSERT_EQ(false, actual);
}