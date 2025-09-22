//
// Created by Wouter Deferme on 22/09/2025.
//

#ifndef VATSIMMETADATA_H
#define VATSIMMETADATA_H

#include <nlohmann/json.hpp>
#include <string>

struct VATSIMMetadata
{
    int version;
    int unique_users;
    int connected_clients;
    std::string update_timestamp;
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE_WITH_DEFAULT( VATSIMMetadata, version, unique_users, connected_clients, update_timestamp );

#endif //VATSIMMETADATA_H
