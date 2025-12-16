//
// Created by JoachimWagner on 15.12.2025.
//
#include <stdexcept>
#include "personen_service_impl_test.h"

TEST_F(personen_service_impl_test,speichern__VornameZuKurz__throws_personen_service_exception) {
    try {

        // Arrange
        EXPECT_CALL (blacklistServiceMock, isBlacklisted(_)).Times(0);
        EXPECT_CALL(repositoryMock,save_or_update(_) ).Times(0);
        person invalidPerson{"j", "Doe"};
        // Action
        objectUnderTest.speichern(invalidPerson);
        FAIL() << "personen_service_exception erwartet";
    } catch( const personen_service_exception & ex) {
        EXPECT_THAT(ex.what(), StrEq("Vorname zu kurz!"));
    }
}

TEST_F(personen_service_impl_test,speichern__NachnameZuKurz__throws_personen_service_exception) {
    try {
        // Arrange
        EXPECT_CALL (blacklistServiceMock, isBlacklisted(_)).Times(0);
        EXPECT_CALL(repositoryMock,save_or_update(_) ).Times(0);
        person invalidPerson{"John", "D"};
        // Action
        objectUnderTest.speichern(invalidPerson);
        FAIL() << "personen_service_exception erwartet";
    } catch( const personen_service_exception & ex) {
        EXPECT_THAT(ex.what(), StrEq("Nachname zu kurz!"));
    }
}

TEST_F(personen_service_impl_test,speichern__blacklistedPerson__throws_personen_service_exception) {
    try {
        // Arrange
        person anyPerson{"Erika", "Mustermann"};
        EXPECT_CALL(blacklistServiceMock, isBlacklisted(anyPerson)).WillOnce(Return(true));
        EXPECT_CALL(repositoryMock,save_or_update(_) ).Times(0);
        // Action
        objectUnderTest.speichern(anyPerson);
        FAIL() << "personen_service_exception erwartet";
    } catch (const personen_service_exception &ex) {
        EXPECT_THAT(ex.what(), StrEq("person is blacklisted"));
    }
}

TEST_F(personen_service_impl_test,speichern__UnexpectedExceptionInUnderlyingService__throws_personen_service_exception){
    try {

        // Arrange
        person validPerson{"John", "Doe"};
        EXPECT_CALL (blacklistServiceMock, isBlacklisted(_)).WillOnce(Return(false));
        EXPECT_CALL(repositoryMock,save_or_update(_) ).WillOnce(Throw(std::runtime_error{"upps"}));
        // Action
        objectUnderTest.speichern(validPerson);
        FAIL() << "personen_service_exception erwartet";
    } catch (const personen_service_exception &ex) {
        EXPECT_THAT(ex.what(), StrEq("Ein Fehler ist aufgetreten"));
    }
}

TEST_F(personen_service_impl_test,speichern__HappyDay__personPassedToRepo) {
    InSequence dummy;
    person validPerson{"John", "Doe"};

    EXPECT_CALL (blacklistServiceMock, isBlacklisted(_)).WillOnce(Return(false));
    EXPECT_CALL(repositoryMock, save_or_update(validPerson));

    objectUnderTest.speichern(validPerson);
}