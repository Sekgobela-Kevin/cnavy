#pragma once
#include "../character/character.hpp"
#include "../characters/characters.hpp"

#include <unordered_map>
#include <string>


typedef std::unordered_multimap<char_type, Character> characters_set_map;

/**
 * @brief stores and manages character objects to be shared on tokens and documents
 * 
 */

class Shared_Characters{
    public:
        /**
         * @brief key value map with key being character and value being Character object
         * 
         */
        characters_set_map characters_map;

    public:
        /**
         * @brief Construct a new Characters_Set object
         * 
         */
        Shared_Characters();
        /**
         * @brief Construct a new Characters_Set object from string
         * 
         * @param input_string 
         */
        Shared_Characters(std::string input_string);
        /**
         * @brief Construct a new Characters_Set object from Characters obj
         * 
         * @param chars_obj 
         */
        Shared_Characters(Characters chars_obj);
        /**
         * @brief insert new shared Character object,
         * only added if not already added.
         * 
         * @param char_obj Character object
         */
        void add(Character char_obj);
        /**
         * @brief insert new shared Character object,
         * only added if not already added.
         * 
         * @param char_ character to be added
         */
        void add(char_type char_);
        /**
         * @brief insert new shared Character object,
         * only added if not already added.
         * 
         * @param input_string string to add Character objects from.
         */
        void add(std::string input_string);
        /**
         * @brief insert new shared Character object,
         * only added if not already added.
         * 
         * @param chars_obj Characters object
         */
        void add(Characters chars_obj);
        /**
         * @brief remove Character objects matching string input_string
         * @param input_string string object
         */
        void remove(std::string input_string);
        /**
         * @brief remove Character object matching character
         * 
         * @param char_ character to remove object it matches
         */
        void remove(char_type char_);
        /**
         * @brief clears all Character objects
         * 
         */
        void clear();
        /**
         * @brief returns Character object associated with character
         * 
         * @param char_ character
         * @return true 
         * @return false 
         */
        bool exists(char_type char_);
        /**
         * @brief test if object is empty
         * 
         * @return true 
         * @return false 
         */
        bool empty();
        /**
         * @brief return size of object
         * 
         * @return size_t 
         */
        size_t size();

        /**
         * @brief remove duplicates from string
         * 
         */
        std::string unique(std::string input_string);
};