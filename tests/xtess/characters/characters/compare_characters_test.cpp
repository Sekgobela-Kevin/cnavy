#include <iostream>
#include <string>

#include "compare_characters.hpp"
#include "doctest.h"
using namespace std;

/*
 g++ ..\character\character.cpp ..\character\character_compute.cpp 
 characters.cpp bool_characters.cpp ratio_characters.cpp 
 bool_set.cpp  static_compare_characters.cpp compare_characters.cpp 
 test\compare_characters_test.cpp 
*/

void Enable_Doctest_Compare_Characters(){};

TEST_CASE("Compare_Characters Class test"){
    clog << "Test: Started Compare_Characters Class Test using" << endl;

    string obj_input_string = "name";
    string obj2_input_string = "names";

    vector<string> attr = {"chars"};
    Characters* obj = new Characters(obj_input_string);
    Characters* obj2 = new Characters(obj2_input_string);

    Compare_Characters* cmp_obj = new Compare_Characters(*obj, *obj2, attr);

    bool_matric_type bool_matrix;
    float ratio;
    ratio_collec_type ratios ;

    ratios = cmp_obj->getRatios();

    for (float ratio : ratios)
    {
        cout << ratio << " ";
    }
    cout << endl;
    

    float final_ratio = Static_Compare_Characters::getFinalRatio(ratios);
    cout << final_ratio << " Final Ratio" << endl;// 0.8
    CHECK(final_ratio == doctest::Approx(0.8));
    

    clog << "Test: Compare_Characters Class passed tests successfully" << endl;
}
