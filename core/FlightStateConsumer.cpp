//
// Created by Wouter Deferme on 25/09/2025.
//

#include "FlightStateConsumer.h"

#include <nlohmann/adl_serializer.hpp>
#include <nlohmann/json.hpp>

#include "FlightState.h"

void FlightStateConsumer::operator()( BloombergLP::rmqp::MessageGuard &messageGuard )
{
    if (processMessage(messageGuard.message())) {
        messageGuard.ack();
    }
    else {
        messageGuard.nack();
    }
}

bool FlightStateConsumer::processMessage( const BloombergLP::rmqt::Message &message )
{
    std::string messageString((const char *)message.payload());
    auto messageJson = nlohmann::json::parse( messageString );
    auto flightState = messageJson.get<FlightState>();
    std::cout << "Consuming flightstate with id " << flightState.id << std::endl;
    return true;
}
