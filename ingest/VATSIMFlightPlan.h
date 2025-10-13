//
// Created by Wouter Deferme on 22/09/2025.
//

#ifndef VATSIMFLIGHTPLAN_H
#define VATSIMFLIGHTPLAN_H
#include <nlohmann/json.hpp>

#include "../shared/FlightPlan.h"


struct VATSIMFlightPlan
{
    std::string flight_rules;
    std::string aircraft;
    std::string departure;
    std::string arrival;
    std::string alternate;
    std::string cruise_tas;
    std::string altitude;
    std::string deptime;
    std::string enroute_time;
    std::string fuel_time;
    std::string remarks;
    std::string route;
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE_WITH_DEFAULT( VATSIMFlightPlan, flight_rules, aircraft, departure, arrival,
    alternate, cruise_tas, altitude, deptime, enroute_time, fuel_time, remarks, route );

#endif //VATSIMFLIGHTPLAN_H
