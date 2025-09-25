//
// Created by Wouter Deferme on 25/09/2025.
//

#ifndef VATSIMFDPS_FLIGHTSTATECONSUMER_H
#define VATSIMFDPS_FLIGHTSTATECONSUMER_H
#include <rmqp_messageguard.h>
#include <rmqt_message.h>

class FlightStateConsumer
{
public:
    void operator()( BloombergLP::rmqp::MessageGuard& messageGuard);
private:
    bool processMessage(const BloombergLP::rmqt::Message& message);
};

#endif //VATSIMFDPS_FLIGHTSTATECONSUMER_H