#pragma once

#include "characters.hpp"
#include "bool_characters.hpp"
#include "ratio_characters.hpp"
#include "summary_characters.hpp"
#include "compare_characters.hpp"

#include "shared_objects.hpp"

#include <string>
#include <vector>

/**
 * @brief Kind of Characters Class that precomputes verything other than calculating for
 * every call to perform task. Its through this Class in which Tokens get created by 
 * inheritance. Intended to be a fast version of Characters Class that can be loaded faster
 * and efficiently. Think of it as Token Class that does not contain data about Document
 * object like index, spans, etc.
 * 
 */
template<class char_class> class Raw_Token{
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
        //using char_class = char_class;

        using char_obj_ref_t = std::reference_wrapper<char_class>;

        using vector_ref_t = std::vector<std::reference_wrapper<char_class>>;

        using shared_char_t = Shared_Objects<char_type, char_class>;

        static shared_char_t shared_char_objs;

        /**
         * @brief vector with references to character objects. It could be Character, Line_Character
         * or Basic_Character.
         * 
         */
        vector_ref_t character_objs_ref;

    public:
        /**
         * @brief Construct a new Raw_Token object
         * 
         * @param chars_obj Characters object
         */
        Raw_Token(Characters chars_obj);
        /**
         * @brief Construct a new Raw_Token object
         * 
         * @param chars_obj characters object
         * @param shared_chars_objs Shared_Objects object of character objects
         */
        Raw_Token(Characters chars_obj, Shared_Objects<std::string, 
        Characters>& shared_chars_objs);
        /**
         * @brief Construct a new Raw_Token object from string
         * 
         * @param input_text 
         */
        Raw_Token(std::string input_text);
        /**
         * @brief Construct a new Raw_Token object
         * 
         * @param input_text 
         * @param shared_char_objs 
         */
        Raw_Token(std::string& input_text, Shared_Objects<std::string, Characters>& shared_char_objs);
        /**
         * @brief Construct a new Raw_Token object
         * 
         */
        Raw_Token();
        /**
         * @brief sets attributes of of object from Characters object
         * 
         * @param chars_obj 
         * @return Characters 
         */
        void setAttrs(Characters& chars_obj);

        /**
         * @brief get copy version of vector of references
         * 
         * @param char_objs_ref 
         * @return std::vector<Character> 
         */
        std::vector<Character> getCharObjs(Raw_Token::vector_ref_t char_objs_ref);
        /**
         * @brief generate Characters object and return it
         *
         * @return Characters Characters object 
         */
        Characters getCharsObj();
        /**
         * @brief returns collection of chararacter objects
         * 
         * @param char_objs_ref 
         * @return std::vector<Character> 
         */
        std::vector<Character> getCharObjs();

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
    

    public:
        // iterator methods
        typename vector_ref_t::iterator begin();
        typename vector_ref_t::iterator end();
        typename vector_ref_t::const_iterator cbegin() const;
        typename vector_ref_t::const_iterator cend() const;
        typename vector_ref_t::const_iterator begin() const;
        typename vector_ref_t::const_iterator end() const;

        // operator overiding
        char_obj_ref_t& operator[](size_t index);
        Raw_Token<char_class> operator+(Raw_Token<char_class>& other);
        bool operator==(std::string other);
        bool operator!=(std::string other);
        bool operator==(const char* other);
        bool operator!=(const char* other);
        bool operator==(Raw_Token<char_class>& other);
        bool operator!=(Raw_Token<char_class>& other);

        // helped by: https://stackoverflow.com/questions/4660123/
        // overloading-friend-operator-for-template-class
        template <typename char_class_, typename val_ft>
        friend std::ostream& operator<<( std::ostream&, const Raw_Token<char_class_>&);
};
