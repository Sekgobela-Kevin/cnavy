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

    assert(obj.isascii());
    obj.setCurrentChar('@', true);
    assert(obj.isascii());
    obj.setCurrentChar('\t', true);

    assert(!obj.isalnum());
    obj.setCurrentChar('H', true);
    assert(obj.isalnum());

    assert(obj.isalpha());
    obj.setCurrentChar('(', true);
    assert(!obj.isalpha());

    assert(obj.isblank() == false);
    obj.setCurrentChar('H', true);
    assert(!obj.isblank());

    assert(obj.iscntrl() == false);
    obj.setCurrentChar('\t', true);
    assert(obj.iscntrl());

    assert(obj.isdigit() == false);
    obj.setCurrentChar('7', true);
    assert(obj.isdigit());

    assert(obj.isgraph());
    obj.setCurrentChar('H', true);
    assert(obj.isgraph());

    assert(!obj.islower());
    obj.setCurrentChar('h', true);
    assert(obj.islower());

    assert(obj.isprint());
    obj.setCurrentChar('6', true);
    assert(obj.isprint());

    assert(obj.ispunct() == false);
    obj.setCurrentChar('?', true);
    assert(obj.ispunct());

    assert(obj.isspace() == false);
    obj.setCurrentChar('\t', true);
    assert(obj.isspace());


    obj.setCurrentChar('H', true);
    assert(obj.isupper());
    obj.setCurrentChar('h', true);
    assert(obj.isupper() == false);

    assert(!obj.isxdigit());
    obj.setCurrentChar('b', true);
    assert(obj.isxdigit());


    clog << "Test: Character class passed tests successfully" << endl;
}

int main(){
    Character_Test();
}