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

bool_chars_type Bool_Characters::isAlnum(Characters chars_obj){
    characters_objs_type chars_objs = chars_obj.getCharsObjs();
    return Bool_Characters::for_each_elem(chars_objs, [](character_type obj){ return obj.isalnum();});
}

bool_chars_type Bool_Characters::isAlpha(Characters chars_obj){
    characters_objs_type chars_objs = chars_obj.getCharsObjs();
    return Bool_Characters::for_each_elem(chars_objs, [](character_type obj){ return obj.isalpha();});
}

bool_chars_type Bool_Characters::isASCII(Characters chars_obj){
    characters_objs_type chars_objs = chars_obj.getCharsObjs();
    return Bool_Characters::for_each_elem(chars_objs, [](character_type obj){ return obj.isASCII();});
}

bool_chars_type Bool_Characters::isBlank(Characters chars_obj){
    characters_objs_type chars_objs = chars_obj.getCharsObjs();
    return Bool_Characters::for_each_elem(chars_objs, [](character_type obj){ return obj.isblank();});
}

bool_chars_type Bool_Characters::isCntrl(Characters chars_obj){
    characters_objs_type chars_objs = chars_obj.getCharsObjs();
    return Bool_Characters::for_each_elem(chars_objs, [](character_type obj){ return obj.iscntrl();});
}

bool_chars_type Bool_Characters::isDigit(Characters chars_obj){
    characters_objs_type chars_objs = chars_obj.getCharsObjs();
    return Bool_Characters::for_each_elem(chars_objs, [](character_type obj){ return obj.isdigit();});
}

bool_chars_type Bool_Characters::isGraph(Characters chars_obj){
    characters_objs_type chars_objs = chars_obj.getCharsObjs();
    return Bool_Characters::for_each_elem(chars_objs, [](character_type obj){ return obj.isgraph();});
}

bool_chars_type Bool_Characters::isLower(Characters chars_obj){
    characters_objs_type chars_objs = chars_obj.getCharsObjs();
    return Bool_Characters::for_each_elem(chars_objs, [](character_type obj){ return obj.islower();});
}

bool_chars_type Bool_Characters::isPrint(Characters chars_obj){
    characters_objs_type chars_objs = chars_obj.getCharsObjs();
    return Bool_Characters::for_each_elem(chars_objs, [](character_type obj){ return obj.isprint();});
}

bool_chars_type Bool_Characters::isPunct(Characters chars_obj){
    characters_objs_type chars_objs = chars_obj.getCharsObjs();
    return Bool_Characters::for_each_elem(chars_objs, [](character_type obj){ return obj.ispunct();});
}

bool_chars_type Bool_Characters::isSpace(Characters chars_obj){
    characters_objs_type chars_objs = chars_obj.getCharsObjs();
    return Bool_Characters::for_each_elem(chars_objs, [](character_type obj){ return obj.isspace();});
}

bool_chars_type Bool_Characters::isUpper(Characters chars_obj){
    characters_objs_type chars_objs = chars_obj.getCharsObjs();
    return Bool_Characters::for_each_elem(chars_objs, [](character_type obj){ return obj.isupper();});
}

bool_chars_type Bool_Characters::isXdigit(Characters chars_obj){
    characters_objs_type chars_objs = chars_obj.getCharsObjs();
    return Bool_Characters::for_each_elem(chars_objs, [](character_type obj){ return obj.isxdigit();});
}

