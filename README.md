# Mini VATSIM FDPS

A C++ application that fetches real-time aviation data from VATSIM and distributes it through a message queue system, simulating a Flight Data Processing System (FDPS) architecture.

## Overview

This project demonstrates modern C++ development practices by implementing a distributed system that:
- Ingests live flight data from the VATSIM network API
- Transforms VATSIM data into standardized flight plan and flight state formats
- Publishes messages to RabbitMQ for downstream processing
- Provides a consumer service for real-time data processing

## Architecture

- **Ingest Service**: Fetches VATSIM data and publishes to message queues
- **Core Service**: Consumes and processes flight state messages
- **Shared Library**: Common data structures and message handling utilities

## Technologies Used

- **C++17**: Modern C++ features, RAII, smart pointers, and STL containers
- **RabbitMQ**: AMQP message broker using Bloomberg's rmqcpp library
- **nlohmann/json**: JSON parsing and serialization
- **CURL**: HTTP client for VATSIM API integration
- **CMake**: Build system with vcpkg package management

## Key Features

- Real-time data ingestion from VATSIM API
- Message-driven architecture with RabbitMQ and ZeroMQ
- ADEXP-inspired flight plan data structures
- Modular design with shared libraries
- Error handling and resource management

## Project Purpose

This project was developed to demonstrate proficiency in:
- Modern C++ development practices
- Distributed system design patterns
- Message queue integration (AMQP/ZeroMQ)
- API integration and data transformation
- CMake build configuration