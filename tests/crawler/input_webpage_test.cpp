#include "doctest.h"
#include "input_webpage.hpp"

#include <string>
#include <iostream>

void Enable_Doctest_Crawl_Web(){};

TEST_CASE("crawler webpage test"){
    clog << "Input_Webpage class test started" << endl;
    /* This test is slow due to repeated curl commands(requests)*/
    // initialise test variables
    string body = "Nelson was a legend of south africa";
    string html = "<!DOCTYPE html><html><div color='blue'>test this</div><body>"+body+"</body></html>";
    string htmlBody = "<body>"+body+"</body>";
    string htmlBodyRemoved = "<!DOCTYPE html><html><div color='blue'>test this</div></html>";
    string source = "www.google.com";
    string title = "301 Moved";
    string type = "webpage";

    Input_Webpage obj = Input_Webpage(title, source);

    clog << "testing HTML methods" << endl;
    // Test html methods(no internet required)
    CHECK(obj.removeTags(html) == "test this" + body);
    CHECK(obj.getHtmlTag(html, "body") == htmlBody);
    CHECK(obj.removeHtmlTag(html, "body") == htmlBodyRemoved);
    CHECK(obj.getHtmlBody(html) == htmlBody);
    CHECK(obj.parseHtmlBody(html) == body);

    CHECK(obj.isHtml(html));
    CHECK(obj.isHtml(body) == false);

    clog << "finished testing HTML methods" << endl;

    // Change state of object
    obj.setContentData(obj.parseHtmlBody(html));
    CHECK(obj.getData()["body"] == body);
    CHECK(obj.getData()["type"] == type);
    CHECK(obj.getData()["source"] == source);


    MESSAGE("checks if interent connection available");
    CHECK_MESSAGE(obj.isWebConneted(), "No internet connection");
    MESSAGE("Finished checking for internet connection");

    // test if commands run with expected return values
    string command = "curl  --ssl-no-revoke --max-time 5 --connect-timeout 3 --silent";
    CHECK(obj.runCommand(command + " datanavy.site").length() > 0);
    CHECK(obj.runCommand(command + " sfrgesdeefs").length() == 0);
    clog << "completed obj.runCommand() commands" << endl;

    CHECK(obj.isSourceActive(source));
    CHECK(obj.isSourceValid(source));
    clog << "completed obj.isSourceActive(source) and obj.isSourceValid(source)" << endl;
    CHECK(obj.fetchData(source).length() > 0);
    clog << "completed obj.fetchData(source))" << endl;



    // real webpage test
    CHECK(obj.requestData(true));
    CHECK(obj.getData()["body"].length() > 0);
    clog << "completed obj.requestData(true)" << endl;

    clog << "Input_Webpage class passed tests successfully" << endl;
    // passed test on 2022 March 07 - before using curl
    // passed test on 2022 March 09 - implemented internet access using curl on commnad processor
        //(lot of fails that faded during testing due to observer effect)
}