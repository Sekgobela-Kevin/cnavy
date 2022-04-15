#include "raw_token.hpp"
#include <cassert>
#include <iostream>

// define static shared_char_objs
// removing this line will cause "undefined reference to `Raw_Token::shared_char_objs"
Raw_Token::shared_char_t Raw_Token::shared_char_objs = shared_char_t();

void Raw_Token::setAttrs(Characters& chars_obj){

        // booleans representing if corresponding character is alphanumeric
        this->bool_is_alnum = Bool_Characters::isAlnum(chars_obj);
        // booleans representing if corresponding character is alphabetic
        this->bool_is_alpha = Bool_Characters::isAlpha(chars_obj);
        // booleans representing if corresponding character is ascii
        this->bool_is_ascii = Bool_Characters::isASCII(chars_obj);
        // booleans representing if corresponding character is blank
        this->bool_is_blank = Bool_Characters::isBlank(chars_obj);
        // booleans representing if corresponding character is control character
        this->bool_is_cntrl = Bool_Characters::isCntrl(chars_obj);
        // booleans representing if corresponding character is digit
        this->bool_is_digit = Bool_Characters::isDigit(chars_obj);
        // booleans representing if corresponding character is graphical
        this->bool_is_graph = Bool_Characters::isGraph(chars_obj);
        // booleans representing if corresponding character is in lowercase
        this->bool_is_lower = Bool_Characters::isLower(chars_obj);
        // booleans representing if corresponding character is printable
        this->bool_is_print = Bool_Characters::isPrint(chars_obj);
        // booleans representing if corresponding character is punctuation
        this->bool_is_punct = Bool_Characters::isPunct(chars_obj);
        // booleans representing if corresponding character is space
        this->bool_is_space = Bool_Characters::isSpace(chars_obj);
        // booleans representing if corresponding character is in uppercase
        this->bool_is_upper = Bool_Characters::isUpper(chars_obj);
        // booleans representing if corresponding character is hexadecial digit
        this->bool_is_xdigit = Bool_Characters::isXdigit(chars_obj);

        // ratio characters

        // proportion/ratio of alphanumeric characters in token
        // not worth to use ratio characters while bool characters already calculated
        // the methods individually calls getBoolRatio() to interact with Bool_Characters
        // directly calling Ratio_Characters::getBoolRatio() will improve performance
        this->ratio_is_alnum = Ratio_Characters::isAlnum(chars_obj);
        // proportion/ratio of alphabetic characters in token
        this->ratio_is_alpha = Ratio_Characters::isAlpha(chars_obj);
        // proportion/ratio of ascii characters in token
        this->ratio_is_ascii = Ratio_Characters::isASCII(chars_obj);
        // proportion/ratio of blank characters in token
        this->ratio_is_blank = Ratio_Characters::isBlank(chars_obj);
        // proportion/ratio of control characters in token
        this->ratio_is_cntrl = Ratio_Characters::isCntrl(chars_obj);
        // proportion/ratio of digits in token
        this->ratio_is_digit = Ratio_Characters::isDigit(chars_obj);
        // proportion/ratio of graphical characters in token
        this->ratio_is_graph = Ratio_Characters::isGraph(chars_obj);
        // proportion/ratio of lowercase characters in token
        this->ratio_is_lower = Ratio_Characters::isLower(chars_obj);
        // proportion/ratio of printable characters in token
        this->ratio_is_print = Ratio_Characters::isPrint(chars_obj);
        // proportion/ratio of punctuation characters in token
        this->ratio_is_punct = Ratio_Characters::isPunct(chars_obj);
        // proportion/ratio of space characters in token
        this->ratio_is_space = Ratio_Characters::isSpace(chars_obj);
        // proportion/ratio of uppercase characters in token
        this->ratio_is_upper = Ratio_Characters::isUpper(chars_obj);
        // proportion/ratio of hexadecimal digits in token
        this->ratio_is_xdigit = Ratio_Characters::isXdigit(chars_obj);

        // summary characters(using ratio of 1)

        // checks if token is alphanumeric
        // to save memory, this attributes can be removed
        // method versions of it can be used
        // just included to simplify accessing attributes of object
        this->is_alnum = this->isAlnum();
        // checks if token is alphabetic
        this->is_alpha = this->isAlpha();
        // checks if token is ascii
        this->is_ascii = this->isAscii();
        // checks if token is blank
        this->is_blank = this->isBlank();
        // checks is made of control characters
        this->is_cntrl = this->isCntrl();
        // checks if token is digit
        this->is_digit = this->isDigit();
        // checks if token has all characters being graphical characters
        this->is_graph = this->isGraph();
        // checks if token is in lowercase
        this->is_lower = this->isLower();
        // checks if token has all characters being printable
        this->is_print = this->isPrint();
        // checks if token has all characters being punctuations
        this->is_punct = this->isPunct();
        // checks if token all characters are space character
        this->is_space = this->isSpace();
        // checks if token his in uppercase
        this->is_upper = this->isUpper();
        // checks if token has all characters are hexadecimal digits
        this->is_xdigit = this->isXdigit();

        // token text
        this->text = chars_obj.getText();   
        // lowercase verstion of token
        this->lower = chars_obj.getLower();
        // uppercase version of token
        this->upper = chars_obj.getUpper();
        // length of token
        this->length = text.length();   
}

