#include "algorithm"
#include "functional"
#include "bool_characters.hpp"


bool_chars_type Bool_Characters::for_each_elem(characters_objs_type char_objs, 
std::function<bool(character_type)> input_func){
    bool_chars_type booleans;
    booleans.reserve(char_objs.size());
    for (character_type obj : char_objs)
    {
        booleans.push_back(input_func(obj));
    }
    return  booleans;
}

bool_chars_type Bool_Characters::boolIsAlnum(Characters chars_obj){
    characters_objs_type chars_objs = chars_obj.getCharsObjs();
    return Bool_Characters::for_each_elem(chars_objs, [](character_type obj){ return obj.isalnum();});
}

bool_chars_type Bool_Characters::boolIsAlpha(Characters chars_obj){
    characters_objs_type chars_objs = chars_obj.getCharsObjs();
    return Bool_Characters::for_each_elem(chars_objs, [](character_type obj){ return obj.isalpha();});
}

bool_chars_type Bool_Characters::boolIsASCII(Characters chars_obj){
    characters_objs_type chars_objs = chars_obj.getCharsObjs();
    return Bool_Characters::for_each_elem(chars_objs, [](character_type obj){ return obj.isASCII();});
}

bool_chars_type Bool_Characters::boolIsBlank(Characters chars_obj){
    characters_objs_type chars_objs = chars_obj.getCharsObjs();
    return Bool_Characters::for_each_elem(chars_objs, [](character_type obj){ return obj.isblank();});
}

bool_chars_type Bool_Characters::boolIsDigit(Characters chars_obj){
    characters_objs_type chars_objs = chars_obj.getCharsObjs();
    return Bool_Characters::for_each_elem(chars_objs, [](character_type obj){ return obj.isdigit();});
}

bool_chars_type Bool_Characters::boolIsGraph(Characters chars_obj){
    characters_objs_type chars_objs = chars_obj.getCharsObjs();
    return Bool_Characters::for_each_elem(chars_objs, [](character_type obj){ return obj.isgraph();});
}

bool_chars_type Bool_Characters::boolIsLower(Characters chars_obj){
    characters_objs_type chars_objs = chars_obj.getCharsObjs();
    return Bool_Characters::for_each_elem(chars_objs, [](character_type obj){ return obj.islower();});
}

bool_chars_type Bool_Characters::boolIsPrint(Characters chars_obj){
    characters_objs_type chars_objs = chars_obj.getCharsObjs();
    return Bool_Characters::for_each_elem(chars_objs, [](character_type obj){ return obj.isprint();});
}

bool_chars_type Bool_Characters::boolIsPunct(Characters chars_obj){
    characters_objs_type chars_objs = chars_obj.getCharsObjs();
    return Bool_Characters::for_each_elem(chars_objs, [](character_type obj){ return obj.ispunct();});
}

bool_chars_type Bool_Characters::boolIsSpace(Characters chars_obj){
    characters_objs_type chars_objs = chars_obj.getCharsObjs();
    return Bool_Characters::for_each_elem(chars_objs, [](character_type obj){ return obj.isspace();});
}

bool_chars_type Bool_Characters::boolIsUpper(Characters chars_obj){
    characters_objs_type chars_objs = chars_obj.getCharsObjs();
    return Bool_Characters::for_each_elem(chars_objs, [](character_type obj){ return obj.isupper();});
}

bool_chars_type Bool_Characters::boolIsXdigit(Characters chars_obj){
    characters_objs_type chars_objs = chars_obj.getCharsObjs();
    return Bool_Characters::for_each_elem(chars_objs, [](character_type obj){ return obj.isxdigit();});
}



