#pragma once
#include "ratio_characters.hpp"

/**
 * @brief Most common Character which is simiar to Spacy tokens and programming strings.
 * They use stored characters to determine if characters as whole are didgits, alpha
 * or other types.
 * Think of them as summary of all characters.
 * They contain almost all methods character but themselfs are based on all characters.
 * If characters contains digits and alphabets then the characters are considered
 * Alphanumeric.
 */
class Summary_Characters{
    public:
        /**
         * @brief returns booleans representing if each character is ASCII
         * @param chars_obj object of type Characters
         * 
         * @return bool number between 0 and 1
         */
        static bool isASCII(Characters chars_obj);
        /**
         * @brief returns booleans representing if each character is alphanumeric
         * @param chars_obj object of type Characters
         * 
         * @return bool number between 0 and 1
         */
        static bool isAlnum(Characters chars_obj);
        /**
         * @brief returns booleans representing if each character is alphabetic
         * @param chars_obj object of type Characters
         * 
         * @return bool number between 0 and 1
         */
        static bool isAlpha(Characters chars_obj);
        /**
         * @brief returns booleans representing if each character is blank character
         * @param chars_obj object of type Characters
         * 
         * @return bool number between 0 and 1
         */
        static bool isBlank(Characters chars_obj);
        /**
         * @brief returns booleans representing if each character is control character
         * @param chars_obj object of type Characters
         * 
         * @return bool number between 0 and 1
         */
        static bool isCntrl(Characters chars_obj);
        /**
         * @brief returns booleans representing if each character is digit
         * @param chars_obj object of type Characters
         * 
         * @return bool number between 0 and 1
         */
        static bool isDigit(Characters chars_obj);
        /**
         * @brief returns booleans representing if each character is in lowercase
         * @param chars_obj object of type Characters
         * 
         * @return bool number between 0 and 1
         */
        static bool isLower(Characters chars_obj);
        /**
         * @brief returns booleans representing if each character is printable
         * @param chars_obj object of type Characters
         * 
         * @return bool number between 0 and 1
         */
        static bool isPrint(Characters chars_obj);
        /**
         * @brief returns booleans representing if each character is punctuation
         * @param chars_obj object of type Characters
         * 
         * @return bool number between 0 and 1
         */
        static bool isPunct(Characters chars_obj);
        /**
         * @brief returns booleans representing if each character is space character
         * @param chars_obj object of type Characters
         * 
         * @return bool number between 0 and 1
         */
        static bool isSpace(Characters chars_obj);
        /**
         * @brief returns booleans representing if each character is in uppercase
         * @param chars_obj object of type Characters
         * 
         * @return bool number between 0 and 1
         */
        static bool isUpper(Characters chars_obj);
        /**
         * @brief returns booleans representing if each character is valid hexadecimal character
         * @param chars_obj object of type Characters
         * 
         * @return bool number between 0 and 1
         */
        static bool isXdigit(Characters chars_obj);
        /**
         * @brief returns booleans representing if each character is graphical character
         * @param chars_obj object of type Characters
         * 
         * @return bool number between 0 and 1
         */
        static bool isGraph(Characters chars_obj);
};