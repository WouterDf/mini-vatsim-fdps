//
// Created by Wouter Deferme on 20/09/2025.
//

#include "VATSIMResource.h"

#include <print>

VATSIMResource::VATSIMResource()
{
    hCurl = curl_easy_init();
    curl_easy_setopt( hCurl, CURLOPT_URL, "https://data.vatsim.net/v3/vatsim-data.json" );
    curl_easy_setopt( hCurl, CURLOPT_WRITEFUNCTION, write_data );
    curl_easy_setopt( hCurl, CURLOPT_WRITEDATA, &strBuffer );
}

std::string VATSIMResource::request()
{
    strBuffer.clear();
    curl_easy_perform( hCurl );
    return std::move(strBuffer);
}

VATSIMResource::~VATSIMResource()
{
    curl_easy_cleanup( hCurl );
}

size_t VATSIMResource::write_data( void *buffer, size_t size, size_t nmemb, std::string *out )
{
    size_t total = size * nmemb;
    out->append((char*)buffer, total);
    return total;
}
