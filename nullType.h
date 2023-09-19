//
// Created by BEN CISNEROS.
//

#ifndef HW5_NULLTYPE_H
#define HW5_NULLTYPE_H

#include "charType.h"
#include "intType.h"
#include "stringType.h"

// A class that represents a null value
class nullType: public charType, intType, stringType {
public:
    nullType(std::string = "");
    nullType(const valueType&);

    bool isNullType() const;

    int toIntegerType() throw (myException);
    std::string toStringType() throw (myException);
    char toCharType() throw (myException);
    int compare(valueType&);
    bool equals(valueType&);
    void print();
};

#endif //HW5_NULLTYPE_H
