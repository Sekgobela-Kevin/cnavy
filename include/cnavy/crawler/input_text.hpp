#pragma once
#include "input.hpp"
#include <iostream>

/*
Class for handling text entered manually or copied from clipboard. The class accepts data from keyboard
with source member variable not used. Class does not change anythong of Input class but implement methods
that are Pure virtual to allow instaces creation.

* @param title
* @param source
* @param body 
*/
class Input_Text : public Input{
    public:
        /**
         * @brief Construct a new Input_Text which also accepts body in the constructor. 
         * As the body is already available when creating the object just as type and title.
         * 
         * @param title
         * @param source
         * @param body
         */
        Input_Text(string title, string source, string body);

        /**
         * @brief since source is unused it always return true(see Input class for details)
         * @param source
         * @return true
         */
        bool isSourceActive(string source);
        /**
         * @brief since source is unused it always return true(see Input class for details)
         * @param source
         * @return true
         */
        bool isSourceValid(string source);
        /**
         * @brief just return the data passed as parameter(see Input class for details)
         * 
         * @param data 
         * @return string 
         */
        string dataToText(string data);
        /**
         * @brief emulates fetching of data by returning content(body) passed to constructor.
         * Navigate to Input class for more details about this->fetchData()
         * @param path
         * @return string 
         */
        string fetchData(string path);
};
