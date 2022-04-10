 #include <functional>   
#include <algorithm>    
#include <string>  
#include "bool_set.hpp"


bool_chars_type Bool_Set::for_each_elem(bool_chars_type bool_collection, 
std::function<bool(bool)> input_func){
    bool_chars_type booleans;
    booleans.reserve(bool_collection.size());
    for (bool obj : bool_collection)
    {
        booleans.push_back(input_func(obj));
    }
    return  booleans;
}

bool_chars_type Bool_Set::for_each_elem(bool_chars_type collection, bool_chars_type collection2,
std::function<bool(bool, bool)> input_func, int overflow_action){
    bool_chars_type booleans;
    //stores largest collection by size
    bool_chars_type largest_collection;
    largest_collection = collection.size()>collection2.size() ? collection : collection2;
    booleans.reserve(collection.size());


    // iteration will happen to all elements in both collection 
    // Even if their sizes are different
    for (size_t i = 0; i < collection.size() || i < collection2.size(); i++)
    {
        if(i >= collection.size() || i >= collection2.size()){
            // one of collections is out of range
            // false is pushed since no logical operation that was performed
            if(overflow_action==0) break;
            else if(overflow_action==1) booleans.push_back(false);
            else booleans.push_back(largest_collection[i]);
        }
        else{
            booleans.push_back(input_func(collection[i], collection2[i]));
        }
    }
    return  booleans;
}


bool_chars_type Bool_Set::boolAND(bool_chars_type collec, bool_chars_type collec2){
    return Bool_Set::for_each_elem(collec, collec2, std::logical_and<bool>());
}

bool_chars_type Bool_Set::boolOR(bool_chars_type collec, bool_chars_type collec2){
    return Bool_Set::for_each_elem(collec, collec2, std::logical_or<bool>());
}

bool_chars_type Bool_Set::boolXOR(bool_chars_type collec, bool_chars_type collec2){
    return Bool_Set::for_each_elem(collec, collec2, [](bool a, bool b){return a ^ b;});
}

bool_chars_type Bool_Set::boolEqual(bool_chars_type collec, bool_chars_type collec2){
    return Bool_Set::for_each_elem(collec, collec2, [](bool a, bool b){return a == b;});
}

bool_chars_type Bool_Set::boolNOT(bool_chars_type collec){
    return Bool_Set::for_each_elem(collec, std::logical_not<bool>());
}


bool Bool_Set::all(bool_chars_type collec){
    return std::count(collec.begin(), collec.end(), true) == collec.size();
}


bool Bool_Set::any(bool_chars_type collec){
    return std::count(collec.begin(), collec.end(), true) == 0;
}

bool Bool_Set::count(bool_chars_type collec){
    return std::count(collec.begin(), collec.end(), true);
}

std::string Bool_Set::toString(bool_chars_type collec){
    std::string str;
    str.reserve(collec.size());
    for (bool elem : collec)
    {
        str.push_back(elem ? '1' : '0');
    }
    return str;
}