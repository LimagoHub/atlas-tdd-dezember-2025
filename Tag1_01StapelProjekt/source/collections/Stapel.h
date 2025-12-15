//
// Created by JoachimWagner on 15.12.2025.
//

#pragma once


class Stapel {
private:
    int data[10];
    int index = 0;
public:
    Stapel() = default;
    auto push(int value)->void;
    auto pop()->int;

    auto isEmpty()->bool const;
    auto isFull()->bool const;
};
