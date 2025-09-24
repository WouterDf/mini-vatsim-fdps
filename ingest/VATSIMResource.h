//
// Created by Wouter Deferme on 20/09/2025.
//

#ifndef VATSIMRESOURCE_H
#define VATSIMRESOURCE_H
#include <string>
#include <curl/curl.h>


struct VATSIMResponse;

class VATSIMResource {
public:
    VATSIMResource();
    VATSIMResponse request();
    ~VATSIMResource();
private:
    CURL* hCurl;
    std::string strBuffer;
    static size_t write_data(void *buffer, size_t size, size_t nmemb, std::string* out);
};

#endif //VATSIMRESOURCE_H
