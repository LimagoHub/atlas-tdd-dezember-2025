//
// Created by JoachimWagner on 15.12.2025.
//

#pragma once

#include "gmock/gmock.h"

#include "Mockpersonen_repository.h"
#include "Mockblacklist_service.h"
#include "../../source/services/personen_service_impl.h"
using namespace testing;
class personen_service_impl_test: public Test{
protected:
    NaggyMock<Mockpersonen_repository> repositoryMock;
    StrictMock<Mockblacklist_service> blacklistServiceMock;
    personen_service_impl objectUnderTest{repositoryMock, blacklistServiceMock};

    void SetUp() override {
        ON_CALL(blacklistServiceMock, isBlacklisted(_)).WillByDefault(Return(false));
    }

};

class personen_service_impl_parameter_test : public personen_service_impl_test, public WithParamInterface<std::pair<person, std::string>> {
public:
    personen_service_impl_parameter_test(): personen_service_impl_test(){}

protected:
    person invalidPerson{"",""};
    std::string expectedErrorMessage;

    void SetUp() override{

        std::tie<person, std::string>(invalidPerson, expectedErrorMessage) = GetParam();

    }

};

