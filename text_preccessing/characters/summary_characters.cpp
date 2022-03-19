#include "summary_characters.hpp"


bool Summary_Characters::isAlnum(Characters chars_obj, int true_ratio){
    int result_ratio = Ratio_Characters::isAlnum(chars_obj);
    return result_ratio >= true_ratio;
}

bool Summary_Characters::isAlpha(Characters chars_obj, int true_ratio){
    int result_ratio = Ratio_Characters::isAlpha(chars_obj);
    return result_ratio >= true_ratio;
}

bool Summary_Characters::isASCII(Characters chars_obj, int true_ratio){
    int result_ratio = Ratio_Characters::isASCII(chars_obj);
    return result_ratio >= true_ratio;
}

bool Summary_Characters::isBlank(Characters chars_obj, int true_ratio){
    int result_ratio = Ratio_Characters::isBlank(chars_obj);
    return result_ratio >= true_ratio;
}

bool Summary_Characters::isCntrl(Characters chars_obj, int true_ratio){
    int result_ratio = Ratio_Characters::isCntrl(chars_obj);
    return result_ratio >= true_ratio;
}

bool Summary_Characters::isDigit(Characters chars_obj, int true_ratio){
    int result_ratio = Ratio_Characters::isDigit(chars_obj);
    return result_ratio >= true_ratio;
}

bool Summary_Characters::isGraph(Characters chars_obj, int true_ratio){
    int result_ratio = Ratio_Characters::isGraph(chars_obj);
    return result_ratio >= true_ratio;
}

bool Summary_Characters::isLower(Characters chars_obj, int true_ratio){
    int result_ratio = Ratio_Characters::isLower(chars_obj);
    return result_ratio >= true_ratio;
}

bool Summary_Characters::isPrint(Characters chars_obj, int true_ratio){
    int result_ratio = Ratio_Characters::isPrint(chars_obj);
    return result_ratio >= true_ratio;
}

bool Summary_Characters::isPunct(Characters chars_obj, int true_ratio){
    int result_ratio = Ratio_Characters::isPunct(chars_obj);
    return result_ratio >= true_ratio;
}

bool Summary_Characters::isSpace(Characters chars_obj, int true_ratio){
    int result_ratio = Ratio_Characters::isSpace(chars_obj);
    return result_ratio >= true_ratio;
}

bool Summary_Characters::isUpper(Characters chars_obj, int true_ratio){
    int result_ratio = Ratio_Characters::isUpper(chars_obj);
    return result_ratio >= true_ratio;
}

bool Summary_Characters::isXdigit(Characters chars_obj, int true_ratio){
    int result_ratio = Ratio_Characters::isXdigit(chars_obj);
    return result_ratio >= true_ratio;
}

