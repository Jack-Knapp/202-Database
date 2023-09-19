//
// Created by BEN CISNEROS.
//

#ifndef HW5_CHARTYPE_H
#define HW5_CHARTYPE_H

#include "valueType.h"

// A class that represents a char value
class charType: virtual public valueType {
public:
    charType(std::string = "");
    charType(const valueType&);

    bool isCharType() const;

    int toIntegerType() throw (myException);
    std::string toStringType() throw (myException);
    char toCharType() throw (myException);
    int compare(valueType&);
    bool equals(valueType&);
    void print();
};

#endif //HW5_CHARTYPE_H
