#ifndef VATSIMFDPS_FLIGHTSTATE_H
#define VATSIMFDPS_FLIGHTSTATE_H

struct FlightState
{
    int id;
    std::string callsign;
    float latitude;
    float longitude;
    int altitude;
    int heading;
    int groundspeed;
    std::string transponder;
    std::string last_updated;
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE_WITH_DEFAULT( FlightState, id, callsign, latitude,
    longitude, altitude, heading, groundspeed, transponder, last_updated );

#endif