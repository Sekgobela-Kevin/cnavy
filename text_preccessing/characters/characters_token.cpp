#include "characters_token.hpp"

Characters_Token::Characters_Token(Characters& chars_obj) : chars_obj(chars_obj){

        // booleans representing if corresponding character is alphanumeric
        this->bool_is_alnum = Bool_Characters::isAlnum(chars_obj);
        // booleans representing if corresponding character is alphabetic
        this->bool_is_alpha = Bool_Characters::isAlpha(chars_obj);
        // booleans representing if corresponding character is ascii
        this->bool_is_ascii = Bool_Characters::isASCII(chars_obj);
        // booleans representing if corresponding character is blank
        this->bool_is_blank = Bool_Characters::isBlank(chars_obj);
        // booleans representing if corresponding character is control character
        this->bool_is_cntrl = Bool_Characters::isCntrl(chars_obj);
        // booleans representing if corresponding character is digit
        this->bool_is_digit = Bool_Characters::isDigit(chars_obj);
        // booleans representing if corresponding character is graphical
        this->bool_is_graph = Bool_Characters::isGraph(chars_obj);
        // booleans representing if corresponding character is in lowercase
        this->bool_is_lower = Bool_Characters::isLower(chars_obj);
        // booleans representing if corresponding character is printable
        this->bool_is_print = Bool_Characters::isPrint(chars_obj);
        // booleans representing if corresponding character is punctuation
        this->bool_is_punct = Bool_Characters::isPunct(chars_obj);
        // booleans representing if corresponding character is space
        this->bool_is_space = Bool_Characters::isSpace(chars_obj);
        // booleans representing if corresponding character is in uppercase
        this->bool_is_upper = Bool_Characters::isUpper(chars_obj);
        // booleans representing if corresponding character is hexadecial digit
        this->bool_is_xdigit = Bool_Characters::isXdigit(chars_obj);

        // ratio characters

        // proportion/ratio of alphanumeric characters in token
        this->ratio_is_alnum = Ratio_Characters::isAlnum(chars_obj);
        // proportion/ratio of alphabetic characters in token
        this->ratio_is_alpha = Ratio_Characters::isAlpha(chars_obj);
        // proportion/ratio of ascii characters in token
        this->ratio_is_ascii = Ratio_Characters::isASCII(chars_obj);
        // proportion/ratio of blank characters in token
        this->ratio_is_blank = Ratio_Characters::isBlank(chars_obj);
        // proportion/ratio of control characters in token
        this->ratio_is_cntrl = Ratio_Characters::isCntrl(chars_obj);
        // proportion/ratio of digits in token
        this->ratio_is_digit = Ratio_Characters::isDigit(chars_obj);
        // proportion/ratio of graphical characters in token
        this->ratio_is_graph = Ratio_Characters::isGraph(chars_obj);
        // proportion/ratio of lowercase characters in token
        this->ratio_is_lower = Ratio_Characters::isLower(chars_obj);
        // proportion/ratio of printable characters in token
        this->ratio_is_print = Ratio_Characters::isPrint(chars_obj);
        // proportion/ratio of punctuation characters in token
        this->ratio_is_punct = Ratio_Characters::isPunct(chars_obj);
        // proportion/ratio of space characters in token
        this->ratio_is_space = Ratio_Characters::isSpace(chars_obj);
        // proportion/ratio of uppercase characters in token
        this->ratio_is_upper = Ratio_Characters::isUpper(chars_obj);
        // proportion/ratio of hexadecimal digits in token
        this->ratio_is_xdigit = Ratio_Characters::isXdigit(chars_obj);

        // summary characters(using ratio of 1)

        // checks if token is alphanumeric
        this->is_alnum;
        // checks if token is alphabetic
        this->is_alpha;
        // checks if token is ascii
        this->is_ascii;
        // checks if token is blank
        this->is_blank;
        // checks is made of control characters
        this->is_cntrl;
        // checks if token is digit
        this->is_digit;
        // checks if token has all characters being graphical characters
        this->is_graph;
        // checks if token is in lowercase
        this->is_lower;
        // checks if token has all characters being printable
        this->is_print;
        // checks if token has all characters being punctuations
        this->is_punct;
        // checks if token all characters are space character
        this->is_space;
        // checks if token his in uppercase
        this->is_upper;
        // checks if token has all characters are hexadecimal digits
        this->is_xdigit;

        // token text
        this->text = chars_obj.getText();   
        // lowercase verstion of token
        this->lower = chars_obj.getLower();
        // uppercase version of token
        this->upper = chars_obj.getUpper();
        // length of token
        this->length = text.length();   
};


bool Summary_Characters::ratioCompare(float true_ratio, float result_ratio){
    return  result_ratio >= true_ratio;
}

bool Characters_Token::isAlnum(float true_ratio){
    return Summary_Characters::ratioCompare(true_ratio, this->ratio_is_alpha);
}

bool Characters_Token::isAlpha(float true_ratio){
    return Summary_Characters::ratioCompare(true_ratio, this->ratio_is_alpha);
}

bool Characters_Token::isAscii(float true_ratio){
    return Summary_Characters::ratioCompare(true_ratio, this->ratio_is_ascii);
}

bool Characters_Token::isBlank(float true_ratio){
    return Summary_Characters::ratioCompare(true_ratio, this->ratio_is_blank);
}

bool Characters_Token::isCntrl(float true_ratio){
    return Summary_Characters::ratioCompare(true_ratio, this->ratio_is_cntrl);
}

bool Characters_Token::isDigit(float true_ratio){
    return Summary_Characters::ratioCompare(true_ratio, this->ratio_is_digit);
}

bool Characters_Token::isGraph(float true_ratio){
    return Summary_Characters::ratioCompare(true_ratio, this->ratio_is_graph);
}

bool Characters_Token::isLower(float true_ratio){
    return Summary_Characters::ratioCompare(true_ratio, this->ratio_is_lower);
}

bool Characters_Token::isPrint(float true_ratio){
    return Summary_Characters::ratioCompare(true_ratio, this->ratio_is_print);
}

bool Characters_Token::isPunct(float true_ratio){
    return Summary_Characters::ratioCompare(true_ratio, this->ratio_is_punct);
}

bool Characters_Token::isSpace(float true_ratio){
    return Summary_Characters::ratioCompare(true_ratio, this->ratio_is_space);
}

bool Characters_Token::isUpper(float true_ratio){
    return Summary_Characters::ratioCompare(true_ratio, this->ratio_is_upper);
}

bool Characters_Token::isXdigit(float true_ratio){;
    return Summary_Characters::ratioCompare(true_ratio, this->ratio_is_xdigit);
}
