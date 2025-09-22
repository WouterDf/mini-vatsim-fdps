//
// Created by Wouter Deferme on 22/09/2025.
//

#ifndef VATSIMPILOT_H
#define VATSIMPILOT_H
#include "nlohmann/json.hpp"
#include "VATSIMFlightPlan.h"

struct VATSIMPrefile
{
    std::string name;
    int cid;
    std::string callsign;
    VATSIMFlightPlan flight_plan;

public:
    FlightPlan toStandardFlightPlan()
    {
        return FlightPlan(
            this->cid,
            this->flight_plan.departure,
            this->flight_plan.arrival,
            this->flight_plan.aircraft,
            this->flight_plan.deptime,
            this->flight_plan.route,
            this->flight_plan.altitude,
            this->flight_plan.cruise_tas
        );
    }
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE_WITH_DEFAULT( VATSIMPrefile, name, cid, callsign, flight_plan );

#endif //VATSIMPILOT_H
