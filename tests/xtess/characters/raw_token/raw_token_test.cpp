#include <iostream>
#include <string>
#include <memory>

#include "raw_token.hpp"
#include "basic_character.hpp"
#include "doctest.h"
using namespace std;

/*
 g++ ..\character\character.cpp ..\character\character_compute.cpp 
 characters.cpp bool_set.cpp bool_characters.cpp ratio_characters.cpp 
 summary_characters.cpp ..\token\raw_token.cpp 
 ..\token\test\raw_token_test.cpp 
*/

void Enable_Doctest_Raw_Token(){};

TEST_CASE("Raw_Token"){
    clog << "Test: Started Raw_Token Class Test using" << endl;
    string* input_string = new string("token");

    string obj_input_string;
    string obj2_input_string;


    vector<string> attr = {"chars", "is_digit", "is_alpha"};
    Characters* chars_obj = new Characters(*input_string);
    clog << "Test: Created Character object" << endl;

    Raw_Token<Basic_Character>* raw_tokens = new Raw_Token<Basic_Character>(*input_string);
    Raw_Token<Basic_Character>* raw_tokens2 = new Raw_Token<Basic_Character>("token2");
    clog << "Test: Created Raw_Token object" << endl;

    CHECK(raw_tokens->is_alnum);
    CHECK(raw_tokens->is_alpha);
    CHECK(raw_tokens->is_digit == false);
    CHECK(raw_tokens->is_ascii);
    CHECK(raw_tokens->is_lower);
    CHECK(raw_tokens->is_upper == false);

    for(auto char_obj : *raw_tokens){
        size_t index = input_string->find(char_obj.get().char_);
        // if it failes then iterator methods are not doing well
        assert(string::npos != index);
        // if it fails then [] or interator methods not working
        assert(input_string->at(index) == (*raw_tokens)[index].get().char_);
    }

    assert(*raw_tokens == *input_string);
    assert(*raw_tokens != string("text"));
    assert(*raw_tokens != "");
    assert(*raw_tokens == "token");

    assert(*raw_tokens != *raw_tokens2);
    assert(*raw_tokens == *raw_tokens);
    assert((*raw_tokens + *raw_tokens2) == "tokentoken2");
    // the rest are likely to be doing well
    delete input_string;

    clog << "Test: Raw_Token Class passed tests successfully" << endl;
}

void bb(bool cc){

}
