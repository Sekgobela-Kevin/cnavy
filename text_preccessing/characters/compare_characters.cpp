#include "static_compare_characters.hpp"
#include "compare_characters.hpp"
#include <cassert>
#include <iostream>

Compare_Characters::Compare_Characters(Characters& chars_obj, Characters& chars_obj2,
std::vector<std::string> scope, bool ignore_case) : chars_obj(chars_obj), chars_obj2(chars_obj2), 
scope(scope), ignore_case(ignore_case){
    assert(this->scope.size());
}

/*void Compare_Characters::update(){
    bools_matrix = this->getBoolsMatrix();
    bools_matrix = this->getRatios();
}
*/

bool_matric_type Compare_Characters::getBoolsMatrix(){
    return Static_Compare_Characters::getBoolsMatrix(chars_obj, chars_obj2, scope, ignore_case);
}

ratio_collec_type Compare_Characters::getRatios(){
    bool_matric_type bools_matrix = this->getBoolsMatrix();
    return Static_Compare_Characters::getBoolRatios(bools_matrix);
}

float Compare_Characters::getRatio(){
    ratio_collec_type ratios = this->getRatios();
    return Static_Compare_Characters::getFinalRatio(ratios);
}