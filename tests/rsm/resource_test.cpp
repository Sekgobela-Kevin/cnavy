#include "resource.hpp"
#include "doctest.h"
using namespace std;


void Enable_Doctest_RSM_Resource(){};

TEST_CASE("Resource Class test"){
    /*Test if Resource class and all its objects are doing well*/
    string body = "Body of text";
    string title = "Title of text";
    string type = "Webpage";
    Resource* ResourceObj;
    ResourceObj = new Resource(body, title, type);

    // Tests methods for validating if member variables are in range
    CHECK(ResourceObj->minRangeValid(make_pair(5, 10), "is pair") == true);
    CHECK(ResourceObj->maxRangeValid(make_pair(5, 10), "is pair") == true);
    CHECK(ResourceObj->rangeValid(make_pair(5, 10), "is pair") == true);

    CHECK(ResourceObj->minRangeValid(make_pair(5, 10), "is pair is extended") == true);
    CHECK(ResourceObj->maxRangeValid(make_pair(5, 10), "is pair is extended") == false);
    CHECK(ResourceObj->rangeValid(make_pair(5, 10), "is pair is extended") == false);

    CHECK(ResourceObj->minRangeValid(make_pair(5, 10), "is") == false);
    CHECK(ResourceObj->maxRangeValid(make_pair(5, 10), "is") == true);
    CHECK(ResourceObj->rangeValid(make_pair(5, 10), "is") == false);

    CHECK(ResourceObj->minRangeValid(make_pair(5, 10), "is pair extended") == true);
    CHECK(ResourceObj->maxRangeValid(make_pair(5, 10), "pair") == true);
    CHECK(ResourceObj->rangeValid(make_pair(5, 10), "is") == false);


    // Test get methods of Resources class
    CHECK(ResourceObj->getType() ==  type);
    CHECK(ResourceObj->getTitle() ==  title);
    CHECK(ResourceObj->getBody() ==  body);
    CHECK(ResourceObj->titleBodyMatch() == false);

    // arguments get swaped and tested if change happened
    ResourceObj->setBody(title);
    ResourceObj->setTitle(body);
    ResourceObj->setType(body);

    CHECK(ResourceObj->getType() ==  body);
    CHECK(ResourceObj->getTitle() ==  body);
    CHECK(ResourceObj->getBody() ==  title);

    // Test if titleBodyMatch() works
    ResourceObj->setBody(title);
    ResourceObj->setTitle(title);
    CHECK(ResourceObj->titleBodyMatch() == true);

    ResourceObj->setBody("This are different");
    ResourceObj->setTitle("This is different");
    CHECK(ResourceObj->titleBodyMatch() == false);


    // resets arguments to test if data is exported well
    ResourceObj->setBody(body);
    ResourceObj->setTitle(title);
    ResourceObj->setType(type);
    unordered_map<string, string> expectedExportedData= {
        {"type", type}, {"body", body}, {"title", title}
    };
    CHECK(ResourceObj->exportData() == expectedExportedData);

    delete ResourceObj;
    cout << "Resource class is doing well" << endl;

}
