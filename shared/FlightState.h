#ifndef VATSIMFDPS_FLIGHTSTATE_H
#define VATSIMFDPS_FLIGHTSTATE_H

#include <string>
#include <nlohmann/json.hpp>

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

    FlightState() = default;
    FlightState(int id, const std::string& callsign, float lat, float lon, int alt, int hdg, int gs,
                const std::string& xpdr, const std::string& updated)
        : id(id), callsign(callsign), latitude(lat), longitude(lon), altitude(alt),
          heading(hdg), groundspeed(gs), transponder(xpdr), last_updated(updated) {}
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE_WITH_DEFAULT( FlightState, id, callsign, latitude,
    longitude, altitude, heading, groundspeed, transponder, last_updated );
inline std::string to_json_string(const FlightState& fs)
{
    nlohmann::json json = fs;
    return json.dump();
}

#endif