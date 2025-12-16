//
// Created by JoachimWagner on 14.12.2022.
//

#pragma once
#include "gmock/gmock.h"
#include "gmock-global/gock-global.h"

MOCK_GLOBAL_FUNC2(mult,double(double, double));

using namespace testing;
class globaltest : public Test{

};




