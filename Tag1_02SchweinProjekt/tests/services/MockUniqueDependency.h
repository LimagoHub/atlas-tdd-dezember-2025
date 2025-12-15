//
// Created by JoachimWagner on 11.07.2024.
//

#pragma once
#include "gmock/gmock.h"

#include "../../../../atlas-tdd-september-2025/Tag1_02Schwein/source/services/UniqueDependency.h"
class MockUniqueDependency : public UniqueDependency {
public:

    MOCK_METHOD(int, foo, (), (const, override));

};