//
// Created by BEN CISNEROS.
//

#include <iostream>

#include "valueType.h"
#include "intType.h"
#include "charType.h"
#include "stringType.h"

int main() {

    // NOTE: dynamic memory is not needed for this test

    // ===================================================================
    // ** intType

    intType i("45");
    intType ii("68");
    intType iii(ii);

    std::cout << std::string(60, '=') << std::endl;
    std::cout << "** Testing intType **" << std::endl;

    // testing boolean functions
    std::cout << std::boolalpha;
    std::cout << "> isIntegerType()?" << std::endl;
    std::cout << i.isIntegerType() << std::endl;            // true
    std::cout << ii.isIntegerType() << std::endl;           // true
    std::cout << iii.isIntegerType() << std::endl;          // true

    std::cout << "> isStringType()?" << std::endl;
    std::cout << i.isStringType() << std::endl;             // false
    std::cout << ii.isStringType() << std::endl;            // false
    std::cout << iii.isStringType() << std::endl;           // false

    std::cout << "> isCharType()?" << std::endl;
    std::cout << i.isCharType() << std::endl;               // false
    std::cout << ii.isCharType() << std::endl;              // false
    std::cout << iii.isCharType() << std::endl;             // false

    std::cout << "> isNullType()?" << std::endl;
    std::cout << i.isNullType() << std::endl;               // false
    std::cout << ii.isNullType() << std::endl;              // false
    std::cout << iii.isNullType() << std::endl;             // false

    std::cout << "> equals()?" << std::endl;
    std::cout << i.equals(ii) << std::endl;              // false
    std::cout << ii.equals(iii)<< std::endl;             // true
    std::cout << i.equals(i) << std::endl;               // true

    std::cout << std::noboolalpha;

    // testing conversion functions
    std::cout << "> toStringType()?" << std::endl;
    std::cout << i.toStringType() << std::endl;             // "45"
    std::cout << ii.toStringType() << std::endl;            // "68"
    std::cout << iii.toStringType() << std::endl;           // "68"

    std::cout << "> toCharType()?" << std::endl;
    try {
        std::cout << i.toCharType() << std::endl;           // error
    } catch (const myException& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        std::cout << ii.toCharType() << std::endl;          // error
    } catch (const myException& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        std::cout << iii.toCharType() << std::endl;         // error
    } catch (const myException& e) {
        std::cout << e.what() << std::endl;
    }

    // ===================================================================
    // ** charType
    std::cout << std::string(60, '=') << std::endl;
    std::cout << "** Testing charType **" << std::endl;

    charType c("ab");
    charType cc("a");
    charType ccc(cc);

    // testing boolean functions
    std::cout << std::boolalpha;
    std::cout << "> isIntegerType()?" << std::endl;
    std::cout << c.isIntegerType() << std::endl;            // false
    std::cout << cc.isIntegerType() << std::endl;           // false
    std::cout << ccc.isIntegerType() << std::endl;          // false

    std::cout << "> isStringType()?" << std::endl;
    std::cout << c.isStringType() << std::endl;             // false
    std::cout << cc.isStringType() << std::endl;            // false
    std::cout << ccc.isStringType() << std::endl;           // false

    std::cout << "> isCharType()?" << std::endl;
    std::cout << c.isCharType() << std::endl;               // false
    std::cout << cc.isCharType() << std::endl;              // true
    std::cout << ccc.isCharType() << std::endl;             // true

    std::cout << "> isNullType()?" << std::endl;
    std::cout << c.isNullType() << std::endl;               // false
    std::cout << cc.isNullType() << std::endl;              // false
    std::cout << ccc.isNullType() << std::endl;             // false

    std::cout << "> equals()?" << std::endl;
    try {
        std::cout << c.equals(cc) << std::endl;         // error
    } catch (const myException& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << cc.equals(ccc)<< std::endl;            // true
    try {
        std::cout << c.equals(c) << std::endl;          // error
    } catch (const myException& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::noboolalpha;

    // testing conversion functions
    std::cout << "> toStringType()?" << std::endl;
    std::cout << c.toStringType() << std::endl;             // "ab"
    std::cout << cc.toStringType() << std::endl;            // "a"
    std::cout << ccc.toStringType() << std::endl;           // "a"

    std::cout << "> toCharType()?" << std::endl;
    try {
        std::cout << c.toCharType() << std::endl;           // error
    } catch (const myException& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << cc.toCharType() << std::endl;              // 'a'
    std::cout << ccc.toCharType() << std::endl;             // 'a'

    // ===================================================================
    // ** stringType

    stringType s("45");
    stringType ss("68");
    stringType sss(ss);

    std::cout << std::string(60, '=') << std::endl;
    std::cout << "** Testing stringType **" << std::endl;

    // testing boolean functions
    std::cout << std::boolalpha;
    std::cout << "> isIntegerType()?" << std::endl;
    std::cout << s.isIntegerType() << std::endl;            // false
    std::cout << ss.isIntegerType() << std::endl;           // false
    std::cout << sss.isIntegerType() << std::endl;          // false

    std::cout << "> isStringType()?" << std::endl;
    std::cout << s.isStringType() << std::endl;             // false
    std::cout << ss.isStringType() << std::endl;            // false
    std::cout << sss.isStringType() << std::endl;           // false

    std::cout << "> isCharType()?" << std::endl;
    std::cout << s.isCharType() << std::endl;               // false
    std::cout << ss.isCharType() << std::endl;              // false
    std::cout << sss.isCharType() << std::endl;             // false

    std::cout << "> isNullType()?" << std::endl;
    std::cout << s.isNullType() << std::endl;               // false
    std::cout << ss.isNullType() << std::endl;              // false
    std::cout << sss.isNullType() << std::endl;             // false

    std::cout << "> equals()?" << std::endl;
    std::cout << s.equals(ss) << std::endl;              // false
    std::cout << ss.equals(sss)<< std::endl;             // true
    std::cout << s.equals(s) << std::endl;               // true

    std::cout << std::noboolalpha;

    // testing conversion functions
    std::cout << "> toStringType()?" << std::endl;
    std::cout << s.toStringType() << std::endl;             // "45"
    std::cout << ss.toStringType() << std::endl;            // "68"
    std::cout << sss.toStringType() << std::endl;           // "68"

    std::cout << "> toCharType()?" << std::endl;
    try {
        std::cout << s.toCharType() << std::endl;           // error
    } catch (const myException& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        std::cout << ss.toCharType() << std::endl;          // error
    } catch (const myException& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        std::cout << sss.toCharType() << std::endl;         // error
    } catch (const myException& e) {
        std::cout << e.what() << std::endl;
    }

    // ===================================================================
    // ** testing valueType

    std::cout << std::string(60, '=') << std::endl;
    std::cout << "> Testing valueType as intType **" << std::endl;

    // testing boolean functions
    std::cout << std::boolalpha;
    std::cout << ((valueType*) &i)->isIntegerType() << std::endl;           // true
    std::cout << ((valueType*) &ii)->isIntegerType() << std::endl;          // true
    std::cout << ((valueType*) &iii)->isIntegerType() << std::endl;         // true

    std::cout << "> isStringType()?" << std::endl;
    std::cout << ((valueType*) &i)->isStringType() << std::endl;             // false
    std::cout << ((valueType*) &ii)->isStringType() << std::endl;            // false
    std::cout << ((valueType*) &iii)->isStringType() << std::endl;           // false

    std::cout << "> isCharType()?" << std::endl;
    std::cout << ((valueType*) &i)->isCharType() << std::endl;               // false
    std::cout << ((valueType*) &ii)->isCharType() << std::endl;              // false
    std::cout << ((valueType*) &iii)->isCharType() << std::endl;             // false

    std::cout << "> isNullType()?" << std::endl;
    std::cout << ((valueType*) &i)->isNullType() << std::endl;               // false
    std::cout << ((valueType*) &ii)->isNullType() << std::endl;              // false
    std::cout << ((valueType*) &iii)->isNullType() << std::endl;             // false

    std::cout << "> equals()?" << std::endl;
    std::cout << ((valueType*) &i)->equals(*((valueType*) &ii)) << std::endl;   // false
    std::cout << ((valueType*) &ii)->equals(*((valueType*) &iii)) << std::endl; // true
    std::cout << ((valueType*) &i)->equals(*((valueType*) &i)) << std::endl;    // true

    std::cout << std::noboolalpha;

    // testing conversion functions
    std::cout << "> toStringType()?" << std::endl;
    std::cout << ((valueType*) &i)->toStringType() << std::endl;             // "45"
    std::cout << ((valueType*) &ii)->toStringType() << std::endl;            // "68"
    std::cout << ((valueType*) &iii)->toStringType() << std::endl;           // "68"

    std::cout << "> toCharType()?" << std::endl;
    try {
        std::cout << ((valueType*) &i)->toCharType() << std::endl;           // error
    } catch (const myException& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        std::cout << ((valueType*) &ii)->toCharType() << std::endl;          // error
    } catch (const myException& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        std::cout << ((valueType*) &iii)->toCharType() << std::endl;         // error
    } catch (const myException& e) {
        std::cout << e.what() << std::endl;
    }

    // ===================================================================
    // ** charType
    std::cout << std::string(60, '=') << std::endl;
    std::cout << "** Testing valueType as charType **" << std::endl;

    // testing boolean functions
    std::cout << std::boolalpha;
    std::cout << "> isIntegerType()?" << std::endl;
    std::cout << ((valueType*) &c)->isIntegerType() << std::endl;            // false
    std::cout << ((valueType*) &cc)->isIntegerType() << std::endl;           // false
    std::cout << ((valueType*) &ccc)->isIntegerType() << std::endl;          // false

    std::cout << "> isStringType()?" << std::endl;
    std::cout << ((valueType*) &c)->isStringType() << std::endl;             // false
    std::cout << ((valueType*) &cc)->isStringType() << std::endl;            // false
    std::cout << ((valueType*) &ccc)->isStringType() << std::endl;           // false

    std::cout << "> isCharType()?" << std::endl;
    std::cout << ((valueType*) &c)->isCharType() << std::endl;               // false
    std::cout << ((valueType*) &cc)->isCharType() << std::endl;              // true
    std::cout << ((valueType*) &ccc)->isCharType() << std::endl;             // true

    std::cout << "> isNullType()?" << std::endl;
    std::cout << ((valueType*) &c)->isNullType() << std::endl;               // false
    std::cout << ((valueType*) &cc)->isNullType() << std::endl;              // false
    std::cout << ((valueType*) &ccc)->isNullType() << std::endl;             // false

    std::cout << "> equals()?" << std::endl;
    try {
        std::cout << ((valueType*) &c)->equals(*((valueType*) &cc)) << std::endl;         // error
    } catch (const myException& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << ((valueType*) &cc)->equals(*((valueType*) &ccc))<< std::endl;            // true
    try {
        std::cout << ((valueType*) &c)->equals(*((valueType*) &c)) << std::endl;          // error
    } catch (const myException& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::noboolalpha;

    // testing conversion functions
    std::cout << "> toStringType()?" << std::endl;
    std::cout << ((valueType*) &c)->toStringType() << std::endl;             // "ab"
    std::cout << ((valueType*) &cc)->toStringType() << std::endl;            // "a"
    std::cout << ((valueType*) &ccc)->toStringType() << std::endl;           // "a"

    std::cout << "> toCharType()?" << std::endl;
    try {
        std::cout << ((valueType*) &c)->toCharType() << std::endl;           // error
    } catch (const myException& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << ((valueType*) &cc)->toCharType() << std::endl;              // 'a'
    std::cout << ((valueType*) &ccc)->toCharType() << std::endl;             // 'a'

    // ===================================================================
    // ** stringType

    std::cout << std::string(60, '=') << std::endl;
    std::cout << "** Testing valueType as stringType **" << std::endl;

    // testing boolean functions
    std::cout << std::boolalpha;
    std::cout << "> isIntegerType()?" << std::endl;
    std::cout << ((valueType*) &s)->isIntegerType() << std::endl;            // true
    std::cout << ((valueType*) &ss)->isIntegerType() << std::endl;           // true
    std::cout << ((valueType*) &sss)->isIntegerType() << std::endl;          // true

    std::cout << "> isStringType()?" << std::endl;
    std::cout << ((valueType*) &s)->isStringType() << std::endl;             // false
    std::cout << ((valueType*) &ss)->isStringType() << std::endl;            // false
    std::cout << ((valueType*) &sss)->isStringType() << std::endl;           // false

    std::cout << "> isCharType()?" << std::endl;
    std::cout << ((valueType*) &s)->isCharType() << std::endl;               // false
    std::cout << ((valueType*) &ss)->isCharType() << std::endl;              // false
    std::cout << ((valueType*) &sss)->isCharType() << std::endl;             // false

    std::cout << "> isNullType()?" << std::endl;
    std::cout << ((valueType*) &s)->isNullType() << std::endl;               // false
    std::cout << ((valueType*) &ss)->isNullType() << std::endl;              // false
    std::cout << ((valueType*) &sss)->isNullType() << std::endl;             // false

    std::cout << "> equals()?" << std::endl;
    std::cout << ((valueType*) &s)->equals(*((valueType*) &ss)) << std::endl;    // false
    std::cout << ((valueType*) &ss)->equals(*((valueType*) &sss))<< std::endl;   // true
    std::cout << ((valueType*) &s)->equals(*((valueType*) &s)) << std::endl;     // true

    std::cout << std::noboolalpha;

    // testing conversion functions
    std::cout << "> toStringType()?" << std::endl;
    std::cout << ((valueType*) &s)->toStringType() << std::endl;             // "45"
    std::cout << ((valueType*) &ss)->toStringType() << std::endl;            // "68"
    std::cout << ((valueType*) &sss)->toStringType() << std::endl;           // "68"

    std::cout << "> toCharType()?" << std::endl;
    try {
        std::cout << ((valueType*) &s)->toCharType() << std::endl;           // error
    } catch (const myException& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        std::cout << ((valueType*) &ss)->toCharType() << std::endl;          // error
    } catch (const myException& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        std::cout << ((valueType*) &sss)->toCharType() << std::endl;         // error
    } catch (const myException& e) {
        std::cout << e.what() << std::endl;
    }

    // ===================================================================
    // ** static array

    const int N = 3;
    valueType* l1[N] = {&i, &c, &s};
    valueType* l2[N] = {&ii, &cc, &ss};

    // testing boolean functions
    std::cout << std::boolalpha;

    std::cout << "> isIntegerType()?" << std::endl;
    for (auto & j : l1)
        std::cout << j->isIntegerType() << std::endl;

    std::cout << "> isCharType()?" << std::endl;
    for (auto & j : l1)
        std::cout << j->isCharType() << std::endl;

    std::cout << "> isStringType()?" << std::endl;
    for (auto & j : l1)
        std::cout << j->isStringType() << std::endl;

    std::cout << "> isNullType()?" << std::endl;
    for (auto & j : l1)
        std::cout << j->isNullType() << std::endl;

    std::cout << "> equals()" << std::endl;
    for (int j = 0; j < N; ++j) {
        try {
            std::cout << l1[j]->equals(*l2[j]) << std::endl;
        } catch (const myException& e) {
            std::cout << e.what() << std::endl;
        }
    }

    std::cout << std::noboolalpha;

    std::cout << "> toStringType()?" << std::endl;
    for (auto & j : l1)
        std::cout << j->toStringType() << std::endl;

    std::cout << "> toCharType()?" << std::endl;
    for (auto & j : l1) {
        try {
            std::cout << j->toCharType() << std::endl;
        } catch (const myException& e) {
            std::cout << e.what() << std::endl;
        }
    }

    std::cout << "> toIntegerType()?" << std::endl;
    for (auto & j : l1) {
        try {
            std::cout << j->toIntegerType() << std::endl;
        } catch (const myException& e) {
            std::cout << e.what() << std::endl;
        }
    }

    std::cout << "> updating the type of each value type through parent class" << std::endl;

    std::cout << std::string(40, '-') << std::endl;
    std::cout << "Before" << std::endl;

    for (auto & val : l1) {
        try {
            val->print();
        } catch (const myException &e) {
            std::cout << e.what() << std::endl;
        }
    }

    l1[0]->setValue("67");              // intType
    l1[1]->setValue("x");               // charType
    l1[2]->setValue("Hello World!");    // stringType

    std::cout << std::string(40, '-') << std::endl;
    std::cout << "After" << std::endl;

    for (auto & val : l1) {
        try {
            val->print();
        } catch (const myException &e) {
            std::cout << e.what() << std::endl;
        }
    }

    std::cout << "\n** DONE TESTING valueType **" << std::endl;
    std::cout << std::string(60, '=') << std::endl;

    return EXIT_SUCCESS;
}
