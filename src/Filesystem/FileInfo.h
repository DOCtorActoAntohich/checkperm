#ifndef FILESYSTEM_FILE_INFO_H_INCLUDED
#define FILESYSTEM_FILE_INFO_H_INCLUDED

#include <string>
#include <filesystem>

/**
 * @brief A class that accesses file info.
 * @note It's up-to-date only when created!
 * Don't store it, use only once right when you need it.
 * 
 */
class FileInfo {
public:
    /**
     * @brief Collects information about the file.
     * 
     * @param path A path to a file.
     */
    FileInfo(const std::filesystem::path& path);

    /**
     * @brief Returns a path to the file.
     * 
     */
    const std::filesystem::path& path() const;
    /**
     * @brief Returns owner's name.
     * 
     */
    const std::string& owner() const;
    /**
     * @brief Returns group name.
     * 
     */
    const std::string& group() const;

    /**
     * @brief Checks if a given user owns this file.
     * 
     * @param owner User's name.
     * @return true if a user owns this file, false otherwise.
     */
    bool isOwner(const std::string& owner) const;
    /**
     * @brief Checks if a given group owns this file.
     * 
     * @param group Group's name.
     * @return true if a group owns this file, false otherwise.
     */
    bool isGroup(const std::string& group) const;

    /**
     * @brief Checks if a file has some permission(s).
     * 
     * @param permission Any combination of permissions (RWX)
     * for any users (owner, group, others).
     * @return true if a file has given permission(s), false otherwise.
     */
    bool hasPermission(std::filesystem::perms permission) const;

private:
    std::filesystem::path  m_path;
    std::filesystem::perms m_perms;

    std::string m_owner;
    std::string m_group;
};

#endif // !FILESYSTEM_FILE_INFO_H_INCLUDED