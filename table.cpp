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
// Created by BEN CISNEROS.
//

//includes
#include "table.h"

/*
 * table : Default Constructor
 * parameters: str of name, ptr to schema
 * return value: N/A
 */
table::table(const std::string& tabName, schema* scheme) {
    //set member vars
    name = tabName;
    count = scheme->countAttributes();
    //create dynamic array of records
    columns = new record*[count];
    //for each column, find the name and type from schema
    //then use those to create an appropriate record
    for (int i=0; i<count; i++) {   
        std::string atName = scheme->getAttributes()->at(i)->toStringType();  
        record::type atType = record::toType(scheme->getAttributes()->at(i)->typeAsString()); 
        columns[i] =  new record(atType, atName);
    }
}   

/*
 * ~table : Destructor
 * parameters: N/A
 * return value: N/A
 */
table::~table() {
    //delete all dynamically allocated mem
    for (int i=0; i<count; i++) {
        delete columns[i];
    }
    delete[] columns;
    count = 0;
    name = "";
}   

/*
 * getName : name getter
 * parameters: N/A
 * return value: str of name
 */
std::string table::getName() const {
    return name;
}

/*
 * countEntries : count getter
 * parameters: N/A
 * return value: int of count
 */
int table::countEntries() const {
    return count;
}   

/*
 * insert: Inserts values into a table
 * parameters: str of column name and 
 *     valueType* value of data to insert
 * return value: N/A
 */
void table::insert(const std::string& colName, valueType* value) throw (myException) {
    //find appropriate column
    for (int i=0; i<count; i++) {
        if (colName != columns[i]->getName()) {
            continue;
        }
        //insert the data
        columns[i]->insert(value);
        break;
    }
}   

/*
 * at : Gets record* of an index
 * parameters: int index of column
 * return value: record* to column at index
 */
record* table::at(int index) const throw (myException) {
    if (index < 0 || index > count) {
        throw myException("ERROR: Invalid Index");
    }
    return columns[index];
}  

/*
 * remove : removes an entry, deletes memory,
 *    and shifts values down to fill empty index
 * parameters: str of column name
 * return value: N/A
 */
void table::remove(const std::string& colName) {
    //get address of column
    int index = indexOf(colName);
    record* pHolder = columns[index];
    //shift columns
    for (int i=index; i < count-1; i++) {
        columns[i] = columns[i+1];   
    }
    //move column to end and delete memory
    columns[count-1] = pHolder;
    delete columns[count-1];
    columns[count-1] = nullptr;
    count--;
}   

/*
 * indexOf : gets index of given column
 * parameters: str of column name
 * return value: Index of column as int
 */
int table::indexOf(const std::string& colName)  const {
    //loop to find a match and return index
    for (int i=0; i<count; i++) {
        if (colName != columns[i]->getName()) {
            return i;
        }
        return -1;
    }
    return 0;
}  

/*
 * print : Outputs table to terminal
 * parameters: N/A
 * return value: N/A
 */                              
void table::print() const {
    int diff = 0;
    std::cout << "+";
    for (int i = 0; i < count; ++i)
        std::cout << std::string(record::MAX_LEN, '-') << "+";
    std::cout << std::endl << "|";
    for (int i = 0; i < count; ++i) {
        diff = abs(record::MAX_LEN - static_cast<int>(columns[i]->getName().size()));
        std::cout << columns[i]->getName() << std::string(diff, ' ') << "|";
    }
    std::cout << std::endl << "+";
    for (int i = 0; i < count; ++i)
        std::cout << std::string(record::MAX_LEN, '-') << "+";
    std::cout << std::endl;
    int cols = columns[0]->countEntries();
    for (int i = 0; i < cols; ++i) {
        std::cout << "|";
        for (int j = 0; j < count; ++j) {
            std::string s = columns[j]->at(i)->realValue();
            diff = abs(record::MAX_LEN - static_cast<int>(s.size()));
            std::cout << s << std::string(diff, ' ') << "|";
        }
        std::cout << std::endl;
    }
    std::cout << "+";
    for (int i = 0; i < count; ++i)
        std::cout << std::string(record::MAX_LEN, '-') << "+";
    std::cout << std::endl;
}   

/*
 * resize : resizes the table if it gets full
 * parameters: N/A
 * return value: N/A
 */                    
void table::resize() {
    //allocate a new temp record** 2x the size
    record** newArr = new record*[count*2];
        //Initialize the allocated array
        for (int i=0; i<count*2; i++) {
            newArr[i] = nullptr;
        }
		//deep copy old array to new one
		for (int i=0; i<count; i++) {
			newArr[i] = columns[i];
		}
		delete []columns; //delete old arr

		//shallow copy new array
		//and set copy array to null
		columns = newArr; 
		newArr = nullptr;

		count *= 2; //double array size
}   