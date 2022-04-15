#pragma once
#include "raw_token.hpp"

#include <string>
#include <functional>

typedef std::function<bool(float ratio, float min_ratio)> sum_func_type;

/**
 * @brief Class that references members 
 * 
 */
class Reference_Token{
    public:
        // bool characters
        // Each boolean value represent state of character in that pos

        // booleans representing if corresponding character is alphanumeric
        const bool_chars_type& bool_is_alnum;
        // booleans representing if corresponding character is alphabetic
        const bool_chars_type& bool_is_alpha;
        // booleans representing if corresponding character is ascii
        const bool_chars_type& bool_is_ascii;
        // booleans representing if corresponding character is blank
        const bool_chars_type& bool_is_blank;
        // booleans representing if corresponding character is control character
        const bool_chars_type& bool_is_cntrl;
        // booleans representing if corresponding character is digit
        const bool_chars_type& bool_is_digit;
        // booleans representing if corresponding character is graphical
        const bool_chars_type& bool_is_graph;
        // booleans representing if corresponding character is in lowercase
        const bool_chars_type& bool_is_lower;
        // booleans representing if corresponding character is printable
        const bool_chars_type& bool_is_print;
        // booleans representing if corresponding character is punctuation
        const bool_chars_type& bool_is_punct;
        // booleans representing if corresponding character is space
        const bool_chars_type& bool_is_space;
        // booleans representing if corresponding character is in uppercase
        const bool_chars_type& bool_is_upper;
        // booleans representing if corresponding character is hexadecial digit
        const bool_chars_type& bool_is_xdigit;

        // ratio characters

        // proportion/ratio of alphanumeric characters in token
        const float& ratio_is_alnum;
        // proportion/ratio of alphabetic characters in token
        const float& ratio_is_alpha;
        // proportion/ratio of ascii characters in token
        const float& ratio_is_ascii;
        // proportion/ratio of blank characters in token
        const float& ratio_is_blank;
        // proportion/ratio of control characters in token
        const float& ratio_is_cntrl;
        // proportion/ratio of digits in token
        const float& ratio_is_digit;
        // proportion/ratio of graphical characters in token
        const float& ratio_is_graph;
        // proportion/ratio of lowercase characters in token
        const float& ratio_is_lower;
        // proportion/ratio of printable characters in token
        const float& ratio_is_print;
        // proportion/ratio of punctuation characters in token
        const float& ratio_is_punct;
        // proportion/ratio of space characters in token
        const float& ratio_is_space;
        // proportion/ratio of uppercase characters in token
        const float& ratio_is_upper;
        // proportion/ratio of hexadecimal digits in token
        const float& ratio_is_xdigit;

        // summary characters(using ratio of 1)

        // checks if token is alphanumeric
        const bool& is_alnum;
        // checks if token is alphabetic
        const bool& is_alpha;
        // checks if token is ascii
        const bool& is_ascii;
        // checks if token is blank
        const bool& is_blank;
        // checks is made of control characters
        const bool& is_cntrl;
        // checks if token is digit
        const bool& is_digit;
        // checks if token graphical
        const bool& is_graph;
        // checks if token is in lowercase
        const bool& is_lower;
        // checks if token is printable
        const bool& is_print;
        // checks if token punctuation
        const bool& is_punct;
        // checks if token is space character
        const bool& is_space;
        // checks if token is in uppercase
        const bool& is_upper;
        // checks if token is hexadecimal
        const bool& is_xdigit;

        // text version of token
        std::string& text;
        // lowercase version of token
        std::string& lower;
        // uppercase version of token
        std::string& upper;
        // length of token
        int& length;

    public:
        /**
         * @brief Characters object
         * 
         */
        //const Characters& chars_obj;
        /**
         * @brief Characters Token object
         * 
         */
        const Raw_Token& chars_token;


    public:
        /**
         * @brief Construct a new Reference_Token object
         * 
         * @param chars_token Raw_Token object
         */
        Reference_Token(Raw_Token& chars_token);
        /**
         * @brief Construct a new Reference_Token object
         * 
         */
        Reference_Token();

        // ----------Summary Characters methods-------------

