//
// Created by JoachimWagner on 16.09.2025.
//

#pragma once


#include "../persistence/person.h"

class personen_service {
public:
    virtual void speichern(person &person_) = 0;

};
