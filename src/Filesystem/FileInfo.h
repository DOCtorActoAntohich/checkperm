#ifndef FILESYSTEM_FILE_INFO_H_INCLUDED
#define FILESYSTEM_FILE_INFO_H_INCLUDED

#include <string>
#include <filesystem>

#include "Filesystem/Permission.h"

// Up-to-date only when created!
// Use it only when
class FileInfo {
public:
    FileInfo(const std::filesystem::path& path);

    const std::filesystem::path& path() const;
    const std::string& owner() const;
    const std::string& group() const;
    Permission_v ownerPermissions() const;
    Permission_v groupPermissions() const;
    Permission_v otherPermissions() const;

    bool checkOwnerPermissions(const std::string& user,  Permission_v p) const;
    bool checkGroupPermissions(const std::string& group, Permission_v p) const;
    bool checkOtherPermissions(Permission_v p) const;

private:
    std::filesystem::path m_path;

    std::string m_owner;
    std::string m_group;

    Permission_v m_ownerPerms;
    Permission_v m_groupPerms;
    Permission_v m_otherPerms;
};

#endif // !FILESYSTEM_FILE_INFO_H_INCLUDED