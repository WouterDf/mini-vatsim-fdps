add_executable(core
    main.cpp
        FlightStateConsumer.cpp
        FlightStateConsumer.h)

find_package(cppzmq CONFIG REQUIRED)
find_package(nlohmann_json 3.12.0 REQUIRED)

target_link_libraries(core  PRIVATE cppzmq nlohmann_json::nlohmann_json vatsim_shared)

target_include_directories(core PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/shared )
