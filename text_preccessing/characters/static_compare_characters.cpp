#include "ratio_characters.hpp"
#include "bool_characters.hpp"
#include "static_compare_characters.hpp"

#include <numeric>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <string>
#include <cassert>


/**
 * This file heavily uses Bool_Characters and Ratio_Characters Classes to implemenet much of
 * functions used for comparing characters. To understand what each function does you may need
 * to read more about those Classes. They are simple but methods in this class can be harder to 
 * since they are not well documeted an function names may not match what they do.
 * 
 * The methods in this File were not planned before being written so theres may be a lot 
 * of confusion. Lot of clean up may be neccessay to make the code more readable and 
 * easy to follow up.
 * 
 */

/*Static_Compare_Characters::Static_Compare_Characters(const Characters& chars_obj, const Characters& chars_obj2){
    this->first_chars_obj = chars_obj;
    this->first_chars_obj = chars_obj2;
}
*/

bool_matric_type Static_Compare_Characters::mapMatrix(bool_matric_type& bools_matrix, 
bool_matric_type& bools_matrix2, std::function<bool_chars_type(bool_chars_type, bool_chars_type)> input_func){
    assert(bools_matrix.size() == bools_matrix2.size());
    bool_matric_type results;
    results.reserve(bools_matrix.size());
    // itrerate through content of metrixes
    for (size_t i = 0; i < bools_matrix.size(); i++)
    {
        // compare corresponding boolean collections(bool_chars_type)
        bool_chars_type compared =  input_func(bools_matrix[i], bools_matrix2[i]);
        // push results into results metrix
        results.push_back(compared);
    }
    return results;
}

bool_chars_type Static_Compare_Characters::compareBools(bool_chars_type& collection, bool_chars_type& collection2){
    // checks if bools are equal(logical AND wont work here)
    // this wont be as expected for characters of different length
    // e.g "names" and "2names" would be different due to mapping of wrong bools(from chars)
    // to handle that, change this funtion to handle it, at moment it does not check mapping
    return Bool_Set::boolEqual(collection, collection2);
}


bool_chars_type Static_Compare_Characters::maskBools(bool_chars_type& bools_collection, bool_chars_type& bools_mask){
    // invert booleans of mask using logical NOT
    // beaware of two loops when inverting and performing logical OR.
    // if value in mask is false then results becomes true but for true then value
    assert(bools_collection.size() == bools_mask.size());
    return Bool_Set::for_each_elem(bools_collection, bools_mask, [](bool collec_elem, bool mask_elem){
        if(!mask_elem) return true;
        else return collec_elem;
    });
}

bool_matric_type Static_Compare_Characters::maskBoolsMatrix(bool_matric_type& bools_matrix, bool_matric_type& mask_matrix_mask){
    bool_matric_type results;
    // loop through each elements of arguments and call function and then return results
    results =  Static_Compare_Characters::mapMatrix(bools_matrix, mask_matrix_mask, 
        [](bool_chars_type bool_coll, bool_chars_type bool_mask){
            return Static_Compare_Characters::maskBools(bool_coll, bool_mask);
        }
    );
    return results;
}

bool_matric_type Static_Compare_Characters::compareBoolsMatrix(bool_matric_type& bools_matrix, bool_matric_type& bools_matrix2){
    assert(bools_matrix.size() == bools_matrix2.size());
    bool_matric_type results;
    // iterate through content of metrixes
    results =  Static_Compare_Characters::mapMatrix(bools_matrix, bools_matrix2, 
        [](bool_chars_type bool_coll, bool_chars_type bool_collc2){
            return Static_Compare_Characters::compareBools(bool_coll,  bool_collc2);
        }
    );
    return results;
}

float Static_Compare_Characters::getBoolRatio(bool_chars_type& collection, bool_chars_type& collection2){
    // performs compare and then calculate ratio from returned bool collection
    bool_chars_type results = Static_Compare_Characters::compareBools(collection, collection2);
    return Ratio_Characters::getBoolRatio(results);
}

float Static_Compare_Characters::getFinalRatio(ratio_collec_type& ratio_collec){
    // calculate average from input coolection and return results
    // initial value of 0.0 gives desired results than 0(due to generaric programming or casting)
    float sum = std::accumulate(ratio_collec.begin(), ratio_collec.end(), 0.0);
    float results = sum/(float)ratio_collec.size();
    return results;
}

ratio_collec_type Static_Compare_Characters::getBoolRatios(bool_matric_type& bools_matrix, bool_matric_type& bools_matrix2){
    //bool_matric_type compared = Static_Compare_Characters::compareBoolsMatrix(bools_matrix, bools_matrix2);
    ratio_collec_type results;
    results.reserve(bools_matrix.size());
    // itrerate through content of metrixes
    for (size_t i = 0; i < bools_matrix.size(); i++)
    {
        results.push_back( Static_Compare_Characters::getBoolRatio(bools_matrix[i], bools_matrix2[i]));
    }
    return results;
}

ratio_collec_type Static_Compare_Characters::getBoolRatios(bool_matric_type& bools_matrix){
    //bool_matric_type compared = Static_Compare_Characters::compareBoolsMatrix(bools_matrix, bools_matrix2);
    ratio_collec_type results;
    results.reserve(bools_matrix.size());
    // itrerate through content of metrixes
    for (size_t i = 0; i < bools_matrix.size(); i++)
    {
        results.push_back(Ratio_Characters::getBoolRatio(bools_matrix[i]));
    }
    return results;
}


bool_matric_type Static_Compare_Characters::getBoolsMatrix(const Characters& chars_obj, 
std::vector<std::string> attributes){
    // calls corresponding method in Bool_Character using 
    bool_matric_type results;
    results.reserve(chars_obj.size());
    for(std::string& elem : attributes){
        // "text" and "char" are reserved when comparing
        if(elem=="text" || elem=="chars") continue;
        results.push_back(Bool_Characters::callMethod(chars_obj, elem));
    }
    return results;
}



bool_matric_type Static_Compare_Characters::getBoolsMatrix(Characters& chars_obj,
Characters& chars_obj2, std::vector<std::string> attributes, bool ignore_case){
    // calls corresponding method in Bool_Character using 
    bool_matric_type results;
    results.reserve(chars_obj.size());
    for(std::string& attr : attributes){
        if(attr == "text" || attr == "chars"){
            // compares corresponding characters with "==" operator
            results.push_back(Bool_Characters::textCompare(chars_obj, chars_obj2, ignore_case));
        }
        else{
            // there are multiple ways of doing this
            // this can be easily done with compareBoolsMatrix()
            bool_chars_type bools = Bool_Characters::callMethod(chars_obj, attr);
            bool_chars_type bools2 = Bool_Characters::callMethod(chars_obj2, attr);
            results.push_back(Static_Compare_Characters::compareBools(bools, bools2));
        }
    }
    return results;
}