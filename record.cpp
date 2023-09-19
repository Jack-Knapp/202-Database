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
#include "record.h"

/*
 * toType : converts a string to a type name
 * parameters: str of a type
 * return value: corresponding type value
 */
record::type record::toType(const std::string& name) {
    if (name == "char")
        return record::type::CHAR_TYPE;
    if (name == "int")
        return record::type::INT_TYPE;
    if (name == "string")
        return record::type::STRING_TYPE;
    if (name == "null")
        return record::type::NULL_TYPE;
    return record::type::VALUE_TYPE;    
}

/*
 * record : default constructor
 * parameters: N/A
 * return value: N/A
 */
record::record() {
    name = "";
    size = 16;
    //dynamically allocate array of vtype and initialize it
    values = new valueType*[size];
        for (int i=0; i < size; i++) {
            values[i] = nullptr;
        }
    count = 0;
    kind = VALUE_TYPE;
}

/*
 * record : parameterized constructor
 * parameters: type, str of name, int of size
 * return value: N/A
 */
record::record(type initType, std::string str, int num) {
    name = str;
    //num error checking
    if (num <= 0) {
        std::cout << "ERROR: INVALID RECORD SIZE\n";
        values = nullptr;
    }
    //dynamically allocate array of vtype and initialize it
    else {
        size = num; 
        values = new valueType*[size];
        for (int i=0; i < size; i++) {
            values[i] = nullptr;
        }
    }    
    count = 0;
    kind = initType;
} 

/*
 * ~record : destructor
 * parameters: N/A
 * return value: N/A
 */
record::~record() {
    //delete dynamically allocated memory
    for (int i=0; i<size; i++) {
        delete values[i];
    }
    delete[] values;
    values = nullptr;
    name = "";
    size = 0;
    count = 0;
    kind = VALUE_TYPE;
}                              

/*
 * insert : insert data into record
 * parameters: valueType* of object to insert
 * return value: N/A
 */
void record::insert(valueType* vptr) {
    //type checking
    if (!checkType(vptr)) {
        std::cout << "ERROR: value's type is "
        <<"not compatible with the record!\n";    
        delete vptr;
    }
    //resize and/or insert
    else {
        if (count <= size && values[count]==nullptr) {
            values[count] = vptr;
        }
        else {
            resize();
            values[count] = vptr;
        }
        count++;
    }
}

/*
 * insert : insert data into record at index
 * parameters: valueType* of object to insert,
 *     int of index to insert at
 * return value: N/A
 */
void record::insert(valueType* vptr, int index) {
    //resize if needed
    if (isFull()) {
        resize();
    }
    //shift data and insert value
    for (int i= size-1; i >= index; i--) {
        if (values[i] != nullptr) {
            values[i+1] = values[i];
        } 
    }
    values[index] = vptr;
    count++;
}  

/*
 * at : get pointer to value at index
 * parameters: int index to search for
 * return value: valueType* to value at index
 */
valueType* record::at(int index) const throw (myException) {
    //throw exception if index invalid
    if (index < 0 || index > count) {
        throw myException("ERROR: Invalid Index");
    }
    //return valueType*
    return values[index];
}  

/*
 * indexOf : find object at given index
 * parameters: valueType* of object to find
 * return value: index of given obj
 */
int record::indexOf(valueType* vptr) const {
    //loop to find object
    for (int i=0; i<size; i++) {
        if (values[i]->equals(*vptr)) {
            return i;
        }
    }
    return -1;
}  

/*
 * remove : remove last object in record
 * parameters: N/A
 * return value: N/A
 */
void record::remove() {
    //delete mem and decrement counters
    delete values[count-1];
    values[count-1] = nullptr;
    count--;
    size--;
}  

/*
 * removeAt : remove object at given index
 * parameters: int index of obj to remove
 * return value: N/A
 */
void record::removeAt(int index) {
    //move index to placeholder
    valueType* pHolder = values[index];
    //shift values
    for (int i=index; i < size-1; i++) {
        values[i] = values[i+1];   
    }
    //put placeholder at end, delete and decrement
    values[size-1] = pHolder;
    delete values[size-1];
    values[size-1] = nullptr;
    count--;
    size--;
}  

/*
 * countEntries : count getter
 * parameters: N/A
 * return value: int of count
 */
int record::countEntries() const {
    return count;
}  

/*
 * print : Outputs table to terminal
 * parameters: N/A
 * return value: N/A
 */     
