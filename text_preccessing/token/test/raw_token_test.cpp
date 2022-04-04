#include <iostream>
#include <cassert>
#include <string>
#include <memory>
#include "../characters_token.hpp"
using namespace std;

/*
 g++ ..\character\character.cpp ..\character\character_compute.cpp 
 characters.cpp bool_set.cpp bool_characters.cpp ratio_characters.cpp 
 summary_characters.cpp ..\token\characters_token.cpp 
 ..\token\test\raw_token_test.cpp 
*/


void Reference_Token_Test(){
    clog << "Test: Started Reference_Token Class Test using" << endl;
    string* input_string = new string("token");

    string obj_input_string;
    string obj2_input_string;


    vector<string> attr = {"chars", "is_digit", "is_alpha"};
    Characters* chars_obj = new Characters(*input_string);
    clog << "Test: Created Character object" << endl;

    Characters_Token* raw_tokens = new Characters_Token(*input_string);
    clog << "Test: Created Characters_Token object" << endl;
 
    cout << (*raw_tokens).is_alpha << endl;
    delete input_string;

    clog << "Test: Reference_Token Class passed tests successfully" << endl;
}


int main(){
    Reference_Token_Test();
}