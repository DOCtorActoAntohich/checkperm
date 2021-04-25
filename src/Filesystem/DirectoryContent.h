#ifndef DIRECTORY_CONTENT_FINDER_H_INCLUDED
#define DIRECTORY_CONTENT_FINDER_H_INCLUDED

#include <vector>
#include <filesystem>

class DirectoryContent {
    using path_t = std::filesystem::path;
public:
    static std::vector<path_t> getAll(const path_t& source);
    static std::vector<path_t> getAllRecursively(const path_t& source);
private:
    DirectoryContent();
};

#endif // !DIRECTORY_CONTENT_FINDER_H_INCLUDED