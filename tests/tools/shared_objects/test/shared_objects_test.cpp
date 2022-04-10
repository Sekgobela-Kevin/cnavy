#include <iostream>
#include <cassert>
#include <string>
#include <iterator>

// trick to include both declaration and definition of templates
// this may bloat the application since source file is included
#include "shared_objects.hpp"
#include "character.hpp"
using namespace std;

// no need compile shared_objects_def.cpp as its already included in shared_objects.hpp
/*
 g++ ..\character\character.cpp ..\character\character_compute.cpp 
 characters.cpp ..\shared\test\shared_objects_test.cpp
*/

void Shared_Characters_Test(){
    clog << "Test: Started Shared_Objects Class Test using" << endl;
    string* input_string = new string(100000000, 'c');

    /*string obj_input_string;
    string obj2_input_string;

    cout << "Enter text: ";
    cin >> obj_input_string;
    */
   
    //Characters* chars_obj = new Characters(input_string);
    string::iterator beg = input_string->begin();
    string::iterator end = input_string->end();

    Shared_Objects<char_type, Character>* shared_chars;
    shared_chars =  new Shared_Objects<char_type, Character>(beg, end);



    clog << "size shared size is " << shared_chars->size() << endl;

    clog << "Test: Shared_Objects Class passed tests successfully" << endl;

    delete input_string;
    //while(true);
}


int main(){
    Shared_Characters_Test();
}