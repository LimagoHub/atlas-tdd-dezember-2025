//
// Created by JoachimWagner on 26.02.2025.
//

#pragma once
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "MockUniqueDependency.h"
#include "../../source/services/UniqueService.h"

using namespace testing;

class UniqueServiceTest: public Test {
protected:

    MockUniqueDependency *mockPtr;
    std::unique_ptr<MockUniqueDependency> mock;
    std::unique_ptr<UniqueService> objectUnderTest;


    void SetUp() override{
        mock = std::make_unique<MockUniqueDependency>();
        mockPtr = mock.get();
        objectUnderTest = std::make_unique<UniqueService>(std::move(mock));
    }
};
