//
// Created by JoachimWagner on 24.02.2025.
//

#pragma once


#include <string>

class Dependency  { // Als Interface
public:
    Dependency() = default;
    virtual ~Dependency() = default;

    virtual void foo(std::string message )const  = 0;
    virtual int bar( )const  = 0;
    virtual size_t foobar(std::string message )const  = 0;
};
