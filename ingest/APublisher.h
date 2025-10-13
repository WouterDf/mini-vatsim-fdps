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
  APublisher(const APublisher &) = default;
  APublisher(APublisher &&) = delete;
  APublisher &operator=(const APublisher &) = delete;
  APublisher &operator=(APublisher &&) = delete;
  APublisher(const std::string &address) : address(address) {}
  virtual ~APublisher() = default;
  virtual void publish(const FlightPlan &flight_plan) = 0;
  virtual void publish(const FlightState &flight_state) = 0;
private:
    std::string address;
};


#endif //VATSIMFDPS_APUBLISHER_H
