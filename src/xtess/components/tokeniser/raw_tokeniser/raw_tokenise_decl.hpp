#pragma once
#include "shared_objects.hpp"
#include "character.hpp"

#include <vector>
#include <string>
#include <functional>


/**
 * @brief tokenises text in different forms into individual tokens
 * 
 */
template<class char_class, class chars_class> class Raw_Tokenise{
    public:
        using this_t = Raw_Tokenise<char_class, chars_class>;
        /**
         * @brief type for shared character objects
         * 
         */
        using shared_char_objs_t = Shared_Objects<char_type, char_class>;
        /**
         * @brief type for shared characters objects
         * 
         */
        using shared_chars_objs_t = Shared_Objects<std::string, chars_class>;
        /**
         * @brief shared object for tokens objects of chars_class
         * 
         */
        static shared_chars_objs_t shared_chars_objs;
        /**
         * @brief Construct a new Raw_Tokenise object
         * 
         * @param text text string to be tokenised
         */
        Raw_Tokenise(std::string text);
        /**
         * @brief Construct a new Raw_Tokenise object
         * 
         * @param text text string to be tokenised
         */
        Raw_Tokenise(std::string text, std::function<bool(char_type)> func);


    public:
        /**
         * @brief tokens text
         * 
         */
        std::string text;
        /**
         * @brief type defining collection of Character_Token objects
         * 
         */
        using chars_coll_t = typename std::vector<std::reference_wrapper<chars_class>>;
        /**
         * @brief type defining collection of Character_Token objects
         * 
         */
        using char_coll_t = typename std::vector<std::reference_wrapper<char_class>>;
        /**
         * @brief type defining characters object reference in std::reference_wrapper
         * 
         */
        using chars_ref_t = std::reference_wrapper<chars_class>;
        /**
         * @brief type defining character object reference in std::reference_wrapper
         * 
         */
        using char_ref_t = std::reference_wrapper<char_class>;
        /**
         * @brief vector with characters objects/tokens
         * 
         */
        chars_coll_t chars_objs_ref;
        /**
         * @brief returns character from chars_class object/
         * 
         * @param chars_obj object of chars_class
         * @return char_type character e.g char or wchar_t
         */
        std::string getText(chars_class chars_obj);
        /**
         * @brief checks if char_class is used to divide tokens. Space and punctution
         * characters are ofsen used for that. By default, only non alphabetic characters
         * return true.
         * 
         * @param char_t character
         * @return true 
         * @return false 
         */
        bool isBreakChar(char_type chat_);
        /**
         * @brief creates token objects from text
         * 
         * @param text text to split to pieces
         * @param func skips character if returns false
         * @return char_coll_t 
         */
        chars_coll_t createTokens(std::string& text, std::function<bool(char_type)> func);
        /**
         * @brief creates token objects from text
         * 
         * @param str string with characters
         * @return char_coll_t 
         */
        chars_coll_t createTokens(std::string& text);
        /**
         * @brief split text into individual tokens(strings)
         * 
         * @param text text to split to pieces
         * @param func if returns true, character is split to its own token.
         * @return std::vector<std::string> 
         */
        std::vector<std::string> splitText(std::string& text, std::function<bool(char_type)> func);




    public:
        // iterator methods
        typename chars_coll_t::iterator begin();
        typename chars_coll_t::iterator end();
        typename chars_coll_t::const_iterator cbegin() const;
        typename chars_coll_t::const_iterator cend() const;
        typename chars_coll_t::const_iterator begin() const;
        typename chars_coll_t::const_iterator end() const;

        // operator overiding
        chars_ref_t& operator[](size_t index);
        Raw_Tokenise<char_class, chars_class> operator+(Raw_Tokenise<char_class, chars_class>& other);
        bool operator==(std::string& other);
        bool operator!=(std::string& other);
        bool operator==(const char* other);
        bool operator!=(const char* other);
        bool operator==(Raw_Tokenise<char_class, chars_class>& other);
        bool operator!=(Raw_Tokenise<char_class, chars_class>& other);

        template <typename char_class_, typename chars_class_>
        friend std::ostream& operator<<( std::ostream&, const Raw_Tokenise<char_class_, chars_class_>&);
};
