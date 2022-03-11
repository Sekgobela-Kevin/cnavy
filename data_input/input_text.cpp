#include "input_text.hpp"

Input_Text::Input_Text(string title_, string source_, string body_) : Input(title_, "text", source_){
    if(title_.length() > body_.length()){
        cerr << "Title should be smaller than body by length: body-title size:" << body_.length() 
            << ", " << title_.length();
        exit(EXIT_FAILURE);
    }
    setContentData(body_);
};

bool Input_Text::isSourceActive(string source){
    return true;
}

bool Input_Text::isSourceValid(string source){
    return true;
}

string Input_Text::fetchData(string source){
    return body;
}

string Input_Text::dataToText(string data){
    return data;
}
