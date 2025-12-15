//
// Created by JoachimWagner on 22.02.2024.
//

#include "euro_to_dollar_presenter_test.h"

void euro_to_dollar_presenter_impl_test::SetUp() {
    object_under_test.set_view(&euro_to_dollar_viewMock);
    object_under_test.set_model(&euro_to_dollar_calculatorMock);
}

TEST_F(euro_to_dollar_presenter_impl_test, beenden__happyDay__maskDisosed) {
    EXPECT_CALL(euro_to_dollar_viewMock, dispose).Times(1);
    object_under_test.beenden();
}

TEST_F(euro_to_dollar_presenter_impl_test, populateItems__happyDay__maskInitialised) {
    InSequence dummy;
    EXPECT_CALL(euro_to_dollar_viewMock, set_euro("0")).Times(1);
    EXPECT_CALL(euro_to_dollar_viewMock, set_dollar("0")).Times(1);
    EXPECT_CALL(euro_to_dollar_viewMock, set_rechnen_enabled(true)).Times(1);
    object_under_test.populate_items();
}