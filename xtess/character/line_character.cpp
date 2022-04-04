#include "line_character.hpp"


Line_Character::Line_Character(char_type input_char) : Character(input_char){
    // C++ will call this method here and inside base class when creating it
    // To prevent multiple calls, remove similar line in base Class constructor
    //this->updateAttrs(input_char);
}

void Line_Character::updateAttrs(char_type input_char){
    this->is_new_line_char = computeIsNewLineChar(this->is_new_line_char);
    this->is_quest_char = computeIsQuestChar(input_char);
    Character::updateAttrs(input_char);
}

bool Line_Character::isNewLineChar(){
    return computeIsNewLineChar(this->is_new_line_char);
}


bool Line_Character::isQuestChar(){
    return computeIsQuestChar(this->is_new_line_char);
}

bool Line_Character::isAtLineBeg(){
    return this->is_at_line_beg;
}
void Line_Character::isAtLineBeg(bool value){
    this->is_at_line_beg = value;
}

bool Line_Character::isAtLineEnd(){
    return this->is_at_line_end;
}
void Line_Character::isAtLineEnd(bool value){
    this->is_at_line_end = value;
}

