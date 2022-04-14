#pragma once
#include "raw_tokenise.hpp"

/**
 * @brief Tokenises text into tokens that are created from shared object. Bother character and 
 * the tokens are shared. Changes in one token would reflect to other token that reference from
 * same object in shared objects.
 * 
 */
class Basic_Tokeniser : public Raw_Tokenise<Character, Raw_Token>{
    using Raw_Tokenise<Character, Raw_Token>::Raw_Tokenise;
};