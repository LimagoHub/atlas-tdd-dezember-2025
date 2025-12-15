//
// Created by JoachimWagner on 30.12.2023.
//
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace ::testing;

TEST(TestCaseName, TestName) {
    EXPECT_THAT(1,Eq(1));
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}
