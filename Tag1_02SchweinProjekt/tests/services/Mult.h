//
// Created by JoachimWagner on 19.08.2024.
//

#pragma once


class Mult {
public:
    Mult() = default;

    virtual ~Mult() = default;

    virtual long mult(int a, int b) const = 0;
};
