#include <iostream>
#include <thread>
#include <zmq.hpp>
#include "VATSIMResource.h"
#include "VATSIMResponse.h"
#include "FlightPlan.h"

int main()
{
    auto VATSIMresource = std::make_unique<VATSIMResource>();

    zmq::context_t context;
    zmq::socket_t socket(context, zmq::socket_type::pub);
    socket.bind( "tcp://*:5555" );

    while( true )
    {
        // Perform request to vatsim
        auto buffer = std::make_unique<std::string>(VATSIMresource->request());
        // Parse request
        auto responseJson = nlohmann::json::parse(*buffer);
        auto vatsimResponse = responseJson.template get<VATSIMResponse>();
        auto standardFlightPlans = vatsimResponse.getStandardFlightPlans();
        std::cout << "System ingested " << standardFlightPlans.size() << " flight plans" << std::endl;

        // Publish each FLP
        for (auto& flp : standardFlightPlans)
        {
            nlohmann::json flpJson = flp;
            std::string flpJsonString = flpJson.dump();
            std::string topic_message = "topic " + flpJsonString;
            zmq::message_t message (topic_message.size());
            memcpy( message.data(), topic_message.data(), topic_message.size() );
            socket.send( message, zmq::send_flags::none );
            std::cout << "Did send FLP with IFPLID " << flp.IFPLID << " to core FDPS" << std::endl;
        }

        std::this_thread::sleep_for(std::chrono::seconds(6));
    }
}
