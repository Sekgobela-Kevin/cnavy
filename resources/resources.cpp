#include <algorithm>
#include <functional>
#include "resources.hpp"

using namespace std;


Resources::Resources(){
    total = 0;
    resourcesObjs = {};
}

Resources::Resources(list<Resource> resourcesList){
    resourcesObjs = resourcesList;
    total = resourcesObjs.size();
}

Resources::Resources(list<unordered_map<string, string>> importData){
    resourcesObjs = importsToResourcesObjs(importData);
    total = resourcesObjs.size();
}

list<Resource> Resources::importsToResourcesObjs(list<unordered_map<string, string>> importData){
    list<Resource> resourcesList;
    function<void(unordered_map<string, string>)> func;
    func = [&resourcesList](unordered_map<string, string> data){
        // Be careful as initialising Resources object withou will result in residing in stack memory
        // It should be changed in production since these objects can be large
        // Use new new ketword and make the object pointer and release memory with delete
        Resource resourceObj = Resource(data["body"], data["title"], data["type"]);
        resourcesList.emplace_back(resourceObj);
    };
    for_each(importData.begin(), importData.end(), func);
    // If size of input is same as output than evrything is doing well
    assert(resourcesList.size() == importData.size());
    return resourcesList;
}


list<string> Resources::getTitles(){
    list<string> titles;
    function<void(Resource)> func = [&titles](Resource obj){
        titles.emplace_back(obj.getTitle());
    };
    for_each(resourcesObjs.begin(), resourcesObjs.end(), func);
    return titles;
}


list<string> Resources::getBodies(){
    list<string> bodies;
    function<void(Resource)> func = [&bodies](Resource obj){
        bodies.emplace_back(obj.getBody());
    };
    for_each(resourcesObjs.begin(), resourcesObjs.end(), func);
    return bodies;
}


list<string> Resources::getTypes(){
    list<string> types;
    function<void(Resource)> func = [&types](Resource obj){
        types.emplace_back(obj.getType());
    };
    for_each(resourcesObjs.begin(), resourcesObjs.end(), func);
    return types;
}

bool Resources::exists(Resource resourceObj){
    list<string> titles = getTitles();
    bool found = find(titles.begin(), titles.end(), resourceObj.getTitle()) != end(titles);
    return found;
}

bool Resources::exists(string title){
    list<string> titles = getTitles();
    bool found = find(titles.begin(), titles.end(), title) != end(titles);
    return found;
}

Resource Resources::get(string title){
    for (Resource& obj : resourcesObjs)
    {
        if (obj.getTitle() == title)
        {
            return obj;
        }
    }
    throw "Resource not found";
}

void Resources::remove(string title){
    assert(exists(title));
    Resource obj = get(title);
    resourcesObjs.remove_if([&title](Resource xObj){return xObj.getTitle() == title;});
    assert(exists(title) != true);
    
}

void Resources::remove(Resource obj){
    assert(exists(obj));
    remove(obj.getTitle());
    assert(exists(obj) != true);
}

void Resources::add(Resource obj){
    resourcesObjs.emplace_back(obj);
}

int Resources::getTotal(){
    return resourcesObjs.size();
}

int Resources::getInitialTotal(){
    return total;
}

void Resources::deleteRef(){
    // Currently unused due to Resourse instead of Resourse* when building this object class
    //for_each(resourcesObjs.begin(), resourcesObjs.end(), [](Resource* obj){delete obj;});
}

void Resources::clear(){
    if (isEmpty()){
        // perform check if resources elemts in resourcesList are pointer or actual objects
        // If they are pointers call this-> deleteRef() to release memory before clear
        resourcesObjs.clear();
    }
    return resourcesObjs.clear();
}

bool Resources::isEmpty(){
    return resourcesObjs.empty();
}

list<Resource> Resources::getResourcesObjs(){
    list<Resource> copied(resourcesObjs);
    return copied;
}

list<unordered_map<string, string>> Resources::exportData(){
    list<unordered_map<string, string>> exported;
    function<void(Resource)> func = [&exported](Resource obj){
        exported.emplace_back(obj.exportData());
    };
    for_each(resourcesObjs.begin(), resourcesObjs.end(), func);
    return exported;
}

