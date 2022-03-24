#include "ratio_characters.hpp"
#include "bool_characters.hpp"
#include "static_compare_characters.hpp"

#include <numeric>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <string>
#include <cassert>

/*Static_Compare_Characters::Static_Compare_Characters(const Characters& chars_obj, const Characters& chars_obj2){
    this->first_chars_obj = chars_obj;
    this->first_chars_obj = chars_obj2;
}
*/

bool_matric_type Static_Compare_Characters::mapMatrix(bool_matric_type& bools_matrix, 
bool_matric_type& bools_matrix2, std::function<bool_chars_type(bool_chars_type, bool_chars_type)> input_func){
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
    // performs logical AND on collection and return results
    return Bool_Set::boolAND(collection, collection2);
}


bool_chars_type Static_Compare_Characters::maskBools(bool_chars_type& bools_collection, bool_chars_type& bools_mask){
    // invert booleans of mask using logical NOT
    // beaware of two loops when inverting and performing logical OR.
    bool_chars_type inverted_bools = Bool_Set::boolNOT(bools_mask);
    return Bool_Set::boolOR(bools_collection, inverted_bools);
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
    int sum = std::accumulate(ratio_collec.begin(), ratio_collec.end(), 0);
    return sum/ratio_collec.size();
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


bool_matric_type Static_Compare_Characters::getMatrixBools(const Characters& chars_obj, 
std::vector<std::string> attributes){
    // calls corresponding method in Bool_Character using 
    bool_matric_type results;
    results.reserve(chars_obj.size());
    for(std::string& elem : attributes){
        results.push_back(Bool_Characters::callMethod(chars_obj, elem));
    }
    return results;
}