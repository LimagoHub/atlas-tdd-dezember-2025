//
// Created by JoachimWagner on 15.12.2025.
//

#pragma once




class Stapel {

    bool empty{true};
public:
    bool isEmpty(){
        return empty;
    }

    void push(int i) {
        empty = false;
    }
};
