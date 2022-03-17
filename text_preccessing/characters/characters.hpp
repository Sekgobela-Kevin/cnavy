#include "string"
#include <vector>
#include "..\character\line_character.hpp"

/**
 * @brief type that stores sequence of Characters of objects
 * 
 */
typedef Character character_type;
typedef std::vector<character_type> characters_objs_type;

/**
 * @brief Base class for charcters. \n
 * Characters is just collection of Character objects in sequence
 * managed by single object.
 * This Class provide base methods shared by all Characters Classes.
 * 
 */
class Characters : public std::string{
    protected:
        //**
        characters_objs_type characters_objs;
        std::string input_string;

    public:
        /**
         * @brief Construct a new Characters object
         * 
         * @param input_text string to be represented
         */
        Characters(std::string input_text);

        /**
         * @brief returns string version of the object
         * 
         * @return std::string 
         */
        std::string getText();
        /**
         * @brief returns underlying Characters objects in collection
         * 
         * @return characters_objs_type collcetion of character objects
         */
        characters_objs_type getCharsObjs();
};
