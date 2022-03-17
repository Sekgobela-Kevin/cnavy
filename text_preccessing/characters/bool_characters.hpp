#include <functional>
#include <vector>
#include <string>
#include "functional"
#include "characters.hpp"


typedef std::vector<bool> bool_chars_type;

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
        static bool_chars_type boolIsASCII(Characters chars_obj);
        /**
         * @brief returns booleans representing if each character is alphanumeric
         * @param chars_obj object of type Characters
         * 
         * @return bool_chars_type sequence of booleans.
         */
        static bool_chars_type boolIsAlnum(Characters chars_obj);
        /**
         * @brief returns booleans representing if each character is alphabetic
         * @param chars_obj object of type Characters
         * 
         * @return bool_chars_type sequence of booleans.
         */
        static bool_chars_type boolIsAlpha(Characters chars_obj);
        /**
         * @brief returns booleans representing if each character is blank character
         * @param chars_obj object of type Characters
         * 
         * @return bool_chars_type sequence of booleans.
         */
        static bool_chars_type boolIsBlank(Characters chars_obj);
        /**
         * @brief returns booleans representing if each character is control character
         * @param chars_obj object of type Characters
         * 
         * @return bool_chars_type sequence of booleans.
         */
        static bool_chars_type boolIsCntrl(Characters chars_obj);
        /**
         * @brief returns booleans representing if each character is digit
         * @param chars_obj object of type Characters
         * 
         * @return bool_chars_type sequence of booleans.
         */
        static bool_chars_type boolIsDigit(Characters chars_obj);
        /**
         * @brief returns booleans representing if each character is in lowercase
         * @param chars_obj object of type Characters
         * 
         * @return bool_chars_type sequence of booleans.
         */
        static bool_chars_type boolIsLower(Characters chars_obj);
        /**
         * @brief returns booleans representing if each character is printable
         * @param chars_obj object of type Characters
         * 
         * @return bool_chars_type sequence of booleans.
         */
        static bool_chars_type boolIsPrint(Characters chars_obj);
        /**
         * @brief returns booleans representing if each character is punctuation
         * @param chars_obj object of type Characters
         * 
         * @return bool_chars_type sequence of booleans.
         */
        static bool_chars_type boolIsPunct(Characters chars_obj);
        /**
         * @brief returns booleans representing if each character is space character
         * @param chars_obj object of type Characters
         * 
         * @return bool_chars_type sequence of booleans.
         */
        static bool_chars_type boolIsSpace(Characters chars_obj);
        /**
         * @brief returns booleans representing if each character is in uppercase
         * @param chars_obj object of type Characters
         * 
         * @return bool_chars_type sequence of booleans.
         */
        static bool_chars_type boolIsUpper(Characters chars_obj);
        /**
         * @brief returns booleans representing if each character is valid hexadecimal character
         * @param chars_obj object of type Characters
         * 
         * @return bool_chars_type sequence of booleans.
         */
        static bool_chars_type boolIsXdigit(Characters chars_obj);
        /**
         * @brief returns booleans representing if each character is graphical character
         * @param chars_obj object of type Characters
         * 
         * @return bool_chars_type sequence of booleans.
         */
        static bool_chars_type boolIsGraph(Characters chars_obj);
};

