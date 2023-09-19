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

//
// Created by OSWALDO CISNEROS on 2/14/23.
//

//includes
#include "schema.h"

/*
 * schema : Default Constructor
 * parameters: str of name
 * return value: N/A
 */
schema::schema(std::string scName) {
    name = scName;
    attrs = new record(record::type::VALUE_TYPE, "name");
}   

/*
 * ~schema : Destructor
 * parameters: N/A
 * return value: N/A
 */
schema::~schema() {
    delete attrs;
    attrs = nullptr;
}   

/*
 * setName : Change schema name
 * parameters: str of new name
 * return value: N/A
 */
void schema::setName(std::string newName) {
    name = newName;
}

/*
 * getName : gets schema name
 * parameters: N/A
 * return value: str of name
 */
std::string schema::getName() const {
    return name;
}

/*
 * getAttributes : gets attributes
 * parameters: N/A
 * return value: record* of attributes
 */
record* schema::getAttributes() const {
    return attrs;
}

/*
 * countAttributes : gets count of entries
 * parameters: N/A
 * return value: int of count
 */
int schema::countAttributes() const {
    int count = attrs->countEntries();
    return count;
}   

/*
 * insertAttribute : Adds attribute to schema
 * parameters: valueType Obj to add to schema
 * return value: N/A
 */
void schema::insertAttribute(valueType* obj) {
    attrs->insert(obj);
}

/*
 * isEmpty : Checks if schema is empty
 * parameters: N/A
 * return value: Bool based on results
 */
bool schema::isEmpty() const {
    return attrs->isEmpty();
}

/*
 * print : Outputs schema to terminal
 * parameters: N/A
 * return value: N/A
 */
void schema::print() const {
    std::cout << "+" << std::string(record::MAX_LEN, '-') << "+"
              << std::string(record::MAX_LEN, '-') << "+" << std::endl;
    int diff = abs(record::MAX_LEN - static_cast<int>(attrs->getName().size()));
    std::cout << "|" << attrs->getName() << std::string(diff, ' ') << "|";
    diff = abs(record::MAX_LEN - static_cast<int>(std::string("type").size()));
    std::cout << "type" << std::string(diff, ' ') << "|" << std::endl;
    std::cout << "+" << std::string(record::MAX_LEN, '-') << "+"
              << std::string(record::MAX_LEN, '-') << "+" << std::endl;
    int count = attrs->countEntries();
    for (int i = 0; i < count; ++i) {
        std::string str = attrs->at(i)->toStringType();
        diff = abs(record::MAX_LEN - static_cast<int>(str.size()));
        std::cout << "|" << str << std::string(diff, ' ') << "|";
        str = attrs->at(i)->typeAsString();
        diff = abs(record::MAX_LEN - static_cast<int>(str.size()));
        std::cout << str << std::string(diff, ' ') << "|" << std::endl;
    }
    std::cout << "+" << std::string(record::MAX_LEN, '-') << "+"
              << std::string(record::MAX_LEN, '-') << "+" << std::endl;
}