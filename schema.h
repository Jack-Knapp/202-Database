//
// Created by OSWALDO CISNEROS on 2/14/23.
//

#ifndef HW5_SCHEMA_H
#define HW5_SCHEMA_H

#include "record.h"

// A class that represents a relation in the database
class schema {
public:
    schema(std::string);            // creates a schema object. This constructor makes use of a
                                    // name (which is used to refer to this schema in the database),
                                    // and should allocate memory for a record of attributes
                                    // whose type must be of valueType (see record::type)
    ~schema();                      // the destructor should deallocate the array of attributes
    void setName(std::string);      // sets the name of this schema
    std::string getName() const;    // returns the name of this schema
    record* getAttributes() const;  // returns the attributes of this schema
    int countAttributes() const;    // returns the total count of attributes in the schema
    void insertAttribute(valueType*);   // inserts an attribute in the specified symbol column
    bool isEmpty() const;           // returns true if the schema is empty, otherwise it should
                                    // return false
    void print() const;             // displays the contents of a relation

private:
    std::string name;       // name of the schema
    record* attrs;          // name of each column in the schema
};


#endif //HW5_SCHEMA_H
