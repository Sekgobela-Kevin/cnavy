#include <iostream>
#include <cassert>
#include <string>
#include "../reference_token.hpp"
using namespace std;

/*
 g++ ..\character\character.cpp ..\character\character_compute.cpp 
 characters.cpp bool_characters.cpp ratio_characters.cpp 
 summary_characters_test.cpp bool_set.cpp  static_Reference_Token.cpp 
 Reference_Token.cpp ..\token\characters_token.cpp ..\token\reference_token.cpp
 ..\token\test\reference_token_test.cpp 
*/

void Reference_Token_Test(){
    clog << "Test: Started Reference_Token Class Test using" << endl;
    string input_string(4, 'c');

    string obj_input_string;
    string obj2_input_string;

    cout << "Enter text: ";
    cin >> obj_input_string;
   

    vector<string> attr = {"chars", "is_digit", "is_alpha"};
    Characters* chars_obj = new Characters(obj_input_string);

    Characters_Token* chars_tok = new Characters_Token(*chars_obj);
    Reference_Token* ref_tok = new Reference_Token(*chars_tok);

    cout << "lower: " << ref_tok->lower << endl;
    ref_tok->lower = "chaned";
    cout << "isUpper: " << (*ref_tok).isUpper(0.5) << endl;
    



    clog << "Test: Reference_Token Class passed tests successfully" << endl;
}


int main(){
    Reference_Token_Test();
}