#include <list>
#include <vector>

#include "resources.hpp"
#include "doctest.h"

void Enable_Doctest_RSM_Resources(){};

list<unordered_map<string, string>> resourcesDataList  = {
    {{"body", "Small body entered"}, {"title", "title also"}, {"type", "webpage"}},
    {{"body", "life is good"}, {"title", "care and love"}, {"type", "file"}},
    {{"body", "my daily life"}, {"title", "expectations"}, {"type", "text"}},
    {{"body", "language as prcess"}, {"title", "human intelligence"}, {"type", "file"}},
};

list<Resource> resourcesList  = {
    Resource("Small body entered", "title also", "webpage"),
    Resource("life is good", "care and love", "file"),
    Resource("my daily life", "expectations", "text"),
    Resource("language as prcess", "human intelligence", "file"),
};



TEST_CASE("Resources Class test"){
    Resources obj = Resources(resourcesDataList);
    // check if total was changed
    CHECK(obj.getTotal() == resourcesList.size());


    // check getTitles works
    list<string> titles = {"title also", "care and love", "expectations", "human intelligence"};
    list<string> bodies = {"Small body entered", "life is good", "my daily life", "language as prcess"};
    list<string> types = {"webpage", "file", "text", "file"};
    CHECK(obj.getTitles() == titles);
    CHECK(obj.getTypes() == types);
    CHECK(obj.getBodies() == bodies);


    // Test exporting of resource list or conversions
    // Resources objects list cannot be since it contains resources objects
    // But trick can help to validate if it returns well
    CHECK(obj.exportData() == resourcesDataList);
    // trick is use return value to create new Resources object which will be tested
    auto sdf = obj.getResourcesObjs();
    Resources obj2 = Resources(sdf);
    CHECK(obj2.getTotal() == resourcesList.size());
    CHECK(obj2.getTitles() == titles);

    // tests methods that work with booleans
    CHECK(obj.exists("care and love"));
    CHECK(obj.exists("human intelligence"));
    CHECK(!obj.exists("music industry scandals"));
    CHECK(!obj.isEmpty());

    // tests get() along with its return value
    Resource uuyt = obj.get("human intelligence");
    CHECK(uuyt.getTitle() == "human intelligence");
    CHECK(obj.exists(uuyt));
    try{
        obj.get("does not exist");
        CHECK(false);
    }
    catch(const char* str){ 
    }

    // Test for method for manipulating the list with resources objects
    obj.add(Resource("Small boy is too short", "Cute", "webpage"));
    obj.add(Resource("Small boy2 is too short", "Cute2", "webpage"));
    CHECK(obj.getTotal() == resourcesList.size()+2);
    CHECK(obj.exists("Cute"));
    CHECK(obj.exists("Cute2"));
    obj.remove(Resource("Small boy2", "Cute2", "webpage"));
    obj.remove("Cute");
    CHECK(obj.getTotal() == resourcesList.size());
    CHECK(!obj.exists("Cute"));
    CHECK(!obj.exists("Cute2"));



    // Test if resources get free or cleared
    obj.clear();
    CHECK(obj.isEmpty());

    clog << "Resources class passed tests successfully";
    
}
