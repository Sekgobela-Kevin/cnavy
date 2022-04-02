#include <iostream>
#include <iomanip>
#include <cassert>
#include <string>
#include <memory>

#include "..\..\character\character.hpp"
#include "..\..\characters\characters.hpp"
#include "..\characters_token.hpp"
#include "..\raw_tokenise.hpp"
using namespace std;

/*
 g++ ..\character\character.cpp ..\character\character_compute.cpp 
 characters.cpp  bool_set.cpp bool_characters.cpp ratio_characters.cpp 
 summary_characters.cpp ..\token\characters_token.cpp 
 ..\token\test\raw_tokenise_test.cpp 
*/

void Raw_Tokenise_Test(){
    clog << "Test: Started Raw_Tokenise Class Test using" << endl;

    string* input_string = new std::string("programming is power on power");

    Shared_Objects<char_type, Character> shared_char;
    Shared_Objects<std::string, Characters_Token> shared_chars;

    using tokens_t = Raw_Tokenise<Character, Characters_Token>;

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

    if(input_string->size() != 29){
        cerr << "Test[FAILED]: Testing string was changed" << endl;
        exit(EXIT_FAILURE);
    }
    
    cerr << "input_string validated" << endl;
    assert(char_objs.size() == input_string->size());
    assert(chars_objs.size() == text_toks.size());
    assert(text_toks.size() == 9);

    assert(shared_chars.size() == 5);
    assert(shared_char.size() < char_objs.size());

    cerr << "length of collections validated" << endl;

    // if values change then, characters were referenced from share objects
    char_objs[1].get().setCurrentChar('N', true);
    char_type char_ = char_objs[char_objs.size()-1].get().char_;
    assert(char_ == 'N');
    cerr << "accessing character object from characters objects" << endl;
    // access character object from characters objects
    string tok_text = token->chars_objects[8].get().text;
    cout << tok_text << endl;
    //assert(tok_text == "poweN");

    clog << "Test: Raw_Tokenise Class passed tests successfully" << endl;
}


int main(){
    Raw_Tokenise_Test();
}