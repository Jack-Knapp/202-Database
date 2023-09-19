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
#include "valueType.h"
#include "myException.h"
#include "stringType.h"
using namespace std;

/*
 * stringType : Default Constructor
 * parameters: Str
 * return value: N/A
 */
stringType::stringType(std::string str) {
    setValue(str);
}

/*
 * stringType : Copy Constructor
 * parameters: stringType Obj
 * return value: N/A
 */
stringType::stringType(const valueType& obj) {
    string str = obj.realValue();
    setValue(str);
}

/*
 * isStringType : Tests if obj is stringType
 * parameters: N/A
 * return value: True
 */
bool stringType::isStringType() const {
    return true;
}

/*
 * toIntegerType : Converts obj to integerType
 * parameters: N/A
 * return value: Throws exception
 */
int stringType::toIntegerType() throw (myException){
    if (typeAsString() != "int") {
        throw myException("ERROR: string cannot be converted to int!");
    }
    return 0;
}

/*
 * toStringType : Converts obj to stringType
 * parameters: N/A
 * return value: Throws exception or 
 *     returns string of obj
 */
std::string stringType::toStringType() throw (myException){
    if (typeAsString() != "string") {
        throw myException("ERROR: value is not a string");
    }
    string str = realValue();
    return str;    
}

/*
 * toCharType : Converts obj to charType
 * parameters: N/A
 * return value: Throws exception
 */
char stringType::toCharType() throw (myException) {
    if (typeAsString() != "char") {
        throw myException("ERROR: string cannot be converted to char!");
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
int stringType::compare(valueType& obj) {
    //test passed obj for valid type
    if (obj.typeAsString() != "string") {
        throw myException("ERROR: value is not a string");
    } 

    //cast passed obj to stringType*
    valueType* vptr = &obj;
    stringType* sptr = NULL;
    sptr = dynamic_cast<stringType*>(vptr);

    //perform the comparison
    return (sptr->realValue() > realValue())? 1:
            (sptr->realValue() < realValue())? -1:
            (sptr->realValue() == realValue())? 0:0;
}

/*
 * equals : Compares two objs to see
 *    if they are the same
 * parameters: A valueType Obj
 * return value: Bool based on comparison
 */
bool stringType::equals(valueType& obj) {
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
void stringType::print() {
    cout << "stringType: " <<toStringType() << std::endl;
}
