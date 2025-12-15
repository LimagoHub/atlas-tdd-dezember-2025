//
// Created by JoachimWagner on 15.12.2025.
//

#include "StapelTest.h"

TEST_F(StapelTest, isEmpty__emptyStack__returnsTrue){
    // Arrange


    // Action
    auto result = objectUnderTest.isEmpty();

    // Assertion
    EXPECT_TRUE(result);

}

TEST_F(StapelTest, isEmpty__NotEmptyStack__returnsFalse){

    const int valid_value = 10;
    // Arrange


    objectUnderTest.push(valid_value);
    // Action
    auto result = objectUnderTest.isEmpty();

    // Assertion
    EXPECT_FALSE(result);

}

TEST_F(StapelTest, isEmpty__EmptyAgainStack__returnsTrue) {

    auto const validValue = 1;
    // Arrange

    objectUnderTest.push(validValue);
    objectUnderTest.pop();
    // Action

    auto result = objectUnderTest.isEmpty();

    // Assertion
    EXPECT_TRUE(result);

}

TEST_F(StapelTest, push__fillupToLimit__noExceptionIsThrown) {
    fillUpToLimitWithoutException();
}

TEST_F(StapelTest, push__Overflow__throwsStapelException) {
    fillUpToLimitWithoutException();
    EXPECT_THROW(objectUnderTest.push(1), StapelException);
}

TEST_F(StapelTest, push__Overflow__throwsStapelException_variante) {
    try {
        fillUpToLimitWithoutException();
        objectUnderTest.push(1);
        FAIL() << "Fehler Stapelexception erwartet!";
    } catch (const StapelException & ex) {
        EXPECT_STREQ("Overflow", ex.what());
    }
}