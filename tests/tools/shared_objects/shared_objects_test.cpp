#include <iostream>
#include <cassert>
#include <string>
#include <iterator>

// trick to include both declaration and definition of templates
// this may bloat the application since source file is included
#include "character.hpp"
#include "shared_objects.hpp"
#include "doctest.h"
using namespace std;

// no need compile shared_objects_def.cpp as its already included in shared_objects.hpp
/*
 g++ ..\character\character.cpp ..\character\character_compute.cpp 
 characters.cpp ..\shared\test\shared_objects_test.cpp
*/

void Enable_Doctest_Tools_Shared_Objects(){};

TEST_CASE("Shared_Objects Class test"){
    clog << "Test: Started Shared_Objects Class Test using" << endl;
    string* input_string = new string("text");

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

    // check if string wasnt changed
    REQUIRE(*input_string == "text");
    // check duplicates removed
    // 't' is duplicated, its expected to be removed
    CHECK(shared_chars->size() == 3);
    CHECK(shared_chars->exists('e'));
    CHECK(shared_chars->get('e').char_ == 'e');
    CHECK(shared_chars->get('x').char_ == 'x');

    shared_chars->remove('e');
    CHECK(shared_chars->exists('e') == false);
    CHECK(shared_chars->size() == 2);

    shared_chars->add('a');
    CHECK(shared_chars->exists('a'));

    clog << "Test: Shared_Objects Class passed tests successfully" << endl;

    delete input_string;
}