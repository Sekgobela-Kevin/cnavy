#include "input_webpage.hpp"
#include <regex>
#include <stdexcept>
#include <cassert>

Input_Webpage::Input_Webpage(string title_, string source_) : Input(title_, "webpage", source_){

}

bool Input_Webpage::isSourceValid(string url){
    /* Regex pattern from : https://stackoverflow.com/questions/38608116/
        how-to-check-a-specified-string-is-a-valid-url-or-not-using-c-code
    */
    std::regex pattern(R"(^(https?:\/\/)?([\da-z\.-]+)\.([a-z\.]{2,6})([\/\w \.-]*)*\/?$)");
    return std::regex_match(url, pattern);
}


bool Input_Webpage::isSourceActive(string url){
    // check if the url(source) is active by connecting to internet
    // Cannot be implemented due to lack of library in C++ for making internet requests
    // if output of fetchData() is small 
    std::string fetched = fetchData(url);
    return isHtml(fetched);
};

string Input_Webpage::fetchData(string url){
    // Needs library for internet requests to work
    // Tried multiple libraries but failed to build with Cmake
    // Using curl seems like the only way to do it
    std::string output;
    try{
        //std::string output = runCommand("curl --ssl-no-revoke " + source);
        string command = "curl --ssl-no-revoke  --max-time 5 --connect-timeout 3 --silent ";
        output = runCommand(command + url);
        return output;
    }
    catch(std::runtime_error& e){
        std::clog << e.what() << std::endl;
        //output = "err";
    }
    return output;
}



string Input_Webpage::getHtmlBody(std::string html){
    return getHtmlTag(html, "body");
}

string Input_Webpage::removeTags(std::string html){
    // not guaranteed to work on all html tags with attributes
    std::regex pattern(R"(<[^<>]*?>)");
    return std::regex_replace (html, pattern, "");
}

string Input_Webpage::parseHtmlBody(std::string html){
    string striptTagsRemoved = removeHtmlTag(html, "stript");
    string htmlBodyContents = getHtmlBody(striptTagsRemoved);
    return removeTags(htmlBodyContents);
}


string Input_Webpage::dataToText(string data){
    return parseHtmlBody(data);
}

string Input_Webpage::removeHtmlTag(string html, string tag){
    // this regex can cause program termination according to: 
    //    https://gcc.gnu.org/bugzilla/show_bug.cgi?id=86164
    //clog << "removeHtmlTag() called" << endl;
    // not working for nested tags(those inside body tag) but works on <body>
    std::regex pattern("<" + tag + R"([^<>]*?>[\s\S]*?</)" + tag + ">");
    // clog << "removeHtmlTag()  pattern created called" << endl;
    return std::regex_replace(html, pattern, "");
}

string Input_Webpage::removeJsCode(string html){
    // this regex can cause program termination according to: 
    //    https://gcc.gnu.org/bugzilla/show_bug.cgi?id=86164
    //clog << "removeHtmlTag() called" << endl;
    // not working for nested tags(those inside body tag) but works on <body>
    std::regex pattern(R"(\{[\s\S\]*})");
    // clog << "removeHtmlTag()  pattern created called" << endl;
    return std::regex_replace(html, pattern, " ---JS block removed here--- ");
}

string Input_Webpage::getHtmlTag(string html, string tag){
    /*std::regex pattern("<" + tag + R"([^<>]*>[\s\S]*</)" + tag + ">", std::regex_constants::icase);
    clog << "getHtmlTag()  pattern created called" << endl;
    std::smatch match;
    clog << "getHtmlTag()  match object created" << endl;
    //this line crashes: https://gcc.gnu.org/bugzilla/show_bug.cgi?id=86164
    std::regex_search (html, match, pattern);
    clog << "getHtmlTag()  regex search finished" << endl;
    */

    // due to problems with regex(stackoverflow)
    // regex is now used to find open and closng tags and then use their position to get tags text

    // set match objects for open tag and closing tag
    std::smatch openTagMatch;
    std::smatch closeTagMatch;

    // also regex pattern for each
    std::regex openTagPattern("<" + tag + R"([^<>]*?>)", std::regex_constants::icase);
    std::regex closeTagPattern("</" + tag + ">", std::regex_constants::icase);

    // perform search on earch
    std::regex_search (html, openTagMatch, openTagPattern);
    std::regex_search (html, closeTagMatch, closeTagPattern);

    // get first character index for each from match objects
    int startIndex = openTagMatch.position();
    // tag.length() + 3 is used to offset to end of substring with 3 length of (</>) characters
    int endIndex = (closeTagMatch.position() + tag.length() + 3);
    int length = endIndex - startIndex;


    // compute substring using the indexes
    string htmlTagText = html.substr(startIndex, length);

    if(closeTagMatch.length() == 0 && openTagMatch.length() == 0){
        cerr << "ERROR: " << tag << " tag not found in html" << endl;
    }

    else if (closeTagMatch.length() == 0)
    {
        cerr << "ERROR: closing tag for " << tag << " not found" << endl;
    }

    else if (openTagMatch.length() == 0)
    {
        cerr << "ERROR: open tag for " << tag << " not found" << endl;
    }
    
    return htmlTagText;
}


bool Input_Webpage::isHtml(string text){
    // if text is HTML then the original text is different from HTML tags removed
    return removeTags(text) != text;
}

std::string Input_Webpage::runCommand(string cmd) {
    /* code sample from: https://stackoverflow.com/questions/478898/
        how-do-i-execute-a-command-and-get-the-output-of-the-command-within-c-using-po
    */
    /* I tried to use stringbuff with cout, cerr, clog with system() but could not capture
       output. It seems like system uses different output streams which I could redirect
       to the string buffer.

       But this code from stackoverflow works by using pipes similar to linux. But myself never
       learnt how to do it in C/C++.
    */
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd.c_str(), "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

bool Input_Webpage::processorAvail(){
    return system(NULL) ? true:false;
}
bool Input_Webpage::isWebConneted(){
    return isSourceActive("datanavy.site");
}
