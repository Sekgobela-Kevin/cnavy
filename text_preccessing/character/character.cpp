#include "character.hpp"


Character::Character(wchar_t input_char){
    this->current_char = input_char;
    //this->updateAttrs(input_char);

}

void Character::updateAttrs(wchar_t input_char){
    
}

void Character::setCurrentChar(wchar_t input_char, bool update_atrr){
    this->current_char = input_char;
    if(update_atrr){
        this->updateAttrs(this->current_char);
    }
}

wchar_t Character::getCurrentChar(){
    return this->current_char;
}

bool Character::isASCII(){
    return Character_Compute::computeIsASCII(this->current_char);
}



bool Character::isalnum(){
    return Character_Compute::computeIsAlnum(this->current_char);
}


bool Character::isalpha(){
    return Character_Compute::computeIsAlpha(this->current_char);
}


bool Character::isblank(){
    return Character_Compute::computeIsBlank(this->current_char);
}


bool Character::iscntrl(){
    return Character_Compute::computeIsCtrl(this->current_char);
}


bool Character::isdigit(){
    return Character_Compute::computeIsDigit(this->current_char);
}

bool Character::isgraph(){
    return Character_Compute::computeIsGraph(this->current_char);
}

bool Character::islower(){
    return Character_Compute::computeIsLower(this->current_char);
}

bool Character::isprint(){
    return Character_Compute::computeIsPrint(this->current_char);
}

bool Character::ispunct(){
    return Character_Compute::computeIsPunct(this->current_char);
}

bool Character::isspace(){
    return Character_Compute::computeIsSpace(this->current_char);
}

bool Character::isupper(){
    return Character_Compute::computeIsUpper(this->current_char);
}

bool Character::isxdigit(){
    return Character_Compute::computeIsXdigit(this->current_char);
}

wchar_t Character::tolower(){
    return Character_Compute::computeToLower(this->current_char);
}

wchar_t Character::toupper(){
    return Character_Compute::computeToUpper(this->current_char);
}
