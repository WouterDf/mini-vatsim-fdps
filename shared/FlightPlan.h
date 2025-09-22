//
// Created by Wouter Deferme on 22/09/2025.
//

#ifndef VATSIMFDPS_FLIGHTPLAN_H
#define VATSIMFDPS_FLIGHTPLAN_H

// A pseudo-ADEXP FLP
struct FlightPlan
{
    int IFPLID;         // Flightplan unique identifier
    std::string ADEP;   // Airport of departure
    std::string ADES;   // Airport of destination
    std::string ARCTYP;
    std::string EOBT;
    std::string ROUTE;
    std::string RFL;
    std::string SPEED;
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE_WITH_DEFAULT( FlightPlan, IFPLID, ADEP, ADES, ARCTYP, EOBT, ROUTE, RFL, SPEED );

#endif //VATSIMFDPS_FLIGHTPLAN_H