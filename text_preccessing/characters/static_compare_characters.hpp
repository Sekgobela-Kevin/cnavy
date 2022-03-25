#pragma once
#include "characters.hpp"
#include "bool_set.hpp"
#include <vector>

// CLasses in the files could be made objects but decided not to but use static methods

/**
 * @brief collection of ratios(numbers between 0-1)
 * 
 */
typedef std::vector<float> ratio_collec_type;
/**
 * @brief Class for comparing Characters objects based on underlying characters they contain.
 * 
 */
class Static_Compare_Characters{
    public:
        /**
         * @brief iterate through two bool matrixs
         * 
         * @param bools_matrix 
         * @param bools_matrix2 
         * @param input_func 
         * @return bool_matric_type 
         */
        static bool_matric_type mapMatrix(bool_matric_type& bools_matrix, bool_matric_type& bools_matrix2, 
            std::function<bool_chars_type(bool_chars_type, bool_chars_type)> input_func);
        /**
         * @brief performs operation on both bools collection and return new bool collection
         * 
         * @param bools_collection collection of booleans
         * @param bools_collection2 collection of booleans from another Characters object
         * @return bool_chars_type 
         */
        static bool_chars_type compareBools(bool_chars_type& bools_collection, bool_chars_type& bools_collection2);
        /**
         * @brief performs logical OR or bools_collection and mask(bools collection).
         * This allows bool values of false in mask to be true at return value no matter
         * value in bool_collection. Its just trick to make it as if corresponding 
         * characters matched.
         * 
         * @param bools_collection collection of booleans
         * @param bools_mask collection of booleans to be used as mask
         * @return bool_chars_type 
         */
        static bool_chars_type maskBools(bool_chars_type& bools_collection, bool_chars_type& bools_mask);
         /**
         * @brief performs operation on both bools collection and return new bool collection
         * 
         * @param bools_matrix matrix of booleans
         * @param bools_matrix2 matrix of booleans from another Characters object
         * @return bool_matric_type matrix of booleans
         */
        static bool_matric_type compareBoolsMatrix(bool_matric_type& bools_matrix, bool_matric_type& bools_matrix2);
         /**
         * @brief performs maskBools(bools_collection, bools_mask) on each element of bools_matrix with 
         * bool mask being element from bools_matrix and bools_mask being corresponding element from
         * mask_matrix_mask.
         * 
         * @param bools_matrix matrix of booleans
         * @param mask_matrix_mask matrix of booleans used as mask
         * @return bool_matric_type matrix of booleans
         */
        static bool_matric_type maskBoolsMatrix(bool_matric_type& bools_matrix, bool_matric_type& mask_matrix_mask);
        /**
         * @brief returns ratio from boolean collections
         * 
         * @param bools_collection collection of booleans
         * @param bools_collection2 collection of booleans
         * @return float number between 0(different) and 1(same)
         */
        static float getBoolRatio(bool_chars_type& bools_collection, bool_chars_type& bools_collection2);
        /**
         * @brief returns ratio calculated from collection of ratios. think of it as
         * average of all ratios.
         * 
         * @param ratio_collec collection of ratios
         * @return float ratio(0-1)
         */
        static float getFinalRatio(ratio_collec_type& ratio_collec);


        /**
         * @brief returns ratio from metrixes of booleans
         * 
         * @param bools_collection collection of booleans
         * @param bools_collection2 collection of booleans
         * @return ratio_collec_type collection containing ratios(0-1)
         */
        static ratio_collec_type getBoolRatios(bool_matric_type& bools_matrix, bool_matric_type& bools_matrix2);
        /**
         * @brief returns ratio from metrix of booleans
         * 
         * @param bools_collection collection of booleans
         * @return ratio_collec_type collection containing ratios(0-1)
         */
        static ratio_collec_type getBoolRatios(bool_matric_type& bools_matrix);

        /**
         * @brief returns Matrix with booleans which represent data about characters
         * in Characters object. E.g could contain booleans for isUpper() and isDigit(). This
         * matrix of booleans can be compared with matrix from another Character object.
         * 
         * @param char_obj object of Characters Class
         * @param attributes list of containing data to be extracted of characters. e.g
         * {"is_digit", "is_space"} will extract for correspinding methods in each 
         * character.
         * @return bool_matric_type Matric of booleans e.g {{true, false}, {false, false}}
         */
        static bool_matric_type getBoolsMatrix(const Characters& chars_obj, 
            std::vector<std::string> attributes);

        /**
         * @brief returns Matrix with booleans which represent results  of comparing of
         * metrix booleans of each Characters object. Bools Matrixes
         * for the Characters objects get compared and then returned. It differs from its overloaded
         * by that it supports 2 Characters objects and is able to compare characters 
         * the objects which is imporsible on the other method. Including "chars" or "text" inside
         * attribute would compare each corresponding characters by "==" operator. 
         * 
         * @param char_obj object of Characters Class
         * @param char_obj2 object of Characters Class
         * @param attributes list of containing data to be extracted of characters. e.g
         * {"is_digit", "is_space"} will extract for correspinding methods in each 
         * character.
         * @param ignore_case ignore_case comparison of Characters of objects text/char is not 
         * 
         * case sensitive. This beneficial if "text" or "chars" is included in attributes argument.
         * @return bool_matric_type Matric of booleans e.g {{true, false}, {false, false}}
         * 
         */
        static bool_matric_type getBoolsMatrix(Characters& chars_obj,
        Characters& chars_obj2, std::vector<std::string> attributes, bool ignore_case=false);

        /**
         * @brief compares text in characters object and return corresponding booleans
         * 
         * @param chars_obj object of type Characters
         * @param chars_obj2 object of type Characters
         * @param ignore_case true if caparison be case insensitive
         * @return bool_chars_type 
         */
        static bool_chars_type textCompare(Characters& chars_obj, Characters& chars_obj2,
         bool ignore_case=false);
};
