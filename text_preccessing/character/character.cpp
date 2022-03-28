#include "character.hpp"


Character::Character(char_type input_char){
    this->updateAttrs(input_char);
}

void Character::updateAttrs(char_type input_char){
    this->current_char = input_char;

    this->is_ascii = Character_Compute::computeIsAscii(input_char);
    this->is_alnum = Character_Compute::computeIsAlnum(input_char);
    this->is_alpha = Character_Compute::computeIsAlpha(input_char);
    this->is_blank = Character_Compute::computeIsBlank(input_char) ;
    this->is_cntrl = Character_Compute::computeIsCtrl(input_char);
    this->is_digit = Character_Compute::computeIsDigit(input_char);
    this->is_lower = Character_Compute::computeIsLower(input_char);
    this->is_print = Character_Compute::computeIsPrint(input_char);
    this->is_punct = Character_Compute::computeIsPunct(input_char);
    this->is_space = Character_Compute::computeIsSpace(input_char);
    this->is_upper = Character_Compute::computeIsUpper(input_char);
    this->is_xdigit = Character_Compute::computeIsXdigit(input_char);
    this->is_graph = Character_Compute::computeIsGraph(input_char);

    this->lower_char = Character_Compute::computeToLower(input_char);
    this->upper_char = Character_Compute::computeToUpper(input_char);
}

void Character::setCurrentChar(char_type input_char, bool update_atrr){
    if(update_atrr){
        this->updateAttrs(this->current_char);
    }
}

char_type Character::getCurrentChar(){
    return this->current_char;
}

bool Character::isascii(){
    return this->is_ascii;
}
void Character::isascii(bool value){
    this->is_ascii = value;
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

char_type Character::tolower(){
    return this->lower_char;
}
void Character::tolower(char_type character){
    this->lower_char = character;
}

char_type Character::toupper(){
    return this->upper_char;
}
void Character::toupper(char_type character){
    this->upper_char = character;
}
