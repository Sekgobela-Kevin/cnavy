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
    string* input_string2 = new string("text data");

    /*string obj_input_string;
    string obj2_input_string;

    cout << "Enter text: ";
    cin >> obj_input_string;
    */
   
    //Characters* chars_obj = new Characters(input_string);
    string::iterator beg = input_string->begin();
    string::iterator end = input_string->end();

    
    Shared_Objects<char_type, Character>* shared_chars;
    Shared_Objects<char_type, Character>* shared_chars2;
    shared_chars =  new Shared_Objects<char_type, Character>(beg, end);
    shared_chars2 =  new Shared_Objects<char_type, Character>(input_string2->begin(), input_string2->end());


    // check if string wasnt changed
    REQUIRE(*input_string == "text");
    REQUIRE(*input_string2 == "text data");
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

    CHECK(shared_chars->getKeys().size() == shared_chars->size());
    CHECK(shared_chars->getValues().size() == shared_chars->size());
    
    for(auto key : shared_chars->getKeys()){
        CHECK(shared_chars->exists(key));
    }

    for(auto value : shared_chars->getValues()){
        CHECK(shared_chars->exists(value.char_));
    }

    // test overloaded operators
    for(auto pair_obj : *shared_chars){
        CHECK(shared_chars->exists(pair_obj.first));
    }

    CHECK((*shared_chars + *shared_chars2).size() > shared_chars->size());
    CHECK((*shared_chars + *shared_chars).size() == shared_chars->size());
    CHECK(shared_chars == shared_chars);
    CHECK(shared_chars != shared_chars2);

    

    clog << "Test: Shared_Objects Class passed tests successfully" << endl;

    delete input_string;
}