#include "character.hpp"


Character::Character(wchar_t input_char){
    this->current_char = input_char;
    //this->updateAttrs(input_char);

}

void Character::updateAttrs(wchar_t input_char){
    this->is_ASCII = computeIsASCII(input_char);
    this->is_alnum = computeIsAlnum(input_char);
    this->is_alpha = computeIsAlpha(input_char);
    this->is_blank = computeIsBlank(input_char) ;
    this->is_cntrl = computeIsCtrl(input_char);
    this->is_digit = computeIsDigit(input_char);
    this->is_lower = computeIsLower(input_char);
    this->is_print = computeIsPrint(input_char);
    this->is_punct = computeIsPunct(input_char);
    this->is_space = computeIsSpace(input_char);
    this->is_upper = computeIsUpper(input_char);
    this->is_xdigit = computeIsXdigit(input_char);
    this->is_graph = computeIsGraph(input_char);

    this->lower_char = computeToLower(input_char);
    this->upper_char = computeToUpper(input_char);
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
    return this->is_ASCII;
}
void Character::isASCII(bool value){
    this->is_ASCII = value;
}


bool Character::isalnum(){
    return this->is_alnum;
}
void Character::isalnum(bool value){
    this->is_alnum = value;
}


bool Character::isalpha(){
    return this->is_alpha;
}
void Character::isalpha(bool value){
    this->is_alpha = value;
}


bool Character::isblank(){
    return this->is_blank;
}
void Character::isblank(bool value){
    this->is_blank = value;
}

bool Character::iscntrl(){
    return this->is_cntrl;
}
void Character::iscntrl(bool value){
    this->is_cntrl = value;
}


bool Character::isdigit(){
    return this->is_digit;
}
void Character::isdigit(bool value){
    this->is_digit = value;
}

bool Character::isgraph(){
    return this->is_graph;
}
void Character::isgraph(bool value){
    this->is_graph = value;
}

bool Character::islower(){
    return this->is_lower;
}
void Character::islower(bool value){
    this->is_lower = value;
}

bool Character::isprint(){
    return this->is_print;
}
void Character::isprint(bool value){
    this->is_print = value;
}

bool Character::ispunct(){
    return this->is_punct;
}
void Character::ispunct(bool value){
    this->is_punct = value;
}

bool Character::isspace(){
    return this->is_space;
}
void Character::isspace(bool value){
    this->is_space = value;
}

bool Character::isupper(){
    return this->is_upper;
}
void Character::isupper(bool value){
    this->is_upper = value;
}

bool Character::isxdigit(){
    return this->is_xdigit;
}
void Character::isxdigit(bool value){
    this->is_xdigit = value;
}

wchar_t Character::tolower(){
    return this->lower_char;
}
void Character::tolower(wchar_t character){
    this->lower_char = character;
}

wchar_t Character::toupper(){
    return this->upper_char;
}
void Character::toupper(wchar_t character){
    this->upper_char = character;
}
