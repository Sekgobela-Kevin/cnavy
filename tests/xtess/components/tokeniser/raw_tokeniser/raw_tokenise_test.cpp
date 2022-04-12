#include <iostream>
#include <iomanip>
#include <string>
#include <memory>

#include "raw_token.hpp"
#include "raw_tokenise.hpp"
#include "character.hpp"
#include "characters.hpp"

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

    Shared_Objects<char_type, Character> shared_char;
    Shared_Objects<std::string, Raw_Token> shared_chars;

    using tokens_t = Raw_Tokenise<Character, Raw_Token>;

    tokens_t* token = new  tokens_t(*input_string, shared_char, shared_chars);

    cout << "tokens created" << endl;

    tokens_t::char_coll_t char_objs = token->createCharObjs(*input_string);
    std::vector<std::string> text_toks = token->splitText(*input_string, char_objs);
    tokens_t::chars_coll_t chars_objs = token->createCharsObjs(*input_string, char_objs);


    cout << "Here is all tokens text" << endl;
    cout << "--------------------------------------------------" << endl;
    for (size_t i = 0; i < text_toks.size(); i++)
    {
        cout << "|" << text_toks[i] << "|" << std::setw(10) << "is at index: ["<< i<< "]" << endl;
    }

    // check if test string was not changed
    REQUIRE(*input_string == "programming is power on power");
    
    cerr << "input_string validated" << endl;
    CHECK(char_objs.size() == input_string->size());
    CHECK(chars_objs.size() == text_toks.size());
    CHECK(text_toks.size() == 9);

    CHECK(shared_chars.size() == 5);
    CHECK(shared_char.size() <= char_objs.size());

    cerr << "length of collections validated" << endl;

    // if values change then, characters were referenced from share objects
    char_objs[1].get().setCurrentChar('N', true);
    char_type char_ = char_objs[char_objs.size()-1].get().char_;
    CHECK(char_ == 'N');
    cerr << "accessing character object from characters objects" << endl;
    // access character object from characters objects
    string tok_text = token->chars_objects[8].get().text;
    cout << tok_text << endl;
    //CHECK(tok_text == "poweN");

    clog << "Test: Raw_Tokenise Class passed tests successfully" << endl;
}
