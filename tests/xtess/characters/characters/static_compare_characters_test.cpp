#include <iostream>
#include <string>

#include "static_compare_characters.hpp"
#include "doctest.h"
using namespace std;

/*
 g++ ..\character\character.cpp ..\character\character_compute.cpp 
 characters.cpp bool_characters.cpp ratio_characters.cpp 
 bool_set.cpp  static_compare_characters.cpp
 test\static_compare_characters_test.cpp
*/

void Enable_Doctest_Static_Compare_Characters(){};

TEST_CASE("Static_Compare_Characters"){
    clog << "Test: Started Static_Compare_Characters Class Test using" << endl;
    string input_string(4, 'c');

    string obj_input_string = "name";
    string obj2_input_string = "names";

    vector<string> attr = {"chars"};
    Characters* obj = new Characters(obj_input_string);
    Characters* obj2 = new Characters(obj2_input_string);
    bool_matric_type obj_matrixs =  Static_Compare_Characters::getBoolsMatrix(*obj, attr);
    bool_matric_type obj2_matrixs =  Static_Compare_Characters::getBoolsMatrix(*obj2, attr);
    ratio_collec_type ratios = Static_Compare_Characters::getBoolRatios(obj_matrixs , obj2_matrixs);
    
    obj_matrixs = Static_Compare_Characters::compareBoolsMatrix(obj_matrixs , obj2_matrixs);
    ratios = Static_Compare_Characters::getBoolRatios(obj_matrixs);

    obj_matrixs = Static_Compare_Characters::getBoolsMatrix(*obj, *obj2, attr);
    ratios = Static_Compare_Characters::getBoolRatios(obj_matrixs);

    for (float ratio : ratios)
    {
        cout << ratio << " ratio";
    }
    cout << endl;
    

    float final_ratio = Static_Compare_Characters::getFinalRatio(ratios);
    cout << final_ratio << endl;// 0.8

    REQUIRE(final_ratio == doctest::Approx(0.8));
    

    clog << "Test: Static_Compare_Characters Class passed tests successfully" << endl;
}
