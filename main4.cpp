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
#include <iostream>
#include <string>

#include "schema.h"
#include "record.h"
#include "charType.h"
#include "intType.h"
#include "stringType.h"
#include "nullType.h"
#include "table.h"

//provided consts
const int MAX_STR_LEN = 1024;   // maximum number of characters
const int MAX_ARGS = 64;        // maximum number of arguments
const int MAX_VECTOR_LEN = 100; // maximum number of schemas

// prints the current database directory followed by the
// number of relations in the database and the ">" character
// @param relations the number of schemas in the database
void print(int);

// returns true if a string represents a number, otherwise
// it should return false
// @param str the string that represents a number
// @returns true if the string is a number, otherwise it returns
// false
bool isNumber(const std::string&);

// compares the first character of each string. If they are
// equal to each other, it continues with the following pairs
// until the character differ or until the terminating null-
// character (i.e., '\0') is reached
// @param s1 a pointer to the first sequence of characters
// @param s2 a pointer to the second sequence of characters
// @return true if both sequence are the same, otherwise it returns false
bool compareCommands(const char*, const char*);

// takes a c-string and parses it into tokens. This function
// replaces all whitespace characters with '\0' until a non-whitespace
// character is encountered. This indicates the end of an expression and
// the beginning of a new one, if any. The address of each expression is
// saved in a static allocated vector for later use. The function should
// null-terminate the vector as required and should return the number
// of arguments parsed. Note that you must declare a static array
// of type char and of size MAX_STR_LEN. This static array will be used
// to reduce the amount of dynamic memory allocation in our program
// @param str a pointer to a sequence of characters
// @param vector the vector into which words are to be inserted
// @returns the count of how many sub-expressions a query expression has.
int parseQuery(const char*, int, char**);

// creates a new schema dynamically, inserts this new schema into the
// specified vector of schemas, and then increments the count of schemas
// currently stored in the vector. If the vector's capacity exceeds its
// limit, the vector should be resized (twice its size). A message should
// be displayed if schema with the same name already exists in the vector.
// The function should return a schema if a new schema was successfully created,
// otherwise it should return nullptr
// @param name the name of the schema
// @param schemas the vector of schemas
// @param count the number of schemas stored int the vector of schemas
// @returns a reference to the schema or null if nothing is found
schema* createSchema(const std::string&, schema**, int&);

// returns a list with all relations in the database
// @param schemas the vector of schemas
// @param param the number of schemas in the vector
void list(schema**, int);

// returns a reference to a schema or null if the reference does not
// exist. The relation is searched by name in the specified vector of
// schemas and once a reference to the relation is found it is returned
// @param the name of the schema
// @param schemas the vector of schemas
// @param int the number of vectors in the schema
// @returns a reference to the schema or null if nothing is found
schema* findSchema(const std::string &, schema **, int);

// inserts a tuple (attribute type) into a relation. The schema is first
// searched by name, then after it is found, we store it in the schema. If
// either the schema cannot be found, the function should return nullptr,
// otherwise it should return a reference to schema
// @param value the attribute to be added
// @param type the type of the attribute
// @param name the name of the schema
// @param schemas a vector of schemas
// @param count the number of schemas in the vector of schemas
schema* insert(const std::string&, const std::string&, const std::string&, schema**, int);

// this functions creates a table from an already existing relation. The
// schema is searched by name in the vector of schemas, and if it is found,
// a table is dynamically created and name is assigned to it. Then, it is
// added to the vector of tables. The count of tables should be incremented
// accordingly
// @param name the name of the schema
// @param schemas a vector of schemas
// @param count the number of schemas in the vector of schemas
// @param tableName the name to be assigned to the table
// @param tables a vector of tables
// @param cntRecords the number of tables in the vector of tables
// @returns a reference to the table or null if noting is found
table* createRelation(const std::string&, schema**, int, const std::string&, table**&, int&);

