#include "resource.hpp"
using namespace std;


void Resource_Test(string body, string title, string type){
    /*Test if Resource class and all its objects are doing well*/
    Resource* ResourceObj;
    ResourceObj = new Resource(body, title, type);

    // Tests methods for validating if member variables are in range
    assert(ResourceObj->minRangeValid(make_pair(5, 10), "is pair") == true);
    assert(ResourceObj->maxRangeValid(make_pair(5, 10), "is pair") == true);
    assert(ResourceObj->rangeValid(make_pair(5, 10), "is pair") == true);

    assert(ResourceObj->minRangeValid(make_pair(5, 10), "is pair is extended") == true);
    assert(ResourceObj->maxRangeValid(make_pair(5, 10), "is pair is extended") == false);
    assert(ResourceObj->rangeValid(make_pair(5, 10), "is pair is extended") == false);

    assert(ResourceObj->minRangeValid(make_pair(5, 10), "is") == false);
    assert(ResourceObj->maxRangeValid(make_pair(5, 10), "is") == true);
    assert(ResourceObj->rangeValid(make_pair(5, 10), "is") == false);

    assert(ResourceObj->minRangeValid(make_pair(5, 10), "is pair extended") == true);
    assert(ResourceObj->maxRangeValid(make_pair(5, 10), "pair") == true);
    assert(ResourceObj->rangeValid(make_pair(5, 10), "is") == false);


    // Test get methods of Resources class
    assert(ResourceObj->getType() ==  type);
    assert(ResourceObj->getTitle() ==  title);
    assert(ResourceObj->getBody() ==  body);
    assert(ResourceObj->titleBodyMatch() == false);

    // arguments get swaped and tested if change happened
    ResourceObj->setBody(title);
    ResourceObj->setTitle(body);
    ResourceObj->setType(body);

    assert(ResourceObj->getType() ==  body);
    assert(ResourceObj->getTitle() ==  body);
    assert(ResourceObj->getBody() ==  title);

    // Test if titleBodyMatch() works
    ResourceObj->setBody(title);
    ResourceObj->setTitle(title);
    assert(ResourceObj->titleBodyMatch() == true);

    ResourceObj->setBody("This are different");
    ResourceObj->setTitle("This is different");
    assert(ResourceObj->titleBodyMatch() == false);


    // resets arguments to test if data is exported well
    ResourceObj->setBody(body);
    ResourceObj->setTitle(title);
    ResourceObj->setType(type);
    unordered_map<string, string> expectedExportedData= {
        {"type", type}, {"body", body}, {"title", title}
    };
    assert(ResourceObj->exportData() == expectedExportedData);

    delete ResourceObj;
    cout << "Resource class is doing well" << endl;

}



int main(){
    string body = "Body of text";
    string title = "Title of text";
    string type = "Webpage";
    try{
        Resource_Test(body, title, type);
    }
    catch (const char *str){
        cout << str << endl;
    }
    
    return 0;
}
