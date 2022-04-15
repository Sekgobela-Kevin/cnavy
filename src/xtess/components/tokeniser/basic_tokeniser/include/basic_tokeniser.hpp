#pragma once
#include "raw_tokenise.hpp"
#include "basic_character.hpp"
#include "basic_token.hpp"

/**
 * @brief Tokenises text into tokens that are created from shared object. Bother character and 
 * the tokens are shared. Changes in one token would reflect to other token that reference from
 * same object in shared objects.
 * 
 */
class Basic_Tokeniser : public Raw_Tokenise<Basic_Character, Basic_Token>{
    using Raw_Tokenise<Basic_Character, Basic_Token>::Raw_Tokenise;
};