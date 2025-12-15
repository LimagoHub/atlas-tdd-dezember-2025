//
// Created by JoachimWagner on 15.12.2025.
//

#include "MyServiceUsingDependencyTest.h"


/*
*
*  void f(std::string value) {
       transform(value.begin(), value.end(), value.begin(), ::toupper);
       dependency.foo(value);
   }
*
*/

TEST_F(MyServiceUsingDependencyTest, MockdemoFooFunc) {


    // Arrange
    // Recordmode
    EXPECT_CALL(dependencyMock, foo("HALLO"));
    //EXPECT_CALL(dependencyMock, foo(_));
    // Replay
    objectUnderTest.f("hallo");
}

/*
 *  size_t g(std::string value) {
        value += " Welt";
        return dependency.foobar(value) + 5;;
    }
 *
 */
TEST_F(MyServiceUsingDependencyTest, MockdemoFooBarFunc) {
    EXPECT_CALL(dependencyMock, foobar("Hallo Welt"))
    .Times(AtLeast(1))
    .WillOnce(Return(10))
    .WillOnce(Return(15))
    .WillOnce(Throw(std::exception{"Upps"}));

    EXPECT_EQ(15,objectUnderTest.g("Hallo"));
    EXPECT_EQ(20,objectUnderTest.g("Hallo"));
}

/*
    * long h() {
       return dependency.bar() * dependency.bar();

   }
    *
    */

TEST_F(MyServiceUsingDependencyTest, MockdemoBarFunc) {
    // Arrange
    // Recordmode
    EXPECT_CALL(dependencyMock, bar()).Times(1).WillRepeatedly(Return(3));
    // Action
    const auto result = objectUnderTest.h();
    // Assertion
    EXPECT_THAT(result, Eq(9));
}