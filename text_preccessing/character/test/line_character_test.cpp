#include <iostream>
#include <cassert>
#include "..\line_character.hpp"
using namespace std;

/**g++ character.cpp character_compute.cpp 
 * compute_line_character.cpp 
 * line_character.cpp
 * test\line_character_test.cpp
*/

void Line_Character_Test(){
    clog << "Test: Started Line_Character Class Test using" << endl;
    char char_ = '\n';
    Line_Character obj(char_);
    assert(obj.isNewLineChar());
    obj.setCurrentChar('\n', true);
    assert(obj.isNewLineChar());
    obj.isNewLineChar(false);
    assert(!obj.isNewLineChar());

    assert(!obj.isQuestChar());
    obj.setCurrentChar('?', true);
    assert(obj.isQuestChar());
    obj.isQuestChar(false);
    assert(!obj.isQuestChar());

    assert(!obj.isAtLineBeg());
    obj.isAtLineBeg(true);
    assert(obj.isAtLineBeg());

    assert(!obj.isAtLineEnd());
    obj.isAtLineEnd(true);
    assert(obj.isAtLineEnd());

    clog << "Test: Line_Character class passed tests successfully" << endl;
}

int main(){
     Line_Character_Test();
}