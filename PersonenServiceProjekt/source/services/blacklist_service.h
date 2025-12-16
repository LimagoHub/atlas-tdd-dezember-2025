//
// Created by JoachimWagner on 16.12.2025.
//

#pragma once


#include "../persistence/person.h"

class blacklist_service {
public:
    blacklist_service() = default;
    virtual ~blacklist_service() = default;

    virtual bool isBlacklisted(const person &possibleBlacklistedPerson) const = 0;

};
