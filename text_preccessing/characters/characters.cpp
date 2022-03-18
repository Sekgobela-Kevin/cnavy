#include <cassert>
#include <iostream>
#include "characters.hpp"


Characters::Characters(std::string input_text) : std::string(input_text){
    this->input_string = input_text;
    size_t input_size = input_string.length();
    this->characters_objs.reserve(input_size);
    for (wchar_t char_ : input_string)
    {
        this->characters_objs.push_back(character_type(char_));
    }
}

void Characters::update(std::string input_text){
    this->input_string = input_text;
    size_t input_size = input_string.length();
    
    // replace contents of underlying string
    this->resize(input_size, '?');
    this->replace(0, input_size, input_text);

    if(this->characters_objs.size()) this->characters_objs.clear();
    this->characters_objs.reserve(input_size);
    for (wchar_t char_ : input_string)
    {
        this->characters_objs.push_back(character_type(char_));
    }
}

std::string Characters::getText(){
    return this->input_string;
}

characters_objs_type Characters::getCharsObjs(){
    return this->characters_objs;
}