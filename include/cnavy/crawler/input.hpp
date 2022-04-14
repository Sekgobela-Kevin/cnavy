#pragma once
#include <list>
#include <unordered_map>
#include <string>
using namespace std;

class Input{
    protected:
        /**
         * @brief title of input
         */
        string title;
        /**
         * @brief type of input, identifies kind of source e.g webpage, file
         */
        string type;
        /**
         * @brief string representing resource locator e.g url or file path
         */
        string source;
        /**
         * @brief text data from source(webpage,file)
         */
        string body;
        /**
         * @brief map for exporting object data to outside
         * 
         */
        unordered_map<string, string> outData;

    public:
        /**
         * @brief Construct a new Input object
         * 
         * @param title title input used for creating resource
         * @param type identifies the type of resource usually incluenced by its source e.g webpage 
         * == url
         * @param source string representing path, url or thing that can be used to locate data
         */
        Input(string title, string type, string source);
        /**
         * @brief initialises object(called by contructor)
         * 
         * @param title 
         * @param type 
         * @param source 
         */
        virtual void Initial(string title, string type, string source);
        /**
         * @brief checks if data is loaded from its source
         * 
         * @return true 
         * @return false 
         */
        bool isLoaded();
        /**
         * @brief Get the Data in map form with neccessary data
         * 
         * @return unordered_map<string, string>
         */
        unordered_map<string, string> getData();
        /**
         * @brief extract raw data from its souurce 
         * @param source
         * @return string bodyText in its raw form e.g HTML
         */
        virtual string fetchData(string source) = 0;
        /**
         * @brief converts data(binary, html, etc) into plain clean natuaral language text
         * 
         * @param data data from the source
         * @return string 
         */
        virtual string dataToText(string data) = 0;
        /**
         * @brief checks if the source is valid based on its structure
         * 
         * @param source 
         * @return string 
         */
        virtual bool isSourceValid(string source) = 0;
        /**
         * @brief checks if source is active meaning data can be accessed on demand(not guaranteed)
         * 
         * @param source 
         * @return string 
         */
        virtual bool isSourceActive(string source) = 0;
        /**
         * @brief request data from source and performs conversions and update object state
         * @param force true if data be requested even if exists(old one get replaced)
         * @return true on success
         * @return false
         */
        virtual bool requestData(bool force=false);
        /**
         * @brief sync or initialises outData member variable with other member variables of class
         * 
         */
        void syncData();
        /**
         * @brief Set the Content(body) and perform a sync with outData using this->syncData()
         * 
         * @param text 
         */
        void setContentData(string text);

};