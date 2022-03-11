#include <cassert>
#include <iostream>
#include <string>
#include <assert.h>
#include "../file.hpp"

/* 
Subclass of FIle CLass that implemets dataToText() for purpose of testing.
dataToText() is pure virtual method not implemeted by File method
*/
class File_Sample : public File{

    public:
        using File::File;
        /**
         * @brief converts file data to string(implemeted by subclasses of files).
         * Since this for testing with txt file, it doesnt do anything with file data.
         * 
         * @param data 
         * @return string 
         */
        string dataToText(string data){
            return data;
        };
};


void File_Test(){
    // Prepare for a test file for testing

    std::ofstream fs;
    string filePath = "test.txt";
    string writeData = "This will be written to file";
    fs.open (filePath);
    fs << writeData;
    fs.close();
    

    // Actual testing start here
    File_Sample obj = File_Sample("something to print", filePath, true);
    string readData = obj.read(filePath);
    assert(obj.isSourceValid(filePath));
    assert(obj.isSourceActive(filePath));
    assert(obj.isOpen());
    assert(obj.isLoaded() == false);
    assert(obj.isSourceActive(filePath));
    assert(readData == writeData);
    assert(obj.fetchData(filePath) == writeData);
    assert(obj.getData()["body"] == "");
    //assert(obj.getData() == {})

    // Change state of object
    assert(obj.requestData());
    assert(obj.requestData() == false);
    assert(obj.requestData(true));
    assert(obj.isLoaded());
    assert(obj.getData()["body"] == writeData);
    assert(obj.getData()["type"] == "file");
    assert(obj.getData()["source"] == filePath);


    
    // files closing test
    obj.close();
    obj.remove();
    assert(obj.isSourceActive(filePath) == false);
    assert(obj.isOpen() == false);
    clog << "File class passed tests successfully";
}

int main(){
    File_Test();
}