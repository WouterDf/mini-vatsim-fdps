add_executable(ingest
        main.cpp
        VATSIMResource.cpp
        VATSIMResource.h)

find_package(CURL REQUIRED)
find_package(nlohmann_json 3.12.0 REQUIRED)
include_directories(${CURL_INCLUDE_DIR})
target_link_libraries(ingest  PRIVATE ${CURL_LIBRARIES} nlohmann_json::nlohmann_json)
target_include_directories(ingest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
