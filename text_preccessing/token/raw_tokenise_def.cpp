#include "raw_tokenise_decl.hpp"
#include <iterator>
#include <cassert>

template<class char_class, class chars_class>
Raw_Tokenise<char_class, chars_class>::Raw_Tokenise(std::string& text, 
Shared_Objects<char_type, char_class>& shared_char_objs,
Shared_Objects<std::string, chars_class>& shared_chars_objs) : 
    text(text),
    shared_char_objs(shared_char_objs),
    shared_chars_objs(shared_chars_objs){
    
    char_coll_t char_objects = this->createCharObjs(text);
    this->chars_objects = this->createCharsObjs(text, char_objects);
}

template<class char_class, class chars_class>
char_type Raw_Tokenise<char_class, chars_class>::getChar(char_class char_obj){
    return char_obj.char_;
}

template<class char_class, class chars_class>
std::string Raw_Tokenise<char_class, chars_class>::getText(chars_class chars_obj){
    return chars_obj.text;
}

template<class char_class, class chars_class>
bool Raw_Tokenise<char_class, chars_class>::isBreakChar(char_class char_obj){
    return !char_obj.is_alpha;
}


template<class char_class, class chars_class>
template<typename Iterator>
typename Raw_Tokenise<char_class, chars_class>::char_coll_t
Raw_Tokenise<char_class, chars_class>::createCharObjs(Iterator begin, Iterator end){
    // create character objects to be shared object
    shared_char_objs.add(begin, end);
    size_t size = std::distance(begin,end);
    // vector storing character objects
    char_coll_t char_objects;
    char_objects.reserve(size);

    for (Iterator it = begin; it != end; it++) {
        // access character object stored corresponsing shared object with key
        // *it is the key to corresponsing object
        char_objects.push_back(this->shared_char_objs.get(*it));
    }
    char_objects.shrink_to_fit();
    return char_objects;
};

template<class char_class, class chars_class>
typename Raw_Tokenise<char_class, chars_class>::char_coll_t
Raw_Tokenise<char_class, chars_class>::createCharObjs(std::string str){
    return this->createCharObjs<std::string::iterator>(str.begin(), str.end());
};

template<class char_class, class chars_class>
std::vector<std::string> 
Raw_Tokenise<char_class, chars_class>::splitText(std::string& text, char_coll_t& char_objects){
    // check char_objects was created from text based on length
    assert(text.size() == char_objects.size());
    size_t size = text.size();
    std::vector<std::string> text_tokens;
    // try to predict size of resulting tokens
    unsigned int pred_tok_size = (int)(size/5);
    text_tokens.reserve(pred_tok_size);
    // start index of possible text token
    unsigned int start_index = 0;
    for (size_t i = 0; i < size; i++)
    {
        bool is_break_char = this->isBreakChar(char_objects[i]);
        if(is_break_char){
            // get token before this break character
            // i-start_index is less that i by 1
            // its hard to work with numbers especiallly indexes to strings
            std::string token_text = text.substr(start_index, i-start_index);
            if(!token_text.empty()){
                // push back token before break charcter
                text_tokens.push_back(token_text);
            }
            // push back also the break character
            text_tokens.push_back(text.substr(i, 1));
            start_index = i+1;
        }
        // get characters from start_index to end of text if end of text is reached
        // its already known that the character is break character
        else if (i==size-1)
        {
            // turn i-start_index to i-start_index+1 to include current character
            std::string token_text = text.substr(start_index, i-start_index+1);
            // check if token_text not empty(not allowed)6
            if(!token_text.empty()){
                text_tokens.push_back(token_text);
            }
        }
        
    }
    // shrink down to save memory in case pred_tok_size was wrong
    char_objects.shrink_to_fit();
    return text_tokens;
}

template<class char_class, class chars_class>
typename Raw_Tokenise<char_class, chars_class>::chars_coll_t
Raw_Tokenise<char_class, chars_class>::createCharsObjs(std::string& text, char_coll_t& char_objects){
    // check char_objects was created from text based on length
    assert(text.size() == char_objects.size());
    // extract tokens in string form
    std::vector<std::string> text_tokens = this->splitText(text, char_objects);
    // create characters objects from the tokens in corresponding shared object
    shared_chars_objs.add(text_tokens.begin(), text_tokens.end());

    size_t size = char_objects.size();
    chars_coll_t chars_objects;
    chars_objects.reserve(text_tokens.size());
    
    // iterate through text tokens and use each as key to shared objects
    for (auto it = text_tokens.begin(); it != text_tokens.end(); it++) {
        // access characters object from shared object and store reference to it
        // *it is key to corresponding object
        chars_objects.push_back(this->shared_chars_objs.get(*it));
    }
    chars_objects.shrink_to_fit();
    return chars_objects;
};