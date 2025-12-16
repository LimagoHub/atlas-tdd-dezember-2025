//
// Created by JoachimWagner on 30.01.2024.
//

#pragma once
#include "gmock/gmock.h"
#include "../../../source/games/take_game/players/computer_player.h"
#include "MockWriter.h"
using namespace testing;

class computer_player_test : public Test{
protected:
    MockWriter writerMock;
    computer_player object_under_test{writerMock};
};

class computer_player_parameter_test : public computer_player_test,
                                       public WithParamInterface<std::pair<int, int>> {
protected:
    int stones;
    int expectedValue;
    void SetUp() override{
        std::tie<int, int>(stones, expectedValue) = GetParam();

    }
};






