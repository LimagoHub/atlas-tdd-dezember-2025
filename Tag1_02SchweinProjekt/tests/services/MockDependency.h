//
// Created by JoachimWagner on 11.07.2024.
//

#pragma once
#include "gmock/gmock.h"

#include "../../source/services/Dependency.h"

class MockDependency : public Dependency {
public:
    MOCK_METHOD(void, foo, (std::string message), (const, override));
    MOCK_METHOD(int, bar, (), (const, override));
    MOCK_METHOD(size_t, foobar, (std::string message), (const, override));
};