// searches for a table by name in the vector of tables. If the
// table is found, this function returns a reference to it; otherwise,
// it returns nullptr
// @param name the name of the table to be searched
// @param tables a vector of tables
// @param count the number of tables in the vector of tables
// @return a reference to table or null if nothing is found
table* findTable(const std::string&, table **, int);


// inserts a tuple into the table. The table is searched by name in
// the vector of tables, if the table is found, the values of the tuple
// are inserted into the table, one by one, and then a reference to
// this table is returned. Otherwise, null is returned if the table
// does not exist
// @param tuple an array of string value
// @param tables a vector of tables
// @param cont the number of tables in the vector of tables
// @param name the name of the table to be searched.
// @return a reference to the table or null if nothing is found
table* insertData(std::string*, table**, int, const std::string&);

void help();

// =======================================================================

int main() {
    //initializing some vars
    int tokens = 0;         // number of characters or commands read
    char *vector[MAX_ARGS]; // a vector of queries
    bool exitFlag = false;  // terminates shell
    std::string line;       // entry line
    int relations = 0;      // number of relations (schemas) in the database
    schema** schemas;       // a vector of schemas in the database
    int records = 0;        // number of records (tables) in the database
    table** tables;         // a vector of tables in the database

    schemas = new schema*[MAX_VECTOR_LEN];
    tables = new table*[MAX_VECTOR_LEN];

    std::cout << "** Starting session ** " << std::endl;
    std::cout << "Please wait....Starting up the CS202 Database " << std::endl;

    //main loop of the program
    while (!exitFlag) {
        try {
            print(relations);
            std::getline(std::cin, line);
            tokens = parseQuery(line.c_str(), static_cast<int>(line.length()), vector);

            //command logic for - list
            if (compareCommands(vector[0],"list")) {
                list(schemas, relations);
            }
            //command logic for - quit
            else if (compareCommands(vector[0],"quit")) {
                exitFlag = !exitFlag;
            }
            //command logic for - show
            else if (compareCommands(vector[0],"show")) {
                //try to find cmd arg in schemas and tables
                schema* fSchema = findSchema(vector[1], schemas, relations);
                table* fTable = findTable(vector[1], tables, records);
                //if neither, cout error
                if (fSchema == nullptr && fTable == nullptr) {
                    std::cout <<"'"<< vector[1] <<"' does not exist in the database.\n";
                }
                //if arg is schema
                else if (fSchema!= nullptr){
                    fSchema->print();
                }
                //if arg is table
                else {
                    fTable->print();
                }
            }
            //command logic for - schema
            else if (compareCommands(vector[0],"schema")) {
                schema* mScheme = createSchema(vector[1], schemas, relations);
                mScheme->print();
            }
            //command logic for - make-schema
            else if (compareCommands(vector[0],"make-schema")) {
                schema sampSchem("");
                sampSchem.print();
            }
            //command logic for - let
            else if (compareCommands(vector[0],"let")) {
                //cmd form - let name be make-schema
                if (compareCommands(vector[3],"make-schema")) {
                    schema* mScheme = createSchema(vector[1], schemas, relations);
                    mScheme->print();
                }
                //otherwise print error
                else {
                    std::cout << "Syntax error: '" << line << "' command malformed.\n";    
                }
            }
            //command logic for - insert
            else if (compareCommands(vector[0],"insert")) {
                    //check which insert cmd was called
                    bool recordF = false;
                    for (int i=1; i<tokens; i++) {
                        if (compareCommands(vector[i],"record")) {
                            recordF = true;
                            break;
                        }
                    }

                    //insert record (insertdata)
                    if (recordF) {
                        //find the number of args in the tuple
                        int arrC = 0;
                        for (int i = 1; i <tokens; i++) {
                            if (compareCommands(vector[i],"into")) {
                                break;
                            }
                            arrC++;
                        }
                        //store these args in a dynamic string array
                        std::string* tuple = new std::string[arrC];
                        for (int i=0; i<arrC; i++) {
                            tuple[i] = vector[i+1];
                        }

                        //finally insert the data and print
                        table* newTab = insertData(tuple, tables, records, vector[tokens-1]);
                        newTab->print();

                        //delete the tuple
                        delete[] tuple;
                    }

                    //insert schema (insert)
                    else if(findSchema(vector[4], schemas, relations) != nullptr) {
                        //if schema exists, insert and print
                        schema* newSchema = insert(vector[1], vector[2], vector[4], schemas, relations);
                        newSchema->print();      
                    }
                    //if the schema does not exist, or other error print msg
                    else {
                        std::cout << "Syntax error: '" << line << "' command malformed.\n";
                    }
            }
            //command logic for - make-relation
            //cmd form: make-relation record be schema
            else if (compareCommands(vector[0],"make-relation")) {
                //create the relation and print table
                table* newR = createRelation(vector[3], schemas, relations, vector[1], tables, records);
                newR->print();
            }
            //general syntax error message
            else {
                std::cout << "Syntax error: '" << line << "' command malformed.\n";
            }

            //clear vector
            //int totD = 0;
            for (int i=0; i<tokens; i++){
                //totD++;
                delete[] vector[i];
                vector[i] = nullptr;
            }
            //std::cout<<"Total D: "<<totD<<std::endl;
           
        } catch (const myException& e) {
            std::cout << e.what() << std::endl;
            std::cout << "** Session terminated due to a handled exception **" << std::endl;
        }
    }
    //delete schemas
    for (int i=0; i<relations; i++) {
        delete schemas[i];
    }
    delete[] schemas;
    schemas = nullptr;

    //delete tables
    for (int i=0; i<records; i++) {
       delete tables[i];
    }
    delete[] tables;
    tables = nullptr;

    std::cout << "** Ending session successfully **" << std::endl;

    return 0;
}

