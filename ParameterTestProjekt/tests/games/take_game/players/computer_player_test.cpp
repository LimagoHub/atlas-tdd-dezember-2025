//
// Created by JoachimWagner on 30.01.2024.
//

#include "computer_player_test.h"


TEST_F(computer_player_test, doTurn__StonesMod4Equal0__returns3) {

    EXPECT_CALL(writerMock, write("Computer nimmt " + std::to_string(3) + " Steine"));
    EXPECT_THAT(object_under_test.do_turn(20), Eq(3));
}

TEST_F(computer_player_test, doTurn__StonesMod4Equal1__returns1) {

    EXPECT_CALL(writerMock, write("Computer nimmt " + std::to_string(1) + " Steine"));
    EXPECT_THAT(object_under_test.do_turn(21), Eq(1));
}


TEST_F(computer_player_test, doTurn__StonesMod4Equal2__returns1) {

    EXPECT_CALL(writerMock, write("Computer nimmt " + std::to_string(1) + " Steine"));
    EXPECT_THAT(object_under_test.do_turn(22), Eq(1));
}

TEST_F(computer_player_test, doTurn__StonesMod4Equal3__returns2) {

    EXPECT_CALL(writerMock, write("Computer nimmt " + std::to_string(2) + " Steine"));
    EXPECT_THAT(object_under_test.do_turn(23), Eq(2));
}

TEST_P(computer_player_parameter_test, do_turn_happy_day) {
    EXPECT_CALL(writerMock, write("Computer nimmt " + std::to_string(expectedValue) + " Steine"));
    EXPECT_THAT(object_under_test.do_turn(stones), Eq(expectedValue));
}

INSTANTIATE_TEST_SUITE_P(
        DoTurnHappyDayParameterTests, // Name der Tests, frei waehlbar
        computer_player_parameter_test, // Verbindung zur Testklasse
        Values(
                std::make_pair(20, 3),
                std::make_pair(21, 1),
                std::make_pair(22, 1),
                std::make_pair(23, 2),
                std::make_pair(4, 3),
                std::make_pair(5, 1),
                std::make_pair(6, 1),
                std::make_pair(7, 2))
);