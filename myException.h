//
// Created by BEN CISNEROS.
//

#ifndef HW5_MYEXCEPTION_H
#define HW5_MYEXCEPTION_H

#include <iostream>
#include <string>

class myException {
public:
    myException(const char* msg);
    myException(const std::string& msg);
    std::string what() const;

private:
    std::string message;
};

#endif //HW5_MYEXCEPTION_H
