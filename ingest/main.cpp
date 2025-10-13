#include "VATSIMResource.h"
#include "../shared/RabbitMQConnection.h"
#include "VATSIMResponse.h"
#include <iostream>
#include <thread>
#include <zmq.hpp>

int main()
{
    auto VATSIMresource = std::make_unique<VATSIMResource>();
    // auto publisher = std::make_unique<ZeroMQPublisher>( "tcp://*:5555" );

    // TODO(wouterdeferme): Authentication details should not be in code base.
    const int port = 5672;
    auto publisher = std::make_unique<RabbitMQConnection>( "localhost", port, "guest", "guest" );

    while( true )
    {
        // Perform request to vatsim
        auto vatsimResponse = std::make_unique<VATSIMResponse>(VATSIMresource->request());

        // Standardize Flight Plans and Flight States
        auto standardFlightPlans = vatsimResponse->getStandardFlightPlans();
        auto standardFlightStates = vatsimResponse->getStandardFlightStates();

        std::cout << "System ingested " << standardFlightPlans.size() << " flight plans" << '\n';

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

	const int SLEEP_MS = 6;
        std::this_thread::sleep_for(std::chrono::seconds(SLEEP_MS));
    }
}
