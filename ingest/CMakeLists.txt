add_executable(ingest
        main.cpp
        VATSIMResource.cpp
        VATSIMResource.h
        VATSIMMetadata.h
        VATSIMResponse.h
        VATSIMFlightPlan.h
        VATSIMPrefile.h
        VATSIMFlightState.h
        ZeroMQPublisher.cpp
        ZeroMQPublisher.h
        APublisher.cpp
        APublisher.h
)

find_package(CURL REQUIRED)
find_package(nlohmann_json 3.12.0 REQUIRED)
find_package(cppzmq CONFIG REQUIRED)

include_directories(${CURL_INCLUDE_DIR})
target_link_libraries(ingest PRIVATE ${CURL_LIBRARIES} nlohmann_json::nlohmann_json cppzmq vatsim_shared)
target_include_directories(ingest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_property(TARGET ingest PROPERTY CXX_STANDARD 17)
