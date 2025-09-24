//
// Created by Wouter Deferme on 23/09/2025.
//

#ifndef VATSIMFDPS_PUBLISHER_H
#define VATSIMFDPS_PUBLISHER_H
#include <zmq.hpp>

#include "APublisher.h"

struct FlightState;
struct FlightPlan;

class ZeroMQPublisher : public APublisher
{
public:
    ZeroMQPublisher(std::string address);
    void publish(FlightPlan flight_plan);
    void publish(FlightState flight_state);

private:
    zmq::context_t context;
    zmq::socket_t socket;
};


#endif //VATSIMFDPS_PUBLISHER_H