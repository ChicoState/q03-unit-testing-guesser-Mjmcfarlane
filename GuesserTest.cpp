/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

/* Example test
TEST(GuesserTest, smoke_test)
{
    ASSERT_EQ( 1+1, 2 );
}
*/

//TEST THE REMAINING FUNCTION
TEST(GuesserTest, right)
{
	string original = "Hello_World";
	Guesser start = Guesser(original);
	string guess1 = "Hello_World";
	bool correct = start.match(guess1);
	int remain = start.remaining();
    ASSERT_EQ( remain, 3);
}

TEST(GuesserTest, one_wrong)
{
	string original = "Hello_World";
	Guesser start = Guesser(original);
	string guess1 = "Hello World";
	bool correct = start.match(guess1);
	int remain = start.remaining();
    ASSERT_EQ( remain, 2);
}

TEST(GuesserTest, one_wrong_then_right)
{
	string original = "Hello_World";
	Guesser start = Guesser(original);
	string guess1 = "Hello World";
	bool correct = start.match(guess1);
	string guess2 = "Hello_World";
	correct = start.match(guess2);
	int remain = start.remaining();
    ASSERT_EQ( remain, 3);
}

TEST(GuesserTest, two_wrong)
{
	string original = "Hello_World";
	Guesser start = Guesser(original);
	string guess1 = "Hello World";
	bool correct = start.match(guess1);
	string guess2 = "hello world";
	correct = start.match(guess2);
	int remain = start.remaining();
    ASSERT_EQ( remain, 1);
}

TEST(GuesserTest, two_wrong_then_right)
{
	string original = "Hello_World";
	Guesser start = Guesser(original);
	string guess1 = "Hello World";
	bool correct = start.match(guess1);
	string guess2 = "hello_world";
	correct = start.match(guess2);
	string guess3 = "Hello_World";
	correct = start.match(guess3);
	int remain = start.remaining();
    ASSERT_EQ( remain, 3);
}

TEST(GuesserTest, three_wrong)
{
	string original = "Hello_World";
	Guesser start = Guesser(original);
	string guess1 = "Hello World";
	bool correct = start.match(guess1);
	string guess2 = "hello_world";
	correct = start.match(guess2);
	string guess3 = "Hello_world";
	correct = start.match(guess3);
	int remain = start.remaining();
    ASSERT_EQ( remain, 0);
}

TEST(GuesserTest, three_wrong_then_right)
{
	string original = "Hello_World";
	Guesser start = Guesser(original);
	string guess1 = "Hello World";
	bool correct = start.match(guess1);
	string guess2 = "hello_world";
	correct = start.match(guess2);
	string guess3 = "Hello_world";
	correct = start.match(guess3);
	string guess4 = "Hello_World";
	correct = start.match(guess4);
	int remain = start.remaining();
    ASSERT_EQ( remain, 0);
}

TEST(GuesserTest, right_after_brute)
{
	string original = "Hello_World";
	Guesser start = Guesser(original);
	string guess1 = "hello world";
	bool correct = start.match(guess1);
	string guess2 = "Hello_World";
	correct = start.match(guess2);
	int remain = start.remaining();
    ASSERT_EQ( remain, 3);
}

TEST(GuesserTest, empty_password_wrong)
{
	string original = "";
	Guesser start = Guesser(original);
	string guess1 = "hi";
	bool correct = start.match(guess1);
	string guess2 = "ah";
	correct = start.match(guess2);
	string guess3 = "oh";
	correct = start.match(guess3);
	int remain = start.remaining();
    ASSERT_EQ( remain, 3);
}

TEST(GuesserTest, empty_password_right)
{
	string original = "";
	Guesser start = Guesser(original);
	string guess1 = "hi";
	bool correct = start.match(guess1);
	string guess2 = "";
	correct = start.match(guess2);
	int remain = start.remaining();
    ASSERT_EQ( remain, 3);
}

TEST(GuesserTest, brute_then_two_wrong)
{
	string original = "Hello_World";
	Guesser start = Guesser(original);
	string guess1 = "hello world";
	bool correct = start.match(guess1);
	string guess2 = "hello_World";
	correct = start.match(guess2);
	string guess3 = "Hello_world";
	correct = start.match(guess3);
	int remain = start.remaining();
    ASSERT_EQ( remain, 0);
}

