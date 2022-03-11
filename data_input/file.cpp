#include <assert.h>
#include <iostream>
#include "file.hpp"

File::File(string title_, string source_, bool binary_mode) : Input(title_, "file", source_){
    if(!isSourceValid(source_)){
        std::cerr << "File in source: " << source << " path is invalid or does not exist";
        exit(EXIT_FAILURE);
    }
    open(source_, binary_mode);
};

bool File::open(string path, bool binary_mode){
    if (!isOpen()){
        if(binary_mode){
            fileStream.open(path, std::fstream::in | std::ios::binary);
        }
        else{
            fileStream.open(path, std::fstream::in);
        }
    }
    return isOpen();
}

bool File::isOpen(){
    return fileStream.is_open();
}

string File::read(string path){
    /* Helped by: https://www.delftstack.com/howto/cpp/read-file-into-string-cpp/
    On 2022 March 05*/
    if (!isOpen()) {
        cerr << "File not yet opened: " << source << "'" << endl;
        exit(EXIT_FAILURE);
    }
    // Changes cursor pos to the begining
    fileStream.seekg (0, fileStream.beg);
    return string((std::istreambuf_iterator<char>(fileStream)), std::istreambuf_iterator<char>());
}

void File::close(){
    fileStream.close();
    assert(!isOpen());
}


bool File::isSourceActive(string path){
    std::fstream fs;
    fs.open (path, std::fstream::in);
    fs.close();
    return fs.good();
};

string File::fetchData(string path){
    return read(path);
};


bool File::isSourceValid(string path){
    // Should validate path without opening
    // Currently I have no way of doing it as file paths have lot of exceptions
    return isSourceActive(path);
};

bool File::remove(){
    return std::remove(source.c_str());
}

