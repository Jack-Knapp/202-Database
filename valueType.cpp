//
// Created by BEN CISNEROS.
//

#include "valueType.h"

valueType::valueType(std::string value) {
    this->value = value;
}

valueType::valueType(const valueType& other) {
    value = other.value;
}

valueType::~valueType() {}

bool valueType::isIntegerType() const {
    return false;
}

bool valueType::isStringType() const {
    return false;
}

bool valueType::isCharType() const {
    return false;
}

bool valueType::isNullType() const {
    return false;
}

void valueType::setValue(std::string value) {
    this->value = value;
}

std::string valueType::realValue() const {
    return value;
}

std::string valueType::typeAsString() {
    return isIntegerType()? "int" :
           isStringType()? "string" :
           isCharType()? "char" :
           isNullType()? "null" : "value";
}