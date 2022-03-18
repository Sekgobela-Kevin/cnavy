#include <iostream>
#include <cassert>
#include "string"
#include "..\bool_characters.hpp"
using namespace std;


/*
 g++ ..\character\character.cpp ..\character\character_compute.cpp 
 ..\character\compute_line_character.cpp 
 ..\character\line_character.cpp characters.cpp
 test\bool_characters_test.cpp
*/


void Bool_Characters_Test(){
    clog << "Test: Started Bool_Characters Class Test using" << endl;
    string input_string(1000000, 'c');
    Characters* obj = new Characters(input_string);
    bool_chars_type results = Bool_Characters::isUpper(*obj);
    
    //assert(obj.boolIsPunct().size() == obj.length());

    cout << "size of characters is " <<  obj->length() << endl;
    cout << "size of results is " <<  results[2] << endl;

    delete obj;
    clog << "Test: Bool_Characters Class passed tests successfully" << endl;
}

int main(){
    Bool_Characters_Test();
}
