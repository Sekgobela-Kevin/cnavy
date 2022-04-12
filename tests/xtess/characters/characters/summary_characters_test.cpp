#include <iostream>
#include <string>

#include "summary_characters.hpp"
#include "doctest.h"
using namespace std;

/*
 g++ ..\character\character.cpp ..\character\character_compute.cpp 
 characters.cpp bool_set.cpp bool_characters.cpp ratio_characters.cpp 
 summary_characters.cpp test\summary_characters_test.cpp 
*/

void Enable_Doctest_Summary_Characters(){};

TEST_CASE("Summary_Chracters"){
    clog << "Test: Started Summary_Characters Class Test using" << endl;
    string input_string(4, 'c');
    Characters* obj = new Characters(input_string);
    int results = Summary_Characters::isDigit(*obj);

    cout << "size of characters is " <<  obj->length() << endl;

    obj->update("test1");
    CHECK(Summary_Characters::isAlnum(*obj));
    CHECK(!Summary_Characters::isAlpha(*obj));
    CHECK(Summary_Characters::isASCII(*obj));

    obj->update("test");
    cout << obj->getText() << endl;
    cout << *obj << endl;
    CHECK(Summary_Characters::isAlpha(*obj));
    CHECK(!Summary_Characters::isBlank(*obj));
    CHECK(!Summary_Characters::isCntrl(*obj));
    CHECK(!Summary_Characters::isDigit(*obj));
    CHECK(Summary_Characters::isGraph(*obj));
    CHECK(Summary_Characters::isLower(*obj));
    CHECK(Summary_Characters::isPrint(*obj));
    CHECK(!Summary_Characters::isSpace(*obj));

    obj->update("TEST");
    CHECK(Summary_Characters::isAlnum(*obj));
    CHECK(Summary_Characters::isAlpha(*obj));
    CHECK(!Summary_Characters::isLower(*obj));
    CHECK(Summary_Characters::isUpper(*obj));
    CHECK(!Summary_Characters::isXdigit(*obj));

    obj->update("2022");
    CHECK(Summary_Characters::isAlnum(*obj));
    CHECK(Summary_Characters::isXdigit(*obj));
    CHECK(Summary_Characters::isDigit(*obj));
    CHECK(Summary_Characters::isGraph(*obj));

    obj->update(" \t");
    CHECK(!Summary_Characters::isAlnum(*obj));
    CHECK(Summary_Characters::isBlank(*obj));
    CHECK(!Summary_Characters::isDigit(*obj));
    CHECK(!Summary_Characters::isGraph(*obj));
    CHECK(!Summary_Characters::isLower(*obj));
    CHECK(Summary_Characters::isSpace(*obj));

    obj->update("\r\f\n\v");
    CHECK(!Summary_Characters::isPrint(*obj));
    CHECK(Summary_Characters::isCntrl(*obj));
    CHECK(!Summary_Characters::isPunct(*obj));
    CHECK(Summary_Characters::isSpace(*obj));

    clog << "Test: Summary_Characters Class passed tests successfully" << endl;
    obj->update("?,]");
    CHECK(Summary_Characters::isPunct(*obj));
    

    obj->update("ab");
    CHECK(!Summary_Characters::isUpper(*obj));
    CHECK(Summary_Characters::isLower(*obj));
    CHECK(Summary_Characters::isXdigit(*obj));
    

    clog << "Test: Summary_Characters Class passed tests successfully" << endl;
}

