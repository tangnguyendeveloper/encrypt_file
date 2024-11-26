#include "../libs/find_files.hpp"


FindFiles::FindFiles(const std::filesystem::path& directory) {
    this->directory = directory;
}

FindFiles& FindFiles::FindRegular(){
    this->list_files.clear();
    for (const std::filesystem::directory_entry& entry : std::filesystem::recursive_directory_iterator(this->directory)) {
        if (std::filesystem::is_regular_file(entry)) {
            list_files.emplace_back(entry.path());
        }
    }
    return *this;
}

FindFiles& FindFiles::FindRegularWithExtensions(const std::vector<std::string>& extensions){
    this->list_files.clear();
    for (const std::filesystem::directory_entry& entry : std::filesystem::recursive_directory_iterator(this->directory)) {
        if (std::filesystem::is_regular_file(entry) && std::find(extensions.begin(), extensions.end(), entry.path().extension()) != extensions.end()) {
            list_files.emplace_back(entry.path());
        }
    }
    return *this;
}

FindFiles& FindFiles::FindHiddenFiles(){
    this->list_files.clear();
    for (const std::filesystem::directory_entry& entry : std::filesystem::recursive_directory_iterator(this->directory)) {
        if (entry.path().filename().string().at(0) == '.' && !entry.is_directory()) {
            list_files.emplace_back(entry.path());
        }
    }
    return *this;
}