#include <gtest/gtest.h>
#include "Six.h"

// ===== Конструкторы =====

TEST(SixConstructor, Default) {
    Six s;
    EXPECT_EQ(s.get_length(), 1);
    EXPECT_EQ(s.get_value()[0], 0);
}

TEST(SixConstructor, DigitConstructor) {
    Six s(3, 2);
    EXPECT_EQ(s.get_length(), 3);
    EXPECT_EQ(s.get_value()[0], 2);
    EXPECT_EQ(s.get_value()[1], 2);
    EXPECT_EQ(s.get_value()[2], 2);
}

TEST(SixConstructor, DigitConstructorInvalidArguments) {
    EXPECT_THROW(Six s(0, 3), std::invalid_argument);
    EXPECT_THROW(Six s(2, 6), std::invalid_argument);
    EXPECT_THROW(Six s(5, 'f'), std::invalid_argument);
}

TEST(SixConstructor, DigitConstructorValidArguments) {
    EXPECT_NO_THROW(Six s(1, 0));
    EXPECT_NO_THROW(Six s(5, 5));
    EXPECT_NO_THROW(Six s(10, 3));
}

TEST(SixConstructor, InitializerList) {
    Six s1({0,0,1,2,3});
    EXPECT_EQ(s1.get_length(), 3);
    const unsigned char* v1 = s1.get_value();
    EXPECT_EQ(v1[0], 3);
    EXPECT_EQ(v1[1], 2);
    EXPECT_EQ(v1[2], 1);

    Six s2({0,0,0,0});
    EXPECT_EQ(s2.get_length(), 1);
    const unsigned char* v2 = s2.get_value();
    EXPECT_EQ(v2[0], 0);

    Six s3({0});
    EXPECT_EQ(s3.get_length(), 1);
    const unsigned char* v3 = s3.get_value();
    EXPECT_EQ(v3[0], 0);
}

TEST(SixConstructor, InitializerListInvalidArguments) {
    EXPECT_THROW(Six s3({1,4,6}), std::invalid_argument);
    EXPECT_THROW(Six s4({1,7,2}), std::invalid_argument);
    EXPECT_THROW(Six s5({8,1,2}), std::invalid_argument);
}

TEST(SixConstructor, InitializerListValidArguments) {
    EXPECT_NO_THROW(Six s({0,1,2,3,4,5}));
    EXPECT_NO_THROW(Six s({5,4,3,2,1,0}));
    EXPECT_NO_THROW(Six s({0,0,0,1}));
}

TEST(SixConstructor, StringConstructor) {
    Six s("0045");
    EXPECT_EQ(s.get_length(), 2);
    const unsigned char* v = s.get_value();
    EXPECT_EQ(v[0], 5);
    EXPECT_EQ(v[1], 4);
}

TEST(SixConstructor, StringConstructorInvalidArguments) {
    EXPECT_THROW(Six s(""), std::invalid_argument);
    EXPECT_THROW(Six s("1236"), std::invalid_argument);
    EXPECT_THROW(Six s("17a"), std::invalid_argument);
    EXPECT_THROW(Six s("89"), std::invalid_argument);
    EXPECT_THROW(Six s("12-3"), std::invalid_argument);
}

TEST(SixConstructor, StringConstructorValidArguments) {
    EXPECT_NO_THROW(Six s("0"));
    EXPECT_NO_THROW(Six s("000"));
    EXPECT_NO_THROW(Six s("12345"));
}

TEST(SixCopyMove, CopyConstructor) {
    Six s1(2, 3);
    Six s2(s1);
    EXPECT_TRUE(s1.equal(s2));
}

TEST(SixCopyMove, MoveConstructor) {
    Six s1(2, 4);
    Six s2(std::move(s1));
    EXPECT_EQ(s2.get_length(), 2);
    EXPECT_EQ(s2.get_value()[0], 4);
}


// ===== Арифметика =====


// Сумма
TEST(SixArithmetic, SimpleSum) {
    Six s1({2,3,4}); 
    Six s2({1,1,1});
    Six result = s1.sum(s2);
    const unsigned char* v = result.get_value();
    EXPECT_EQ(result.get_length(), 3);
    EXPECT_EQ(v[0], 5); 
    EXPECT_EQ(v[1], 4);
    EXPECT_EQ(v[2], 3);
}

TEST(SixArithmetic, SumWithZero) {
    Six s1({1,2,3});
    Six s2({0});
    Six result = s1.sum(s2);
    const unsigned char* v = result.get_value();
    EXPECT_EQ(result.get_length(), 3);
    EXPECT_EQ(v[0], 3);
    EXPECT_EQ(v[1], 2);
    EXPECT_EQ(v[2], 1);
}

