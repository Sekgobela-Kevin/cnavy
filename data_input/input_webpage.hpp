#include "input.hpp"
#include <iostream>

/*
Class for handling handling input from world wide web specifically webpages text data.

* @param title title of the webpage
* @param source url pointing to the webpage in world wide web
*/
class Input_Webpage : public Input{
    public:
        /**
         * @brief Construct a new Input_Webpage object
         * 
         * @param title
         * @param source
         * @param body
         */
        Input_Webpage(string title, string source);

        /**
         * @brief checks if url(source) of webpage is still active
         * 
         * @param url url to fetch webpage data
         * @return true
         */
        bool isSourceActive(string url);
        /**
         * @brief checks if url(source) of webpage is valid based on its structure
         * @param url url to fetch webpage data
         * @return true
         */
        bool isSourceValid(string url);
        /**
         * @brief receives html data and parses it to get only text data without HTML tags
         * 
         * @param data 
         * @return string 
         */
        string dataToText(string data);
        /**
         * @brief fetches data from url(source) and then return it.
         * Navigate to Input class for more details about this->fetchData()
         * @param url url to fetch webpage data
         * @return string 
         */
        string fetchData(string url);
        /**
         * @brief retrieves body part of HTML(including body tags)
         * 
         * @param html 
         * @return string 
         */
        string getHtmlBody(string html);
        /**
         * @brief removes all tags leaving only their contents
         * 
         * @param html 
         * @return string 
         */
        string removeTags(string html);
        /**
         * @brief retrieves contents of <body> and remove all tags including contents of <script>
         * 
         * @param htmlBody 
         * @return string 
         */
        string parseHtmlBody(string html);
        /**
         * @brief removes HTML tag and its contents
         * 
         * @param html 
         * @param tag 
         * @return string 
         */
        string removeHtmlTag(string html, string tag);
        /**
         * @brief checks if text is a valid html with tags
         * 
         * @param text 
         * @return string 
         */
        bool isHtml(string text);
        /**
         * @brief extracts HTML tag along with its contents
         * 
         * @param html 
         * @return string 
         */
        string getHtmlTag(string html, string tag);
        /**
         * @brief runs a system command and return results
         * 
         * @param cmd 
         * @return string 
         */
        string runCommand(string cmd);
        /**
         * @brief checks if command processor is available
         * 
         * @return true 
         * @return false 
         */
        bool processorAvail();
        /**
         * @brief checks if computer is connected to internet
         * 
         * @return true 
         * @return false 
         */
        bool isWebConneted();
        /**
         * @brief attempts to remove js code from HTML. No solution so far but
         * it removes any text between curly brackets({}) which may remove lot of js code.
         * 
         * @param html 
         * @return string 
         */
        string removeJsCode(string html);

};
