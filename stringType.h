//
// Created by BEN CISNEROS.
//

#ifndef HW5_STRINGTYPE_H
#define HW5_STRINGTYPE_H

#include <sstream>

#include "valueType.h"

// A class that represents a string value
class stringType: virtual public valueType {
public:
    stringType(std::string = "");
    stringType(const valueType&);

    bool isStringType() const;

    int toIntegerType() throw (myException);
    std::string toStringType() throw (myException);
    char toCharType() throw (myException);
    int compare(valueType&);
    bool equals(valueType&);
    void print();
};

#endif //HW5_STRINGTYPE_H
