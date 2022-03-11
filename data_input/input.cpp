#include "input.hpp"
#include <iostream>


void Input::Initial(string title_, string type_, string source_){
    title = title_;
    type = type_;
    source = source_;
}

Input::Input(string title_, string type_, string source_){
    Initial(title_, type_, source_);
}

unordered_map<string, string> Input::getData(){
    return outData;
}

bool Input::isLoaded(){
    return !outData.empty();
}

void Input::syncData(){
    // It seems like c++ doesnt validate if exists when acccessing element by Key via []
    outData = {{"title", title}, {"type", type}, {"source", source}, {"body", body}};
}

void Input::setContentData(string text){
    body = text;
    syncData();
}

bool Input::requestData(bool force){
    // Procceed obly if source is active and not loaded or force being true
    if(isSourceActive(source) && (!isLoaded() || force)){
        string fetched = fetchData(source);
        if(fetched != ""){
            string converted = dataToText(fetched);
            setContentData(converted);
            return true;
        }
        else{
            clog << source + " returned empty string, it may be empty or bug" << endl;
        }
    }
    return false;
}

