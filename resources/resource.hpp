#include <utility>
#include <iostream>
#include <string>
#include <assert.h>
#include <unordered_map>
using namespace std;


class Resource{

        /**
         * @brief represent full text of resource
         * 
         */
        string bodyText;
        /**
         * @brief heading or title of resource
         * Its usually extracted from the resource text and is substring of bodytext
         * 
         */
        string title;
        /**
         * @brief identifies the medium in which the resource was extracted from.
         * It could be file, webpage, ect
         * 
         */
        string type;

        /**
         * @brief defines range for body text
         */
        pair <int,int> bodyRange;
        /**
         * @brief defines range for title
         */
        pair <int,int> titleRange;
        /**
         * @brief defines range for type text
         */
        pair <int,int> typeRange;

    public:
        /**
         * @brief Construct a new Resource object
         * 
         * @param bodyText 
         * @param title 
         * @param type 
         */
        Resource(string bodyText, string title, string type);
        
        /**
         * @brief Set the Body member variable
         * 
         * @param text 
         */
        void setBody(string text);

        /**
         * @brief Set the Title member variable
         * 
         * @param text 
         */
        void setTitle(string text);

        /**
         * @brief Set the Type member variable
         * 
         * @param text 
         */
        void setType(string text);

        /**
         * @brief Get the body(full text) of resource including title
         * 
         * @return string 
         */
        string getBody();

        /**
         * @brief Get the Title of resource
         * 
         * @return string 
         */
        string getTitle();

        /**
         * @brief Get the type of resource which can be webpage, file, etc
         * 
         * @return string 
         */
        string getType();

        /**
         * @brief checks if title is a substring of body
         * 
         * @return true if title is substring of body
         * @return false if title is not substring of body
         */
        bool titleBodyMatch();


        /**
         * @brief returns true if text has minimum length  of pair.second or more
         * 
         * @param pair 
         * @param text 
         * @return true 
         * @return false 
         */
        bool minRangeValid(pair <int,int> range, string text);

        /**
         * @brief returns true if text has minimum length of pair.second or less
         * 
         * @param pair 
         * @param text 
         * @return true 
         * @return false 
         */
        bool maxRangeValid(pair <int,int> range, string text);

        /**
         * @brief true if text length is in range
         * 
         * @param pair 
         * @param text 
         * @return true 
         * @return false 
         */
        bool rangeValid(pair <int,int> range, string text);
        /**
         * @brief export essential resources data into a map(title, type and body)
         * 
         * @return unordered_map<string, string> 
         */
        unordered_map<string, string> exportData();
};


/**
 * @brief Performs Unit Testing for Resources Class using assert statements.
 * 
 * @param body 
 * @param title 
 * @param type 
 */
void Resource_Test(string body, string title, string type);