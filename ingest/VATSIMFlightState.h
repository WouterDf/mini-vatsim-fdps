//
// Created by Wouter Deferme on 23/09/2025.
//

#ifndef VATSIMFDPS_VATSIMFLIGHTSTATE_H
#define VATSIMFDPS_VATSIMFLIGHTSTATE_H
#include <nlohmann/json.hpp>

#include "FlightState.h"

struct VATSIMFlightState
{
    int cid;
    std::string callsign;
    float latitude;
    float longitude;
    int altitude;
    int heading;
    int groundspeed;
    std::string transponder;
    std::string last_updated;

public:
    FlightState toStandardFlightState()
    {
        return FlightState(cid, callsign, latitude, longitude, altitude, heading, groundspeed, transponder, last_updated);
    }
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE_WITH_DEFAULT( VATSIMFlightState, cid, callsign, latitude,
    longitude, altitude, heading, groundspeed, transponder, last_updated );

#endif //VATSIMFDPS_VATSIMFLIGHTSTATE_H