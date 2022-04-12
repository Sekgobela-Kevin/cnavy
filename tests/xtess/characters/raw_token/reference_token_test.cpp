#include <iostream>
#include <string>
#include <memory>

#include "reference_token.hpp"
#include "doctest.h"
using namespace std;

/*
 g++ ..\character\character.cpp ..\character\character_compute.cpp 
 characters.cpp bool_set.cpp bool_characters.cpp ratio_characters.cpp 
 summary_characters.cpp ..\token\raw_token.cpp ..\token\reference_token.cpp
 ..\token\test\reference_token_test.cpp 
*/


void Enable_Doctest_Reference_Token(){};

TEST_CASE("Reference_Token Class test"){
    clog << "Test: Started Reference_Token Class Test using" << endl;
    string* input_string = new string("token");

    string obj_input_string;
    string obj2_input_string;
   

    vector<string> attr = {"chars", "is_digit", "is_alpha"};
    Characters* chars_obj = new Characters(*input_string);

    Raw_Token* chars_tok = new Raw_Token(*chars_obj);
    Reference_Token ref_tok = Reference_Token(*chars_tok);

    CHECK(ref_tok.is_alnum);
    CHECK(ref_tok.is_alpha);
    CHECK(ref_tok.is_digit == false);
    CHECK(ref_tok.is_ascii);
    CHECK(ref_tok.is_lower);
    CHECK(ref_tok.is_upper == false);

    // the rest is likely to be doing well
    delete input_string;

    clog << "Test: Reference_Token Class passed tests successfully" << endl;
}
