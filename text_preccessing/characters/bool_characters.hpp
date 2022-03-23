#pragma once
#include <vector>
#include <functional>
#include <unordered_map>
#include <string>

#include "characters.hpp"
#include "bool_set.hpp"

/**
 * @brief This are Characters with methods that return collection with booleans.
 * The booleans represent characteristic of each character.
 * [true, false, true] for digit would mean that first character and last character
 * of string are digits with middle not being digits.
 * 
 */
class Bool_Characters{
    public:
        /**
         * @brief map containing text with corresponding method.
         * e.g {{"is_alpha", is_alpha()}}
         * 
         */
        static std::unordered_map<std::string, std::function<bool_chars_type(Characters)>> text_method_map;
        /**
         * @brief calls method in Characters object that matches string
         * 
         * @param chars_obj string representing method
         * @param attr string representing method in this Class
         * @return bool_chars_type 
         */
        static bool_chars_type callMethod(const Characters& chars_obj, std::string& attr);
        
        /**
         * @brief for each element in char_objs executes func(function) and return its values
         * in a collection
         * 
         * @param char_objs collection of elements
         * @param func function to be called on each element
         * @return bool_chars_type Collection of booalean values
         */
        static bool_chars_type for_each_elem(characters_objs_type char_objs, std::function<bool(character_type)> func);
        /**
         * @brief returns booleans representing if each character is ASCII
         * @param chars_obj object of type Characters
         * 
         * @return bool_chars_type sequence of booleans.
         */
        static bool_chars_type isASCII(Characters chars_obj);
        /**
         * @brief returns booleans representing if each character is alphanumeric
         * @param chars_obj object of type Characters
         * 
         * @return bool_chars_type sequence of booleans.
         */
        static bool_chars_type isAlnum(Characters chars_obj);
        /**
         * @brief returns booleans representing if each character is alphabetic
         * @param chars_obj object of type Characters
         * 
         * @return bool_chars_type sequence of booleans.
         */
        static bool_chars_type isAlpha(Characters chars_obj);
        /**
         * @brief returns booleans representing if each character is blank character
         * @param chars_obj object of type Characters
         * 
         * @return bool_chars_type sequence of booleans.
         */
        static bool_chars_type isBlank(Characters chars_obj);
        /**
         * @brief returns booleans representing if each character is control character
         * @param chars_obj object of type Characters
         * 
         * @return bool_chars_type sequence of booleans.
         */
        static bool_chars_type isCntrl(Characters chars_obj);
        /**
         * @brief returns booleans representing if each character is digit
         * @param chars_obj object of type Characters
         * 
         * @return bool_chars_type sequence of booleans.
         */
        static bool_chars_type isDigit(Characters chars_obj);
        /**
         * @brief returns booleans representing if each character is in lowercase
         * @param chars_obj object of type Characters
         * 
         * @return bool_chars_type sequence of booleans.
         */
        static bool_chars_type isLower(Characters chars_obj);
        /**
         * @brief returns booleans representing if each character is printable
         * @param chars_obj object of type Characters
         * 
         * @return bool_chars_type sequence of booleans.
         */
        static bool_chars_type isPrint(Characters chars_obj);
        /**
         * @brief returns booleans representing if each character is punctuation
         * @param chars_obj object of type Characters
         * 
         * @return bool_chars_type sequence of booleans.
         */
        static bool_chars_type isPunct(Characters chars_obj);
        /**
         * @brief returns booleans representing if each character is space character
         * @param chars_obj object of type Characters
         * 
         * @return bool_chars_type sequence of booleans.
         */
        static bool_chars_type isSpace(Characters chars_obj);
        /**
         * @brief returns booleans representing if each character is in uppercase
         * @param chars_obj object of type Characters
         * 
         * @return bool_chars_type sequence of booleans.
         */
        static bool_chars_type isUpper(Characters chars_obj);
        /**
         * @brief returns booleans representing if each character is valid hexadecimal character
         * @param chars_obj object of type Characters
         * 
         * @return bool_chars_type sequence of booleans.
         */
        static bool_chars_type isXdigit(Characters chars_obj);
        /**
         * @brief returns booleans representing if each character is graphical character
         * @param chars_obj object of type Characters
         * 
         * @return bool_chars_type sequence of booleans.
         */
        static bool_chars_type isGraph(Characters chars_obj);

        static bool_chars_type textCompare(Characters& chars_obj, Characters& chars_obj2,
         bool ignore_case=false);
};

