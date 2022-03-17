#include <iostream>
#include <cctype>
#include "character.hpp"


bool Character_Compute::computeIsASCII(wchar_t input_char){
    // ANSCII characters are 7 bit ==> 2^7 ==> 128(max value)
    return static_cast<unsigned char>(input_char) < 128;
}

bool Character_Compute::computeIsAlnum(wchar_t input_char){
    return std::iswalnum(input_char);
}

bool Character_Compute::computeIsAlpha(wchar_t input_char){
    return std::iswalpha(input_char);
}

bool Character_Compute::computeIsBlank(wchar_t input_char){
    return std::iswblank(input_char);
}

bool Character_Compute::computeIsCtrl(wchar_t input_char){
    return std::iswcntrl(input_char);
}

bool Character_Compute::computeIsDigit(wchar_t input_char){
    return std::iswdigit(input_char);
}

bool Character_Compute::computeIsGraph(wchar_t input_char){
    return std::iswgraph(input_char);
}

bool Character_Compute::computeIsLower(wchar_t input_char){
    return std::iswlower(input_char);
}

bool Character_Compute::computeIsPrint(wchar_t input_char){
    return std::iswprint(input_char);
}

bool Character_Compute::computeIsPunct(wchar_t input_char){
    return std::iswpunct(input_char);
}

bool Character_Compute::computeIsSpace(wchar_t input_char){
    return std::iswspace(input_char);
}

bool Character_Compute::computeIsUpper(wchar_t input_char){
    return std::iswupper(input_char);
}

bool Character_Compute::computeIsXdigit(wchar_t input_char){
    return std::iswxdigit(input_char);
}

wchar_t Character_Compute::computeToLower(wchar_t input_char){
    return std::towlower(input_char);
}

wchar_t Character_Compute::computeToUpper(wchar_t input_char){
    return std::towupper(input_char);
}
