//
// Created by Wouter Deferme on 22/09/2025.
//

#ifndef VATSIMRESPONSE_H
#define VATSIMRESPONSE_H
#include <nlohmann/json.hpp>
#include <vector>
#include "VATSIMMetadata.h"
#include "VATSIMPrefile.h"


struct VATSIMResponse
{
    VATSIMMetadata general;
    std::vector<VATSIMPrefile> prefiles;
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
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE_WITH_DEFAULT( VATSIMResponse, general, prefiles );

#endif //VATSIMRESPONSE_H
