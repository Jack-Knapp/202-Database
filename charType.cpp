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
#include "charType.h"
#include "myException.h"
#include "valueType.h"
using namespace std;

/*
 * charType : Default Constructor
 * parameters: Str
 * return value: N/A
 */
charType::charType(std::string str) {
    setValue(str);
}

/*
 * charType : Copy Constructor
 * parameters: charType Obj
 * return value: N/A
 */
charType::charType(const valueType& obj) {
    string str = obj.realValue();
    setValue(str);
}

/*
 * isCharType : Tests if obj is char
 * parameters: N/A
 * return value: Bool based on results
 */
bool charType::isCharType() const {
    string str = realValue();
    return (str.size() > 1) ? false : true;
}

/*
 * toIntegerType : Converts Obj to IntType
 * parameters: N/A
 * return value: Throws Exception
 */
int charType::toIntegerType() throw (myException) {
    if (typeAsString() != "int") {
        std::string err = "ERROR: char cannot be converted to int!";
        throw myException(err);
    }
    return 0;
}

/*
 * toStringType : Converts Obj to StringType
 * parameters: N/A
 * return value: String of Obj
 */
std::string charType::toStringType() throw (myException) {
    string str = realValue();
    return str;  
}

/*
 * toCharType : Converts Obj to CharType
 * parameters: N/A
 * return value: Throws Exception or returns
 *    a char obj
 */
char charType::toCharType() throw (myException) {
    //initialize some vars
    string str = realValue();
    bool isChar = isCharType();
    
    //test whether obj is char
    if (!isChar||!isalpha(str[0])) {
        std::string err = "ERROR: '"+ toStringType();
        err += "' is not a character!";
        throw myException(err);
    }
    char myChar = str[0];
    return myChar;
}

/*
 * compare : Compare two objs to see
      which is larger
 * parameters: An obj of ValueType
 * return value: Throws exception or returns 
 *    a value based on the comparison
 */
int charType::compare(valueType& obj) {
    //test passed obj for valid type
    if (!obj.isCharType()) {
        std::string err = "ERROR: compare failed due to invalid type!";
        throw myException(err);
    }
    //test obj for valid type
    if (!isCharType()) {
        std::string err = "ERROR: '"+ toStringType();
        err += "' is not a character!";
        throw myException(err);
    }
    
    //cast passed obj to charType*
    valueType* vptr = &obj;
    charType* cptr = NULL;
    cptr = dynamic_cast<charType*>(vptr);

    //perform the comparison
    return (cptr->realValue() > realValue())? 1:
            (cptr->realValue() < realValue())? -1:
            (cptr->realValue() == realValue())? 0:0;
}

/*
 * equals : Compares two objs to see
 *    if they are the same
 * parameters: A valueType Obj
 * return value: Bool based on comparison
 */
bool charType::equals(valueType& obj) {
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
void charType::print() {
    cout << "charType: " <<toCharType() << std::endl;
}
