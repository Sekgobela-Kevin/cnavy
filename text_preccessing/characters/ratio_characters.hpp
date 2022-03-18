#include "bool_characters.hpp"

/**
 * @brief uses Bool_Characters methods to return digit from 0-1 representing characters in 
 * Characters object fall fall in certain category or fit certain contion.
 * 
 */
class Ratio_Characters{
    public:
        /**
         * @brief returns ratio(0-1) representing true values from input
         * 
         * @param bool_collection collection with boolean values
         * @return int number between 0 and 1
         */
        static int getBoolRatio(bool_chars_type bool_collection);
        /**
         * @brief returns ratio(0-1) representing characters which are ASCII
         * @param chars_obj object of type Characters
         * 
         * @return int number between 0 and 1
         */
        static int isASCII(Characters chars_obj);
        /**
         * @brief returns ratio(0-1) representing characters which are alphanumeric
         * @param chars_obj object of type Characters
         * 
         * @return int number between 0 and 1
         */
        static int isAlnum(Characters chars_obj);
        /**
         * @brief returns ratio(0-1) representing characters which are alphabetic
         * @param chars_obj object of type Characters
         * 
         * @return int number between 0 and 1
         */
        static int isAlpha(Characters chars_obj);
        /**
         * @brief returns ratio(0-1) representing characters which are blank character
         * @param chars_obj object of type Characters
         * 
         * @return int number between 0 and 1
         */
        static int isBlank(Characters chars_obj);
        /**
         * @brief returns ratio(0-1) representing characters which are control character
         * @param chars_obj object of type Characters
         * 
         * @return int number between 0 and 1
         */
        static int isCntrl(Characters chars_obj);
        /**
         * @brief returns ratio(0-1) representing characters which are digit
         * @param chars_obj object of type Characters
         * 
         * @return int number between 0 and 1
         */
        static int isDigit(Characters chars_obj);
        /**
         * @brief returns ratio(0-1) representing characters which are in lowercase
         * @param chars_obj object of type Characters
         * 
         * @return int number between 0 and 1
         */
        static int isLower(Characters chars_obj);
        /**
         * @brief returns ratio(0-1) representing characters which are printable
         * @param chars_obj object of type Characters
         * 
         * @return int number between 0 and 1
         */
        static int isPrint(Characters chars_obj);
        /**
         * @brief returns ratio(0-1) representing characters which are punctuation
         * @param chars_obj object of type Characters
         * 
         * @return int number between 0 and 1
         */
        static int isPunct(Characters chars_obj);
        /**
         * @brief returns ratio(0-1) representing characters which are space character
         * @param chars_obj object of type Characters
         * 
         * @return int number between 0 and 1
         */
        static int isSpace(Characters chars_obj);
        /**
         * @brief returns ratio(0-1) representing characters which are in uppercase
         * @param chars_obj object of type Characters
         * 
         * @return int number between 0 and 1
         */
        static int isUpper(Characters chars_obj);
        /**
         * @brief returns ratio(0-1) representing characters which are valid hexadecimal character
         * @param chars_obj object of type Characters
         * 
         * @return int number between 0 and 1
         */
        static int isXdigit(Characters chars_obj);
        /**
         * @brief returns ratio(0-1) representing characters which are graphical character
         * @param chars_obj object of type Characters
         * 
         * @return int number between 0 and 1
         */
        static int isGraph(Characters chars_obj);
};

