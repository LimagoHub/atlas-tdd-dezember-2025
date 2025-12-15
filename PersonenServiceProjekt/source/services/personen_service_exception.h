//
// Created by JoachimWagner on 13.12.2022.
//

#pragma once


#include <exception>
#include <string>
class personen_service_exception : public std::exception
{
    char const* message;
    std::exception *nested;

public:
    personen_service_exception()
    {
        nested = nullptr;
    }


    personen_service_exception(char const* _Message)
            : message(_Message)
    {
        nested = nullptr;
    }


    personen_service_exception(exception const& _Other)
            : exception(_Other), nested(const_cast<exception *>(&_Other))
    {
    }
    personen_service_exception(char const* _Message,exception const& _Other)
            : exception(_Other), message(message), nested(const_cast<exception *>(&_Other))
    {
    }

    const char *what() const override {
        return message;
    }

    exception *getNested() const {
        return nested;
    }
};
