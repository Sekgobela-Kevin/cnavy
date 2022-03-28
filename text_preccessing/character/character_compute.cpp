#include <iostream>
#include <cctype>
#include "character.hpp"


bool Character_Compute::computeIsAscii(char_type input_char){
    // ANSCII characters are 7 bit ==> 2^7 ==> 128(max value)
    return static_cast<unsigned char>(input_char) < 128;
}

bool Character_Compute::computeIsAlnum(char_type input_char){
    return std::iswalnum(input_char);
}

bool Character_Compute::computeIsAlpha(char_type input_char){
    return std::iswalpha(input_char);
}

bool Character_Compute::computeIsBlank(char_type input_char){
    return std::iswblank(input_char);
}

bool Character_Compute::computeIsCtrl(char_type input_char){
    return std::iswcntrl(input_char);
}

bool Character_Compute::computeIsDigit(char_type input_char){
    return std::iswdigit(input_char);
}

bool Character_Compute::computeIsGraph(char_type input_char){
    return std::iswgraph(input_char);
}

bool Character_Compute::computeIsLower(char_type input_char){
    return std::iswlower(input_char);
}

bool Character_Compute::computeIsPrint(char_type input_char){
    return std::iswprint(input_char);
}

bool Character_Compute::computeIsPunct(char_type input_char){
    return std::iswpunct(input_char);
}

bool Character_Compute::computeIsSpace(char_type input_char){
    return std::iswspace(input_char);
}

bool Character_Compute::computeIsUpper(char_type input_char){
    return std::iswupper(input_char);
}

bool Character_Compute::computeIsXdigit(char_type input_char){
    return std::iswxdigit(input_char);
}

char_type Character_Compute::computeToLower(char_type input_char){
    return std::towlower(input_char);
}

char_type Character_Compute::computeToUpper(char_type input_char){
    return std::towupper(input_char);
}
