#include <algorithm>
#include <functional>
#include <iostream>
#include <cassert>
#include <algorithm>

#include "bool_characters.hpp"



std::unordered_map<std::string, std::function<bool_chars_type(Characters)>> 
    Bool_Characters::text_method_map = {
    {"is_alnum", Bool_Characters::isAlnum},
    {"is_alpha", Bool_Characters::isAlpha},
    {"is_ascii", Bool_Characters::isASCII},
    {"is_blank", Bool_Characters::isBlank},
    {"is_cntrl", Bool_Characters::isCntrl},
    {"is_digit", Bool_Characters::isDigit},
    {"is_graph", Bool_Characters::isGraph},
    {"is_lower", Bool_Characters::isLower},
    {"is_print", Bool_Characters::isPrint},
    {"is_punct", Bool_Characters::isPunct},
    {"is_space", Bool_Characters::isSpace},
    {"is_upper", Bool_Characters::isUpper},
    {"is_xdigit", Bool_Characters::isXdigit},
};

bool_chars_type Bool_Characters::callMethod(const Characters& chars_obj, std::string& attr){
    bool attr_exists = Bool_Characters::text_method_map.count(attr);
    assert(attr_exists);
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
    //method is now large and needs its own file with different functions
    // variables to store strings of Characters objects
    std::string chars_objs_text;
    std::string chars_objs2_text;
    std::string  small_text;
    std::string  large_text;
    // retrieve lowecase version
    if(ignore_case){
        // get lowercase version of Characters objects(objects not modified)
        chars_objs_text = chars_obj.getLower();
        chars_objs2_text = chars_obj2.getLower();
    }
    else{
        // Get text as it is from Characters objects
        chars_objs_text = chars_obj.getText();
        chars_objs2_text = chars_obj2.getText();
    }

    // stores smallest text by size
    small_text = chars_objs_text.size() < chars_objs2_text.size() ? chars_objs_text : chars_objs2_text;
    large_text = chars_objs_text == small_text ?  chars_objs2_text : chars_objs_text;

    // variable to store return value
    bool_chars_type results;
    // reserve memory to improve performance
    results.reserve(chars_objs_text.size());
    

    //contains how many characters to be compared
    // the more characters, the more strict it will be
    int range_size;
    if (small_text.size()<=1) range_size = 1;
    else if (small_text.size()<=12) range_size = 2;
    // things start slow-down here
    else if (small_text.size()<=100) range_size = 3;
    else if (small_text.size()<=1000) range_size = 4;
    else range_size = 5;

    // small named var to use in loop
    int& rs = range_size;
    // same as range_size but used to accomodate c++(0 based indexes)
    int irs = range_size-1;

    for (int i = irs; i < large_text.size(); i++)
    {
        // if index is out of range for one of strings then false is added to results
        // obviously theres no match for those characters involved
        if( i >= small_text.size() || small_text.size()<=1 && large_text.size()>1){
            // this just trick in case Characters objects differ in length
            results.push_back(false);
        }
        else{
            // expect slowness for larger strings due to .find()
            int index = large_text.find(small_text.substr(i-irs, rs));
            bool cmp = index != std::string::npos;
            //std::cout << small_text.substr(i-irs, rs) << " " << cmp << std::endl;
            results.push_back(cmp);
        }
    }
    // trick to improve results to match whats expected by Static_Bool_Characters Class
    // This would allow results to match for compares including "is_alpha"
    // the idea is to turn e.g 3/7 to 4/8 which is what is expected
    // names and name should be 4/5=0.8 than 3/4=0.75
    // this is mathematical trick done in collections of bools
    // it if value is 0(all false or empty) or 1(all bools)
    if(results.size() || !Bool_Set::all(results)){
        // this will increase both total and true_ratio(true_values_count/total) by 1
        results.push_back(true);
    }
    return results;
}

