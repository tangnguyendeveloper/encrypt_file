
#include <iostream>
#include "libs/find_files.hpp"

int main() {
    const std::filesystem::path directory = "/home/tangdev/test/VLCPredict";
    FindFiles finder = FindFiles(directory);
    const std::vector<std::filesystem::path> list_files = finder.FindRegular().Files();
    const std::vector<std::filesystem::path> list_files_py = finder.FindRegularWithExtensions(
        {".py", ".pyd", ".pyc"}
    ).Files();
    const std::vector<std::filesystem::path> list_files_cc = finder.FindRegularWithExtensions(
        {".c", ".cpp", ".h", ".hpp"}
    ).Files();
    const std::vector<std::filesystem::path> list_files_hidden = finder.FindHiddenFiles().Files();

    //for (const std::filesystem::path& entry : list_files) std::cout << entry  << std::endl; 
    std::cout << "Total files: " << list_files.size() << std::endl; 
    std::cout << "Python files: " << list_files_py.size() << std::endl; 
    std::cout << "C/C++ files: " << list_files_cc.size() << std::endl; 
    std::cout << "Hidden files: " << list_files_hidden.size() << std::endl; 
    return 0;
}


