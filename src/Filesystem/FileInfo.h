#ifndef FILESYSTEM_FILE_INFO_H_INCLUDED
#define FILESYSTEM_FILE_INFO_H_INCLUDED

#include <string>
#include <filesystem>

// Up-to-date only when created!
// Use it only when
class FileInfo {
public:
    FileInfo(const std::filesystem::path& path);

    const std::filesystem::path& path() const;
    const std::string& owner() const;
    const std::string& group() const;

    bool isOwner(const std::string& owner) const;
    bool isGroup(const std::string& group) const;
    bool hasPermission(std::filesystem::perms permission) const;

private:
    std::filesystem::path m_path;

    std::string m_owner;
    std::string m_group;

    std::filesystem::perms m_perms;
};

#endif // !FILESYSTEM_FILE_INFO_H_INCLUDED