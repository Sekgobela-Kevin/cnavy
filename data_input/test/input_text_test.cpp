#include <cassert>
#include "../input_text.hpp"



void Input_Text_Test(){
    string body = "Nelso was a legend of south africa";
    string source = "wikipedia nelson page";
    string title = "Mandela great man";
    string type = "text";
    Input_Text obj(title, source, body);
    // Actual testing start here
    assert(obj.isSourceValid(source));
    assert(obj.isSourceActive(source));
    assert(obj.isLoaded());
    assert(obj.isSourceActive(source));
    assert(obj.fetchData(source) == body);
    assert(obj.getData()["body"] == body);
    //assert(obj.getData() == {})

    // Change state of object
    assert(obj.requestData() == false);
    assert(obj.requestData() == false);
    assert(obj.requestData(true));
    assert(obj.isLoaded());
    assert(obj.getData()["body"] == body);
    assert(obj.getData()["type"] == type);
    assert(obj.getData()["title"] == title);
    assert(obj.getData()["source"] == source);
}

int main(){
    Input_Text_Test();
    cout << "Input_Text class passed tests successfully";
}