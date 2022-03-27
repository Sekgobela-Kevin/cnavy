#pragma once

#include "..\characters\characters.hpp"
#include "..\characters\bool_characters.hpp"
#include "..\characters\ratio_characters.hpp"
#include "..\characters\summary_characters.hpp"
#include "..\characters\compare_characters.hpp"

#include <string>

/**
 * @brief Kind of Characters Class that precomputes verything other than calculating for
 * every call to perform task. Its through this Class in which Tokens get created by 
 * inheritance. Intended to be a fast version of Characters Class that can be loaded faster
 * and efficiently. Think of it as Token Class that does not contain data about Document
 * object like index, spans, etc.
 * 
 */
class Characters_Token{
    public:
        // bool characters
        // Each boolean value represent state of character in that pos

        // booleans representing if corresponding character is alphanumeric
        bool_chars_type bool_is_alnum;
        // booleans representing if corresponding character is alphabetic
        bool_chars_type bool_is_alpha;
        // booleans representing if corresponding character is ascii
        bool_chars_type bool_is_ascii;
        // booleans representing if corresponding character is blank
        bool_chars_type bool_is_blank;
        // booleans representing if corresponding character is control character
        bool_chars_type bool_is_cntrl;
        // booleans representing if corresponding character is digit
        bool_chars_type bool_is_digit;
        // booleans representing if corresponding character is graphical
        bool_chars_type bool_is_graph;
        // booleans representing if corresponding character is in lowercase
        bool_chars_type bool_is_lower;
        // booleans representing if corresponding character is printable
        bool_chars_type bool_is_print;
        // booleans representing if corresponding character is punctuation
        bool_chars_type bool_is_punct;
        // booleans representing if corresponding character is space
        bool_chars_type bool_is_space;
        // booleans representing if corresponding character is in uppercase
        bool_chars_type bool_is_upper;
        // booleans representing if corresponding character is hexadecial digit
        bool_chars_type bool_is_xdigit;

        // ratio characters

        // proportion/ratio of alphanumeric characters in token
        float ratio_is_alnum;
        // proportion/ratio of alphabetic characters in token
        float ratio_is_alpha;
        // proportion/ratio of ascii characters in token
        float ratio_is_ascii;
        // proportion/ratio of blank characters in token
        float ratio_is_blank;
        // proportion/ratio of control characters in token
        float ratio_is_cntrl;
        // proportion/ratio of digits in token
        float ratio_is_digit;
        // proportion/ratio of graphical characters in token
        float ratio_is_graph;
        // proportion/ratio of lowercase characters in token
        float ratio_is_lower;
        // proportion/ratio of printable characters in token
        float ratio_is_print;
        // proportion/ratio of punctuation characters in token
        float ratio_is_punct;
        // proportion/ratio of space characters in token
        float ratio_is_space;
        // proportion/ratio of uppercase characters in token
        float ratio_is_upper;
        // proportion/ratio of hexadecimal digits in token
        float ratio_is_xdigit;

        // summary characters(using ratio of 1)

        // checks if token is alphanumeric
        bool is_alnum;
        // checks if token is alphabetic
        bool is_alpha;
        // checks if token is ascii
        bool is_ascii;
        // checks if token is blank
        bool is_blank;
        // checks is made of control characters
        bool is_cntrl;
        // checks if token is digit
        bool is_digit;
        // checks if token graphical
        bool is_graph;
        // checks if token is in lowercase
        bool is_lower;
        // checks if token is printable
        bool is_print;
        // checks if token punctuation
        bool is_punct;
        // checks if token is space character
        bool is_space;
        // checks if token is in uppercase
        bool is_upper;
        // checks if token is hexadecimal
        bool is_xdigit;

        // text version of token
        std::string text;
        // lowercase version of token
        std::string lower;
        // uppercase version of token
        std::string upper;
        // length of token
        int length;

    public:
        Characters& chars_obj;

    public:
        /**
         * @brief Construct a new Characters_Token object
         * 
         * @param chars_obj Characters object
         */
        Characters_Token(Characters& chars_obj);
        /**
         * @brief Construct a new Characters_Token object
         * 
         */
        Characters_Token();

        // ----------Summary Characters methods-------------

