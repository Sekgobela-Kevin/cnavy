#include <functional>
#include <deque>
#include <string>
#include "functional"
#include "characters.hpp"


typedef std::deque<bool> bool_chars_type;

/**
 * @brief This are Characters with methods that return collection with booleans.
 * The booleans represent characteristic of each character.
 * [true, false, true] for digit would mean that first character and last character
 * of string are digits with middle not being digits.
 * 
 */
class Bool_Characters : public Characters{
    public:
        using Characters::Characters;
        /**
         * @brief for each element in char_objs executes func(function) and return its values
         * in a collection
         * 
         * @param char_objs collection of elements
         * @param func function to be called on each element
         * @return bool_chars_type Collection of booalean values
         */
        bool_chars_type for_each_elem(characters_objs_type char_objs, std::function<bool(character_type)> func);
        /**
         * @brief returns booleans representing if each character is ASCII
         * 
         * @return bool_chars_type sequence of booleans.
         */
        bool_chars_type boolIsASCII();
        /**
         * @brief returns booleans representing if each character is alphanumeric
         * 
         * @return bool_chars_type sequence of booleans.
         */
        bool_chars_type boolIsAlnum();
        /**
         * @brief returns booleans representing if each character is alphabetic
         * 
         * @return bool_chars_type sequence of booleans.
         */
        bool_chars_type boolIsAlpha();
        /**
         * @brief returns booleans representing if each character is blank character
         * 
         * @return bool_chars_type sequence of booleans.
         */
        bool_chars_type boolIsBlank();
        /**
         * @brief returns booleans representing if each character is control character
         * 
         * @return bool_chars_type sequence of booleans.
         */
        bool_chars_type boolIsCntrl();
        /**
         * @brief returns booleans representing if each character is digit
         * 
         * @return bool_chars_type sequence of booleans.
         */
        bool_chars_type boolIsDigit();
        /**
         * @brief returns booleans representing if each character is in lowercase
         * 
         * @return bool_chars_type sequence of booleans.
         */
        bool_chars_type boolIsLower();
        /**
         * @brief returns booleans representing if each character is printable
         * 
         * @return bool_chars_type sequence of booleans.
         */
        bool_chars_type boolIsPrint();
        /**
         * @brief returns booleans representing if each character is punctuation
         * 
         * @return bool_chars_type sequence of booleans.
         */
        bool_chars_type boolIsPunct();
        /**
         * @brief returns booleans representing if each character is space character
         * 
         * @return bool_chars_type sequence of booleans.
         */
        bool_chars_type boolIsSpace();
        /**
         * @brief returns booleans representing if each character is in uppercase
         * 
         * @return bool_chars_type sequence of booleans.
         */
        bool_chars_type boolIsUpper();
        /**
         * @brief returns booleans representing if each character is valid hexadecimal character
         * 
         * @return bool_chars_type sequence of booleans.
         */
        bool_chars_type boolIsXdigit();
        /**
         * @brief returns booleans representing if each character is graphical character
         * 
         * @return bool_chars_type sequence of booleans.
         */
        bool_chars_type boolIsGraph();
};

