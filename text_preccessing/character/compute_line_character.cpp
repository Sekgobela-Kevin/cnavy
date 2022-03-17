#include "line_character.hpp"


bool Compute_Line_Character::computeIsNewLineChar(char_type character){
    return character == L'\n';
}

bool Compute_Line_Character::computeIsQuestChar(char_type character){
    return character == L'?';
}
