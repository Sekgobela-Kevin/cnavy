#include "../input_webpage.hpp"
#include <cassert>


void Input_Webpage_Test(){
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
    assert(obj.removeTags(html) == "test this" + body);
    assert(obj.getHtmlTag(html, "body") == htmlBody);
    assert(obj.removeHtmlTag(html, "body") == htmlBodyRemoved);
    assert(obj.getHtmlBody(html) == htmlBody);
    assert(obj.parseHtmlBody(html) == body);

    assert(obj.isHtml(html));
    assert(obj.isHtml(body) == false);

    clog << "finished testing HTML methods" << endl;

    // Change state of object
    obj.setContentData(obj.parseHtmlBody(html));
    assert(obj.getData()["body"] == body);
    assert(obj.getData()["type"] == type);
    assert(obj.getData()["source"] == source);


    clog << "checks if interent connection available" << endl;
    if(!obj.isWebConneted()){
        clog << "Input_Webpage test failed: No internet connection";
        return;
    }
    clog << "completed obj.isWebConneted()" << endl;

    // test if commands run with expected return values
    string command = "curl  --ssl-no-revoke --max-time 5 --connect-timeout 3 --silent";
    assert(obj.runCommand(command + " datanavy.site").length() > 0);
    assert(obj.runCommand(command + " sfrgesdeefs").length() == 0);
    clog << "completed obj.runCommand() commands" << endl;

    assert(obj.isSourceActive(source));
    assert(obj.isSourceValid(source));
    clog << "completed obj.isSourceActive(source) and obj.isSourceValid(source)" << endl;
    assert(obj.fetchData(source).length() > 0);
    clog << "completed obj.fetchData(source))" << endl;



    // real webpage test
    assert(obj.requestData(true));
    assert(obj.getData()["body"].length() > 0);
    clog << "completed obj.requestData(true)" << endl;

    clog << "Input_Webpage class passed tests successfully" << endl;
    // passed test on 2022 March 07 - before using curl
    // passed test on 2022 March 09 - implemented internet access using curl on commnad processor
        //(lot of fails that faded during testing due to observer effect)
}

int main(){
    Input_Webpage_Test();
}
