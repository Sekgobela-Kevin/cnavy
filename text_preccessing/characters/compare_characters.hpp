#include "static_compare_characters.hpp"
#include "characters.hpp"


/**
 * @brief Class for two comparing Characters objects
 * 
 */
class Compare_Characters{
    public:
        // first character object
        Characters& chars_obj;
        // second character object
        Characters& chars_obj2;
        // stores what compare should be based on("is_alpha", "text", etc)
        std::vector<std::string> scope;
        bool ignore_case;

    public:
        /**
         * @brief Construct a new Compare_Characters object
         * 
         * @param char_obj object of Characters Class
         * @param char_obj2 object of Characters Class
         * @param scope list of containing data to be extracted of characters. e.g
         * {"is_digit", "is_space"} will extract for correspinding methods in each 
         * character.
         * @param ignore_case ignore_case comparison of Characters of objects text/char is not 
         * case sensitive. This beneficial if "text" or "chars" is included in scope argument.
         */
        Compare_Characters(Characters& chars_obj, Characters& chars_obj2,
        std::vector<std::string> scope, bool ignore_case=false);
        /**
         * @brief Construct a new Compare_Characters object
         * 
         */
        Compare_Characters();

        /**
         * @brief returns compared bools metrixes from Characters objects
         * 
         * case sensitive. This beneficial if "text" or "chars" is included in scope argument.
         * @return bool_matric_type Matric of booleans e.g {{true, false}, {false, false}}
         * 
         */
        bool_matric_type getBoolsMatrix();

        /**
         * @brief ratio representing overal similarity of Characters objects based on 
         * attribute arguments elememets
         * 
         * @return ratio_collec_type collection containing ratios(0-1)
         */
        float getRatio();

        /**
         * @brief collection of ratios representing similarity each correspoding to specified
         * scope from argument. The ratios are in order of scope argument.
         * 
         * @return ratio_collec_type collection containing ratios(0-1)
         */
        ratio_collec_type getRatios();
};

