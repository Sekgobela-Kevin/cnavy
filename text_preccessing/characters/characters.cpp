#include <cassert>
#include <iostream>
#include <algorithm>
#include "characters.hpp"


Characters::Characters(std::string input_text) : std::string(input_text){
    this->input_string = input_text;
    size_t input_size = input_string.length();
    this->characters_objs.reserve(input_size);
    for (char_type char_ : input_string)
    {
        this->characters_objs.push_back(character_type(char_));
    }
}

void Characters::update(std::string input_text){
    this->input_string = input_text;
    size_t input_size = input_string.length();
    
    // replace contents of underlying string
    this->resize(input_size);
    this->replace(0, input_size, input_text);

    if(this->characters_objs.size()) this->characters_objs.clear();
    this->characters_objs.reserve(input_size);
    for (char_type char_ : input_string)
    {
        character_type char_obj(char_);
        //char_obj.updateAttrs(char_obj.getCurrentChar());
        this->characters_objs.push_back(char_obj);
    }
}

std::string Characters::getText(){
    return this->input_string;
}

characters_objs_type Characters::getCharsObjs(){
    return this->characters_objs;
}

std::string Characters::getLower(){
    // replaces character in string with lowercase versions
    std::string str = this->input_string;
    for (size_t i = 0; i < this->input_string.size(); i++)
    {
        // get lowecase from created character object and replace
        str[i] = Character_Compute::computeToLower(str[i]);
    }
    // flaged to be used in develoment only(but had no choice)
    return str;
}

std::string Characters::getUpper(){
    // replaces character in string with uppercase versions
    std::string str = this->input_string;
    for (size_t i = 0; i < this->input_string.size(); i++)
    {
        // get lowecase from created character object and replace
        str[i] = Character_Compute::computeToUpper(str[i]);
    }
    // flaged to be used in develoment only(but had no choice)
    return str;
}


std::string Characters::toLower(){
    std::string text = this->getLower();
    // flaged to be used in develoment only(but had no choice)
    this->update(text);
    return this->getText();
}


std::string Characters::toUpper(){
    std::string text = this->getUpper();
    // flaged to be used in develoment only(but had no choice)
    this->update(text);
    return this->getText();
}