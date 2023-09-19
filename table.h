//
// Created by BEN CISNEROS.
//

#ifndef HW5_TABLE_H
#define HW5_TABLE_H

#include "myException.h"
#include "record.h"
#include "schema.h"

// A class that represent a table used to store data in a relational
// database. It contains a header row at the top of the table which
// gives the list of columns names, followed by rows of data
class table {
public:
    table(const std::string&, schema*);     // default constructor used to initialize the attributes
                                            // of this class with default values. Note that the reference
                                            // to a schema object should be used to create each column
                                            // of the table
    ~table();           // the destructor should deallocate the array of pointers to
                        // record objects and set count to 0 and name to ""
    std::string getName() const;    // returns the name of this table
    int countEntries() const;       // returns the total count of data in the table
    void insert(const std::string&, valueType*) throw (myException);    // inserts an entry at the specified column in
                                                    // the dynamic array of columns and increments the count of
                                                    // values currently stored in the array. The array should
                                                    // be resized as necessary to accommodate the new entry.
                                                    // Note that the values following the specified position
                                                    // should be shifted right to make room for the new value.
                                                    // Also, the record capacity should be increased if the
                                                    // size exceeds the maximum capacity
    record* at(int) const throw (myException);  // returns the column at the specified position in the table
                                            // or throws an exception if the position is less than 0 or
                                            // greater than count
    void remove(const std::string&);        // removes a column at the specified position from the table
                                            // and decrements the count of values stored in the table
    int indexOf(const std::string&) const;  // returns the position of a column with the specified
                                            // name, otherwise it should return -1
    void print() const;     // prints the values stored in the table. Each entry should
                            // make use of the toStringType function to get a string that
                            // represents the actual value of the entry
private:
    void resize();          // creates a new array of columns twice the size of the
                            // existing one, copies all entries from the current array
                            // into the new one, and then deletes the old one. The array
                            // size should be updated accordingly

    std::string name;   // the name of the table
    record** columns;   // the list of columns names in the table
    int count;          // the number of columns in the table
};


#endif //HW5_TABLE_H
