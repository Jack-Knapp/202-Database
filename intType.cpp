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
#include "intType.h"
#include "myException.h"
#include "valueType.h"
using namespace std;

/*
 * intType : Default Constructor
 * parameters: N/A
 * return value: N/A
 */
intType::intType(string str) {
    setValue(str);
}

/*
 * intType : Copy Constructor
 * parameters: intType Obj
 * return value: N/A
 */
intType::intType(const valueType& obj) {
    string str = obj.realValue();
    setValue(str);
}

/*
 * isIntegerType : Test if obj is intType 
 * parameters: N/A
 * return value: Bool based on function
 */
bool intType::isIntegerType() const {
    return true;
}

/*
 * to IntegerType : Convert Obj to intType
 * parameters: N/A
 * return value: String of obj or throws exception
 */
int intType::toIntegerType() throw (myException){
    string str = realValue();
    //test if each char is an int
    for (int i=0; i<str.size(); i++) {
        if (str[i] > 47 && str[i] < 58) {
            continue;
        }
        throw myException("ERROR: value is not a integer");
    }
    return stoi(str);    
}

/*
 * toStringType : Convert Obj to stringType
 * parameters: N/A
 * return value: String of obj
 */
std::string intType::toStringType() throw (myException) {
    string str = realValue();
    return str;  
}

/*
 * toCharType : Convert Obj to CharType
 * parameters: N/A
 * return value: Throws exception
 */
char intType::toCharType() throw (myException) {
    if (typeAsString() != "char") {
        throw myException("ERROR: integer cannot be converted to char!");
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
int intType::compare(valueType& obj) {
    //test for type
    if (obj.typeAsString() != "int") {
        throw myException("ERROR: value is not a integer");    
    } 

    //cast passed obj to intType*
    valueType* vptr = &obj;
    intType* iptr = NULL;
    iptr = dynamic_cast<intType*>(vptr);

    //compare objs
    return (stoi(iptr->realValue()) > stoi(realValue()))? 1:
            (stoi(iptr->realValue()) > stoi(realValue()))? -1:
            (stoi(iptr->realValue()) > stoi(realValue()))? 0:0;
}

/*
 * equals : Compare two objs to see
      if they are the same
 * parameters: An obj of ValueType
 * return value: Bool based on results
 */
bool intType::equals(valueType& obj) {
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
void intType::print() {
    cout << "intType: " <<toIntegerType() << std::endl;
}