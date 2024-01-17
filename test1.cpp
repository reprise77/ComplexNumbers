#include <gtest/gtest.h>
#include "Complex.h"

TEST(ComplexTest, DefaultConstructor) {
    Complex<double> c;
    EXPECT_EQ(c.getReal(), 0);
    EXPECT_EQ(c.getImag(), 0);
}

TEST(ComplexTest, ParameterizedConstructor) {
    Complex<double> c(3.0, 5.0);
    EXPECT_EQ(c.getReal(), 3.0);
    EXPECT_EQ(c.getImag(), 5.0);
}

TEST(ComplexTest, Addition) {
    Complex<double> c1(2.0, 3.0);
    Complex<double> c2(4.0, 5.0);
    Complex<double> result = c1 + c2;
    EXPECT_EQ(result, Complex<double>(6.0, 8.0));
}

TEST(ComplexTest, Subtraction) {
    Complex<double> c1(6.0, 7.0);
    Complex<double> c2(2.0, 3.0);
    Complex<double> result = c1 - c2;
    EXPECT_EQ(result, Complex<double>(4.0, 4.0));
}

TEST(ComplexTest, Multiplication) {
    Complex<double> c1(2.0, 3.0);
    Complex<double> c2(4.0, 5.0);
    Complex<double> result = c1 * c2;
    EXPECT_EQ(result, Complex<double>(-7.0, 22.0));
}

TEST(ComplexTest, Division) {
    Complex<double> c1(6.0, 8.0);
    Complex<double> c2(2.0, 2.0);
    Complex<double> result = c1 / c2;
    EXPECT_FLOAT_EQ(result.getReal(), 3.5);
    EXPECT_FLOAT_EQ(result.getImag(), 0.5);
}

TEST(ComplexTest, Equality) {
    Complex<double> c1(2.0, 3.0);
    Complex<double> c2(2.0, 3.0);
    EXPECT_EQ(c1, c2);
}

TEST(ComplexTest, Power) {
    Complex<double> c(2.0, 3.0);
    Complex<double> result = c.pow(2);
    EXPECT_FLOAT_EQ(result.getReal(), -5.0);
    EXPECT_FLOAT_EQ(result.getImag(), 12.0);
}

TEST(ComplexTest, AbsoluteValue) {
    Complex<double> c(3.0, 4.0);
    EXPECT_EQ(c.abs(), 5.0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
