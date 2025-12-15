//
// Created by JoachimWagner on 26.02.2025.
//

#pragma once
#include <memory>
#include "../../../../atlas-tdd-september-2025/Tag1_02Schwein/source/services/UniqueDependency.h"



class UniqueService {
    std::unique_ptr<UniqueDependency> dependency;

public:
    explicit UniqueService(std::unique_ptr<UniqueDependency> dependency) : dependency(std::move(dependency)) {}


    int doWork() {
        return dependency->foo() + 10;
    }
};
