#pragma once
#include "string"
#include <vector>
#include "..\character\character.hpp"

/**
 * @brief type that stores sequence of Characters of objects
 * 
 */
typedef Character character_type;
typedef std::vector<character_type> characters_objs_type;

/**
 * @brief Base class for characters. \n
 * Characters is just collection of Character objects in sequence
 * managed by single object.
 * This Class provide base methods shared by all Characters Classes.
 * 
 */
class Characters : public std::string{
    protected:
        //**
        characters_objs_type characters_objs;
        std::string input_string;

    public:
        /**
         * @brief Construct a new Characters object
         * 
         * @param input_text string to be represented
         */
        Characters(std::string input_text);
        
        /**
         * @brief update data about object with new calculated data from input_text.
         * Intended for testing purposes, never use in production.
         * 
         * @param input_text 
         */
        void update(std::string input_text);

        /**
         * @brief returns string version of the object
         * 
         * @return std::string 
         */
        std::string getText();
        /**
         * @brief returns underlying Characters objects in collection
         * 
         * @return characters_objs_type collcetion of character objects
         */
        characters_objs_type getCharsObjs();
        /**
         * @brief convert characters to lowercase
         * 
         * @return std::string 
         */
        std::string toLower();
        /**
         * @brief convert characters to lowercase(modifies object)
         * 
         * @return std::string 
         */
        std::string toUpper();

        /**
         * @brief convert characters to lowercase(modifies object)
         * 
         * @return std::string 
         */
        std::string getLower();
        /**
         * @brief convert characters to lowercase
         * 
         * @return std::string 
         */
        std::string getUpper();

        
};