void record::print() const {
    int diff = abs(MAX_LEN - static_cast<int>(name.size()));
    std::cout << "+" << std::string(MAX_LEN, '-') << "+" << std::endl;
    std::cout << "|" << name << std::string(diff, ' ') << "|" << std::endl;
    std::cout << "|" << std::string(MAX_LEN, '-') << "|" << std::endl;
    for (int i = 0; i < count; ++i) {
        const std::string s = values[i]->toStringType();
        diff = abs(MAX_LEN - static_cast<int>(s.size()));
        std::cout << "|" << s << std::string(diff, ' ') << "|" << std::endl;
    }
    std::cout << "+" << std::string(MAX_LEN, '-') << "+" << std::endl;
}   

/*
 * swap : swaps two given objects
 * parameters: two valuetype*s to be swapped
 * return value: N/A
 */     
void record::swap(valueType* obj1, valueType* obj2) {
    //check that record has values and 
    //that passed objs are in record
    if (!isEmpty() && contains(obj1) && contains(obj2)) {
        //check that objs are not identical
        if (!obj1->equals(*obj2)) {
            //perform the swap
            int index1 = indexOf(obj1);
            int index2 = indexOf(obj2);
            valueType* pHolder = values[index1];
            values[index1] =  values[index2];
            values[index2] = pHolder;
        }
    }
}  

/*
 * contains : Finds if value is in record
 * parameters: valueType* obj to find
 * return value: Bool of the results
 */     
bool record::contains(const valueType* obj) const throw (myException) {
    for (int i=0; i<count; i++) {
        //if (obj->equals(*values[i])) {
        
        if (values[i]!=nullptr) {
            if (values[i]->realValue() == obj->realValue()) {
                return true;
            }
        }  
    }
    throw myException("Error: Value not Found");
} 

/*
 * isEmpty : checks whether record is empty
 * parameters: N/A
 * return value: Bool of the results
 */     
bool record::isEmpty() const {
    //loop to check for data
    for (int i=0; i<size; i++) {
        if (values[i] != nullptr) {
            return false;
        }
    }
    return true;
}  

/*
 * isFull : checks whether record is full
 * parameters: N/A
 * return value: Bool of the results
 */     
bool record::isFull() const {
    //loop to check for empty values
   for (int i=0; i<size; i++) {
        if (values[i] == nullptr) {
            return false;
        }
    }
    return true; 
}  

/*
 * equals : checks whether two objs are 
 *    identical or different
 * parameters: record obj to check
 * return value: Bool of the results
 */   
bool record::equals(const record& obj) const {
    //kind, names, count and size checks
    if (kind != obj.getType() || name != obj.getName() ||
    count != obj.countEntries() || size != obj.size) {
        return false;
    }
    //checking each value
    for (int i=0; i<count; i++) {
        valueType* ptr1 = reinterpret_cast<valueType*>(values[i]);
        valueType* ptr2 = reinterpret_cast<valueType*>(obj.values[i]);    
        if (!ptr1->equals(*ptr2)) {
            return false;
        }
    }
    return true;
} 

/*
 * getType : type getter
 * parameters: N/A
 * return value: type of the record type
 */   
record::type record::getType() const {
    return kind;
} 

/*
 * getName : name getter
 * parameters: N/A
 * return value: string of the record name
 */   
std::string record::getName() const {
    return name;
}   

/*
 * resize : resize the record to 2x current size
 * parameters: N/A
 * return value: N/A
 */  
void record::resize() {
    //allocate a new temp valueType** arr 2x the size
    valueType** newArr = new valueType*[size*2];
    //initalize array values to nullptr
    for (int i=0; i<size*2; i++) {
        newArr[i] = nullptr;
    }
    //deep copy old array to new one
    for (int i=0; i<count; i++) {
        newArr[i] = values[i];
    }

    delete []values; //delete old arr

    //shallow copy new array
    //and set copy array to null
    values = newArr; 
    newArr = nullptr;

    size *= 2; //double array size
}   

/*
 * checkType : check if record and 
 *    valueType obj have the same type
 * parameters: valueTyle* obj
 * return value: Bool of the results
 */ 
bool record::checkType(valueType* newObj) const {
    //place object type in a string
    std::string oType = newObj->typeAsString();
    //if record is valueType, all values are allowed
    if (kind == VALUE_TYPE) {
        return true;
    }
    //else check type compatibility
    if (toType(oType) == kind) {
        return true;
    }
    return false;
}  
