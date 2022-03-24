#pragma once 
#include <string>
#include <vector>
#include <functional>

// collection of bools e.g {true, false, ..}
typedef std::vector<bool> bool_chars_type;
// collection of containing collection of bools e.g {{tru, false}, ...}
typedef std::vector<std::vector<bool>> bool_matric_type;

class Bool_Set{
    public:
        /**
         * @brief performs operation on each element of bool collection and return results
         * 
         * @param bool_collection collection of booleans
         * @param input_func funtion to call on each element
         * @return bool_chars_type 
         */
        static bool_chars_type for_each_elem(bool_chars_type bool_collection, 
            std::function<bool(bool)> input_func);
        /**
         * @brief performs operation based on each elements of bool collections and return results
         * 
         * @param collection collection of booleans
         * @param collection2 collection of booleans
         * @param input_func funtion to call on each element
         * @return bool_chars_type 
         */
        static bool_chars_type for_each_elem(bool_chars_type collection,  bool_chars_type collection2,
            std::function<bool(bool, bool)> input_func);
        /**
         * @brief Performs bitwise AND operation on bool_collection
         * 
         * @param bool_collection collection of booleans to perform operation
         * @param bool_collection2 collection of booleans apply on bool_collection arg
         * @return bool_chars_type 
         */
        static bool_chars_type boolAND(bool_chars_type bool_collection, bool_chars_type bool_collection2);
        /**
         * @brief Performs bitwise OR operation on bool_collection
         * 
         * @param bool_collection collection of booleans to perform operation
         * @param bool_collection2 collection of booleans apply on bool_collection arg
         * @return bool_chars_type 
         */
        static bool_chars_type boolOR(bool_chars_type bool_collection, bool_chars_type bool_collection2);
        /**
         * @brief Performs bitwise XOR operation on bool_collection
         * 
         * @param bool_collection collection of booleans to perform operation
         * @param bool_collection2 collection of booleans apply on bool_collection arg
         * @return bool_chars_type 
         */
        static bool_chars_type boolXOR(bool_chars_type bool_collection, bool_chars_type bool_collection2);
        /**
         * @brief Performs bitwise NOT operation on bool_collection
         * 
         * @param bool_collection collection of booleans to perform operation
         * @param bool_collection2 collection of booleans apply on bool_collection arg
         * @return bool_chars_type 
         */
        static bool_chars_type boolNOT(bool_chars_type bool_collection);
        /**
         * @brief Checks if correspoding bool values are equal in bool collections
         * 
         * @param bool_collection collection of booleans to perform operation
         * @param bool_collection2 collection of booleans apply on bool_collection arg
         * @return bool_chars_type 
         */
        static bool_chars_type boolEqual(bool_chars_type bool_collection, bool_chars_type bool_collection2);

        /**
         * @brief Tests whether all bits from bool_collection  are set or not.
         * 
         * @param bool_collection 
         * @return true 
         * @return false 
         */
        static bool any(bool_chars_type bool_collection);
        /**
         * @brief Tests whether all bits from bool_collection  are set or not.
         * 
         * @param bool_collection 
         * @return true 
         * @return false 
         */
        static bool all(bool_chars_type bool_collection);
        /**
         * @brief Count number of set bits from bitset.
         * 
         * @param bool_collection 
         * @return true 
         * @return false 
         */
        static bool count(bool_chars_type bool_collection);
        /**
        * @brief Converts bool_collection to string object.
        * 
        * @param bool_collection 
        * @return true 
        * @return false 
        */
        std::string static toString(bool_chars_type bool_collection);
};