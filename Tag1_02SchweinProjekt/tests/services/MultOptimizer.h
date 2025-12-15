//
// Created by JoachimWagner on 19.08.2024.
//

#pragma once


#include "Mult.h"

class MultOptimizer: public Mult {
private:
    Mult &mult_;

public:
    explicit MultOptimizer(Mult &_mult) : mult_(_mult) {}

    ~MultOptimizer() override = default;
    long mult(int a, int b) const override {
        if(a > b)
            return mult_.mult(b,a);
        return mult_.mult(a,b);
    }
};
