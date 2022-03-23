#include "algorithm"
#include "functional"
#include "bool_characters.hpp"


std::unordered_map<std::string, std::function<bool_chars_type(Characters)>> 
    Bool_Characters::text_method_map = {
    {"is_alnum", Bool_Characters::isAlnum},
    {"is_alpha", Bool_Characters::isAlpha},
    {"is_ascii", Bool_Characters::isASCII},
    {"is_ascii", Bool_Characters::isBlank},
    {"is_cntrl", Bool_Characters::isCntrl},
    {"is_digit", Bool_Characters::isDigit},
    {"is_graph", Bool_Characters::isGraph},
    {"is_lower", Bool_Characters::isLower},
    {"is_print", Bool_Characters::isPrint},
    {"is_punct", Bool_Characters::isPunct},
    {"is_space", Bool_Characters::isSpace},
    {"is_xdigit", Bool_Characters::isXdigit},
};

bool_chars_type Bool_Characters::callMethod(const Characters& chars_obj, std::string& attr){
    if((bool)Bool_Characters::text_method_map.count(attr)) throw "atrr" + attr + " not found";
    return Bool_Characters::text_method_map[attr](chars_obj);
}



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


bool_chars_type Bool_Characters::textCompare(Characters& chars_obj, Characters& chars_obj2,
bool ignore_case){
    // variables to store strings of Characters objects
    std::string chars_objs_text;
    std::string chars_objs2_text;
    // retrieve lowecase version
    if(ignore_case){
        chars_objs_text = chars_obj.getLower();
        chars_objs2_text = chars_obj2.getLower();
    }
    else{
        chars_objs_text = chars_obj.getText();
        chars_objs_text = chars_obj2.getText();
    }

    // retrive largest size between strings
    int largestCount = chars_obj.size() > chars_obj2.size() ? chars_obj.size() : chars_obj2.size();
    bool_chars_type results;
    // reserve memory to improve performance
    results.reserve(largestCount);
    for (size_t i = 0; i < largestCount; i++)
    {
        // if index is out of range for one of strings then false is added to results
        // obviously theres no match for those characters involved
        if( i > chars_obj.size() || i > chars_obj2.size()){
            results.push_back(false);
        }
        else{
            // check if characters are same in corresponding strings
            results.push_back(chars_objs_text[i] == chars_objs2_text[i]);
        }
    }
    return results;
}

