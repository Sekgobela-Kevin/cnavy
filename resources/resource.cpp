#include "resource.hpp"

using namespace std;

Resource::Resource(string bodyText, string title, string type){
    bodyRange = make_pair(10, 800000);
    titleRange = make_pair(2, 50);
    typeRange = make_pair(2, 50);

    assert(titleRange.first <  titleRange.second);
    assert(bodyRange.first <  bodyRange.second);
    assert(typeRange.first <  typeRange.second);
    
    setBody(bodyText);
    setTitle(title);
    setType(type);

    assert(getType() ==  type);
    assert(getTitle() ==  title);
    assert(getBody() ==  bodyText);
};

void Resource::setBody(string text){
    /* Sets the text of the resource which includes the title. The body is every text with
    resource.*/
    if(!rangeValid(bodyRange, text)){
        throw "Length of resource body text is out of range";
    }
    bodyText = text;
}

void Resource::setTitle(string text){
    /* Sets title of resource which is the heading of the resource usually extracted from
    heading of the resource.*/
    if(!rangeValid(titleRange, text)){
        throw "Length of resource title text is out of range";
    }
    title = text;
}

void Resource::setType(string text){
    /* Sets type of resource to help in identifying where it was extracted
        e.g webpage, file or cmd*/
    if(!rangeValid(typeRange, text)){
        throw "Length of resource type text is out of range";
    }
    type = text;
}



string Resource::getBody(){
    /* Get text(all) of the resource which includes the title. The body is every text with
    resource.*/
    return bodyText;
}

string Resource::getTitle(){
    /* Get title of resource which is the heading of the resource usually extracted from
    heading of the resource.*/
    return title;
}

string Resource::getType(){
    /**
     * @brief Get type of resource to help in identifying where it was extracted
     e.g webpage, file or cmd
    */
    return type;
}

bool Resource::titleBodyMatch(){
    /**
     * @brief Checks if title of resource matches its body
    */
    return bodyText.find(title)!= string::npos? true : false;
}

bool Resource::minRangeValid(pair <int,int> range_pair, string text){
    assert(range_pair.first <  range_pair.second);
    return text.length() >= range_pair.first;
}

bool Resource::maxRangeValid(pair <int,int> range_pair, string text){
    assert(range_pair.first <  range_pair.second);
    return text.length() <= range_pair.second;
}


bool Resource::rangeValid(pair <int,int> range_pair, string text){
    assert(range_pair.first <  range_pair.second);
    return minRangeValid(range_pair, text) && maxRangeValid(range_pair, text);
}

unordered_map<string, string> Resource::exportData(){
    unordered_map<string, string> map = {{"type", type}, {"body", bodyText}, {"title", title}};
    return map;
}



