#include <iostream>
#include "character.hpp"
#include "doctest.h"

using namespace std;

/**  g++ character.cpp 
 * character_compute.cpp 
 * test\character_test.cpp
*/

void Enable_Doctest_Character(){};

TEST_CASE("Character Class test"){
    clog << "Test: Started Character Class Test using" << endl;

    wchar_t char_ = 'a';  
    Character obj(char_);
    
    CHECK(obj.getCurrentChar() == char_);
    obj.setCurrentChar('@', true);
    CHECK(obj.getCurrentChar() == '@');

    CHECK(obj.isascii());
    obj.setCurrentChar('@', true);
    CHECK(obj.isascii());
    obj.setCurrentChar('\t', true);

    CHECK(!obj.isalnum());
    obj.setCurrentChar('H', true);
    CHECK(obj.isalnum());

    CHECK(obj.isalpha());
    obj.setCurrentChar('(', true);
    CHECK(!obj.isalpha());

    CHECK(obj.isblank() == false);
    obj.setCurrentChar('H', true);
    CHECK(!obj.isblank());

    CHECK(obj.iscntrl() == false);
    obj.setCurrentChar('\t', true);
    CHECK(obj.iscntrl());

    CHECK(obj.isdigit() == false);
    obj.setCurrentChar('7', true);
    CHECK(obj.isdigit());

    CHECK(obj.isgraph());
    obj.setCurrentChar('H', true);
    CHECK(obj.isgraph());

    CHECK(!obj.islower());
    obj.setCurrentChar('h', true);
    CHECK(obj.islower());

    CHECK(obj.isprint());
    obj.setCurrentChar('6', true);
    CHECK(obj.isprint());

    CHECK(obj.ispunct() == false);
    obj.setCurrentChar('?', true);
    CHECK(obj.ispunct());

    CHECK(obj.isspace() == false);
    obj.setCurrentChar('\t', true);
    CHECK(obj.isspace());


    obj.setCurrentChar('H', true);
    CHECK(obj.isupper());
    obj.setCurrentChar('h', true);
    CHECK(obj.isupper() == false);

    CHECK(!obj.isxdigit());
    obj.setCurrentChar('b', true);
    CHECK(obj.isxdigit());


    clog << "Test: Character class passed tests successfully" << endl;
}
