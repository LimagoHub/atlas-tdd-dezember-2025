//
// Created by JoachimWagner on 16.12.2025.
//

#pragma once
#include "gmock/gmock.h"
#include "../../source/services/blacklist_service.h"

class Mockblacklist_service: public blacklist_service {
public:
    MOCK_METHOD(bool, isBlacklisted, (const person &p), (const, override));

};
