#include "FileInfo.h"

#include <tuple>
#include <exception>
#include <iostream>

#include <pwd.h>
#include <grp.h>
#include <sys/stat.h>

std::tuple<std::string, std::string>
getOwnerAndGroup(const std::filesystem::path& file);



FileInfo::FileInfo(const std::filesystem::path& path)
    : m_path(path)
    , m_perms(std::filesystem::status(path).permissions())
{
    std::tie(m_owner, m_group) = getOwnerAndGroup(path);
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

bool FileInfo::isOwner(const std::string& owner) const {
    return owner == m_owner;
}

bool FileInfo::isGroup(const std::string& group) const {
    return group == m_group;
}

bool FileInfo::hasPermission(std::filesystem::perms permission) const {
    return (m_perms & permission) != std::filesystem::perms::none;
}





#pragma region C Wrapper

std::tuple<std::string, std::string>
getOwnerAndGroup(const std::filesystem::path& file) {
    struct stat info;
    if (stat(file.c_str(), &info) != 0) {
        throw std::runtime_error("Cannot access file: " + file.string());
    }

    struct passwd* pw = getpwuid(info.st_uid);
    struct group*  gr = getgrgid(info.st_gid);

    return { pw->pw_name, gr->gr_name };
}


#pragma endregion