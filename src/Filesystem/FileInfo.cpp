#include "FileInfo.h"

#include <tuple>
#include <exception>
#include <iostream>

#include <pwd.h>
#include <grp.h>
#include <sys/stat.h>

std::tuple<std::string, std::string, int32_t>
getFileData(const std::filesystem::path& file);

std::tuple<Permission_v, Permission_v, Permission_v>
splitPermissionBits(int32_t permissionsBits);




FileInfo::FileInfo(const std::filesystem::path& path)
    : m_path(path)
{
    int32_t perms;
    std::tie(m_owner, m_group, perms) = getFileData(path);
    std::tie(m_ownerPerms, m_groupPerms, m_otherPerms) = splitPermissionBits(perms);
}


const std::filesystem::path& FileInfo::path() const {
    return m_path;
}

const std::string& FileInfo::owner() const {
    return m_owner;
}

const std::string& FileInfo::group() const {
    return m_group;
}

Permission_v FileInfo::ownerPermissions() const {
    return m_ownerPerms;
}
Permission_v FileInfo::groupPermissions() const {
    return m_groupPerms;
}
Permission_v FileInfo::otherPermissions() const {
    return m_otherPerms;
}

bool FileInfo::checkOwnerPermissions(const std::string& user, Permission_v permission) const {
    return user == m_owner && ownerPermissions() & permission;
}

bool FileInfo::checkGroupPermissions(const std::string& group, Permission_v permission) const {
    return group == m_group && groupPermissions() & permission;
}

bool FileInfo::checkOtherPermissions(Permission_v permission) const {
    return otherPermissions() & permission;
}




#pragma region C Wrapper

std::tuple<std::string, std::string, int32_t>
getFileData(const std::filesystem::path& file) {
    struct stat info;
    if (stat(file.c_str(), &info) != 0) {
        throw std::runtime_error("Cannot access file: " + file.string());
    }

    struct passwd *pw = getpwuid(info.st_uid);
    struct group*  gr = getgrgid(info.st_gid);
    int32_t permBits = info.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO);

    return { pw->pw_name, gr->gr_name, permBits };
}



std::tuple<Permission_v, Permission_v, Permission_v>
splitPermissionBits(int32_t permissionsBits) {
    // Groups order is preserved.
    Permission_v owner = (permissionsBits & S_IRWXU) >> 6;
    Permission_v group = (permissionsBits & S_IRWXG) >> 3;
    Permission_v other = (permissionsBits & S_IRWXO) >> 0;
    return { owner, group, other };
}

#pragma endregion