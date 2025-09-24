//
// Created by Wouter Deferme on 24/09/2025.
//

#ifndef VATSIMFDPS_APUBLISHER_H
#define VATSIMFDPS_APUBLISHER_H
#include <string>


struct FlightState;
struct FlightPlan;

class APublisher
{
public:
    APublisher(std::string address) : address( address ){};
    virtual void publish(FlightPlan flight_plan) = 0;
    virtual void publish(FlightState flight_state) = 0;
private:
    std::string address;
};


#endif //VATSIMFDPS_APUBLISHER_H