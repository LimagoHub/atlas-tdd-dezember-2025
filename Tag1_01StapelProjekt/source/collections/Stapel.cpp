//
// Created by JoachimWagner on 15.12.2025.
//

#include "Stapel.h"
#include "StapelException.h"

auto Stapel::push(int value) -> void {
    if(isFull()) throw StapelException{"Overflow"};
    data[index++] = value;
}
auto Stapel::pop() -> int {
    if(isEmpty()) throw StapelException{"Underflow"};

    return data[--index];
}


auto Stapel::isEmpty() -> bool const {
    return index <= 0;
}

auto Stapel::isFull() -> bool const {
    return index >= 10;
}