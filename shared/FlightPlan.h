//
// Created by Wouter Deferme on 22/09/2025.
//

#ifndef VATSIMFDPS_FLIGHTPLAN_H
#define VATSIMFDPS_FLIGHTPLAN_H

#include <string>
#include <nlohmann/json.hpp>

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

    FlightPlan() = default;
    FlightPlan(int ifplid, const std::string& adep, const std::string& ades, const std::string& arctyp,
               const std::string& eobt, const std::string& route, const std::string& rfl, const std::string& speed)
        : IFPLID(ifplid), ADEP(adep), ADES(ades), ARCTYP(arctyp), EOBT(eobt), ROUTE(route), RFL(rfl), SPEED(speed) {}
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE_WITH_DEFAULT( FlightPlan, IFPLID, ADEP, ADES, ARCTYP, EOBT, ROUTE, RFL, SPEED );

inline std::string to_json_string(const FlightPlan& fp)
{
    nlohmann::json json = fp;
    return json.dump();
}


#endif //VATSIMFDPS_FLIGHTPLAN_H