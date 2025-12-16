//
// Created by JoachimWagner on 02.06.2023.
//

#pragma once

#include <string>
class Writer {
public:
    virtual void write(const std::string &message) const = 0;
};
