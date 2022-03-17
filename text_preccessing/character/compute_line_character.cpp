#include "line_character.hpp"


bool Compute_Line_Character::computeIsNewLineChar(wchar_t character){
    return character == L'\n';
}

bool Compute_Line_Character::computeIsQuestChar(wchar_t character){
    return character == L'?';
}
