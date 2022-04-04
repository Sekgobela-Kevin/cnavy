#include <iostream>
#include <cassert>
#include <string>
#include "../shared_characters.hpp"
using namespace std;

/*
 g++ ..\character\character.cpp ..\character\character_compute.cpp 
 characters.cpp bool_characters.cpp ratio_characters.cpp 
 summary_characters.cpp bool_set.cpp ..\shared\shared_characters.cpp
 ..\shared\test\shared_characters_test.cpp
*/

void Shared_Characters_Test(){
    clog << "Test: Started Shared_Characters Class Test using" << endl;
    string* input_string = new string(100000000, 'c');

    /*string obj_input_string;
    string obj2_input_string;

    cout << "Enter text: ";
    cin >> obj_input_string;
    */
   
    //Characters* chars_obj = new Characters(input_string);

    Shared_Characters* shared_chars = new Shared_Characters(*input_string);

    clog << "size shared size is " << shared_chars->size() << endl;

    clog << "Test: Shared_Characters Class passed tests successfully" << endl;

    delete input_string;
    //while(true);
}


int main(){
    Shared_Characters_Test();
}