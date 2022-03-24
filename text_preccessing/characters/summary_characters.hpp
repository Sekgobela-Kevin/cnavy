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
         * @brief compares 2 true ratios based on requirments of this class(internal use only)
         * 
         * @param true_ratio value between 0 and 1
         * @param result_ratio value between 0 and 1
         * @return true 
         * @return false 
         */
        static bool ratioCompare(float true_ratio1, float result_ratio);
        /**
         * @brief returns boolean representing if each character is ASCII.
         * The output depends on truth_ratio(default = 1) which means each character should
         * pass for true to be returned.
         * @param chars_obj object of type Characters
         * @param true_ratio number between 0 and 1 in which defines ratio characters that needs 
         * to be true for this  method return true. 
         * If its 1 then all charactres needs to be true for this method for this method return true.
         * 
         * @return bool
         */
        static bool isASCII(Characters chars_obj, float true_ratio=1);
        /**
         * @brief returns booleans representing if each character is alphanumeric.
         * The output depends on truth_ratio(default = 1) which means each character should
         * pass for true to be returned.
         * @param chars_obj object of type Characters
         * @param true_ratio number between 0 and 1 in which defines ratio characters that needs 
         * to be true for this  method return true. 
         * If its 1 then all charactres needs to be true for this method for this method return true.
         * 
         * @return bool
         */
        static bool isAlnum(Characters chars_obj, float true_ratio=1);
        /**
         * @brief returns booleans representing if each character is alphabetic.
         * The output depends on truth_ratio(default = 1) which means each character should
         * pass for true to be returned.
         * @param chars_obj object of type Characters
         * @param true_ratio number between 0 and 1 in which defines ratio characters that needs 
         * to be true for this  method return true. 
         * If its 1 then all charactres needs to be true for this method for this method return true.
         * 
         * @return bool
         */
        static bool isAlpha(Characters chars_obj, float true_ratio=1);
        /**
         * @brief returns booleans representing if each character is blank character.
         * The output depends on truth_ratio(default = 1) which means each character should
         * pass for true to be returned.
         * @param chars_obj object of type Characters
         * @param true_ratio number between 0 and 1 in which defines ratio characters that needs 
         * to be true for this  method return true. 
         * If its 1 then all charactres needs to be true for this method for this method return true.
         * 
         * @return bool
         */
        static bool isBlank(Characters chars_obj, float true_ratio=1);
        /**
         * @brief returns booleans representing if each character is control character.
         * The output depends on truth_ratio(default = 1) which means each character should
         * pass for true to be returned.
         * @param chars_obj object of type Characters
         * @param true_ratio number between 0 and 1 in which defines ratio characters that needs 
         * to be true for this  method return true. 
         * If its 1 then all charactres needs to be true for this method for this method return true.
         * 
         * @return bool
         */
        static bool isCntrl(Characters chars_obj, float true_ratio=1);
        /**
         * @brief returns booleans representing if each character is digit.
         * The output depends on truth_ratio(default = 1) which means each character should
         * pass for true to be returned.
         * @param chars_obj object of type Characters
         * @param true_ratio number between 0 and 1 in which defines ratio characters that needs 
         * to be true for this  method return true. 
         * If its 1 then all charactres needs to be true for this method for this method return true.
         * 
         * @return bool
         */
        static bool isDigit(Characters chars_obj, float true_ratio=1);
        /**
         * @brief returns booleans representing if each character is in lowercase.
         * The output depends on truth_ratio(default = 1) which means each character should
         * pass for true to be returned.
         * @param chars_obj object of type Characters
         * @param true_ratio number between 0 and 1 in which defines ratio characters that needs 
         * to be true for this  method return true. 
         * If its 1 then all charactres needs to be true for this method for this method return true.
         * 
         * @return bool
         */
        static bool isLower(Characters chars_obj, float true_ratio=1);
        /**
         * @brief returns booleans representing if each character is printable.
         * The output depends on truth_ratio(default = 1) which means each character should
         * pass for true to be returned.
         * @param chars_obj object of type Characters
         * @param true_ratio number between 0 and 1 in which defines ratio characters that needs 
         * to be true for this  method return true. 
         * If its 1 then all charactres needs to be true for this method for this method return true.
         * 
         * @return bool
         */
        static bool isPrint(Characters chars_obj, float true_ratio=1);
        /**
         * @brief returns booleans representing if each character is punctuation.
         * The output depends on truth_ratio(default = 1) which means each character should
         * pass for true to be returned.
         * @param chars_obj object of type Characters
         * @param true_ratio number between 0 and 1 in which defines ratio characters that needs 
         * to be true for this  method return true. 
         * If its 1 then all charactres needs to be true for this method for this method return true.
         * 
         * @return bool
         */
        static bool isPunct(Characters chars_obj, float true_ratio=1);
        /**
         * @brief returns booleans representing if each character is space character.
         * The output depends on truth_ratio(default = 1) which means each character should
         * pass for true to be returned.
         * @param chars_obj object of type Characters
         * @param true_ratio number between 0 and 1 in which defines ratio characters that needs 
         * to be true for this  method return true. 
         * If its 1 then all charactres needs to be true for this method for this method return true.
         * 
         * @return bool
         */
        static bool isSpace(Characters chars_obj, float true_ratio=1);
        /**
         * @brief returns booleans representing if each character is in uppercase.
         * The output depends on truth_ratio(default = 1) which means each character should
         * pass for true to be returned.
         * @param chars_obj object of type Characters
         * @param true_ratio number between 0 and 1 in which defines ratio characters that needs 
         * to be true for this  method return true. 
         * If its 1 then all charactres needs to be true for this method for this method return true.
         * 
         * @return bool
         */
        static bool isUpper(Characters chars_obj, float true_ratio=1);
        /**
         * @brief returns booleans representing if each character is valid hexadecimal character.
         * The output depends on truth_ratio(default = 1) which means each character should
         * pass for true to be returned.
         * @param chars_obj object of type Characters
         * @param true_ratio number between 0 and 1 in which defines ratio characters that needs 
         * to be true for this  method return true. 
         * If its 1 then all charactres needs to be true for this method for this method return true.
         * 
         * @return bool
         */
        static bool isXdigit(Characters chars_obj, float true_rati=1);
        /**
         * @brief returns booleans representing if each character is graphical character.
         * The output depends on truth_ratio(default = 1) which means each character should
         * pass for true to be returned.
         * @param chars_obj object of type Characters
         * @param true_ratio number between 0 and 1 in which defines ratio characters that needs 
         * to be true for this  method return true. 
         * If its 1 then all charactres needs to be true for this method for this method return true.
         * 
         * @return bool
         */
        static bool isGraph(Characters chars_obj, float true_ratio=1);
        /**
         * @brief returns booleans representing if corresponding characters in Characters objects
         * are the same.
         * The output depends on truth_ratio(default = 1) which means all characters are the same.
         * 
         * @param chars_obj object of type Characters
         * @param chars_obj2 object of type Characters
         * @param ignore_case true if caparison be case insensitive
         * @return bool
         */
        static bool textCompare(Characters& chars_obj, Characters& chars_obj2,
         float true_ratio=1, bool ignore_case=false);
};