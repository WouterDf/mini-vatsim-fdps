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

## Building the Project

### Prerequisites

- C++17 compatible compiler (GCC 9+, Clang 10+, or MSVC 2019+)
- CMake 3.30+
- vcpkg package manager
- RabbitMQ server (for runtime)

### Setup

1. **Clone the repository**
   ```bash
   git clone <repository-url>
   cd vatsimfdps
   ```

2. **Install vcpkg** (if not already installed)
   ```bash
   git clone https://github.com/Microsoft/vcpkg.git
   cd vcpkg
   ./bootstrap-vcpkg.sh  # or bootstrap-vcpkg.bat on Windows
   ./vcpkg integrate install
   ```

3. **Configure CMake with vcpkg**
   ```bash
   mkdir build
   cd build
   cmake .. -DCMAKE_TOOLCHAIN_FILE=[path-to-vcpkg]/scripts/buildsystems/vcpkg.cmake
   ```

4. **Build the project**
   ```bash
   make -j$(nproc)  # or cmake --build . --parallel on Windows
   ```

### Dependencies

The following packages are automatically managed by vcpkg:
- `curl` - HTTP client library
- `nlohmann-json` - JSON parsing
- `cppzmq` - ZeroMQ C++ bindings
- `rmqcpp` - Bloomberg RabbitMQ C++ library

### Running

1. **Start RabbitMQ server**
   ```bash
   docker run -d --name rabbitmq -p 5672:5672 -p 15672:15672 rabbitmq:3-management
   ```

2. **Run the ingest service**
   ```bash
   ./ingest/ingest
   ```

3. **Run the core service**
   ```bash
   ./core/core
   ```

## Project Purpose

This project was developed to demonstrate proficiency in:
- Modern C++ development practices
- Distributed system design patterns
- Message queue integration (AMQP/ZeroMQ)
- API integration and data transformation
- CMake build configuration