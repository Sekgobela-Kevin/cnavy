#include "doctest.h"
#include "file.hpp"

#include <string>


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

/* called to enable testing */
void Enable_Doctest_Crawl_File(){
    printf("Enable_Doctest_File()");
};


TEST_CASE("crawler files test"){
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
    CHECK(obj.isSourceValid(filePath));
    CHECK(obj.isSourceActive(filePath));
    CHECK(obj.isOpen());
    CHECK(obj.isLoaded() == false);
    CHECK(obj.isSourceActive(filePath));
    CHECK(readData == writeData);
    CHECK(obj.fetchData(filePath) == writeData);
    CHECK(obj.getData()["body"] == "");
    //CHECK(obj.getData() == {})

    // Change state of object
    CHECK(obj.requestData());
    CHECK(obj.requestData() == false);
    CHECK(obj.requestData(true));
    CHECK(obj.isLoaded());
    CHECK(obj.getData()["body"] == writeData);
    CHECK(obj.getData()["type"] == "file");
    CHECK(obj.getData()["source"] == filePath);


    
    // files closing test
    obj.close();
    obj.remove();
    CHECK(obj.isSourceActive(filePath) == false);
    CHECK(obj.isOpen() == false);
}