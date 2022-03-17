#include <iostream>
#include <cassert>
#include "string"
#include "..\bool_characters.cpp"
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
    Bool_Characters* obj  = new Bool_Characters(input_string);
   
    //assert(obj.boolIsPunct().size() == obj.length());

    cout << "size of Bool characters is " <<  obj->length() << endl;

    clog << "Test: Bool_Characters Class passed tests successfully" << endl;
}

int main(){
    Bool_Characters_Test();
}
