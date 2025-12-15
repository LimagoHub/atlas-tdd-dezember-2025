//
// Created by JoachimWagner on 13.04.2023.
//

#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../../source/services/euro_to_dollar_calculator_impl.h"
#include "../Mockexchange_rate_service.h"

using namespace testing;

class euro_to_dollar_impl_test : public Test{

protected:
    Mockexchange_rate_service exchange_rate_service_mock;
    euro_to_dollar_calculator_impl object_under_test{exchange_rate_service_mock};
};
