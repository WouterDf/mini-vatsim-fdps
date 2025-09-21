#include <iostream>
#include <thread>
#include <memory>
#include <curl/curl.h>
#include "VATSIMResource.h"

int main()
{
    auto VATSIMresource = std::make_unique<VATSIMResource>();

    while( true )
    {
        auto buffer = std::make_unique<std::string>(VATSIMresource->request());
        std::cout << "Ingest fetched " << buffer->size() << " bytes \n";
        std::this_thread::sleep_for(std::chrono::seconds(6));
    }
}
