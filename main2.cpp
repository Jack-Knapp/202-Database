//
// Created by BEN CISNEROS.
//

#include <iostream>

#include "intType.h"
#include "stringType.h"

#include "record.h"

int main() {

    // NOTE: dynamic memory is needed for this test
    
    // ===================================================================
    // ** record name

    record r1(record::type::STRING_TYPE, "name");
    r1.insert(new stringType("Bob"));
    r1.insert(new stringType("Jimi"));
    r1.insert(new stringType("Jorge"));
    r1.insert(new stringType("Sam"));
    r1.insert(new stringType("Jason"));
    r1.insert(new stringType("Joel"));

    std::cout << std::string(60, '=') << std::endl;
    std::cout << "** Testing record name **" << std::endl;
    std::cout << "> printing data in record name" << std::endl;
    r1.print();

    std::cout << "> number of entries: " << r1.countEntries() << std::endl;

    std::cout << "> inserting Ellie at position 3 " << std::endl;
    r1.insert(new stringType("Ellie"), 3);
    r1.print();

    std::cout << "> number of entries: " << r1.countEntries() << std::endl;

    stringType* jimi = new stringType("Jimi");
    int pos = r1.indexOf(jimi);
    delete jimi;
    std::cout << "> Jimi is at position " << pos << " in the record" << std::endl;
    std::cout << "> removing Jimi from the record" << std::endl;
    r1.removeAt(pos);
    r1.print();

    std::cout << "> number of entries: " << r1.countEntries() << std::endl;

    try {
        stringType *joel = new stringType("Joel");
        stringType *ellie = new stringType("Ellie");
        int joelPos = r1.indexOf(joel);
        int elliePos = r1.indexOf(ellie);
        std::cout << "> swapping Joel (at position " << joelPos << ") and "
                  << "Ellie (at position " << elliePos << ")" << std::endl;
        r1.swap(joel, ellie);
        delete joel;
        delete ellie;
        r1.print();
    } catch (const myException& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "> removing Ellie" << std::endl;
    r1.remove();
    r1.print();

    std::cout << std::boolalpha;
    std::cout << "> is the record full? " << r1.isFull() << std::endl;
    std::cout << std::noboolalpha;

    intType* it = new intType("5");
    try {
        std::cout << "> inserting the value 5 (an incompatible type) into the record" << std::endl;
        r1.insert(it);
    } catch (const myException& e) {
        std::cout << e.what() << std::endl;
        delete it;
    }

    std::cout << "> removing value at index 4" << std::endl;
    r1.removeAt(4);
    r1.print();

    std::cout << "> removing value at index 2" << std::endl;
    r1.removeAt(2);
    r1.print();

    std::cout << "> removing value at index 1" << std::endl;
    r1.removeAt(1);
    r1.print();

    std::cout << "> removing value at index 0" << std::endl;
    r1.removeAt(0);
    r1.print();

    std::cout << "> removing the last value" << std::endl;
    r1.remove();
    r1.print();

    std::cout << std::boolalpha;
    std::cout << "> is the record empty? " << r1.isEmpty() << std::endl;
    std::cout << std::noboolalpha;

    std::cout << "> comparing r1 with r1 for equality" << std::endl;
    std::cout << std::boolalpha;
    std::cout << "is r1 equal to r1? " << r1.equals(r1) << std::endl;
    std::cout << std::noboolalpha;

    // ===================================================================
    // ** record area

    std::cout << std::string(60, '=') << std::endl;
    std::cout << "** Testing record area **" << std::endl;
    record r2(record::type::INT_TYPE, "area");
    r2.print();

    std::cout << "> comparing record name with record area for equality" << std::endl;
    std::cout << std::boolalpha;
    std::cout << "is r1 equal to r2? " << r1.equals(r2) << std::endl;
    std::cout << std::noboolalpha;

    std::cout << "> inserting the value 89" << std::endl;
    r2.insert(new intType("89"));
    r2.print();

    std::cout << "> number of entries: " << r2.countEntries() << std::endl;

    std::cout << "\n** DONE TESTING record **" << std::endl;
    std::cout << std::string(60, '=') << std::endl;

    return EXIT_SUCCESS;
}