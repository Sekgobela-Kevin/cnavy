#include "algorithm"
#include "functional"
#include "ratio_characters.hpp"


int Ratio_Characters::getBoolRatio(bool_chars_type bools_collection){
    int true_count = std::count(bools_collection.begin(), bools_collection.end(), true);
    return true_count / bools_collection.size();
}

int Ratio_Characters::isAlnum(Characters chars_obj){
    bool_chars_type bools_collection = Bool_Characters::isAlnum(chars_obj);
    return Ratio_Characters::getBoolRatio(bools_collection);
}

int Ratio_Characters::isAlpha(Characters chars_obj){
    bool_chars_type bools_collection = Bool_Characters::isAlpha(chars_obj);
    return Ratio_Characters::getBoolRatio(bools_collection);
}

int Ratio_Characters::isASCII(Characters chars_obj){
    bool_chars_type bools_collection = Bool_Characters::isASCII(chars_obj);
    return Ratio_Characters::getBoolRatio(bools_collection);
}

int Ratio_Characters::isBlank(Characters chars_obj){
    bool_chars_type bools_collection = Bool_Characters::isBlank(chars_obj);
    return Ratio_Characters::getBoolRatio(bools_collection);
}

int Ratio_Characters::isCntrl(Characters chars_obj){
    bool_chars_type bools_collection = Bool_Characters::isCntrl(chars_obj);
    return Ratio_Characters::getBoolRatio(bools_collection);
}

int Ratio_Characters::isDigit(Characters chars_obj){
    bool_chars_type bools_collection = Bool_Characters::isDigit(chars_obj);
    return Ratio_Characters::getBoolRatio(bools_collection);
}

int Ratio_Characters::isGraph(Characters chars_obj){
    bool_chars_type bools_collection = Bool_Characters::isGraph(chars_obj);
    return Ratio_Characters::getBoolRatio(bools_collection);
}

int Ratio_Characters::isLower(Characters chars_obj){
    bool_chars_type bools_collection = Bool_Characters::isLower(chars_obj);
    return Ratio_Characters::getBoolRatio(bools_collection);
}

int Ratio_Characters::isPrint(Characters chars_obj){
    bool_chars_type bools_collection = Bool_Characters::isPrint(chars_obj);
    return Ratio_Characters::getBoolRatio(bools_collection);
}

int Ratio_Characters::isPunct(Characters chars_obj){
    bool_chars_type bools_collection = Bool_Characters::isPunct(chars_obj);
    return Ratio_Characters::getBoolRatio(bools_collection);
}

int Ratio_Characters::isSpace(Characters chars_obj){
    bool_chars_type bools_collection = Bool_Characters::isSpace(chars_obj);
    return Ratio_Characters::getBoolRatio(bools_collection);
}

int Ratio_Characters::isUpper(Characters chars_obj){
    bool_chars_type bools_collection = Bool_Characters::isUpper(chars_obj);
    return Ratio_Characters::getBoolRatio(bools_collection);
}

int Ratio_Characters::isXdigit(Characters chars_obj){
    bool_chars_type bools_collection = Bool_Characters::isXdigit(chars_obj);
    return Ratio_Characters::getBoolRatio(bools_collection);
}
