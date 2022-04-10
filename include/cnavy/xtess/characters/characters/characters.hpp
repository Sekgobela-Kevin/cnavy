#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "character.hpp"

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
class Characters{
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
         * @brief Construct a new Characters object
         * 
         */
        Characters();
        
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

        // string like methods
        /**
         * @brief returns size of object
         * 
         * @return size_t
         */
        size_t size() const;
        /**
         * @brief returns length of object(same as size())
         * 
         * @return size_t
         */
        size_t length() const;



        // iterator methods
        /* https://stackoverflow.com/questions/8164567/
        how-to-make-my-custom-type-to-work-with-range-based-for-loops
        */
        characters_objs_type::iterator begin();
        characters_objs_type::iterator end();
        characters_objs_type::const_iterator cbegin() const;
        characters_objs_type::const_iterator cend() const;
        characters_objs_type::const_iterator begin() const;
        characters_objs_type::const_iterator end() const;

        // operator overiding
        Character& operator[](size_t index);
        Characters operator+(Characters& other);
        bool operator==(std::string other);
        bool operator==(const char* other);
        bool operator==(Characters& other);
        friend std::ostream& operator<<(std::ostream& out_stream, Characters& chars_obj);
};
