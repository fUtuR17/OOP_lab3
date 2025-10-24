#include <gtest/gtest.h>
#include "Square.h"
#include "Octagon.h"
#include "Triangle.h"
#include "FigureArray.h"

TEST(FigureTest, SquareArea) {
    Square sqr(0, 0, 1);
    EXPECT_NEAR(sqr.area(), 2, 0.001);
}

TEST(FigureTest, OctagonArea) {
    Octagon oct(0, 0, 1);
    EXPECT_NEAR(oct.area(), 4.828, 0.001);
}

TEST(FigureTest, TriangleArea) {
    Triangle tri(0, 0, 1);
    EXPECT_NEAR(tri.area(), 1.299, 0.001);
}

TEST(FigureTest, FigureComparison) {
    Square tri1(0, 0, 1);
    Square tri2(0, 0, 1);
    Square tri3(1, 1, 2);
    
    EXPECT_TRUE(tri1 == tri2);
    EXPECT_FALSE(tri1 == tri3);
}

TEST(FigureArrayTest, AddAndRemove) {
    FigureArray array;
    array.addSquare(0, 0, 1);
    array.addTriangle(1, 1, 2);
    
    EXPECT_EQ(array.size(), 2);
    
    array.removeFigure(0);
    EXPECT_EQ(array.size(), 1);
}

TEST(FigureArrayTest, TotalArea) {
    FigureArray array;
    array.addSquare(0, 0, 1);
    array.addTriangle(0, 0, 1);
    
    double total = array.totalArea();
    EXPECT_GT(total, 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}