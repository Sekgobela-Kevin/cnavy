#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#include "input_webpage.hpp"

#include "basic_token.hpp"
#include "basic_tokeniser.hpp"
#include "resources.hpp"

#include <SQLiteCpp/SQLiteCpp.h>
#include <SQLiteCpp/VariadicBind.h>

string web_request(){
    vector<string> urls = {
        "https://en.wikipedia.org/wiki/South_Africa",
        "https://en.wikipedia.org/wiki/Pan-Africanism",
        "https://en.wikipedia.org/wiki/Pan-African_Congress#5th_Pan-African_Congress",
        "https://en.wikipedia.org/wiki/First_Pan-African_Conference",
        "https://en.wikipedia.org/wiki/United_States",
        "https://en.wikipedia.org/wiki/Americas"
    };

    string text;
    
    for(auto url : urls){
        Input_Webpage web_crawl("C++ tutorialspoint", url);
        if(!web_crawl.requestData()){
            clog << "failed to get data from url: " << url << endl;
        }
        else{
            string extracted = web_crawl.getData()["body"];
            text += extracted;
        }
    }
    return text;
}

Basic_Tokeniser tokenise(string text){
    cout << "tokenising text: " << text.size() << endl;

    Basic_Tokeniser tokens = Basic_Tokeniser(text, [](char_type c){
        return Basic_Token::shared_char_objs[c].is_blank;
    });
    for (auto token_ref : tokens)
    {
        Basic_Token token = token_ref.get();
        if(token.isDigit(0.4) && token.isUpper(0.4)){
            cout << token.text << "      is_digit & is_upper  --> " << token.ratio_is_alpha << endl;
        }
        
    }

    cout << "shared char objs size is: " << Basic_Token::shared_char_objs.size() << endl;
    cout << "shared token objs size is: " << Basic_Tokeniser::shared_chars_objs.size() << endl;
    cout << endl;

    return tokens;
}



Resources getResourcesFromDB(string filename, int limit){
    Resources resources_obj;
    try{
        SQLite::Database db(filename, SQLite::OPEN_READWRITE|SQLite::OPEN_CREATE);
        SQLite::Statement   query(db, "SELECT type, source, title, body FROM RESOURCES\
        WHERE LENGTH(body) > 50 LIMIT :limit;");
        query.bind(":limit", limit); 
        while (query.executeStep())
        {
            string body = query.getColumn("body");
            string title = query.getColumn("title");
            string type = query.getColumn("type");
            string source = query.getColumn("source");
            auto resource_obj = Resource(body, title, type);
            resources_obj.add(resource_obj);
        }
    }
    catch (std::exception& e)
    {
        std::cout << "SQLite exception: " << e.what() << std::endl;
        exit(1);
    }
    return resources_obj;
}


void setResourceDB(string filename, string type, string source, string title, 
string body){
    SQLite::Database db(filename, SQLite::OPEN_READWRITE|SQLite::OPEN_CREATE);

    string sql = "INSERT INTO RESOURCES (type, source, title, body)\
    VALUES(:type, :source, :title, :body);";
    SQLite::Statement   query(db, sql);
    query.bind(":type", type); 
    query.bind(":source", source); 
    query.bind(":title", title); 
    query.bind(":body", body); 
    try{
        query.exec();
    }
    catch (std::exception& e)
    {
        std::cout << "SQLite exception: " << e.what() << std::endl;
        std::cout << "Continuing INSERT INTO RESOURCES" << std::endl;
        cout << endl;
    }
}

void setResourcesDbFromWeb(string filename, vector<string> urls){
    for(auto url : urls){
        Input_Webpage web_crawl("C++ tutorialspoint", url);
        if(!web_crawl.requestData()){
            clog << "failed to get data from url: " << url << endl;
            cout << endl;
        }
        else{
            try{
                string body = web_crawl.getData()["body"];
                clog << "Received data from url: " << url << endl;
                setResourceDB(filename, "webpage", url, "unknown", body);
                clog << "Loaded to Database: " << url << endl;
                cout << endl;
            }
            catch (std::exception& e)
            {
                std::cout << "SQLite exception: " << e.what() << std::endl;
                exit(1);
            }
            
        }
    }
}

vector<Basic_Tokeniser> getDocObjects(Resources resources_obj){
    vector<Basic_Tokeniser> doc_objects; 
    auto texts = resources_obj.getBodies();
    for(auto text : texts){
        Basic_Tokeniser basic_doc (text);
        doc_objects.push_back(basic_doc);
    }
    return doc_objects;
}




int main(){
    try{
        vector<string> urls = {
            "https://www.theguardian.com/world/2013/dec/05/nelson-mandela-obituary",
            "https://www.un.org/en/events/mandeladay/",
            "https://www.sahistory.org.za/article/history-apartheid-south-africa",
            "https://en.wikipedia.org/wiki/Apartheid",
            "https://www.britannica.com/topic/apartheid",
            "http://www.avoiceonline.org/apartheid-edu/essay.html",
            ""


        };
        string db_filename = "test.db";
        //setResourcesDbFromWeb(db_filename, urls);
        auto resources_obj = getResourcesFromDB(db_filename, 1000);
        auto basic_tokens = getDocObjects(resources_obj);
        


        cout << "Total resources from DB: " << resources_obj.getTotal() << endl;
        cout << "Total Doc objects(basic): " << basic_tokens.size() << endl;
        cout << "Shared char objects(basic): " << Basic_Token::shared_char_objs.size() << endl;
        cout << "Shared char objects(basic): " << Basic_Tokeniser::shared_chars_objs.size() << endl;

        cout << "print shared tokens" << endl << endl;
    }

    catch (std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
        exit(1);
    }
    catch (char const* e)
    {
        std::cout << "Exception caught: " << e << std::endl;
        exit(1);
    }
    return 0;
}