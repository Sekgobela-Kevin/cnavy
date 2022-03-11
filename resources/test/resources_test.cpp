#include <list>
#include <vector>
#include "../resources.hpp"


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



void Resources_Test(){
    Resources obj = Resources(resourcesDataList);
    // check if total was changed
    assert(obj.getTotal() == resourcesList.size());


    // check getTitles works
    list<string> titles = {"title also", "care and love", "expectations", "human intelligence"};
    list<string> bodies = {"Small body entered", "life is good", "my daily life", "language as prcess"};
    list<string> types = {"webpage", "file", "text", "file"};
    assert(obj.getTitles() == titles);
    assert(obj.getTypes() == types);
    assert(obj.getBodies() == bodies);


    // Test exporting of resource list or conversions
    // Resources objects list cannot be since it contains resources objects
    // But trick can help to validate if it returns well
    assert(obj.exportData() == resourcesDataList);
    // trick is use return value to create new Resources object which will be tested
    auto sdf = obj.getResourcesObjs();
    Resources obj2 = Resources(sdf);
    assert(obj2.getTotal() == resourcesList.size());
    assert(obj2.getTitles() == titles);

    // tests methods that work with booleans
    assert(obj.exists("care and love"));
    assert(obj.exists("human intelligence"));
    assert(!obj.exists("music industry scandals"));
    assert(!obj.isEmpty());

    // tests get() along with its return value
    Resource uuyt = obj.get("human intelligence");
    assert(uuyt.getTitle() == "human intelligence");
    assert(obj.exists(uuyt));
    try{
        obj.get("does not exist");
        assert(false);
    }
    catch(const char* str){ 
    }

    // Test for method for manipulating the list with resources objects
    obj.add(Resource("Small boy is too short", "Cute", "webpage"));
    obj.add(Resource("Small boy2 is too short", "Cute2", "webpage"));
    assert(obj.getTotal() == resourcesList.size()+2);
    assert(obj.exists("Cute"));
    assert(obj.exists("Cute2"));
    obj.remove(Resource("Small boy2", "Cute2", "webpage"));
    obj.remove("Cute");
    assert(obj.getTotal() == resourcesList.size());
    assert(!obj.exists("Cute"));
    assert(!obj.exists("Cute2"));



    // Test if resources get free or cleared
    obj.clear();
    assert(obj.isEmpty());

    clog << "Resources class passed tests successfully";
    
}



int main(){
    Resources_Test();
}