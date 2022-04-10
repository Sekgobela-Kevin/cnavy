#include <iostream>
#include <regex>
#include <stdexcept>
using namespace std;
 
int main() {
    string html = "<script>a = b;</script> {round world}.";
    string substr = "round";
    string openTag = "hello";
    string closeTag = "round";
    string tag = "body";
    string bodyContent = "<script>hello world.</script>";

    std::smatch openTagMatch;
    std::smatch closeTagMatch;

    // also regex pattern for each
    std::regex openTagPattern(R"(\{[\s\S]+\})", std::regex_constants::icase);

    // perform search on earch
    std::regex_search (html, openTagMatch, openTagPattern);

    cout <<  openTagMatch.str() << endl;


}