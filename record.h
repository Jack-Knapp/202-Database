//
// Created by BEN CISNEROS.
//

#ifndef HW5_RECORD_H
#define HW5_RECORD_H

#include <cstdlib>

#include "valueType.h"
#include "myException.h"

class record {
public:
    static const int MAX_LEN = 20;

    // a wrapper that represents the type of values stored in a record
    enum type { CHAR_TYPE, INT_TYPE, STRING_TYPE, NULL_TYPE, VALUE_TYPE };

    static type toType(const std::string&);     // a static function that returns a type (see enum) from a
                                                // string that contains a sequence of characters which
                                                // represent one of the value's type (such as char, int,
                                                // string, null, or value)
    record();                                   // default constructor used to initialize the attributes
                                                // of this class with default values (name to "", values
                                                // to nullptr, size and count to 0, and type to value type)
    record(type, std::string = "", int = 16);   // creates a new default record object. This constructor
                                                // makes use of the arguments to initialize each attribute
                                                // of the record. If the size is less than or equal to 0,
                                                // an error message should be thrown
    ~record();                                   // the destructor should delete the memory allocated for the
                                                // the array of pointers to record objects and should also
                                                // set the values of the remaining attributes, for example,
                                                // size and count should be set to 0 and name to ""
    void insert(valueType*);        // inserts an entry into the record. If the count of record entries
                                    // exceeds the record size, the record must be expanded via the private
                                    // resize function before the new value is added to the record
    void insert(valueType*, int);   // inserts an entry at the specified location into the
                                    // record and increments the count of values currently
                                    // stored in the record. The record should be resized as
                                    // necessary to accommodate the new entry. Note that the
                                    // values following the specified position should be
                                    // shifted right to make room for the new value. Also,
                                    // the record capacity should be increased if the size
                                    // exceeds the maximum capacity
    valueType* at(int) const throw (myException);   // returns the entry at the specified location or throws
                                    // an exception if the index is less than 0 or greater than count
    int indexOf(valueType*) const;  // returns the position of a given value in the record, otherwise
                                    // returns -1 if the value does not exist
    void remove();                  // removes the last element from the record
    void removeAt(int);             // removes a value at the specified position from the record
                                    // and decrements the count of values stored in the record
    int countEntries() const;       // returns the total count of values in the record
    void print() const;             // prints the values stored in the record. Each entry should
                                    // make use of the toStringType function to get a string that
                                    // represents the actual value of the entry
    void swap(valueType*, valueType*);      // swaps the values of two different entries. This function
                                            // must check if the record is empty, and then make use of
                                            // the function contains to search for the entry before
                                            // swapping the values of such entry. Note that reinterpret
                                            // cast should be used to cast before comparing val1 with
                                            // val2 for equality (hint: use the equals function)
                                            // Additionally, the function should throw an error message
                                            // if one of the values does not exist in the record
    bool contains(const valueType*) const throw (myException);      // returns true if the entry is in the record
    bool isEmpty() const;           // returns true if the record is empty, otherwise it should
                                    // return false
    bool isFull() const;            // returns true if the record is full, otherwise it should
                                    // return false
    bool equals(const record&) const;   // returns true if two records are equal. Equality is defined
                                        // as having the same type, same name, same size, and the same
                                        // number of values. In addition, the values that belong to
                                        // each of the record must be compare one by one (hint: use
                                        // reinterpret cast)
    type getType() const;               // returns the type of this record
    std::string getName() const;        // returns the name of this record

private:
    void resize();          // creates a new record twice the size of the existing record,
                            // copies all entries from the current record into the new record,
                            // and then deletes the old record. The record size should be
                            // updated accordingly
    bool checkType(valueType*) const;   // checks that the type of value being added is the same as
                                        // the type of the record. The enum type should be used when
                                        // comparing types

    std::string name;       // the attribute field for a record
    valueType** values;     // array of pointers to abstract values
    int size;               // the initial size of the record
    int count;              // number of count values stored in the record
    type kind;              // the type of values stored in the record
};

#endif //HW5_RECORD_H
