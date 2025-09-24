//
// Created by Wouter Deferme on 23/09/2025.
//

#include "ZeroMQPublisher.h"

#include <iostream>
#include <nlohmann/json.hpp>

#include "FlightPlan.h"
#include "FlightState.h"

ZeroMQPublisher::ZeroMQPublisher(std::string address) : APublisher(address)
{
    this->socket = zmq::socket_t( this->context, zmq::socket_type::pub );
    socket.bind( address );
}

void ZeroMQPublisher::publish( FlightPlan flight_plan )
{
    nlohmann::json flpJson = flight_plan;
    std::string flpJsonString = flpJson.dump();
    std::string topic_message = "topic " + flpJsonString;
    zmq::message_t message (topic_message.size());
    memcpy( message.data(), topic_message.data(), topic_message.size() );
    socket.send( message, zmq::send_flags::none );
    std::cout << "Did send FLP with IFPLID " << flight_plan.IFPLID << " to core FDPS" << std::endl;
}

void ZeroMQPublisher::publish( FlightState flight_state )
{
    nlohmann::json fsJson = flight_state;
    std::string fsJsonString = fsJson.dump();
    std::string topic_message = "topic " + fsJsonString;
    zmq::message_t message (topic_message.size());
    memcpy( message.data(), topic_message.data(), topic_message.size() );
    socket.send( message, zmq::send_flags::none );
    std::cout << "Did send Flight State with ID " << flight_state.id << " to core FDPS" << std::endl;
}
