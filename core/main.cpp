#include <iostream>
#include <zmq.hpp>
#include <nlohmann/json.hpp>

#include "FlightPlan.h"

int main()
{
    zmq::context_t context;
    zmq::socket_t socket(context, zmq::socket_type::sub);
    socket.set( zmq::sockopt::subscribe, "topic" );
    socket.connect( "tcp://localhost:5555" );

    std::cout << "Core is running" << std::endl;
    while( true )
    {
        zmq::message_t message;
        socket.recv( message, zmq::recv_flags::none );

        std::string data(static_cast<char*>(message.data()), message.size());

        std::cout << "Received message of " << message.size() << " bytes" << std::endl;
        std::string messageString(static_cast<const char*>(message.data()), message.size());
        std::string messageContent = messageString.substr( 6 );

        auto messageJson = nlohmann::json::parse(messageContent);
        FlightPlan flightPlan = messageJson.get<FlightPlan>();

        std::cout << "Received flightplan with IFPLID " << flightPlan.IFPLID << std::endl;

    }
    return 0;
}
