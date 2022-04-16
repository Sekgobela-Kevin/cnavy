#include "raw_tokenise_decl.hpp"
#include <iterator>
#include <cassert>

// Define static shared_chars_objs
// This is shared object for tokens using Raw_Tokenise class
template<class char_class, class chars_class>
typename Raw_Tokenise<char_class, chars_class>::shared_chars_objs_t 
Raw_Tokenise<char_class, chars_class>::shared_chars_objs = shared_chars_objs_t ();

template<class char_class, class chars_class>
Raw_Tokenise<char_class, chars_class>::Raw_Tokenise(std::string text){
    this->text = text;
    this->chars_objs_ref = this->createTokens(this->text, [this](char_type c){
        return this->isBreakChar(c);
    });
}

template<class char_class, class chars_class>
Raw_Tokenise<char_class, chars_class>::Raw_Tokenise(std::string text, std::function<bool(char_type)> func){
    this->text = text;
    this->chars_objs_ref = this->createTokens(text, func);
}

template<class char_class, class chars_class>
std::string Raw_Tokenise<char_class, chars_class>::getText(chars_class chars_obj){
    return chars_obj.text;
}

template<class char_class, class chars_class>
bool Raw_Tokenise<char_class, chars_class>::isBreakChar(char_type char_){
    chars_class::shared_char_objs.add(char_);
    return !chars_class::shared_char_objs.get(char_).is_alnum;
}


template<class char_class, class chars_class>
std::vector<std::string> 
Raw_Tokenise<char_class, chars_class>::splitText(std::string& input_text, std::function<bool(char_type)> func){
    size_t size = input_text.size();
    std::vector<std::string> text_tokens;
    // try to predict size of resulting tokens
    unsigned int pred_tok_size = (int)(size/5);
    text_tokens.reserve(pred_tok_size);
    // start index of possible text token
    unsigned int start_index = 0;
    for (size_t i = 0; i < size; i++)
    {
        bool is_break_char = func(input_text[i]);
        if(is_break_char){
            // get token before this break character
            // i-start_index is less that i by 1
            // its hard to work with numbers especiallly indexes to strings
            std::string token_text = input_text.substr(start_index, i-start_index);
            if(!token_text.empty()){
                // push back token before break charcter
                text_tokens.push_back(token_text);
            }
            // push back also the break character
            text_tokens.push_back(input_text.substr(i, 1));
            start_index = i+1;
        }
        // get characters from start_index to end of text if end of text is reached
        // its already known that the character is break character
        else if (i==size-1)
        {
            // turn i-start_index to i-start_index+1 to include current character
            std::string token_text = input_text.substr(start_index, i-start_index+1);
            // check if token_text not empty(not allowed)6
            if(!token_text.empty()){
                text_tokens.push_back(token_text);
            }
        }
        
    }
    // shrink down to save memory in case pred_tok_size was wrong
    text_tokens.shrink_to_fit();
    return text_tokens;
}

template<class char_class, class chars_class>
typename Raw_Tokenise<char_class, chars_class>::chars_coll_t
Raw_Tokenise<char_class, chars_class>::createTokens(std::string& input_text, std::function<bool(char_type)> func){
    // add character objects to shared object chars_class
    // shared object for character object is stored as static variable in chars_class
    // chars_class is expected to use shared object which is stored as static variable
    chars_class::shared_char_objs.add(input_text.begin(), input_text.end());
    // extract tokens in string form
    std::vector<std::string> text_tokens = this->splitText(input_text, func);
    // create characters objects from the tokens in corresponding shared object
    this_t::shared_chars_objs.add(text_tokens.begin(), text_tokens.end());

    // declare vector of references to tokens in shared object(this->shared_chars_objs)
    chars_coll_t chars_objs_ref;
    // reserve memory to improve performance
    chars_objs_ref.reserve(text_tokens.size());
    
    // iterate through text tokens and use each as key to shared objects
    for (auto it = text_tokens.begin(); it != text_tokens.end(); it++) {
        // access characters object from shared object and store reference to it
        // *it is key to corresponding object
        chars_objs_ref.push_back(this_t::shared_chars_objs.get(*it));
    }
    chars_objs_ref.shrink_to_fit();
    return chars_objs_ref;
};




// iterator methods
template<class char_class, class chars_class>
typename Raw_Tokenise<char_class, chars_class>::chars_coll_t::iterator 
Raw_Tokenise<char_class, chars_class>::begin(){ return this->chars_objs_ref.begin(); }

template<class char_class, class chars_class>
typename Raw_Tokenise<char_class, chars_class>::chars_coll_t::iterator 
Raw_Tokenise<char_class, chars_class>::end() { return this->chars_objs_ref.end(); }

template<class char_class, class chars_class>
typename  Raw_Tokenise<char_class, chars_class>::chars_coll_t::const_iterator 
Raw_Tokenise<char_class, chars_class>::cbegin() const { return this->chars_objs_ref.begin(); }

template<class char_class, class chars_class>
typename Raw_Tokenise<char_class, chars_class>::chars_coll_t::const_iterator 
Raw_Tokenise<char_class, chars_class>::cend() const { return this->chars_objs_ref.end(); }

template<class char_class, class chars_class>
typename Raw_Tokenise<char_class, chars_class>::chars_coll_t::const_iterator 
Raw_Tokenise<char_class, chars_class>::begin() const { return this->chars_objs_ref.begin(); }

template<class char_class, class chars_class>
typename Raw_Tokenise<char_class, chars_class>::chars_coll_t::const_iterator 
Raw_Tokenise<char_class, chars_class>::end() const { return this->chars_objs_ref.end(); }


// method overiding
template<class char_class, class chars_class>
typename Raw_Tokenise<char_class, chars_class>::chars_ref_t& 
Raw_Tokenise<char_class, chars_class>::operator[](size_t index) { return this->chars_objs_ref[index]; }

template<class char_class, class chars_class>
Raw_Tokenise<char_class, chars_class> 
Raw_Tokenise<char_class, chars_class>::operator+(Raw_Tokenise<char_class, chars_class>& other){
    std::string concat_text = this->text + other.text;
    return Raw_Tokenise<char_class, chars_class>(concat_text);
}

template<class char_class, class chars_class>
bool Raw_Tokenise<char_class, chars_class>::operator==(Raw_Tokenise<char_class, chars_class>& other){
    return this->text == other.text;
};


template<class char_class, class chars_class>
bool Raw_Tokenise<char_class, chars_class>::operator!=(Raw_Tokenise<char_class, chars_class>& other){
    return this->text != other.text;
};

template<class char_class, class chars_class>
bool Raw_Tokenise<char_class, chars_class>::operator==(std::string& other){
    return this->text == other;
}

template<class char_class, class chars_class>
bool Raw_Tokenise<char_class, chars_class>::operator!=(std::string& other){
    return this->text != other;
}

template<class char_class, class chars_class>
bool Raw_Tokenise<char_class, chars_class>::operator==(const char* other){
    return this->text == other;
}

template<class char_class, class chars_class>
bool Raw_Tokenise<char_class, chars_class>::operator!=(const char* other){
    return this->text != other;
}

template <typename char_class_t, typename chars_class_t>
std::ostream& operator<<( std::ostream& out_stream, const Raw_Tokenise<char_class_t, chars_class_t>& token_obj){
    out_stream << token_obj.text << std::endl;
    return out_stream;
}

