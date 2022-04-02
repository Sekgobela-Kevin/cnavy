#pragma once
#include "../shared/shared_objects.hpp"
#include "characters_token.hpp"

#include <vector>


/**
 * @brief tokenises text in different forms into individual tokens
 * 
 */
template<class char_class, class chars_class> class Raw_Tokenise{
    public:
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
         * @brief Construct a new Raw_Tokenise object
         * 
         * @param text text string to be tokenised
         * @param shared_char_objs shared character object
         * @param shared_chars_objs shared characters object
         */
        Raw_Tokenise(std::string& text, shared_char_objs_t& shared_char_objs, 
        shared_chars_objs_t& shared_chars_objs);


    public:
        /**
         * @brief tokens text
         * 
         */
        std::string text;
        /**
         * @brief stores char_class objects to be shared by Tokens
         * 
         */
        shared_char_objs_t& shared_char_objs; 
        /**
         * @brief stores chars_class class objects to be shared by Tokens
         * 
         */
        shared_chars_objs_t& shared_chars_objs; 
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
         * @brief vector with characters objects/tokens
         * 
         */
        chars_coll_t chars_objects;
        /**
         * @brief creates character objects from iterator
         * 
         * @param begin begining of iterator
         * @param end end of of iterator
         * @return char_coll_t 
         */
        template<typename Iterator>
        char_coll_t createCharObjs(Iterator begin, Iterator end);
        /**
         * @brief returns character from char_class object/
         * 
         * @param char_obj object of char_class
         * @return char_type character e.g char or wchar_t
         */
        char_type getChar(char_class char_obj);
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
         * @param char_obj object of char_class
         * @return true 
         * @return false 
         */
        bool isBreakChar(char_class char_obj);
        /**
         * @brief creates character objects from iterator
         * 
         * @param begin begining of iterator
         * @param end end of of iterator
         * @param func skips character if returns false
         * @return char_coll_t 
         */
        template<typename Iterator>
        char_coll_t createCharObjs(Iterator begin, Iterator end, std::function<bool(char_type)> func);
        /**
         * @brief reates character objects from string
         * 
         * @param str string with characters
         * @return char_coll_t 
         */
        char_coll_t createCharObjs(std::string str);
        /**
         * @brief split text into individual tokens(strings)
         * 
         * @param text text to split to pieces
         * @param char_objects collection of characters object(vector)
         * @return std::vector<std::string> 
         */
        std::vector<std::string> splitText(std::string& text, char_coll_t& char_objects);
        /**
         * @brief create characters objects/raw_tokens into collection
         * 
         * @param char_objects character objects in collection
         * @return chars_coll_t 
         */
        chars_coll_t createCharsObjs(std::string& text, char_coll_t& char_objects);

        /**
         * @brief create characters objects/raw_tokens into collection
         * 
         * @param char_objects character objects in collection
         * @param func if function returns true then that character is seen as seperate token
         * @return chars_coll_t 
         */
        chars_coll_t createCharsObjs(chars_coll_t char_objects, std::function<bool(char_class)> func);

        
};