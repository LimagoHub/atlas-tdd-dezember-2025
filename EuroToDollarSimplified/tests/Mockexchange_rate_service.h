//
// Created by JoachimWagner on 30.05.2022.
//

#ifndef EURO2DOLLAR_MOCKEXCHANGE_RATE_SERVICE_H
#define EURO2DOLLAR_MOCKEXCHANGE_RATE_SERVICE_H
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../source/services/exchange_rate_service.h"

class Mockexchange_rate_service : public exchange_rate_service {
public:
    MOCK_METHOD( double , get_rate_for, (const std::string currency), (const, override));
};

#endif //EURO2DOLLAR_MOCKEXCHANGE_RATE_SERVICE_H
