#include "shared_characters.hpp"
#include <unordered_set>
#include <set>

Shared_Characters::Shared_Characters(std::string input_string){
    this->add(input_string);
}

Shared_Characters::Shared_Characters(Characters chars_obj){
    this->add(chars_obj);
}

void Shared_Characters::add(char_type char_){
    if(!this->exists(char_)){
        Character char_obj(char_);
        this->characters_map.emplace(char_, char_obj);
    }
}

void Shared_Characters::add(Character char_obj){
    char_type char_ = char_obj.getCurrentChar();
    if(!this->exists(char_)){
        this->characters_map.emplace(char_, char_obj);
    }
}

void Shared_Characters::add(std::string input_string){
    //std::string chars_set = unique(input_string);
    //printf("unique string created with size %d\n", chars_set.size());
    for(char_type character : input_string){
        this->add(character);
    }
}

void Shared_Characters::add(Characters chars_obj){
    characters_objs_type char_objs = chars_obj.getCharsObjs();
    for(Character char_obj : char_objs){
        this->add(char_obj);
    }
}

void Shared_Characters::remove(char_type char_){
    this->characters_map.erase(char_);
}

void Shared_Characters::remove(std::string input_string){
    for(char_type character : this->unique(input_string)){
        this->remove(character);
    }
}

bool Shared_Characters::exists(char_type char_){
    return this->characters_map.count(char_);
}

void Shared_Characters::clear(){
    this->characters_map.clear();
}

size_t Shared_Characters::size(){
    return this->characters_map.size();
}

bool Shared_Characters::empty(){
    return this->characters_map.empty();
}

std::string Shared_Characters::unique(std::string input_string){
    size_t size = input_string.length();
    std::set<char_type> chars_set;
    for( unsigned i = 0; i < size; ++i ) chars_set.insert( input_string[i] );
    input_string.assign(chars_set.begin(), chars_set.end());
    return input_string;
}