TEST(SixArithmetic, HardcoreSum1) {
    Six s1({2,3,4}); 
    Six s2({4,3,2,1});
    Six result = s1.sum(s2);
    const unsigned char* v = result.get_value();
    EXPECT_EQ(result.get_length(), 4);
    EXPECT_EQ(v[0], 5); // младший разряд
    EXPECT_EQ(v[1], 5);
    EXPECT_EQ(v[2], 5); 
    EXPECT_EQ(v[3], 4);// старший разряд
}

TEST(SixArithmetic, HardcoreSum2) {
    Six s1({5,5,5,5}); 
    Six s2({5,5});
    Six result = s1.sum(s2);
    const unsigned char* v = result.get_value();
    EXPECT_EQ(result.get_length(), 5);
    EXPECT_EQ(v[0], 4); // младший разряд
    EXPECT_EQ(v[1], 5);
    EXPECT_EQ(v[2], 0); 
    EXPECT_EQ(v[3], 0);
    EXPECT_EQ(v[4], 1);// старший разряд
}

// Разность
TEST(SixArithmetic, SimpleDifference) {
    Six s1({2,3,1});
    Six s2({1,1,0});
    Six result = s1.difference(s2);
    const unsigned char* v = result.get_value();
    EXPECT_EQ(result.get_length(), 3);
    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(v[1], 2);
    EXPECT_EQ(v[2], 1);
}

TEST(SixArithmetic, HardcoreDifference) {
    Six s1({1,0,0,0});
    Six s2({4,4});
    Six result = s1.difference(s2);
    const unsigned char* v = result.get_value();
    EXPECT_EQ(result.get_length(), 3);
    EXPECT_EQ(v[0], 2);
    EXPECT_EQ(v[1], 1);
    EXPECT_EQ(v[2], 5);
}

TEST(SixArithmetic, DifferenceWithZero) {
    Six s1({1,2,3});
    Six s2({0});
    Six result = s1.difference(s2);
    const unsigned char* v = result.get_value();
    EXPECT_EQ(result.get_length(), 3);
    EXPECT_EQ(v[0], 3);
    EXPECT_EQ(v[1], 2);
    EXPECT_EQ(v[2], 1);
}

TEST(SixArithmetic, ZeroDifference) {
    Six s1({0});
    Six s2({0});
    Six result = s1.difference(s2);
    const unsigned char* v = result.get_value();
    EXPECT_EQ(v[0], 0);
    EXPECT_EQ(result.get_length(), 1);
}

TEST(SixArithmetic, DifferenceInvalidArgument) {
    Six s1({5,5});
    Six s2({5,5,5,5});
    EXPECT_THROW(s1.difference(s2), std::invalid_argument);
}

// ===== Сравнение =====
TEST(SixComparison, Greater) {
    Six s1({1,2});
    Six s2({0,5});
    EXPECT_TRUE(s1.greater(s2));
    EXPECT_FALSE(s2.greater(s1));
}

TEST(SixComparison, GreaterMixedInitialization) {
    Six s1({1,2,3});
    Six s2("123");
    EXPECT_FALSE(s1.greater(s2));
    EXPECT_FALSE(s2.greater(s1));
}

TEST(SixComparison, GreaterDigitAndInitializerList) {
    Six s1(3, 4);
    Six s2({4,4,3});
    EXPECT_TRUE(s1.greater(s2));
    EXPECT_FALSE(s2.greater(s1));
}

TEST(SixComparison, GreaterStringAndDigit) {
    Six s1("1234");
    Six s2(4, 2);
    EXPECT_FALSE(s1.greater(s2));
    EXPECT_TRUE(s2.greater(s1));
}

TEST(SixComparison, GreaterWithZeroMixed) {
    Six s1({1,2});
    Six s2("0");
    EXPECT_TRUE(s1.greater(s2));
    EXPECT_FALSE(s2.greater(s1));
}

TEST(SixComparison, GreaterDefaultAndString) {
    Six s1;
    Six s2("0");
    EXPECT_FALSE(s1.greater(s2));
    EXPECT_FALSE(s2.greater(s1));
}

TEST(SixComparison, Equal) {
    Six s1;
    Six s2("0");
    EXPECT_TRUE(s1.equal(s2));
}


// ===== Копирование =====
TEST(SixCopyMethod, CopyNunmber) {
    Six s1({1,2,3});
    Six s2 = s1.copy();
    EXPECT_TRUE(s1.equal(s2));
}

TEST(SixCopyMethod, ZeroCopy) {
    Six s1("0");
    Six s2 = s1.copy();
    EXPECT_TRUE(s1.equal(s2));
}



