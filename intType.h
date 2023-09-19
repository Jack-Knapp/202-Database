//
// Created by BEN CISNEROS.
//

#ifndef HW5_INTTYPE_H
#define HW5_INTTYPE_H

#include <sstream>

#include "valueType.h"

// A class that represents an integer value
class intType: virtual public valueType {
public:
    intType(std::string = "");
    intType(const valueType&);

    bool isIntegerType() const;

    int toIntegerType() throw (myException);
    std::string toStringType() throw (myException);
    char toCharType() throw (myException);
    int compare(valueType&);

    bool equals(valueType&);
    void print();
};

#endif //HW5_INTTYPE_H
