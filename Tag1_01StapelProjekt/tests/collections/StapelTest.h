//
// Created by JoachimWagner on 15.12.2025.
//

#pragma once
#include "gtest/gtest.h"

#include "../../source/collections/Stapel.h"
#include "../../source/collections/StapelException.h"
using namespace testing;

class StapelTest :public Test{
protected:
    Stapel objectUnderTest;


    auto fillUpToLimitWithoutException() -> void {
        for (int i = 0; i < 10; ++i) {
            EXPECT_NO_THROW(objectUnderTest.push(1));
        }
    }
};
