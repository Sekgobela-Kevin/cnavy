#pragma once
#include "bool_characters.hpp"

/**
 * @brief uses Bool_Characters methods to return digit from 0-1 representing characters in 
 * Characters object fall fall in certain category or fit certain contion.
 * 
 */
class Ratio_Characters{
    public:
        /**
         * @brief returns number(0-1) representing ratio of true values in bool_collection argument
         * 
         * @param bool_collection collection with boolean values
         * @return float number between 0 and 1
         */
        static float getBoolRatio(bool_chars_type bool_collection);
        /**
         * @brief returns ratio(0-1) which represents ratio of ASCII characters
         * @param chars_obj object of type Characters
         * 
         * @return float number between 0 and 1
         */
        static float isASCII(Characters chars_obj);
        /**
         * @brief returns ratio(0-1) which represents ratio of alphanumeric characters
         * @param chars_obj object of type Characters
         * 
         * @return float number between 0 and 1
         */
        static float isAlnum(Characters chars_obj);
        /**
         * @brief returns ratio(0-1) which represents ratio of alphabetic characters
         * @param chars_obj object of type Characters
         * 
         * @return float number between 0 and 1
         */
        static float isAlpha(Characters chars_obj);
        /**
         * @brief returns ratio(0-1) which represents ratio of blank character characters
         * @param chars_obj object of type Characters
         * 
         * @return float number between 0 and 1
         */
        static float isBlank(Characters chars_obj);
        /**
         * @brief returns ratio(0-1) which represents ratio of control character characters
         * @param chars_obj object of type Characters
         * 
         * @return float number between 0 and 1
         */
        static float isCntrl(Characters chars_obj);
        /**
         * @brief returns ratio(0-1) which represents ratio of digit characters
         * @param chars_obj object of type Characters
         * 
         * @return float number between 0 and 1
         */
        static float isDigit(Characters chars_obj);
        /**
         * @brief returns ratio(0-1) which represents ratio of in lowercase characters
         * @param chars_obj object of type Characters
         * 
         * @return float number between 0 and 1
         */
        static float isLower(Characters chars_obj);
        /**
         * @brief returns ratio(0-1) which represents ratio of printable characters
         * @param chars_obj object of type Characters
         * 
         * @return float number between 0 and 1
         */
        static float isPrint(Characters chars_obj);
        /**
         * @brief returns ratio(0-1) which represents ratio of punctuation characters
         * @param chars_obj object of type Characters
         * 
         * @return float number between 0 and 1
         */
        static float isPunct(Characters chars_obj);
        /**
         * @brief returns ratio(0-1) which represents ratio of space character characters
         * @param chars_obj object of type Characters
         * 
         * @return float number between 0 and 1
         */
        static float isSpace(Characters chars_obj);
        /**
         * @brief returns ratio(0-1) which represents ratio of in uppercase characters
         * @param chars_obj object of type Characters
         * 
         * @return float number between 0 and 1
         */
        static float isUpper(Characters chars_obj);
        /**
         * @brief returns ratio(0-1) which represents ratio of valid hexadecimal character characters
         * @param chars_obj object of type Characters
         * 
         * @return float number between 0 and 1
         */
        static float isXdigit(Characters chars_obj);
        /**
         * @brief returns ratio(0-1) which represents ratio of graphical character characters
         * @param chars_obj object of type Characters
         * 
         * @return float number between 0 and 1
         */
        static float isGraph(Characters chars_obj);
        /**
         * @brief compares text in characters object and return corresponding ratio. If ratio is 1
         * then all characters are the same.
         * 
         * @param chars_obj object of type Characters
         * @param chars_obj2 object of type Characters
         * @param ignore_case true if caparison be case insensitive
         * @return float number between 0 and 1
         */
        static float textCompare(Characters& chars_obj, Characters& chars_obj2,
         bool ignore_case=false);
};

