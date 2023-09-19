/*
Name: Jack Knapp, 202.5
Purpose: Pointer Math, Dynamic Mem Allocation, OOP
Description: Database w/ QueryLang
Input: Misc Query Commands
What to do?: Identify commands to create schemas and tables 
    in which the user can create and store data
Output: Create the database items per passed 
    commands and print data after each
    command is called by the user
*/

//includes
#include "nullType.h"
#include "charType.h"
#include "intType.h"
#include "stringType.h"
#include "myException.h"
using namespace std;

/*
 * nullType : Default Constructor
 * parameters: Str
 * return value: N/A
 */
nullType::nullType(std::string str) {
    setValue(str);
}

/*
 * nullType : Copy Constructor
 * parameters: nullType Obj
 * return value: N/A
 */
nullType::nullType(const valueType& obj) {
    string str = obj.realValue();
    setValue(str);
}

/*
 * isNullType : Tests if obj is null
 * parameters: N/A
 * return value: Bool based on results
 */
bool nullType::isNullType() const {
    return true;
}

/*
 * toIntegerType : Convert obj to IntegerType
 * parameters: N/A
 * return value: Throws exception
 */
int nullType::toIntegerType() throw (myException) {
    if (typeAsString() != "int") {
        throw myException("ERROR: value is not an integer");
    }
    return 0;
}

/*
 * toStringType : Converts obj to stringType
 * parameters: N/A
 * return value: Throws exception
 */
std::string nullType::toStringType() throw (myException) {
    if (typeAsString() != "string") {
        throw myException("ERROR: value is not a string");
    }
    return "";
}

/*
 * toCharType : Converts Obj to CharType
 * parameters: N/A
 * return value: Throws exception
 */
char nullType::toCharType() throw (myException) {
    if (typeAsString() != "char") {
        throw myException("ERROR: value is not a character");
    }
    return '\0';
}

/*
 * compare : Compare two objs to see
      which is larger
 * parameters: An obj of ValueType
 * return value: Throws exception or returns 
 *    a value based on the comparison
 */
int nullType::compare(valueType& obj) {
    //check passed obj type
    if (obj.typeAsString() != "null") {
        throw myException("ERROR: value is not null");
    } 
    
    //cast passed obj to nullType*
    nullType* nptr = NULL;
    nptr = dynamic_cast<nullType*>(nptr);
    return 0;
}

/*
 * equals : Compares two objs to see
 *    if they are the same
 * parameters: A valueType Obj
 * return value: Bool based on comparison
 */
bool nullType::equals(valueType& obj) {
    if (compare(obj)==0) {
        return true;
    }
    return false;
}

/*
 * print : Outputs obj to terminal
 * parameters: N/A
 * return value: N/A
 */
void nullType::print() {
    cout << "null\n";
}
