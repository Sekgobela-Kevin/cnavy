#include <list>
#include <unordered_map>
#include <string>
#include "resource.hpp"

class Resources{
    private:
        /**
         * @brief represents total number of resources
         * 
         */
        int total;
        /**
         * @brief convert list of maps with resources data into list of resources
         * 
         * @param importData list of maps with resources data
         * @return list<Resource> 
         */
        list<Resource> importsToResourcesObjs(list<unordered_map<string, string>> importData);
    list<Resource> resourcesObjs;
    public:
        /**
         * @brief Construct a new Resources empty object
         * 
         */
        Resources();
        /**
         * @brief Construct a new Resources object from list of resourses exported data
         * 
         * @param resourcesList 
         */
        Resources(list<unordered_map<string, string>> resourcesExportedData);
        /**
         * @brief Construct a new Resources object from list of containing resources objects
         * 
         * @param resourcesList 
         */
        Resources(list<Resource> resourcesList);
        /**
         * @brief removes resource
         * 
         * @param resourceObj
         */
        void remove(Resource resourceObj);
        /**
         * @brief removes resource
         * 
         * @param title 
         */
        void remove(string title);
        /**
         * @brief add resource
         * 
         */
        void add(Resource resourceObj);
        /**
         * @brief clears all reasources
         * 
         */
        void clear();
        /**
         * @brief checks resourses list is empty
         * @return bool
        */
        bool isEmpty();
        /**
         * @brief Get the types associated with resources
         * 
         * @return list<string> 
         */
        list<string> getTypes();
        /**
         * @brief Get the titles of resources
         * 
         * @return list<string> 
         */
        list<string> getTitles();
        /**
         * @brief Get the body(full text) of resources
         * 
         * @return list<string> 
         */
        list<string> getBodies();
        /**
         * @brief checks for existance of resources using the object
         * 
         * @param resourceObj 
         * @return true 
         * @return false 
         */
        bool exists(Resource resourceObj);
        /**
         * @brief checks for existance of resources using its title
         * 
         * @param title
         * @return true 
         * @return false 
         */
        bool exists(string title);
        /**
         * @brief returns actual resource object from its title
         * 
         * @param title 
         * @return Resource 
         */
        Resource get(string title);
        /**
         * @brief retrieves number of resources in the object
         * 
         * @return int 
         */
        int getTotal();
        /**
         * @brief total resources during initilization.\n
         * The return value is >= current total value which can calculate with this->getTotal().
         * 
         * @return int 
         */
        int getInitialTotal();
        /**
         * @brief releases memory occupied by resources(Resource class) objects
         * 
         */
        void deleteRef();
        /**
         * @brief test if resources in the list are pointers or actual objects. Method may soon
         * go out of date since all elements will be pointer after re-implementation.
         * 
         * @return true if contain pointers pointing to Resource Class instances
         * @return false if its actual object of Resource Class
         */
        bool isPointers();
        /**
         * @brief returns the list with resources objects(copy of original)
         * 
         * @return list<Resource>
         */
        list<Resource> getResourcesObjs();
        /**
         * @brief turns resources objects into maps using .exportData() of the objects
         * 
         * @return list<unordered_map<string, string>> 
         */
        list<unordered_map<string, string>> exportData();

};