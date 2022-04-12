#include <iostream>
#include "string"

#include "bool_characters.hpp"
#include "doctest.h"
using namespace std;


/*
 g++ ..\character\character.cpp ..\character\character_compute.cpp 
  characters.cpp bool_characters.cpp test\bool_characters_test.cpp
*/


void Enable_Doctest_Bool_Characters(){};

TEST_CASE("Bool_Characters Class test"){
    clog << "Test: Started Bool_Characters Class Test using" << endl;
    string input_string(100, 'c');
    string input_string2("is_alpha");
    Characters* obj = new Characters(input_string);
    Characters* obj2 = new Characters("name");
    Characters* obj3 = new Characters("names3");
    bool_chars_type results = Bool_Characters::isUpper(*obj);
    clog << "Bool_Characters::callMethod(*obj3, input_string2);" << endl;
    Bool_Characters::callMethod(*obj3, input_string2);
    Bool_Characters::textCompare(*obj2, *obj3);


    cout << "size of characters is " <<  obj->length() << endl;
    cout << "size of results is " <<  results[2] << endl;

    delete obj;
    clog << "Test: Bool_Characters Class passed tests successfully" << endl;
}