Raw_Token::Raw_Token(Characters chars_obj){
    /**
     * creates object from Characters object
     * only text of character object is neccessay
     */
    // extract text from Characters object
    std::string obj_text = chars_obj.getText();
    // call another constructor
    // this will handle everything
    Raw_Token(chars_obj.getText());
};

Raw_Token::Raw_Token(std::string input_text){
    std::cout << "Raw_Token(std::string input_text)\n" << std::endl;
    /**
     * Creates Raw_Token object from string
     * No dependence from Characters object 
     * Character objects are shared but Characters object not.
     * Characters objects get created dynamically
    */

    // creates needed character objects in shared object
    // shared object will take care of everything
    std::cout << "add to shared" << std::endl;
    Raw_Token::shared_char_objs.add(input_text.begin(), input_text.end());
    std::cout << "finished adding to shared\n" << std::endl;
    character_objs_ref.reserve(input_text.size());
    std::cout << "looping string" << std::endl;
    for(char_type char_ : input_text){
        // retrieve corresponding character object from shared objects
        // time complexity not measured but expect constant time
        Character& char_obj = Raw_Token::shared_char_objs.get(char_);
        // store reference of character object locally from shared object
        character_objs_ref.push_back(char_obj);
    }
    std::cout << "finished looping string\n" << std::endl;
    std::cout << "getting char objects" << std::endl;
    // get copy version of char_objs
    // turns vector<std::reference_wrapper<Character>> to vector<Character>
    std::vector<Character> char_objs = this->getCharObjs(character_objs_ref);
    std::cout << "finished getting char objects\n" << std::endl;
    std::cout << "creating chars object" << std::endl;
    // create characters object to be used temporary
    // creating characters object from char_objs is faster than from string
    // character objects get reused which makes it faster than creating new ones everytime
    Characters chars_obj_ = Characters(char_objs);
    std::cout << "finished getting chars objs\n" << std::endl;
    // set object(this) attributes from character object
    // this method can be slow as it performs calculations on character object
    this->setAttrs(chars_obj_);
    std::cout << "finished Raw_Token(std::string input_text)" << std::endl;
}

std::vector<Character> Raw_Token::getCharObjs(Raw_Token::vector_ref_t char_objs_ref){
    std::vector<Character> char_objs;
    char_objs.reserve(char_objs_ref.size());
    for(auto char_obj_ref : char_objs_ref){
        char_objs.push_back(char_obj_ref.get());
    }
    return char_objs;
}

bool Raw_Token::isAlnum(float true_ratio) const{
    return Summary_Characters::ratioCompare(true_ratio, this->ratio_is_alpha);
}

bool Raw_Token::isAlpha(float true_ratio) const{
    return Summary_Characters::ratioCompare(true_ratio, this->ratio_is_alpha);
}

bool Raw_Token::isAscii(float true_ratio) const{
    return Summary_Characters::ratioCompare(true_ratio, this->ratio_is_ascii);
}

bool Raw_Token::isBlank(float true_ratio) const{
    return Summary_Characters::ratioCompare(true_ratio, this->ratio_is_blank);
}

bool Raw_Token::isCntrl(float true_ratio) const{
    return Summary_Characters::ratioCompare(true_ratio, this->ratio_is_cntrl);
}

bool Raw_Token::isDigit(float true_ratio) const{
    return Summary_Characters::ratioCompare(true_ratio, this->ratio_is_digit);
}

bool Raw_Token::isGraph(float true_ratio) const{
    return Summary_Characters::ratioCompare(true_ratio, this->ratio_is_graph);
}

bool Raw_Token::isLower(float true_ratio) const{
    return Summary_Characters::ratioCompare(true_ratio, this->ratio_is_lower);
}

bool Raw_Token::isPrint(float true_ratio) const{
    return Summary_Characters::ratioCompare(true_ratio, this->ratio_is_print);
}

bool Raw_Token::isPunct(float true_ratio) const{
    return Summary_Characters::ratioCompare(true_ratio, this->ratio_is_punct);
}

bool Raw_Token::isSpace(float true_ratio) const{
    return Summary_Characters::ratioCompare(true_ratio, this->ratio_is_space);
}

bool Raw_Token::isUpper(float true_ratio) const{
    return Summary_Characters::ratioCompare(true_ratio, this->ratio_is_upper);
}

bool Raw_Token::isXdigit(float true_ratio) const{;
    return Summary_Characters::ratioCompare(true_ratio, this->ratio_is_xdigit);
}
