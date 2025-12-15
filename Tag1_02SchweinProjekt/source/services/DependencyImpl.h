//
// Created by JoachimWagner on 24.02.2025.
//

#pragma once


#include <iostream>
#include "Dependency.h"

class DependencyImpl: public Dependency{
public:
    void foo(std::string message) const override {
        std::cout << message << std::endl;
    }

    int bar() const override {
        return 42;
    }

    size_t foobar(std::string message) const override {
        return message.length();
    }
};
