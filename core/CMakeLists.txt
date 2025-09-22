add_executable(core
    main.cpp)

find_package(cppzmq CONFIG REQUIRED)

find_package(nlohmann_json 3.12.0 REQUIRED)

target_link_libraries(core  PRIVATE cppzmq nlohmann_json::nlohmann_json)

target_include_directories(core PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/shared)