// =======================================================================

/*
 * print : Prints Database and num of Databases
 * parameters: N/A
 * return value: N/A
 */
void print(int relations) {
    std::cout << "/Database" << relations << "> " << std::endl;
}

/*
 * isNumber : determines if a given string
 * is a number or not
 * parameters: string str
 * return value: Bool of the results
 */
bool isNumber(const std::string& str) {
    //loop to check if each char is int
    for (int i=0; i<str.size(); i++) {
        if (str[i] > 47 && str[i] < 58) {
            continue;
        }
        return false;
    }
    return true; 
}

/*
 * compareCommands : determines if two expressions
 *    are identical or different
 * parameters: 2x const char* that point to the 
 *    first values of strings
 * return value: Bool of the results
 */
bool compareCommands(const char* s1, const char* s2) {
    //test loop
    for (int i=0; i < MAX_VECTOR_LEN; i++) {
        //check for equivalancy and no null chars
        if (*s1==*s2 && *s1 != '\0' && *s2 != '\0') {
            s1++;
            s2++;
            continue;
        }
        //check for both null chars
        if (*s1=='\0' && *s2=='\0') {
            return true;
        }
    }
    return false;
}

/*
 * parseQuery: tokenize a string,
 *    and store each word into a c-string
 *    inside of vector (ezpz)
 * parameters: const char* str-string to parse,
 *    int n-length of string, char** vector-
 *    array to store c-strings in 
 * return value: int with the number of tokens
 */