TEST(GuesserTest, brute_then_wrong)
{
	string original = "Hello_World";
	Guesser start = Guesser(original);
	string guess1 = "hello world";
	bool correct = start.match(guess1);
	string guess2 = "Hello_world";
	correct = start.match(guess2);
	int remain = start.remaining();
    ASSERT_EQ( remain, 1);
}

TEST(GuesserTest, size_over_32)
{
	string original = "ABCDEFHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	Guesser start = Guesser(original);
	string guess1 = "ABCDEFHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	bool correct = start.match(guess1);
	int remain = start.remaining();
    ASSERT_EQ( remain, 2);
}

TEST(GuesserTest, right_size_over_32)
{
	string original = "ABCDEFHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	Guesser start = Guesser(original);
	string guess1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdef";
	bool correct = start.match(guess1);
	int remain = start.remaining();
    ASSERT_EQ( remain, 2);
}



//Testing the match function

TEST(GuesserTest, immediate_correct)
{
	string original = "Hello_World";
	Guesser start = Guesser(original);
	string guess1 = "Hello_World";
	bool correct = start.match(guess1);
    ASSERT_EQ( correct, true);
}

TEST(GuesserTest, missing_underscore)
{
	string original = "Hello_World";
	Guesser start = Guesser(original);
	string guess1 = "Hello World";
	bool correct = start.match(guess1);
    ASSERT_EQ( correct, false);
}

TEST(GuesserTest, right_after_wrong)
{
	string original = "Hello_World";
	Guesser start = Guesser(original);
	string guess1 = "Hello World";
	bool correct = start.match(guess1);
	string guess2 = "Hello_World";
	correct = start.match(guess2);
    ASSERT_EQ( correct, true);
}

TEST(GuesserTest, no_caps)
{
	string original = "Hello_World";
	Guesser start = Guesser(original);
	string guess1 = "hello_world";
	bool correct = start.match(guess1);
    ASSERT_EQ( correct, false);
}

TEST(GuesserTest, right_after_two_wrong)
{
	string original = "Hello_World";
	Guesser start = Guesser(original);
	string guess1 = "Hello World";
	bool correct = start.match(guess1);
	string guess2 = "hello_world";
	correct = start.match(guess2);
	string guess3 = "Hello_World";
	correct = start.match(guess3);
    ASSERT_EQ( correct, true);
}

TEST(GuesserTest, right_after_three_wrong)
{
	string original = "Hello_World";
	Guesser start = Guesser(original);
	string guess1 = "Hello World";
	bool correct = start.match(guess1);
	string guess2 = "hello_world";
	correct = start.match(guess2);
	string guess3 = "Hello_world";
	correct = start.match(guess3);
	string guess4 = "Hello_World";
	correct = start.match(guess4);
    ASSERT_EQ( correct, false);
}

TEST(GuesserTest, brute_then_right)
{
	string original = "Hello_World";
	Guesser start = Guesser(original);
	string guess1 = "hello world";
	bool correct = start.match(guess1);
	string guess2 = "Hello_World";
	correct = start.match(guess2);
    ASSERT_EQ( correct, false);
}

TEST(GuesserTest, empty_wrong)
{
	string original = "";
	Guesser start = Guesser(original);
	string guess1 = "hi";
	bool correct = start.match(guess1);
    ASSERT_EQ( correct, true);
}

TEST(GuesserTest, empty_right)
{
	string original = "";
	Guesser start = Guesser(original);
	string guess1 = "hi";
	bool correct = start.match(guess1);
	string guess2 = "";
	correct = start.match(guess2);
    ASSERT_EQ( correct, true);
}

TEST(GuesserTest, length_over_32)
{
	string original = "ABCDEFHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	Guesser start = Guesser(original);
	string guess1 = "ABCDEFHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	bool correct = start.match(guess1);
    ASSERT_EQ( correct, false);
}

TEST(GuesserTest, right_to_32)
{
	string original = "ABCDEFHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	Guesser start = Guesser(original);
	string guess1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdef";
	bool correct = start.match(guess1);
    ASSERT_EQ( correct, true);
}

TEST(GuesserTest, right_up_to_32)
{
	string original = "ABCDEFHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	Guesser start = Guesser(original);
	string guess1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefGHIJKLMNOPQRSTUVWXYZ";
	bool correct = start.match(guess1);
    ASSERT_EQ( correct, false);
}

TEST(GuesserTest, exclamation)
{
	string original = "Hello_World";
	Guesser start = Guesser(original);
	string guess1 = "Hello_World!";
	bool correct = start.match(guess1);
    ASSERT_EQ( correct, false);
}