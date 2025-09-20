#include <gtest/gtest.h>
#include "number_speller.h"

TEST(Spelling, Zero) {
    EXPECT_EQ(spell_number(0), "sifir");
}

TEST(Spelling, OutOfRange) {
    EXPECT_EQ(spell_number(114), "Число должно быть от 0 до 99");
}

TEST(Spelling, Thirty) {
    EXPECT_EQ(spell_number(30), "otuz");
}

TEST(Spelling, NinetyNine) {
    EXPECT_EQ(spell_number(99), "doksan dokuz");
}

TEST(Spelling, SeventyFour) {
    EXPECT_EQ(spell_number(74), "yetmiş dört");
}
