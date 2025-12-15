//
// Created by JoachimWagner on 24.02.2025.
//

#pragma once

#include <exception>

class StapelException: public std::exception {
    const char *const message;
public:
    //StapelException() {}

    explicit StapelException(const char *const message="") :message(message) {}

    const char *what() const noexcept override {
        return message;
    }


};
