#pragma once
#include "raw_token.hpp"

/**
 * @brief Basic token that contain only token level data.
 * Only non context data is included without context specific
 * data like index or span/doc object its part of.
 * 
 */
class Basic_Token : Raw_Token{
    // Raw_Token is expected to be generic just as Raw_Tokenise
    // That may be changed in future but now Basic_Token is used
    using Raw_Token::Raw_Token;
};