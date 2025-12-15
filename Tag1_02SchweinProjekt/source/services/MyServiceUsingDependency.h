//
// Created by JoachimWagner on 24.02.2025.
//

#pragma once
#include "Dependency.h"
#include <algorithm>

class MyServiceUsingDependency {

    Dependency &dependency;

public:
    explicit MyServiceUsingDependency(Dependency &dependency) : dependency(dependency) {}

    void f(std::string value) {
        transform(value.begin(), value.end(), value.begin(), ::toupper);
        dependency.foo(value);

    }

    size_t g(std::string value) {
        value += " Welt";
        return dependency.foobar(value) + 5;
    }

    long h() {
        const auto barValue = dependency.bar();
        return barValue * barValue;

    }
};
