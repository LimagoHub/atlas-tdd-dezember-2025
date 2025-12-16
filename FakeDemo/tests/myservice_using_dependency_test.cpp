#include "myservice_using_dependency_test.h"



std::string dependency_to_fake::get_firstname() const {
	//return "Max";
	return dependency_to_fake_mock_repo::getInstance().getMock((dependency_to_fake *)this).get_firstname();
}

string dependency_to_fake::get_lastname()
{
	return "Mustermann";
} 
long dependency_to_fake::calculate(const int value) const
{
	return value + value;
}

TEST_F(myservice_using_dependency_test, FirstMethod) {
	dependency_to_fake_mock dMock;// Instanz eines Mocks je Test
	dependency_to_fake_mock_repo::getInstance().add_mock_to_use(&dMock); // Mock dem Repo bekannt machen
	EXPECT_CALL(dMock, get_firstname()).WillOnce(::testing::Return("Fritz"));

	EXPECT_EQ(object_under_test.first_method_under_test(), "Fritz Hallo");

}