int parseQuery(const char* str, int n, char** vector) {
    //int totalc = 0;
    //create char array, initialize to null
    char cArr[MAX_STR_LEN];
    for (int i=0; i<MAX_STR_LEN; i++) {
        cArr[i]='\0';
    }

    //strip parentheses and copy str
    //into cArr; offset prevents empty indices
    //from the stripped parentheses
    int offset = 0;
    for (int i=0; i<n; i++) {
        if (*str=='(' || *str==')') {
            str++;
            offset++;
            continue;
        }
        cArr[i-offset] = *str;
        str++;    
    }

    //remove ws and replace with null
    //also count number of words
    bool inWord = false;
    int count = 0;
    for (int i=1; i<n+1; i++) {
        if (cArr[i]=='"') {
            inWord = !inWord;
        }
        if (inWord == false && cArr[i]==' '||cArr[i]=='\t'||cArr[i]=='\n'||cArr[i]=='\0') {
            cArr[i]='\0';
            count++;
        }
    }

    //load words into vector
    //vector = new char*[count];
    int lenCount=0, word=0;
    for (int i=0; i <n+1-offset; i++) {
        //count the length of each word
        if (cArr[i]!='\0') {
            lenCount++;
        }
        //store the word into the vector
        else {
            vector[word]= new char[lenCount+1];
            //totalc++;
            int letC = 0;
            for(int j=i-lenCount; j<i; j++) {
                vector[word][letC] = cArr[j];
                //cout << vector[word][letC] << endl;
                letC++;
            }
            //set last value to null, reset counter,
            // and increment word count
            vector[word][lenCount]='\0';
            lenCount = 0;
            word++;
        }   
    }
    //return the final value
    //std::cout<<"Word C: "<<word<<std::endl;
    //std::cout<<"Token C: "<<count-offset<<std::endl;
    //std::cout<<"Num Allocs: "<<totalc<<std::endl;
    return count-offset;
}

/*
 * createSchema : make a new schema and store it in 
       schema vector
 * parameters: string name-naem of the new schema,
 *     schema** schemas-pointer to array of schemas,
 *     int count-number of schemas in database
 * return value: schema* w the address of 
 *     the new schema or nullptr
 */
schema* createSchema(const std::string& name, schema** schemas, int& count) {
    //check that schema w/ name doesn't already exist
    for (int i=0; i<count; i++) {
        if (schemas[i]->getName()==name) {
            std::cout << "ERROR: This schema already exists.\n";
            return nullptr;
        }
    }

    //resize if the schema vector is full
    if (count >= MAX_VECTOR_LEN) {
        schema** newArr = new schema*[MAX_VECTOR_LEN*2];
        //initialize new schema vector to null
        for (int i=0; i<MAX_VECTOR_LEN*2; i++) {
            newArr[i] = nullptr;
        }
		//deep copy old array to new one
		for (int i=0; i<count; i++) {
			newArr[i] = schemas[i];
		}

		delete []schemas; //delete old arr

		//shallow copy new array
		//and set copy array to null
		schemas = newArr; 
		newArr = nullptr;
    }

    //create and insert schema, increment count
    schemas[count] = new schema(name);
    schema* rSchema = schemas[count];
    count++;

    return rSchema;
}

/*
 * list : print all schemas in db
 * parameters: schema** schema-vector of schemas
 *     and int count-number of schemas
 * return value: N/A
 */    
void list(schema** schema, int count) {
    std::cout << "+" << std::string(record::MAX_LEN, '-') << "+"
              << std::string(record::MAX_LEN, '-') << "+" << std::endl;
    int diff = abs(record::MAX_LEN - static_cast<int>(std::string("name").size()));
    std::cout << "|name" << std::string(diff, ' ') << "|";
    diff = abs(record::MAX_LEN - static_cast<int>(std::string("size").size()));
    std::cout << "size" << std::string(diff, ' ') << "+" << std::endl;
    std::cout << "+" << std::string(record::MAX_LEN, '-') << "+"
              << std::string(record::MAX_LEN, '-') << "+" << std::endl;
    for (int i = 0; i < count; ++i) {
        std::string s = schema[i]->getName();
        diff = abs(record::MAX_LEN - static_cast<int>(s.size()));
        std::cout << "|" << s << std::string(diff, ' ') << "|";
        s = std::to_string(schema[i]->countAttributes());
        diff = abs(record::MAX_LEN - static_cast<int>(s.size()));
        std::cout << s << std::string(diff, ' ') << "|" << std::endl;
    }
    std::cout << "+" << std::string(record::MAX_LEN, '-') << "+"
              << std::string(record::MAX_LEN, '-') << "+" << std::endl;
}

/*
 * findSchema : find,return address of schema or nullptr
 * parameters: string name-schemas name, schema** schemas-vector
 *     of all schemas, int count-number of schemas in db
 * return value: schema* w/ address of given schema
 */    
