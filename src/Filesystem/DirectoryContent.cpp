#include "DirectoryContent.h"

#include <queue>

DirectoryContent::DirectoryContent()
{ }


using path_t = std::filesystem::path;


std::vector<path_t> DirectoryContent::getAll(const path_t& source) {
    std::vector<path_t> contents;
    try {
        if ((source.string().find("/sys") == 0) || (source.string().find("/proc") == 0)) {
            throw "Wait, that's illegal.";
        }
        for (const auto& entry : std::filesystem::directory_iterator(source)) {
            if (!std::filesystem::is_symlink(entry)) {
                contents.push_back(entry);
            }
        }
    }
    catch (...) { } // In case that directory can't open, it's ignored.
    return contents;
}


std::vector<path_t> DirectoryContent::getAllRecursively(const path_t& source) {
    std::vector<path_t> contents;

    std::queue<path_t> dirsToCheck;
    dirsToCheck.push(source);

    while (!dirsToCheck.empty()) {
        auto dir = dirsToCheck.front();
        dirsToCheck.pop();

        auto localContents = DirectoryContent::getAll(dir);
        if (localContents.size() == 0) {
            contents.push_back(dir);
            continue;
        }
        for (auto& path : localContents) {
            if (std::filesystem::is_directory(path)) {
                dirsToCheck.push(path);
            }
            else {
                contents.push_back(path);
            }
        }
    }

    return contents;
}