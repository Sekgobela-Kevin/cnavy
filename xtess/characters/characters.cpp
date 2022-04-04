#include <cassert>
#include <iostream>
#include <algorithm>
#include "characters.hpp"


Characters::Characters(std::string input_text){
    this->update(input_text);
}

Characters::Characters(){
    // included just to fix bug undefined reference to `Characters::Characters()'
    // it really fixed the bug, I dont know why default constructor is called when
    // using referenced to object
}

void Characters::update(std::string input_text){
    this->input_string = input_text;
    size_t input_size = input_string.length();

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

size_t Characters::size(){
    return this->characters_objs.size();
}

size_t Characters::length(){
    return this->characters_objs.size();
}


std::string Characters::toUpper(){
    std::string text = this->getUpper();
    // flaged to be used in develoment only(but had no choice)
    this->update(text);
    return this->getText();
}


// iterator methods
characters_objs_type::iterator Characters::begin() { return this->characters_objs.begin(); }
characters_objs_type::iterator Characters::end() { return this->characters_objs.end(); }
characters_objs_type::const_iterator Characters::cbegin() const { return this->characters_objs.begin(); }
characters_objs_type::const_iterator Characters::cend() const { return this->characters_objs.end(); }
characters_objs_type::const_iterator Characters::begin() const { return this->characters_objs.begin(); }
characters_objs_type::const_iterator Characters::end() const { return this->characters_objs.end(); }


// method overiding
Character& Characters::operator[](size_t i) { return this->characters_objs[i]; }
Characters Characters::operator+(Characters& other){
    std::string concat_text = this->getText() + other.getText();
    return Characters(concat_text);
}
// change this in future and make copare based on characters objects than string
bool Characters::operator==(std::string other){ return this->getText()==other;}
bool Characters::operator==(const char* other){ return this->getText() == other;}
bool Characters::operator==(Characters& other){ return this->getText()==other.getText();};

std::ostream& operator<<(std::ostream& out_stream, Characters& chars_obj){
    out_stream << chars_obj.getText();
    return out_stream;
}

