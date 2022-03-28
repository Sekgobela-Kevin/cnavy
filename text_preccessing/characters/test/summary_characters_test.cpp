#include <iostream>
#include <cassert>
#include "string"
#include "..\summary_characters.hpp"
using namespace std;

/*
 g++ ..\character\character.cpp ..\character\character_compute.cpp 
 characters.cpp bool_set.cpp bool_characters.cpp ratio_characters.cpp 
 summary_characters.cpp test\summary_characters_test.cpp 
*/

void Summary_Chracters_test(){
    clog << "Test: Started Summary_Characters Class Test using" << endl;
    string input_string(4, 'c');
    Characters* obj = new Characters(input_string);
    int results = Summary_Characters::isDigit(*obj);

    cout << "size of characters is " <<  obj->length() << endl;

    obj->update("test1");
    assert(Summary_Characters::isAlnum(*obj));
    assert(!Summary_Characters::isAlpha(*obj));
    assert(Summary_Characters::isASCII(*obj));

    obj->update("test");
    cout << obj->getText() << endl;
    cout << *obj << endl;
    assert(Summary_Characters::isAlpha(*obj));
    assert(!Summary_Characters::isBlank(*obj));
    assert(!Summary_Characters::isCntrl(*obj));
    assert(!Summary_Characters::isDigit(*obj));
    assert(Summary_Characters::isGraph(*obj));
    assert(Summary_Characters::isLower(*obj));
    assert(Summary_Characters::isPrint(*obj));
    assert(!Summary_Characters::isSpace(*obj));

    obj->update("TEST");
    assert(Summary_Characters::isAlnum(*obj));
    assert(Summary_Characters::isAlpha(*obj));
    assert(!Summary_Characters::isLower(*obj));
    assert(Summary_Characters::isUpper(*obj));
    assert(!Summary_Characters::isXdigit(*obj));

    obj->update("2022");
    assert(Summary_Characters::isAlnum(*obj));
    assert(Summary_Characters::isXdigit(*obj));
    assert(Summary_Characters::isDigit(*obj));
    assert(Summary_Characters::isGraph(*obj));

    obj->update(" \t");
    assert(!Summary_Characters::isAlnum(*obj));
    assert(Summary_Characters::isBlank(*obj));
    assert(!Summary_Characters::isDigit(*obj));
    assert(!Summary_Characters::isGraph(*obj));
    assert(!Summary_Characters::isLower(*obj));
    assert(Summary_Characters::isSpace(*obj));

    obj->update("\r\f\n\v");
    assert(!Summary_Characters::isPrint(*obj));
    assert(Summary_Characters::isCntrl(*obj));
    assert(!Summary_Characters::isPunct(*obj));
    assert(Summary_Characters::isSpace(*obj));

    clog << "Test: Summary_Characters Class passed tests successfully" << endl;
    obj->update("?,]");
    assert(Summary_Characters::isPunct(*obj));
    

    obj->update("ab");
    assert(!Summary_Characters::isUpper(*obj));
    assert(Summary_Characters::isLower(*obj));
    assert(Summary_Characters::isXdigit(*obj));
    

    clog << "Test: Summary_Characters Class passed tests successfully" << endl;
}


int main(){
    Summary_Chracters_test();
}

