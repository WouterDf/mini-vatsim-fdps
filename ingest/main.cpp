#include <iostream>
#include <thread>
#include <zmq.hpp>
#include "VATSIMResource.h"
#include "VATSIMResponse.h"
#include "FlightPlan.h"
#include "../shared/RabbitMQConnection.h"
#include "ZeroMQPublisher.h"

int main()
{
    auto VATSIMresource = std::make_unique<VATSIMResource>();
    // auto publisher = std::make_unique<ZeroMQPublisher>( "tcp://*:5555" );

    // TODO: Authentication details should not be in code base.
    auto publisher = std::make_unique<RabbitMQConnection>( "localhost", 5672, "guest", "guest" );

    while( true )
    {
        // Perform request to vatsim
        auto vatsimResponse = std::make_unique<VATSIMResponse>(VATSIMresource->request());

        // Standardize Flight Plans and Flight States
        auto standardFlightPlans = vatsimResponse->getStandardFlightPlans();
        auto standardFlightStates = vatsimResponse->getStandardFlightStates();

        std::cout << "System ingested " << standardFlightPlans.size() << " flight plans" << std::endl;

        // Publish each Flight State
        for( auto& flight_state : standardFlightStates )
        {
            publisher->publish( flight_state );
        }

        // Publish each FLP
        // for (auto& flp : standardFlightPlans)
        // {
        //     publisher->publish( flp );
        // }

        std::this_thread::sleep_for(std::chrono::seconds(6));
    }
}
