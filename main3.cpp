//
// Created by OSWALDO CISNEROS on 2/15/23.
//

#include <iostream>
#include <string>

#include "intType.h"
#include "stringType.h"
#include "schema.h"
#include "table.h"

using namespace std;

int main() {
    schema sc("summer2002");
    sc.insertAttribute(new intType("course"));
    sc.insertAttribute(new stringType("professor"));
    sc.insertAttribute(new stringType("course-name"));
    sc.print();

    table tb("blah", &sc);
    tb.insert("course", new intType("202"));
    tb.insert("course", new intType("202"));
    tb.insert("course", new intType("202"));

    tb.insert("professor", new stringType("Jorge Fonseca"));
    tb.insert("professor", new stringType("Jimi Vasko"));
    tb.insert("professor", new stringType("Kishore Chidella"));

    tb.insert("course-name", new stringType("Computer Science II"));
    tb.insert("course-name", new stringType("Computer Science II"));
    tb.insert("course-name", new stringType("Computer Science II"));
    tb.print();
    std::cout << "Done!" << std::endl;

    return 0;
}