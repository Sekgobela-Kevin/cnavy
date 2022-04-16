#include <iostream>
#include <iomanip>
#include <string>
#include <memory>
#include <functional>

#include "basic_tokeniser.hpp"

#include "doctest.h"
using namespace std;

/*
 g++ xtess/character/*.cpp xtess/characters/*.cpp xtess/shared/*.cpp 
 xtess/components/tokeniser/*.cpp
*/

void Enable_Doctest_Basic_Tokeniser(){};

TEST_CASE("Basic_Tokeniser Class test"){
    clog << "Test: Started Basic_Tokeniser Class Test using" << endl;

    string* input_string = new std::string("programming is power on power");

    Shared_Objects<char_type, Basic_Character> shared_char;
    Shared_Objects<std::string, Basic_Token> shared_chars;

    using tokens_t = Basic_Tokeniser;

    tokens_t* tokenised = new  tokens_t(*input_string);

 
    clog << "Test: Basic_Tokeniser Class passed tests successfully" << endl;
}