        /**
         * @brief returns boolean representing if each character is ASCII.
         * The output depends on truth_ratio(default = 1) which means each character should
         * pass for true to be returned.
         * @param true_ratio number between 0 and 1 in which defines ratio characters that needs 
         * to be true for this  method return true. 
         * If its 1 then all characters needs to be true for this method for this method return true.
         * 
         * @return bool
         */
        bool isAscii(float true_ratio=1) const;
        /**
         * @brief returns booleans representing if each character is alphanumeric.
         * The output depends on truth_ratio(default = 1) which means each character should
         * pass for true to be returned.
         * @param true_ratio number between 0 and 1 in which defines ratio characters that needs 
         * to be true for this  method return true. 
         * If its 1 then all characters needs to be true for this method for this method return true.
         * 
         * @return bool
         */
        bool isAlnum(float true_ratio=1) const;
        /**
         * @brief returns booleans representing if each character is alphabetic.
         * The output depends on truth_ratio(default = 1) which means each character should
         * pass for true to be returned.
         * @param true_ratio number between 0 and 1 in which defines ratio characters that needs 
         * to be true for this  method return true. 
         * If its 1 then all characters needs to be true for this method for this method return true.
         * 
         * @return bool
         */
        bool isAlpha(float true_ratio=1) const;
        /**
         * @brief returns booleans representing if each character is blank character.
         * The output depends on truth_ratio(default = 1) which means each character should
         * pass for true to be returned.
         * @param true_ratio number between 0 and 1 in which defines ratio characters that needs 
         * to be true for this  method return true. 
         * If its 1 then all characters needs to be true for this method for this method return true.
         * 
         * @return bool
         */
        bool isBlank(float true_ratio=1) const;
        /**
         * @brief returns booleans representing if each character is control character.
         * The output depends on truth_ratio(default = 1) which means each character should
         * pass for true to be returned.
         * @param true_ratio number between 0 and 1 in which defines ratio characters that needs 
         * to be true for this  method return true. 
         * If its 1 then all characters needs to be true for this method for this method return true.
         * 
         * @return bool
         */
        bool isCntrl(float true_ratio=1) const;
        /**
         * @brief returns booleans representing if each character is digit.
         * The output depends on truth_ratio(default = 1) which means each character should
         * pass for true to be returned.
         * @param true_ratio number between 0 and 1 in which defines ratio characters that needs 
         * to be true for this  method return true. 
         * If its 1 then all characters needs to be true for this method for this method return true.
         * 
         * @return bool
         */
        bool isDigit(float true_ratio=1) const;
        /**
         * @brief returns booleans representing if each character is in lowercase.
         * The output depends on truth_ratio(default = 1) which means each character should
         * pass for true to be returned.
         * @param true_ratio number between 0 and 1 in which defines ratio characters that needs 
         * to be true for this  method return true. 
         * If its 1 then all characters needs to be true for this method for this method return true.
         * 
         * @return bool
         */
        bool isLower(float true_ratio=1) const;
        /**
         * @brief returns booleans representing if each character is printable.
         * The output depends on truth_ratio(default = 1) which means each character should
         * pass for true to be returned.
         * @param true_ratio number between 0 and 1 in which defines ratio characters that needs 
         * to be true for this  method return true. 
         * If its 1 then all characters needs to be true for this method for this method return true.
         * 
         * @return bool
         */
        bool isPrint(float true_ratio=1) const;
        /**
         * @brief returns booleans representing if each character is punctuation.
         * The output depends on truth_ratio(default = 1) which means each character should
         * pass for true to be returned.
         * @param true_ratio number between 0 and 1 in which defines ratio characters that needs 
         * to be true for this  method return true. 
         * If its 1 then all characters needs to be true for this method for this method return true.
         * 
         * @return bool
         */
        bool isPunct(float true_ratio=1) const;
        /**
         * @brief returns booleans representing if each character is space character.
         * The output depends on truth_ratio(default = 1) which means each character should
         * pass for true to be returned.
         * @param true_ratio number between 0 and 1 in which defines ratio characters that needs 
         * to be true for this  method return true. 
         * If its 1 then all characters needs to be true for this method for this method return true.
         * 
         * @return bool
         */
        bool isSpace(float true_ratio=1) const;
        /**
         * @brief returns booleans representing if each character is in uppercase.
         * The output depends on truth_ratio(default = 1) which means each character should
         * pass for true to be returned.
         * @param true_ratio number between 0 and 1 in which defines ratio characters that needs 
         * to be true for this  method return true. 
         * If its 1 then all characters needs to be true for this method for this method return true.
         * 
         * @return bool
         */
        bool isUpper(float true_ratio=1) const;
        /**
         * @brief returns booleans representing if each character is valid hexadecimal character.
         * The output depends on truth_ratio(default = 1) which means each character should
         * pass for true to be returned.
         * @param true_ratio number between 0 and 1 in which defines ratio characters that needs 
         * to be true for this  method return true. 
         * If its 1 then all characters needs to be true for this method for this method return true.
         * 
         * @return bool
         */
        bool isXdigit(float true_rati=1) const;
        /**
         * @brief returns booleans representing if each character is graphical character.
         * The output depends on truth_ratio(default = 1) which means each character should
         * pass for true to be returned.
         * @param true_ratio number between 0 and 1 in which defines ratio characters that needs 
         * to be true for this  method return true. 
         * If its 1 then all characters needs to be true for this method for this method return true.
         * 
         * @return bool
         */
        bool isGraph(float true_ratio=1) const;
};
