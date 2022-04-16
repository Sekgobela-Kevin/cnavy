#include <iostream>
#include <iomanip>
#include <string>
#include <memory>
#include <functional>

#include "raw_token.hpp"
#include "raw_tokenise.hpp"
#include "character.hpp"
#include "characters.hpp"

#include "basic_character.hpp"

#include "doctest.h"
using namespace std;

/*
 g++ xtess/character/*.cpp xtess/characters/*.cpp xtess/shared/*.cpp 
 xtess/components/tokeniser/*.cpp
*/

void Enable_Doctest_Raw_Tokeniser(){};

TEST_CASE("Raw_Tokenise Class test"){
    clog << "Test: Started Raw_Tokenise Class Test using" << endl;

    string* input_string = new std::string("programming is power on power");
    string* input_string2 = new std::string("hardwork pays");

    using tokens_t = Raw_Tokenise<Character, Raw_Token<Basic_Character>>;
    using tokens_vect_t = std::vector<std::string>;

    tokens_t* tokens = new  tokens_t(*input_string);
    tokens_t* tokens2 = new  tokens_t(*input_string2);

    std::function<bool(char_type)> func = [](char_type c){return !Basic_Character(c).is_alnum;};


    tokens_vect_t text_toks = tokens->splitText(*input_string, func);

    vector<string> text_tok_results = {"programming", " ", "is", " ", "power", " ", "on", " ", "power"};

    CHECK(text_tok_results.size() == text_toks.size());

    for (size_t i = 0; i < text_toks.size(); i++)
    {
        CHECK(text_tok_results[i] == text_toks[i]);
    }

    // check if test string was not changed
    REQUIRE(*input_string == "programming is power on power");
    REQUIRE(*input_string2 == "hardwork pays");
    
    cerr << "input_string validated" << endl;
    CHECK(text_toks.size() == 9);

    CHECK(tokens_t::shared_chars_objs.size() == 7);

    cerr << "length of collections validated" << endl;


    for(auto token : *tokens){
        string token_text = token.get().text;
        assert(input_string->find(token_text) != string::npos);
    }

    assert(*tokens == *input_string);
    assert(*tokens == *input_string);
    assert(*tokens != *input_string2);
    assert(*tokens != "");
    assert(*tokens2 == "hardwork pays");

    assert(*tokens != *tokens2);
    assert(*tokens == *tokens);
    assert((*tokens + *tokens2).text == (*input_string + *input_string2));

    clog << "Test: Raw_Tokenise Class passed tests successfully" << endl;
}
