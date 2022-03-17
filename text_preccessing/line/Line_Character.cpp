#include <iostream>
#include <Line_Character.hpp>

Line_Character::Line_Character(std::string& line, int index) : Character(line[index]){
    if(line.length() && !isLine(line)){
        std::clog << "ERROR: Text provided is not a line(not ending/starting with \n)";
        throw "Line provided is not valid line(has no \n or has multiple \n";
    }
    this->line_text = line;
}


bool Line_Character::isLine(std::string input_text){
    return this->isNewLineBeg() ^ this->isNewLineEnd();
}

bool Line_Character::isNewLine(){
    return this->current_char == L'\n';
}


bool Line_Character::isNewLineBeg(){
    return this->line_text[0] == L'\n';
}

bool Line_Character::isNewLineEnd(){
    return this->line_text[this->line_text.length()] == L'\n';
}

bool Line_Character::isEndLine(){
    return index == line_text.length() - 1;
}

