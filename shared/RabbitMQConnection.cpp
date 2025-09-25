//
// Created by Wouter Deferme on 24/09/2025.
//

#include "RabbitMQConnection.h"

#include <rmqt_simpleendpoint.h>
#include <rmqt_plaincredentials.h>
#include <rmqa_producer.h>

#include "FlightPlan.h"
#include "FlightState.h"

using namespace BloombergLP;

RabbitMQConnection::RabbitMQConnection(std::string address, int port, std::string username, std::string password)
{
    const std::string EXCHANGE_NAME("vatsim-fdps");
    const std::string QUEUE_NAME("vatsim-fdps-queue");

    hQueue = topology.addQueue( QUEUE_NAME );
    hExchange = topology.addExchange( EXCHANGE_NAME );
    topology.bind( hExchange, hQueue, DEFAULT_ROUTING_KEY );

    auto hostInfo = bsl::make_shared<rmqt::SimpleEndpoint>(
        address, "/", port);
    auto credentials = bsl::make_shared<rmqt::PlainCredentials>(
        username, password);

    vhost = context.createVHostConnection( "connection", hostInfo, credentials);
    const uint16_t macOutstandingConfirms = 10;
    auto producerResult = vhost->createProducer( topology, hExchange, macOutstandingConfirms);

    if (! producerResult)
    {
        std::cout << "Error creating producer" << std::endl;
        return;
    }

    producer = producerResult.value();

    std::cout << "Created a producer" << std::endl;
}

void RabbitMQConnection::publish( FlightPlan flight_plan )
{
    std::string json = to_json_string(flight_plan);
    publish( json );
}

void RabbitMQConnection::publish( FlightState flight_state )
{
    std::string json = to_json_string(flight_state);
    publish( json );
}

void RabbitMQConnection::createConsumer(rmqp::Consumer::ConsumerFunc consumer_func)
{
    auto consumerResult = vhost->createConsumer( topology, hQueue, consumer_func, "label", 500 );
    if (!consumerResult)
    {
        std::cout << "Error creating consumer" << std::endl;
        return;
    }
    consumer = consumerResult.value();
}

void RabbitMQConnection::publish( std::string message_string )
{
    rmqt::Message message(bsl::make_shared<bsl::vector<uint8_t>>(message_string.cbegin(), message_string.cend()));

    auto callback = [](const rmqt::Message&, const bsl::string&, const rmqt::ConfirmResponse&) {
        // Empty callback - message sent
    };

    const rmqp::Producer::SendStatus result = producer->send(message, DEFAULT_ROUTING_KEY, callback);
    if (result != rmqp::Producer::SENDING)
    {
        std::cout << "Unable to enqueue message" << std::endl;
    }
}
