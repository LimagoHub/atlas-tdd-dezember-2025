#pragma once

#include "gmock/gmock.h"
#include "../../../source/games/take_game/io/Writer.h"




class MockWriter : public Writer {
public:
    MOCK_METHOD(void, write, (const std::string &message), (const, override));
};
