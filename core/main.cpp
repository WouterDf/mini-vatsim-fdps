#include <iostream>
#include <zmq.hpp>
#include <nlohmann/json.hpp>

#include "FlightPlan.h"
#include "FlightState.h"
#include "FlightStateConsumer.h"
#include "RabbitMQConnection.h"

int main()
{
    std::cout << "Core is running" << std::endl;
    auto rabbit = std::make_unique<RabbitMQConnection>( "localhost", 5672, "guest", "guest" );

    rabbit->createConsumer( FlightStateConsumer() );

    while( true )
    {

    } // Keep main thread running

    return 0;
}
