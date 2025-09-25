# Shared library for common components
add_library(vatsim_shared SHARED
    FlightPlan.h
    FlightState.h
        RabbitMQConnection.cpp
        RabbitMQConnection.h
)

# Find required packages
find_package(nlohmann_json 3.12.0 REQUIRED)
find_package(rmqcpp REQUIRED)

# Link libraries
target_link_libraries(vatsim_shared PUBLIC nlohmann_json::nlohmann_json rmqcpp::rmq)

# Set C++ standard
set_property(TARGET vatsim_shared PROPERTY CXX_STANDARD 17)

# Make headers available to other targets
target_include_directories(vatsim_shared PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})