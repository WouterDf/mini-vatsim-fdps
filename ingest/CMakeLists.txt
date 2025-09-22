add_executable(ingest
        main.cpp
        VATSIMResource.cpp
        VATSIMResource.h
        VATSIMMetadata.h
        VATSIMResponse.h
        VATSIMFlightPlan.h
        VATSIMPrefile.h
)

find_package(CURL REQUIRED)
find_package(nlohmann_json 3.12.0 REQUIRED)
find_package(cppzmq CONFIG REQUIRED)

include_directories(${CURL_INCLUDE_DIR})
target_link_libraries(ingest  PRIVATE ${CURL_LIBRARIES} nlohmann_json::nlohmann_json cppzmq)
target_include_directories(ingest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/shared)
