//
// Created by Wouter Deferme on 24/09/2025.
//

#ifndef VATSIMFDPS_RABBITMQPUBLISHER_H
#define VATSIMFDPS_RABBITMQPUBLISHER_H
#include "../ingest/APublisher.h"
#include <rmqa_rabbitcontext.h>

#include <rmqa_topology.h>

using namespace BloombergLP;

class RabbitMQConnection
{
public:

    RabbitMQConnection(std::string address, int port, std::string username, std::string password);
    void publish(FlightPlan flight_plan);
    void publish(FlightState flight_state);
    void createConsumer(rmqp::Consumer::ConsumerFunc consumer_func);
private:
    void publish(std::string message);

private:
    rmqa::RabbitContext context;
    rmqa::Topology topology;
    rmqt::QueueHandle hQueue;
    rmqt::ExchangeHandle hExchange;
    bsl::shared_ptr<rmqa::VHost> vhost;
    bsl::shared_ptr<rmqa::Producer> producer;
    bsl::shared_ptr<rmqa::Consumer> consumer;
    std::string DEFAULT_ROUTING_KEY = "";
};


#endif //VATSIMFDPS_RABBITMQPUBLISHER_H