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
         * @return int number between 0 and 1
         */
        static int getBoolRatio(bool_chars_type bool_collection);
        /**
         * @brief returns ratio(0-1) which represents ratio of ASCII characters
         * @param chars_obj object of type Characters
         * 
         * @return int number between 0 and 1
         */
        static int isASCII(Characters chars_obj);
        /**
         * @brief returns ratio(0-1) which represents ratio of alphanumeric characters
         * @param chars_obj object of type Characters
         * 
         * @return int number between 0 and 1
         */
        static int isAlnum(Characters chars_obj);
        /**
         * @brief returns ratio(0-1) which represents ratio of alphabetic characters
         * @param chars_obj object of type Characters
         * 
         * @return int number between 0 and 1
         */
        static int isAlpha(Characters chars_obj);
        /**
         * @brief returns ratio(0-1) which represents ratio of blank character characters
         * @param chars_obj object of type Characters
         * 
         * @return int number between 0 and 1
         */
        static int isBlank(Characters chars_obj);
        /**
         * @brief returns ratio(0-1) which represents ratio of control character characters
         * @param chars_obj object of type Characters
         * 
         * @return int number between 0 and 1
         */
        static int isCntrl(Characters chars_obj);
        /**
         * @brief returns ratio(0-1) which represents ratio of digit characters
         * @param chars_obj object of type Characters
         * 
         * @return int number between 0 and 1
         */
        static int isDigit(Characters chars_obj);
        /**
         * @brief returns ratio(0-1) which represents ratio of in lowercase characters
         * @param chars_obj object of type Characters
         * 
         * @return int number between 0 and 1
         */
        static int isLower(Characters chars_obj);
        /**
         * @brief returns ratio(0-1) which represents ratio of printable characters
         * @param chars_obj object of type Characters
         * 
         * @return int number between 0 and 1
         */
        static int isPrint(Characters chars_obj);
        /**
         * @brief returns ratio(0-1) which represents ratio of punctuation characters
         * @param chars_obj object of type Characters
         * 
         * @return int number between 0 and 1
         */
        static int isPunct(Characters chars_obj);
        /**
         * @brief returns ratio(0-1) which represents ratio of space character characters
         * @param chars_obj object of type Characters
         * 
         * @return int number between 0 and 1
         */
        static int isSpace(Characters chars_obj);
        /**
         * @brief returns ratio(0-1) which represents ratio of in uppercase characters
         * @param chars_obj object of type Characters
         * 
         * @return int number between 0 and 1
         */
        static int isUpper(Characters chars_obj);
        /**
         * @brief returns ratio(0-1) which represents ratio of valid hexadecimal character characters
         * @param chars_obj object of type Characters
         * 
         * @return int number between 0 and 1
         */
        static int isXdigit(Characters chars_obj);
        /**
         * @brief returns ratio(0-1) which represents ratio of graphical character characters
         * @param chars_obj object of type Characters
         * 
         * @return int number between 0 and 1
         */
        static int isGraph(Characters chars_obj);
};

