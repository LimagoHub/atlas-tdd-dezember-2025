cmake_minimum_required (VERSION 3.12)

project(EuroToDollarProject)

set(CMAKE_CXX_STANDARD 17)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(OUTPUT_DIR ${CMAKE_SOURCE_DIR}/build/${PLATFORM_ARCHITECTURE}/$<CONFIG>)
set(PROJ_CONFIG $<CONFIG>)

enable_testing()

add_executable(
	EuroToDollarProject
	source/main.cpp
        source/presenter/euro_to_dollar_presenter.h source/presenter/euro_to_dollar_presenter_impl.h source/services/euro_to_dollar_calculator.h source/services/exchange_rate_service.h source/services/exchange_rate_service_impl.h source/view/euro_to_dollar_view.h source/services/euro_to_dollar_calculator_impl.h source/presenter/euro_to_dollar_presenter_impl.h)


# Add tests
add_subdirectory(tests)

