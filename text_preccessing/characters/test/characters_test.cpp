#include <iostream>
#include <cassert>
#include "string"
#include "..\characters.hpp"
using namespace std;

/*
 g++ ..\character\character.cpp ..\character\character_compute.cpp 
 characters.cpp test\characters_test.cpp
*/

void Characters_Test(){
    clog << "Test: Started Characters Class Test using" << endl;
    string* input_string = new string(5, 'a');
    string* input_string2 = new string(5, '1');
    Characters* obj = new Characters(*input_string);
    Characters* obj2 = new Characters(*input_string2);
    
    // test overloaded operators
    Characters new_chars_obj = *obj + *obj2;
    cout << "print chars_obj: " << new_chars_obj << endl;

    cout << "print character objs throug for each" << endl;
    for(auto char_obj: new_chars_obj) cout << char_obj;
    cout << endl;

    // check if + operator works
    assert(new_chars_obj.getText() == *input_string+*input_string2);


    // Characters implemets string
    // comaparing with string is valid
    assert(*obj == *input_string);
    //cout << obj->getText() << endl;
    assert(obj->getText() == *input_string);
    obj->update("str");
    assert(*obj== "str");

    cout << "size of characters is " <<  obj->length() << endl;

    delete input_string;
    delete obj;
    clog << "Test: Characters Class passed tests successfully" << endl;
}


int main(){
    Characters_Test();
}


/*
--------------------------
2022 March 16
--------------------------
--------------------------
1. First test
--------------------------
git bash(VS code terminal)
compiler - g++
os - windows 10
terminal - VS code git bash
--------------------------
obj.boolIsPunct() was called
twice after init of obj
--------------------------
Characters count - 1 041 900
real    0m3.702s
user    0m0.000s
sys     0m0.125s
--------------------------
--------------------------
Characters count - 3 386 250
real    0m11.026s
user    0m0.031s
sys     0m0.078s
--------------------------
--------------------------
Characters count - 5 000 000
real    0m15.503s
user    0m0.015s
sys     0m0.046s
--------------------------
--------------------------
Characters count - 5 000 000(only string creation)
real    0m0.368s
user    0m0.015s
sys     0m0.109s
--------------------------
--------------------------
Characters count - 5 000 000(without characters update on init)
real    0m11.157s
user    0m0.000s
sys     0m0.124s
--------------------------
--------------------------
Characters count - 10 000 000
real    0m22.048s
user    0m0.015s
sys     0m0.046s
--------------------------
--------------------------
Characters count - 10 000 000(with update on init)
real    0m30.292s
user    0m0.000s
sys     0m0.078s
--------------------------
--------------------------
*/

/*
--------------------------
2. second test
--------------------------
Only initialisation 
3 standard out calls
--------------------------
--------------------------
Characters count - 100 000(with update on init)
real    0m0.516s
user    0m0.015s
sys     0m0.062s
--------------------------
--------------------------
Characters count - 3 000 000(with update on init)
real    0m4.562s
user    0m0.015s
sys     0m0.077s
--------------------------
--------------------------
Characters count - 5 000 000(with update on init)
real    0m7.384s
user    0m0.015s
sys     0m0.061s
--------------------------
--------------------------
Characters count - 10 000 000(with update on init)
real    0m15.381s
user    0m0.015s
sys     0m0.061s
--------------------------
--------------------------
Characters count - 50 000 000(with update on init)
real    1m28.125s
user    0m0.016s
sys     0m0.108s
--------------------------
*/



/*
Notes and conclusion:

Class is supper fast for small number of elements less than 1 million which can 
take 1 minute to create object. For 100 000 elements it takes about half a minute.
Without calling update inside each Character object, performance is improved by
50% based on first test..

Boleans object will only contain few characters of size same as word. The speed of the class
is fast for creating the objects meaning tokens will be created faster. The test shows that it
be slow to create doc objects since they will contain millions of character. 7 seconds on 5 million 
characters is too much. If it can be decreased by 50% in a way that it takes 3.5 seconds that
will be better.

Characters will freed from updates of atrributes values on initialisation and other classes freed 
from characters including compute classes and Character class used other than Line_Character Class.
That may help make creating Characters fast since that will be repeated millions of times
for each character in text.

Bad_bit error was thrown when input_string(text) length was 50 000 000. Spacy has a limit on tokens 
which was 1 million and reason was memory. Similar a limit needs to be set for how many characters 
can exist in document.

Problems and performance issues mensioned does not impact Bool_Characters as it stores little number 
of elements. They will impact mostly the document that will house all the characters and tokens.

*/


/*
--------------------------
2022 March 17
--------------------------
without update on
init in Character Class
--------------------------
--------------------------
Characters count - 5 000 000
real    0m4.918s
user    0m0.031s
sys     0m0.030s
memory  167 Mb
--------------------------
Characters count - 50 000 000
real    0m28.236s
user    0m0.000s
sys     0m0.062s
memory  1700 Mb
cpu     70%
--------------------------
Character used instead of
Line_Characters
--------------------------
Characters count - 50 000 000
real    0m25.030s
user    0m0.000s
sys     0m0.109s
memory  1384 Mb
cpu     50-69%
--------------------------
Vector used instead of
Deque
--------------------------
Characters count - 50 000 000
real    0m10.080s
user    0m0.000s
sys     0m0.093s
memory  1299 Mb
cpu     60-79%
--------------------------
Using for loop range in 
Characters other regular
for loop
--------------------------
Characters count - 50 000 000
real    0m8.891s
user    0m0.000s
sys     0m0.093s
--------------------------
re test(final)
--------------------------
Characters count - 5 000 000
real    0m1.173s from 0m4.918s
user    0m0.000s
sys     0m0.062s
--------------------------
*/


/*
--------------------------
2022 March 18
--------------------------
--------------------------
Characters count - 100 000 000
real    0m10.900s
user    0m0.000s
sys     0m0.046s
memory  1199 MB
cpu     50 - 72%
--------------------------

*/