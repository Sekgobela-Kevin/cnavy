#include "characters_token.hpp"
#include "reference_token.hpp"

Reference_Token::Reference_Token(Characters_Token& chars_token) :

// argumets via object initialization lists
chars_token(chars_token),
chars_obj(chars_token.chars_obj),

// booleans representing if corresponding character is alphanumeric
bool_is_alnum(chars_token.bool_is_alnum),
// booleans representing if corresponding character is alphabetic
bool_is_alpha(chars_token.bool_is_alpha),
// booleans representing if corresponding character is ascii
bool_is_ascii(chars_token.bool_is_ascii),
// booleans representing if corresponding character is blank
bool_is_blank(chars_token.bool_is_blank),
// booleans representing if corresponding character is control character
bool_is_cntrl(chars_token.bool_is_cntrl),
// booleans representing if corresponding character is digit
bool_is_digit(chars_token.bool_is_digit),
// booleans representing if corresponding character is graphical
bool_is_graph(chars_token.bool_is_graph),
// booleans representing if corresponding character is in lowercase
bool_is_lower(chars_token.bool_is_lower),
// booleans representing if corresponding character is printable
bool_is_print(chars_token.bool_is_print),
// booleans representing if corresponding character is punctuation
bool_is_punct(chars_token.bool_is_punct),
// booleans representing if corresponding character is space
bool_is_space(chars_token.bool_is_space),
// booleans representing if corresponding character is in uppercase
bool_is_upper(chars_token.bool_is_upper),
// booleans representing if corresponding character is hexadecial digit
bool_is_xdigit(chars_token.bool_is_xdigit),

// ratio characters

// proportion/ratio of alphanumeric characters in token
ratio_is_alnum(chars_token.ratio_is_alnum),
// proportion/ratio of alphabetic characters in token
ratio_is_alpha(chars_token.ratio_is_alpha),
// proportion/ratio of ascii characters in token
ratio_is_ascii(chars_token.ratio_is_ascii),
// proportion/ratio of blank characters in token
ratio_is_blank(chars_token.ratio_is_blank),
// proportion/ratio of control characters in token
ratio_is_cntrl(chars_token.ratio_is_cntrl),
// proportion/ratio of digits in token
ratio_is_digit(chars_token.ratio_is_digit),
// proportion/ratio of graphical characters in token
ratio_is_graph(chars_token.ratio_is_graph),
// proportion/ratio of lowercase characters in token
ratio_is_lower(chars_token.ratio_is_lower),
// proportion/ratio of printable characters in token
ratio_is_print(chars_token.ratio_is_print),
// proportion/ratio of punctuation characters in token
ratio_is_punct(chars_token.ratio_is_punct),
// proportion/ratio of space characters in token
ratio_is_space(chars_token.ratio_is_space),
// proportion/ratio of uppercase characters in token
ratio_is_upper(chars_token.ratio_is_upper),
// proportion/ratio of hexadecimal digits in token
ratio_is_xdigit(chars_token.ratio_is_xdigit),

// summary characters(using ratio of 1)

// checks if token is alphanumeric
is_alnum(chars_token.is_alnum),
// checks if token is alphabetic
is_alpha(chars_token.is_alpha),
// checks if token is ascii
is_ascii(chars_token.is_ascii),
// checks if token is blank
is_blank(chars_token.is_blank),
// checks is made of control characters
is_cntrl(chars_token.is_cntrl),
// checks if token is digit
is_digit(chars_token.is_digit),
// checks if token has all characters being graphical characters
is_graph(chars_token.is_graph),
// checks if token is in lowercase
is_lower(chars_token.is_lower),
// checks if token has all characters being printable
is_print(chars_token.is_print),
// checks if token has all characters being punctuations
is_punct(chars_token.is_alnum),
// checks if token all characters are space character
is_space(chars_token.is_space),
// checks if token his in uppercase
is_upper(chars_token.is_upper),
// checks if token has all characters are hexadecimal digits
is_xdigit(chars_token.is_xdigit),

// token text
text(chars_token.text),   
// lowercase verstion of token
lower(chars_token.lower),
// uppercase version of token
upper(chars_token.upper),
// length of token
length(chars_token.length){

}


bool Reference_Token::isAlnum(float min_ratio) const{
    return chars_token.isAlnum(min_ratio);
}

bool Reference_Token::isAlpha(float min_ratio) const{
    return chars_token.isAlpha(min_ratio);
}

bool Reference_Token::isAscii(float min_ratio) const{
    return chars_token.isAscii(min_ratio);
}

bool Reference_Token::isBlank(float min_ratio) const{
    return chars_token.isBlank(min_ratio);
}

bool Reference_Token::isCntrl(float min_ratio) const{
    return chars_token.isCntrl(min_ratio);
}

bool Reference_Token::isDigit(float min_ratio) const{
    return chars_token.isDigit(min_ratio);
}

bool Reference_Token::isGraph(float min_ratio) const{
    return chars_token.isGraph(min_ratio);
}

bool Reference_Token::isLower(float min_ratio) const{
    return chars_token.isLower(min_ratio);
}

bool Reference_Token::isPrint(float min_ratio) const{
    return chars_token.isPrint(min_ratio);
}

bool Reference_Token::isPunct(float min_ratio) const{
    return chars_token.isPunct(min_ratio);
}

bool Reference_Token::isSpace(float min_ratio) const{
    return chars_token.isSpace(min_ratio);
}

bool Reference_Token::isUpper(float min_ratio) const{
    return chars_token.isUpper(min_ratio);
}

bool Reference_Token::isXdigit(float min_ratio) const{;
    return chars_token.isXdigit(min_ratio);
}