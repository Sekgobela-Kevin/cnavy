#include <cassert>
#include <iostream>
#include <string>
#include <assert.h>
#include "file.hpp"

/* 
Class for reading and working with text files. It is an derived of File Class of which
is also derived class of Input class. It has purpose of extracting data from text which will
be converted to resources objects by other objects.
*/
class File_Text : public File{

    public:
        using File::File;
        /**
         * @brief converts file data to string(implemeted by subclasses of files).
         * Since .txt files contain text data, theres no need for conversion
         * 
         * @param data 
         * @return string 
         */
        string dataToText(string data){
            return data;
        };
};
