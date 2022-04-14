#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include "input.hpp"

/*
Base class for all input file Classes. This calss can be implemeted by classes for PDF, DOC, TXT, etc. It 
containes basic methods for reading files and then storing the data with methods for extractiong
text data from files.

* @param title_ 
* @param source_ 
* @param binary_mode true if file opened in binary mode(default false)
*/
class File:public Input{

    public:
        /**
         * @brief file input stream object for handling file operations
         */
        std::ifstream fileStream;

    public:
        /**
         * @brief Construct a new File object
         * 
         * @param title_ 
         * @param source_ 
         * @param binary_mode true if file opened in binary mode(default false)
         */
        File(string title_, string source_, bool binary_mode=false);
        /**
         * @brief extract raw data from its source 
         * @param path path to file
         * @return string bodyText in its raw form e.g HTML
         */
        virtual string fetchData(string path);
        /**
         * @brief converts data(binary, html, etc) into plain clean natuaral language text
         * 
         * @param data data from the source
         * @return string 
         */
        //virtual string dataToText(string data);
        /**
         * @brief checks if the source is valid based on its structure
         * 
         * @param path
         * @return string 
         */
        bool isSourceValid(string path);
        /**
         * @brief checks if source is active meaning data can be accessed on demand(not guaranteed)
         * 
         * @param path 
         * @return string 
         */
        bool isSourceActive(string path);
        /**
         * @brief opens file in this->source
         * @param path 
         */
        bool open(string path, bool binary_mode);
        /**
         * @brief closes file in this->source
         * 
         */
        void close();
        /**
         * @brief checks if file is currently open
         * 
         * @param path
         * @return true 
         * @return false 
         */
        bool isOpen();
        /**
         * @brief reads all string data from file. This is not reccommendaded for memory capacity reasons.
         * @param path
         * @return string 
         */
        string read(string path);
        /**
         * @brief remove file in path(source)
         * 
         * @return true 
         * @return false 
         */
        virtual bool remove();
        
};