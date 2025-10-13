//
// Created by Wouter Deferme on 20/09/2025.
//

#ifndef VATSIMRESOURCE_H
#define VATSIMRESOURCE_H
#include <curl/curl.h>
#include <string>


struct VATSIMResponse;

class VATSIMResource {
public:
    VATSIMResource();
    VATSIMResource(const VATSIMResource &) = default;
    VATSIMResource(VATSIMResource &&) = delete;
    VATSIMResource &operator=(const VATSIMResource &) = delete;
    VATSIMResource &operator=(VATSIMResource &&) = delete;
    VATSIMResponse request();
    ~VATSIMResource();
private:
    CURL* hCurl;
    std::string strBuffer;
    static size_t write_data(void *buffer, size_t size, size_t nmemb, std::string* out);
};

#endif //VATSIMRESOURCE_H
