#pragma once
#include <unordered_map>
#include <functional>
#include <set>
#include <vector>


/**
 * @brief stores and manages objects to be shared/referenced or shared by other objects
 * 
 */

template<class key_t, class val_t> class Shared_Objects{
    public:
        /**
         * @brief key value map with key being character and value being Character object
         * 
         */
        std::unordered_map<key_t, val_t> shared_map;

    public:
        /**
         * @brief Construct a new Characters_Set object
         * 
         */
        Shared_Objects();
        

        /**
         * @brief Construct a new Shared_Objects object from iterator of keys
         * 
         * @param begin beginning of iterartor
         * @param end end of iterator
         */
        template<typename Iterator>
        Shared_Objects(Iterator begin, Iterator end);

        /**
         * @brief Construct a new Shared_Objects object from iterator of keys
         * 
         * @param begin beginning of iterator
         * @param end end of iterator
         * @param func callback function that creates object from key
         */
        template<typename Iterator>
        Shared_Objects(Iterator begin, Iterator end, std::function< val_t(key_t)> func);

        /**
         * @brief add key and value to shared map
         * 
         * @param key key to be added
         * @param value object to be added with key
         */
        void add(key_t key, val_t value);

        /**
         * @brief add element with key from argument and object calculated by passing
         * the key as parameter to val_t(represent type of value)
         * 
         * @param key value to use as key in map
         */
        void add(key_t key);

        /**
         * @brief add elements with keys from iterator and objects get created
         * by passing key as argument to val_t(type for values)
         * 
         * @param begin beginning of iterator
         * @param end end of iterator
         */
        template<typename Iterator>
        void add(Iterator begin, Iterator end);

        /**
         * @brief add elements with keys from iterator and objects created from funct callback
         * 
         * @param begin beginning of iterator
         * @param end end of iterator
         * @param func callback function that creates object from key
         */
        template<typename Iterator>
        void add(Iterator begin, Iterator end, std::function<val_t(key_t)> func);


        /**
         * @brief removes all elements in iterator matching any of values in iterator
         * 
         * @param begin beginining of iterrator
         * @param end end of iterator
         */
        template<typename Iterator>
        void remove(Iterator begin, Iterator end);
        /**
         * @brief remove element matching key
         * 
         * @param key
         */
        void remove(key_t key);
        /**
         * @brief removes all elements
         * 
         */
        void clear();
        /**
         * @brief checks if element with key exists
         * 
         * @param key
         * @return true 
         * @return false 
         */
        bool exists(key_t key);
        /**
         * @brief checks if object is empty
         * 
         * @return true 
         * @return false 
         */
        bool empty();
        /**
         * @brief return size of object
         * 
         * @return size_t 
         */
        size_t size();

        /**
         * @brief returns iterator with duplicates removed
         * 
         * @param begin beginning of iterator
         * @param end end of iterator
         * @return Iterator iterator with unique elements
         */
        template<typename Iterator>
        std::set<key_t> unique(Iterator begin, Iterator end);

        /**
         * @brief get object corresponding with key
         * 
         * @param key 
         * @return val_t 
         */
        val_t& get(key_t key);

        /**
         * @brief returns keys in vector
         * 
         * @return std::vector<key_t> 
         */
        std::vector<key_t> getKeys();
        /**
         * @brief returns values in vector
         * 
         * @return std::vector<val_t>
         */
        std::vector<val_t> getValues();


        // iterator methods
        typename std::unordered_map<key_t, val_t>::iterator begin();
        typename std::unordered_map<key_t, val_t>::iterator end();
        typename std::unordered_map<key_t, val_t>::const_iterator cbegin() const;
        typename std::unordered_map<key_t, val_t>::const_iterator cend() const;
        typename std::unordered_map<key_t, val_t>::const_iterator begin() const;
        typename std::unordered_map<key_t, val_t>::const_iterator end() const;

        // operator overiding
        val_t& operator[](key_t index);
        Shared_Objects<key_t, val_t> operator+(Shared_Objects<key_t, val_t> other);
        bool operator==(std::string other);
        bool operator==(const char* other);
        bool operator==(Shared_Objects<key_t, val_t>& other);
        bool operator!=(Shared_Objects<key_t, val_t>& other);

        // helped by: https://stackoverflow.com/questions/4660123/
        // overloading-friend-operator-for-template-class
        template <typename key_ft, typename val_ft>
        friend std::ostream& operator<<( std::ostream&, const Shared_Objects<key_ft, val_ft>&);
};