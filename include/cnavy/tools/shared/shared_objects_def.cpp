#include "shared_objects_decl.hpp"
#include <iterator>
#include <set>
#include <unordered_set>
#include "cassert"

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

template<class key_t, class val_t>
std::vector<key_t> 
Shared_Objects<key_t, val_t>::getKeys(){
    std::vector<key_t> keys;
    keys.reserve(this->shared_map.size());
    for(auto pair_obj : this->shared_map) keys.push_back(pair_obj.first);
    return keys;
}

template<class key_t, class val_t>
std::vector<val_t> Shared_Objects<key_t, val_t>::getValues(){
    std::vector<val_t> values;
    values.reserve(this->shared_map.size());
    for(auto pair_obj : this->shared_map) values.push_back(pair_obj.second);
    return values;
}



// iterator methods
template<class key_t, class val_t>
typename std::unordered_map<key_t, val_t>::iterator 
Shared_Objects<key_t, val_t>::begin(){ return this->shared_map.begin(); };

template<class key_t, class val_t>
typename std::unordered_map<key_t, val_t>::iterator 
Shared_Objects<key_t, val_t>::end() { return this->shared_map.end(); }

template<class key_t, class val_t>
typename  std::unordered_map<key_t, val_t>::const_iterator 
Shared_Objects<key_t, val_t>::cbegin() const { return this->shared_map.begin(); }

template<class key_t, class val_t>
typename std::unordered_map<key_t, val_t>::const_iterator 
Shared_Objects<key_t, val_t>::cend() const { return this->shared_map.end(); }

template<class key_t, class val_t>
typename std::unordered_map<key_t, val_t>::const_iterator 
Shared_Objects<key_t, val_t>::begin() const { return this->shared_map.begin(); }

template<class key_t, class val_t>
typename std::unordered_map<key_t, val_t>::const_iterator 
Shared_Objects<key_t, val_t>::end() const { return this->shared_map.end(); }


// method overiding
template<class key_t, class val_t>
val_t& Shared_Objects<key_t, val_t>::operator[](key_t key) { return this->shared_map.at(key); }

template<class key_t, class val_t>
Shared_Objects<key_t, val_t> Shared_Objects<key_t, val_t>::operator+(Shared_Objects<key_t, val_t> other){
    for(auto pair_obj : this->shared_map){
        other.add(pair_obj.first, pair_obj.second);
    };
    return other;
}

template<class key_t, class val_t>
bool Shared_Objects<key_t, val_t>::operator==(Shared_Objects<key_t, val_t>& other){
    return this->shared_map == other.shared_map;
};

template<class key_t, class val_t>
bool Shared_Objects<key_t, val_t>::operator!=(Shared_Objects<key_t, val_t>& other){
    return this->shared_map != other.shared_map;
};


template <typename key_ft, typename val_ft>
std::ostream& operator<<( std::ostream& out_stream, const Shared_Objects<key_ft, val_ft>& shared_obj){
    for(auto pair_obj : shared_obj->shared_map) out_stream << pair_obj.first << std::endl;
    return out_stream;
}
