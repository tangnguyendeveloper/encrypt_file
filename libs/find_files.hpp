#ifndef FIND_FILES_HPP_ 
#define FIND_FILES_HPP_ 

#include <filesystem>
#include <vector>
#include <algorithm>


class FindFiles {
    private:
    std::vector<std::filesystem::path> list_files;
    std::filesystem::path directory;

    public:
    FindFiles(const std::filesystem::path& directory);

    FindFiles& FindRegular();
    FindFiles& FindRegularWithExtensions(const std::vector<std::string>& extensions);
    FindFiles& FindHiddenFiles();
    
    inline const std::vector<std::filesystem::path>& Files() const {return this->list_files;}


};


#endif /* FIND_FILES_HPP_ */