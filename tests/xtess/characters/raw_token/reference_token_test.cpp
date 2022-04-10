#include <iostream>
#include <cassert>
#include <string>
#include <memory>
#include "reference_token.hpp"
using namespace std;

/*
 g++ ..\character\character.cpp ..\character\character_compute.cpp 
 characters.cpp bool_set.cpp bool_characters.cpp ratio_characters.cpp 
 summary_characters.cpp ..\token\raw_token.cpp ..\token\reference_token.cpp
 ..\token\test\reference_token_test.cpp 
*/


void Reference_Token_Test(){
    clog << "Test: Started Reference_Token Class Test using" << endl;
    string* input_string = new string("token");

    string obj_input_string;
    string obj2_input_string;


   

    vector<string> attr = {"chars", "is_digit", "is_alpha"};
    Characters* chars_obj = new Characters(*input_string);
    vector<std::reference_wrapper<Reference_Token>> chars_tokens;

    Raw_Token* chars_tok = new Raw_Token(*chars_obj);
    Reference_Token ref_tok = Reference_Token(*chars_tok);

    
    size_t count = 20000000;
    for (size_t i = 0; i < count; i++)
    {
        chars_tokens.push_back(ref_tok);
    }
    
 

    cout << "size of vector of chars_ref is " << chars_tokens.size() << " " << ", items size " <<
    input_string->size() << " and " << chars_tokens.size()*input_string->size() << " chars obj"<<  endl;


    cout << chars_tokens[3].get().is_alpha << endl;
    delete input_string;
    while(true);
    



    clog << "Test: Reference_Token Class passed tests successfully" << endl;
}


int main(){
    Reference_Token_Test();
}