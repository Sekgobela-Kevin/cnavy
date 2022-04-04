#include "shared_objects_decl.hpp"
#include <iterator>
#include <set>

template<class key_t, class val_t>
Shared_Objects<key_t, val_t>::Shared_Objects(){
}

template<class key_t, class val_t>
template<typename Iterator>
Shared_Objects<key_t, val_t>::Shared_Objects(Iterator begin, Iterator end){
    this->add(begin, end);
}

template<class key_t, class val_t>
template<typename Iterator>
Shared_Objects<key_t, val_t>::Shared_Objects(Iterator begin, Iterator end, 
std::function<val_t(key_t)> func){
    this->add(begin, end, func);
}


template<class key_t, class val_t>
void Shared_Objects<key_t, val_t>::add(key_t key, val_t value){
    if(!this->exists(key)){
        this->shared_map.emplace(key, value);
    }
}

template<class key_t, class val_t>
void Shared_Objects<key_t, val_t>::add(key_t key){
    this->add(key, val_t(key));
}

template<class key_t, class val_t>
template<typename Iterator>
void Shared_Objects<key_t, val_t>::add(Iterator begin, Iterator end){
    std::set<key_t> unique_set = this->unique(begin, end);
    using value_type = typename std::iterator_traits<Iterator>::value_type;
    for (value_type elem_key: unique_set) {
        this->add(elem_key);
    }
}

template<class key_t, class val_t>
template<typename Iterator>
void Shared_Objects<key_t, val_t>::add(Iterator begin, Iterator end, std::function<val_t(key_t)> func){
    std::set<key_t> unique_set = this->unique(begin, end);
    using value_type = typename std::iterator_traits<Iterator>::value_type;
    for (value_type elem_key: unique_set) {
        this->add(elem_key, func(elem_key));
    }
}


template<class key_t, class val_t>
void Shared_Objects<key_t, val_t>::remove(key_t key){
    this->shared_map.erase(key);
}

template<class key_t, class val_t>
template<typename Iterator>
void Shared_Objects<key_t, val_t>::remove(Iterator begin, Iterator end){
    for (Iterator it = begin; it != end; it++) {
        this->remove(*it);
    }
}

template<class key_t, class val_t>
bool Shared_Objects<key_t, val_t>::exists(key_t key){
    return this->shared_map.count(key);
}

template<class key_t, class val_t>
void Shared_Objects<key_t, val_t>::clear(){
    this->shared_map.clear();
}

template<class key_t, class val_t>
size_t Shared_Objects<key_t, val_t>::size(){
    return this->shared_map.size();
}

template<class key_t, class val_t>
bool Shared_Objects<key_t, val_t>::empty(){
    return this->shared_map.empty();
}

template<class key_t, class val_t>
val_t& Shared_Objects<key_t, val_t>::get(key_t key){
    return this->shared_map.at(key);
}

template<class key_t, class val_t>
template<typename Iterator>
std::set<key_t> Shared_Objects<key_t, val_t>::unique(Iterator begin, Iterator end){
    size_t size = std::distance(begin,end);
    std::set<key_t> unique_set;
    for( Iterator it = begin; it != end; it++) unique_set.insert( *it );
    return unique_set;
}
