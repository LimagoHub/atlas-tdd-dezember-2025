cmake_minimum_required (VERSION 3.12)

project(FakeDemo)


set(CMAKE_CXX_STANDARD 17)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)




add_executable(FakeDemo main.cpp dependecy_to_fake.cpp)


# Add tests
add_subdirectory(tests)

