#ifndef FILESYSTEM_DIRECTORY_CONTENT_FINDER_H_INCLUDED
#define FILESYSTEM_DIRECTORY_CONTENT_FINDER_H_INCLUDED

#include <vector>
#include <filesystem>

/**
 * @brief A class that can examine directories and find their contents.
 * 
 */
class DirectoryContent {
    using path_t = std::filesystem::path;
public:
    /**
     * @brief Gets all the contents in a given directory.
     * 
     * @param source A path to a directory to examine.
     * @return A list of all files/folders in the given directory.
     */
    static std::vector<path_t> getAll(const path_t& source);

    /**
     * @brief Gest all the contents in a given directory.
     * Recursively walks over all directories found inside.
     * @note This is basicalle breadth-first search.
     * 
     * @param source A path to a directory to examine.
     * @return A list of all files/folders in the given directory.
     */
    static std::vector<path_t> getAllRecursively(const path_t& source);
private:
    DirectoryContent();
};

#endif // !FILESYSTEM_DIRECTORY_CONTENT_FINDER_H_INCLUDED