//
// Created by JoachimWagner on 19.08.2024.
//

#include "SchweinTest.h"

const int MyInitialWeight = 10;


TEST_F(SchweinTest, ctor__default__correctInitialisation){
    std::string expectedValue = "Nobody";

    //EXPECT_THAT(MyInitialWeight, Not(Ge(objectUnderTest.getGewicht())));
    EXPECT_EQ(MyInitialWeight, objectUnderTest.getGewicht());


    //EXPECT_THAT("Nobody", Eq(objectUnderTest.getName()));
    EXPECT_EQ(expectedValue, objectUnderTest.getName());
}

TEST_F(SchweinTest, ctor__overloaded_with_invalid_name__throwsInvalidArgument){
        try {
            const std::string invalidName = "Elsa";
            Schwein objectUnderTestLocal{invalidName};
            FAIL()<< "Upps";
        } catch (const std::invalid_argument &e) {
            EXPECT_THAT("Name verstoesst gegen die Schweinewuerde!", StrEq(e.what()));
            EXPECT_STREQ("Name verstoesst gegen die Schweinewuerde!", e.what());
        }


    }
    TEST_F(SchweinTest, ctor__overloaded_with_valid_name__correctInitialisation){
        const std::string validName = "Piggy";
        Schwein objectUnderTestLocal{validName};
        EXPECT_EQ(MyInitialWeight, objectUnderTestLocal.getGewicht());
        EXPECT_EQ(validName, objectUnderTestLocal.getName());
}

TEST_F(SchweinTest, setName__invalidName__throwsInvalidArgument){
    try {
        const std::string invalidName = "Elsa";
        objectUnderTest.setName(invalidName);
        FAIL()<< "Upps";
    } catch(const std::invalid_argument &ex){
        EXPECT_STREQ("Name verstoesst gegen die Schweinewuerde!", ex.what());
    }
}

TEST_F(SchweinTest, setName__validName__nameCorrectlySetAndNoExceptionIsThrown){

    const std::string validName = "Piggy";
    EXPECT_NO_THROW(objectUnderTest.setName(validName));
    EXPECT_EQ("Piggy", objectUnderTest.getName());
}

TEST_F(SchweinTest, fuettern__happyDay__weightIncreasedByOne){

    const auto expectedResult = MyInitialWeight + 1;
    objectUnderTest.fuettern();
    EXPECT_THAT( objectUnderTest.getGewicht(), Eq(expectedResult));
}
