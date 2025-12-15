cmake_minimum_required(VERSION 3.14)

# Avoid warning about DOWNLOAD_EXTRACT_TIMESTAMP in CMake 3.24:
if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
	cmake_policy(SET CMP0135 NEW)
endif()

enable_testing()


set(SOURCE test.cpp)

find_package(GTest CONFIG REQUIRED)
include(GoogleTest)

# Create test executable
add_executable(BlankCMakeProjectTest ${SOURCE} ${HEADER} )

target_link_libraries(
		BlankCMakeProjectTest
		GTest::gmock
		GTest::gtest_main

)


add_test(NAME BlankCMakeProjectTest COMMAND BlankCMakeProjectTest)
include(GoogleTest)
gtest_discover_tests(BlankCMakeProjectTest)

# Push it to tests
set_target_properties(BlankCMakeProjectTest PROPERTIES FOLDER Tests)

# Build tests where other libraries reside
set_target_properties(BlankCMakeProjectTest
		PROPERTIES
		ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIG>"
		LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIG>"
		RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIG>"
)