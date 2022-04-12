#include <iostream>

#include "line_character.hpp"
#include "doctest.h"
using namespace std;

/**g++ character.cpp character_compute.cpp 
 * compute_line_character.cpp 
 * line_character.cpp
 * test\line_character_test.cpp
*/

void Enable_Doctest_Line_Character(){};

TEST_CASE("Line_Character CLass test"){
    clog << "Test: Started Line_Character Class Test using" << endl;
    char char_ = '\n';
    Line_Character obj(char_);
    CHECK(obj.isNewLineChar());
    obj.setCurrentChar('\n', true);
    CHECK(obj.isNewLineChar());
    obj.isNewLineChar(false);
    CHECK(!obj.isNewLineChar());

    CHECK(!obj.isQuestChar());
    obj.setCurrentChar('?', true);
    CHECK(obj.isQuestChar());
    obj.isQuestChar(false);
    CHECK(!obj.isQuestChar());

    CHECK(!obj.isAtLineBeg());
    obj.isAtLineBeg(true);
    CHECK(obj.isAtLineBeg());

    CHECK(!obj.isAtLineEnd());
    obj.isAtLineEnd(true);
    CHECK(obj.isAtLineEnd());

    clog << "Test: Line_Character class passed tests successfully" << endl;
}
