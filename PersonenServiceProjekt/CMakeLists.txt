cmake_minimum_required (VERSION 3.12)

project(PersonenServiceProject)

set(CMAKE_CXX_STANDARD 17)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(OUTPUT_DIR ${CMAKE_SOURCE_DIR}/build/${PLATFORM_ARCHITECTURE}/$<CONFIG>)
set(PROJ_CONFIG $<CONFIG>)

enable_testing()

add_executable(
	PersonenServiceProject 
	source/main.cpp
		source/persistence/person.h
		source/services/personen_service_impl.h
)


# Add tests
add_subdirectory(tests)