        /**
         * @brief returns boolean representing if each character is ASCII.
         * The output depends on truth_ratio(default = 1) which means each character should
         * pass for true to be returned.
         * @param min_ratio number between 0 and 1 in which defines ratio characters that needs 
         * to be true for this  method return true. 
         * If its 1 then all characters needs to be true for this method for this method return true.
         * 
         * @return bool
         */
        bool isAscii(float min_ratio=1) const;
        /**
         * @brief returns booleans representing if each character is alphanumeric.
         * The output depends on truth_ratio(default = 1) which means each character should
         * pass for true to be returned.
         * @param min_ratio number between 0 and 1 in which defines ratio characters that needs 
         * to be true for this  method return true. 
         * If its 1 then all characters needs to be true for this method for this method return true.
         * 
         * @return bool
         */
        bool isAlnum(float min_ratio=1) const;
        /**
         * @brief returns booleans representing if each character is alphabetic.
         * The output depends on truth_ratio(default = 1) which means each character should
         * pass for true to be returned.
         * @param min_ratio number between 0 and 1 in which defines ratio characters that needs 
         * to be true for this  method return true. 
         * If its 1 then all characters needs to be true for this method for this method return true.
         * 
         * @return bool
         */
        bool isAlpha(float min_ratio=1) const;
        /**
         * @brief returns booleans representing if each character is blank character.
         * The output depends on truth_ratio(default = 1) which means each character should
         * pass for true to be returned.
         * @param min_ratio number between 0 and 1 in which defines ratio characters that needs 
         * to be true for this  method return true. 
         * If ratio of token for this method greater or less than zero it returns true else return false.
         * 
         * @return bool
         */
        bool isBlank(float min_ratio=1) const;
        /**
         * @brief returns booleans representing if each character is control character.
         * The output depends on truth_ratio(default = 1) which means each character should
         * pass for true to be returned.
         * @param min_ratio number between 0 and 1 in which defines ratio characters that needs 
         * to be true for this  method return true. 
         * If its 1 then all characters needs to be true for this method for this method return true.
         * 
         * @return bool
         */
        bool isCntrl(float min_ratio=1) const;
        /**
         * @brief returns booleans representing if each character is digit.
         * The output depends on truth_ratio(default = 1) which means each character should
         * pass for true to be returned.
         * @param min_ratio number between 0 and 1 in which defines ratio characters that needs 
         * to be true for this  method return true. 
         * If its 1 then all characters needs to be true for this method for this method return true.
         * 
         * @return bool
         */
        bool isDigit(float min_ratio=1) const;
        /**
         * @brief returns booleans representing if each character is in lowercase.
         * The output depends on truth_ratio(default = 1) which means each character should
         * pass for true to be returned.
         * @param min_ratio number between 0 and 1 in which defines ratio characters that needs 
         * to be true for this  method return true. 
         * If its 1 then all characters needs to be true for this method for this method return true.
         * 
         * @return bool
         */
        bool isLower(float min_ratio=1) const;
        /**
         * @brief returns booleans representing if each character is printable.
         * The output depends on truth_ratio(default = 1) which means each character should
         * pass for true to be returned.
         * @param min_ratio number between 0 and 1 in which defines ratio characters that needs 
         * to be true for this  method return true. 
         * If its 1 then all characters needs to be true for this method for this method return true.
         * 
         * @return bool
         */
        bool isPrint(float min_ratio=1) const;
        /**
         * @brief returns booleans representing if each character is punctuation.
         * The output depends on truth_ratio(default = 1) which means each character should
         * pass for true to be returned.
         * @param min_ratio number between 0 and 1 in which defines ratio characters that needs 
         * to be true for this  method return true. 
         * If its 1 then all characters needs to be true for this method for this method return true.
         * 
         * @return bool
         */
        bool isPunct(float min_ratio=1) const;
        /**
         * @brief returns booleans representing if each character is space character.
         * The output depends on truth_ratio(default = 1) which means each character should
         * pass for true to be returned.
         * @param min_ratio number between 0 and 1 in which defines ratio characters that needs 
         * to be true for this  method return true. 
         * If its 1 then all characters needs to be true for this method for this method return true.
         * 
         * @return bool
         */
        bool isSpace(float min_ratio=1) const;
        /**
         * @brief returns booleans representing if each character is in uppercase.
         * The output depends on truth_ratio(default = 1) which means each character should
         * pass for true to be returned.
         * @param min_ratio number between 0 and 1 in which defines ratio characters that needs 
         * to be true for this  method return true. 
         * If its 1 then all characters needs to be true for this method for this method return true.
         * 
         * @return bool
         */
        bool isUpper(float min_ratio=1) const;
        /**
         * @brief returns booleans representing if each character is valid hexadecimal character.
         * The output depends on truth_ratio(default = 1) which means each character should
         * pass for true to be returned.
         * @param min_ratio number between 0 and 1 in which defines ratio characters that needs 
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
         * @param min_ratio number between 0 and 1 in which defines ratio characters that needs 
         * to be true for this  method return true. 
         * If its 1 then all characters needs to be true for this method for this method return true.
         * 
         * @return bool
         */
        bool isGraph(float min_ratio=1) const;
};
