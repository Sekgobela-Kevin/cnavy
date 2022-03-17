#include <iostream>
#include <cassert>
#include "../character.hpp"

using namespace std;

/**  g++ character.cpp 
 * character_compute.cpp 
 * test\character_test.cpp
*/

void Character_Test(){
    clog << "Test: Started Character Class Test using" << endl;

    wchar_t char_ = 'a';  
    Character obj(char_);
    
    assert(obj.getCurrentChar() == char_);
    obj.setCurrentChar('@', true);
    assert(obj.getCurrentChar() == '@');

    assert(obj.isASCII());
    obj.setCurrentChar('@', true);
    assert(obj.isASCII());
    obj.isASCII(false);
    assert(!obj.isASCII());
    obj.setCurrentChar('\t', true);

    assert(!obj.isalnum());
    obj.setCurrentChar('H', true);
    assert(obj.isalnum());
    obj.isalnum(false);
    assert(!obj.isalnum());

    assert(obj.isalpha());
    obj.setCurrentChar('(', true);
    assert(!obj.isalpha());
    obj.isalpha(true);
    assert(obj.isalpha());

    assert(obj.isblank() == false);
    obj.setCurrentChar('H', true);
    assert(!obj.isblank());
    obj.isblank(true);
    assert(obj.isblank());

    assert(obj.iscntrl() == false);
    obj.setCurrentChar('\t', true);
    assert(obj.iscntrl());
    obj.iscntrl(false);
    assert(!obj.iscntrl());

    assert(obj.isdigit() == false);
    obj.setCurrentChar('7', true);
    assert(obj.isdigit());
    obj.isdigit(false);
    assert(!obj.isdigit());

    assert(obj.isgraph());
    obj.setCurrentChar('H', true);
    assert(obj.isgraph());
    obj.isgraph(false);
    assert(!obj.isgraph());

    assert(!obj.islower());
    obj.setCurrentChar('h', true);
    assert(obj.islower());
    obj.islower(false);
    assert(!obj.islower());

    assert(obj.isprint());
    obj.setCurrentChar('6', true);
    assert(obj.isprint());
    obj.isprint(false);
    assert(!obj.isprint());

    assert(obj.ispunct() == false);
    obj.setCurrentChar('?', true);
    assert(obj.ispunct());
    obj.ispunct(false);
    assert(obj.ispunct() == false);

    assert(obj.isspace() == false);
    obj.setCurrentChar('\t', true);
    assert(obj.isspace());
    obj.isspace(false);
    assert(obj.isspace() == false);

    obj.setCurrentChar('H', true);
    assert(obj.isupper());
    obj.setCurrentChar('h', true);
    assert(obj.isupper() == false);
    obj.isupper(true);
    assert(obj.isupper());

    assert(!obj.isxdigit());
    obj.setCurrentChar('b', true);
    assert(obj.isxdigit());
    obj.isxdigit(false);
    assert(!obj.isxdigit());


    clog << "Test: Character class passed tests successfully" << endl;
}

int main(){
    Character_Test();
}