//
// Created by JoachimWagner on 13.04.2023.
//

#include "euro_to_dollar_presenter_impl_test.h"

void euro_to_dollar_presenter_impl_test::SetUp() {
    object_under_test.set_view(&euro_to_dollar_viewMock);
    object_under_test.set_model(&euro_to_dollar_calculatorMock);
}

TEST_F(euro_to_dollar_presenter_impl_test, beenden__happy_day__mask_closed){
    EXPECT_CALL(euro_to_dollar_viewMock, dispose).Times(1);
    object_under_test.beenden();
}

TEST_F(euro_to_dollar_presenter_impl_test, populate_items__happy_day__mask_initialized){

    InSequence s;

    EXPECT_CALL(euro_to_dollar_viewMock, set_euro("0"));
    EXPECT_CALL(euro_to_dollar_viewMock, set_dollar("0"));
    EXPECT_CALL(euro_to_dollar_viewMock, set_rechnen_enabled(true));
    object_under_test.populate_items();
}


TEST_F(euro_to_dollar_presenter_impl_test, rechnen__NotANumberInEuroField__error_message_in_dollar_field){
    InSequence s;
    EXPECT_CALL(euro_to_dollar_viewMock, get_euro()).Times(1).WillOnce(Return("Not a Number"));
    EXPECT_CALL(euro_to_dollar_viewMock, set_dollar("Keine Zahl"));
    object_under_test.rechnen();
}



TEST_F(euro_to_dollar_presenter_impl_test, rechnen__unexpected_exception_in_underlying_service__error_message_in_dollar_field){
    InSequence s;
    EXPECT_CALL(euro_to_dollar_viewMock, get_euro()).Times(1).WillOnce(Return("10"));
    EXPECT_CALL(euro_to_dollar_calculatorMock, convert(_)).WillOnce(Throw(std::runtime_error{"Upps"}));
    EXPECT_CALL(euro_to_dollar_viewMock, set_dollar("Internal Server Error"));
    object_under_test.rechnen();
}



TEST_F(euro_to_dollar_presenter_impl_test, rechnen__euro_vcalue_followed_by_char__euro_passed_to_model){
    EXPECT_CALL(euro_to_dollar_viewMock, get_euro()).Times(1).WillOnce(Return("10Euro"));
    EXPECT_CALL(euro_to_dollar_viewMock, set_dollar("Keine Zahl"));
    object_under_test.rechnen();
}

TEST_F(euro_to_dollar_presenter_impl_test, rechnen__NAN_inEuro__euro_passed_to_model){
    EXPECT_CALL(euro_to_dollar_viewMock, get_euro()).Times(1).WillOnce(Return("NAN"));
    EXPECT_CALL(euro_to_dollar_viewMock, set_dollar("Keine Zahl"));
    object_under_test.rechnen();
}

TEST_F(euro_to_dollar_presenter_impl_test, rechnen__happyDay__dollar_value_in_dollar_field){

    EXPECT_CALL(euro_to_dollar_viewMock, get_euro()).Times(1).WillOnce(Return("10"));
    EXPECT_CALL(euro_to_dollar_calculatorMock, convert(10.0)).WillOnce(Return(120.0));
    EXPECT_CALL(euro_to_dollar_viewMock, set_dollar("120.00"));
    object_under_test.rechnen();
}

TEST_F(euro_to_dollar_presenter_impl_test, update_rechnen_action_state_NotANumberInEuroField__button_disabled){

    EXPECT_CALL(euro_to_dollar_viewMock, get_euro()).Times(1).WillOnce(Return("Not a Number"));

    EXPECT_CALL(euro_to_dollar_viewMock, set_rechnen_enabled(false));
    object_under_test.update_rechnen_action_state();
}

TEST_F(euro_to_dollar_presenter_impl_test, update_rechnen_action_state__ValiEuroValueInEuroField__button_enabeld){

    EXPECT_CALL(euro_to_dollar_viewMock, get_euro()).Times(1).WillOnce(Return("10"));

    EXPECT_CALL(euro_to_dollar_viewMock, set_rechnen_enabled(true));
    object_under_test.update_rechnen_action_state();
}




