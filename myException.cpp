//
// Created by BEN CISNEROS.
//

#include "myException.h"

myException::myException(const char *msg): message(msg) {}

myException::myException(const std::string& msg): message(msg) {}

std::string myException::what() const {
    return message.c_str();
}