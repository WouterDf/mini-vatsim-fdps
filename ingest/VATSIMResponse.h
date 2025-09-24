//
// Created by Wouter Deferme on 22/09/2025.
//

#ifndef VATSIMRESPONSE_H
#define VATSIMRESPONSE_H
#include <nlohmann/json.hpp>
#include <vector>
#include "VATSIMMetadata.h"
#include "VATSIMPrefile.h"
#include "VATSIMFlightState.h"

struct VATSIMResponse
{
    VATSIMMetadata general;
    std::vector<VATSIMPrefile> prefiles;
    std::vector<VATSIMFlightState> pilots;

public:
    std::vector<FlightPlan> getStandardFlightPlans()
    {
        std::vector<FlightPlan> standardFlightPlans{};

        for( auto& prefile : this->prefiles )
        {
            standardFlightPlans.push_back( prefile.toStandardFlightPlan() );
        }

        return standardFlightPlans;
    }

    std::vector<FlightState> getStandardFlightStates()
    {
        std::vector<FlightState> standardFlightStates{};

        for( auto& flightstate : this->pilots )
        {
            standardFlightStates.push_back( flightstate.toStandardFlightState() );
        }

        return standardFlightStates;
    }
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE_WITH_DEFAULT( VATSIMResponse, general, prefiles, pilots );

#endif //VATSIMRESPONSE_H