schema* findSchema(const std::string& name, schema** schemas, int count) {
    //search for schema by name
    for (int i=0; i<count; i++) {
        if (schemas[i]->getName()==name) {
            schema* rSchema = schemas[i];
            return rSchema;
        }
    }
    return nullptr;
}

/*
 * insert : insert a tuple into a given schema
 * parameters: string value-value to insert, string type-
 *     type of data being inserted, string name-name of schema
 *     to insert into, schema** schemas-vector of schemas in db,
 *     int count-number of schemas in db
 * return value: schema* w/ address of schema
 */    
schema* insert(const std::string& value, const std::string& type,
    const std::string& name, schema** schemas, int count) {
    
    //find schema to store in ptr or return nullptr
    schema* toSchema = findSchema(name, schemas, count);
    if (toSchema == nullptr) {
        return toSchema;
    }

    //insert value into schema based on its type
    if (type == "int") {
        toSchema->insertAttribute(new intType(value));    
    }
    else if (type == "string"){
        toSchema->insertAttribute(new stringType(value));    
    }
    else if (type == "char"){
        toSchema->insertAttribute(new charType(value));    
    }
    else if (type == "null"){
        toSchema->insertAttribute(new nullType(value));    
    }
    else {
        std::cout << "ERROR: Invalid Type\n";
        return nullptr;
    }

    return toSchema;  //return the ptr
}

/*
 * createRelation : make a table based on parameters
 *     and an existing schema
 * parameters: string name-schemas name, schema** schemas-vector
 *     of all schemas, int count-number of schemas in db,
 *     string tableName-name for table, table** tables-vector
 *     of tables in db, int cntRecords- num of tables in db
 * return value: table* w/ address of new table
 */   
table* createRelation(const std::string& name, schema** schemas, int count, const std::string& tableName,
                      table**& tables, int& cntRecords) {
    //find the schema or return nullptr
    schema* rSchema = findSchema(name,schemas,count);
    if (rSchema == nullptr) {
        return nullptr;
    }

    //create the table and increment table counter
    tables[cntRecords] = new table(tableName, rSchema);
    table* rTable = tables[cntRecords];
    cntRecords++;

    return rTable; //return ptr to new table
}

/*
 * findTable : find,return address of table or nullptr
 * parameters: string name-table name, table** tables-vector
 *     of all tables, int count-number of tables in db
 * return value: table* w/ address of given table
 */   
table* findTable(const std::string& name, table** tables, int count) {
    //search for table by name
    for (int i=0; i<count; i++) {
        if (tables[i]->getName()==name) {
            table* rTable = tables[i];
            return rTable;
        }
    }
    return nullptr;
}

/*
 * insertData : insert a tuple into a given table
 * parameters: string tuple-arr of data to insert, table**
 *     tables-vector of tables, int count-num of tables in db,
 *     string name-name of table to insert into
 * return value: table* w/ address of table
 */    
table* insertData(std::string* tuple, table** tables, int count, const std::string& name) {
    //find table or return nullptr
    table* fTable = findTable(name, tables, count);
    if (fTable == nullptr) {
        return fTable;
    }

    //insert data into column from tuple based
    //on the data type of the column
    for (int i = 0; i < fTable->countEntries(); i++) {
        record* column = fTable->at(i);
        if (column->getType() == record::CHAR_TYPE) {
            fTable->insert(column->getName(), new charType(tuple[i]));
        }
        else if (column->getType() == record::INT_TYPE){
            fTable->insert(column->getName(), new intType(tuple[i]));    
        }
        else if (column->getType() == record::STRING_TYPE){
            fTable->insert(column->getName(), new stringType(tuple[i]));   
        }
        else if (column->getType() == record::NULL_TYPE){
            fTable->insert(column->getName(), new nullType(tuple[i]));    
        }
        else {
            std::cout << "ERROR: Invalid Type\n";
            return nullptr;
        }
    }
    return fTable; //return ptr to table
}