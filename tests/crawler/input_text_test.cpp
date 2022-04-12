
#include "doctest.h"
#include "input_text.hpp"

/* called to enable tests */
void Enable_Doctest_Crawl_Text(){};

TEST_CASE("crawler file_text test"){
    string body = "Nelso was a legend of south africa";
    string source = "wikipedia nelson page";
    string title = "Mandela great man";
    string type = "text";
    Input_Text obj(title, source, body);
    // Actual testing start here
    CHECK(obj.isSourceValid(source));
    CHECK(obj.isSourceActive(source));
    CHECK(obj.isLoaded());
    CHECK(obj.isSourceActive(source));
    CHECK(obj.fetchData(source) == body);
    CHECK(obj.getData()["body"] == body);
    //CHECK(obj.getData() == {})

    // Change state of object
    CHECK(obj.requestData() == false);
    CHECK(obj.requestData() == false);
    CHECK(obj.requestData(true));
    CHECK(obj.isLoaded());
    CHECK(obj.getData()["body"] == body);
    CHECK(obj.getData()["type"] == type);
    CHECK(obj.getData()["title"] == title);
    CHECK(obj.getData()["source"] == source);
}
