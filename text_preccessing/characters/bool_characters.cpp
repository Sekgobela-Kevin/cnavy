#include "algorithm"
#include "functional"
#include "bool_characters.hpp"


bool_chars_type Bool_Characters::for_each_elem(characters_objs_type char_objs, 
std::function<bool(character_type)> input_func){
    bool_chars_type booleans;
    std::function<void(character_type)> internal_func = [&booleans, &input_func](character_type obj){
        booleans.emplace_back(input_func(obj));
    };
    for_each(char_objs.begin(), char_objs.end(), internal_func);
    return  booleans;
}

bool_chars_type Bool_Characters::boolIsAlnum(){
    return this->for_each_elem(this->characters_objs, [](character_type obj){ return obj.isalnum();});
}

bool_chars_type Bool_Characters::boolIsAlpha(){
    return this->for_each_elem(this->characters_objs, [](character_type obj){ return obj.isalpha();});
}

bool_chars_type Bool_Characters::boolIsASCII(){
    return this->for_each_elem(this->characters_objs, [](character_type obj){ return obj.isASCII();});
}

bool_chars_type Bool_Characters::boolIsBlank(){
    return this->for_each_elem(this->characters_objs, [](character_type obj){ return obj.isblank();});
}

bool_chars_type Bool_Characters::boolIsDigit(){
    return this->for_each_elem(this->characters_objs, [](character_type obj){ return obj.isdigit();});
}

bool_chars_type Bool_Characters::boolIsGraph(){
    return this->for_each_elem(this->characters_objs, [](character_type obj){ return obj.isgraph();});
}

bool_chars_type Bool_Characters::boolIsLower(){
    return this->for_each_elem(this->characters_objs, [](character_type obj){ return obj.islower();});
}

bool_chars_type Bool_Characters::boolIsPrint(){
    return this->for_each_elem(this->characters_objs, [](character_type obj){ return obj.isprint();});
}

bool_chars_type Bool_Characters::boolIsPunct(){
    return this->for_each_elem(this->characters_objs, [](character_type obj){ return obj.ispunct();});
}

bool_chars_type Bool_Characters::boolIsSpace(){
    return this->for_each_elem(this->characters_objs, [](character_type obj){ return obj.isspace();});
}

bool_chars_type Bool_Characters::boolIsUpper(){
    return this->for_each_elem(this->characters_objs, [](character_type obj){ return obj.isupper();});
}

bool_chars_type Bool_Characters::boolIsXdigit(){
    return this->for_each_elem(this->characters_objs, [](character_type obj){ return obj.isxdigit();});
}



