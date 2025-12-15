//
// Created by JoachimWagner on 31.05.2022.
//

#ifndef EURO2DOLLAR_MOCKEURO_TO_DOLLAR_VIEW_H
#define EURO2DOLLAR_MOCKEURO_TO_DOLLAR_VIEW_H
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../source/presenter/euro_to_dollar_presenter.h"

class Mockeuro_to_dollar_view : public euro_to_dollar_view {
public:
    MOCK_METHOD(void, set_presenter, (euro_to_dollar_presenter* presenter), (override));
    MOCK_METHOD(void, dispose, (), (override));
    MOCK_METHOD(  std::string, get_euro, (), (const, override));
    MOCK_METHOD(void, set_euro, (std::string euro), (override));
    MOCK_METHOD(  std::string, get_dollar, (), (const, override));
    MOCK_METHOD(void, set_dollar, (std::string dollar), (override));
    MOCK_METHOD( bool , is_rechnen_enabled, (), (const, override));
    MOCK_METHOD(void, set_rechnen_enabled, (bool enabled), (override));
};

#endif //EURO2DOLLAR_MOCKEURO_TO_DOLLAR_VIEW_H
