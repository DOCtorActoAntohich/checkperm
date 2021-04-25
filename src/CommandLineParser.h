#ifndef COMMAND_LINE_PARSER_H_INCLUDED
#define COMMAND_LINE_PARSER_H_INCLUDED

#include <vector>
#include <string>

/**
 * @brief A class that simplifies parsing names command line arguments.
 * @remark Thanks to this answer for an idea:
 * https://stackoverflow.com/questions/865668/parsing-command-line-arguments-in-c
 */
class CommandLineParser {
public:
    /**
     * @brief Parse command line arguments on construction.
     * 
     * @param argc Amount of command line parameters.
     * @param argv An array of command line parameters.
     */
    CommandLineParser(int argc, char* argv[]);

    /**
     * @brief Checks if the token is present in the command line arguments.
     * 
     * @param key A string key
     * @return true if the object was provided as command line argument, false otherwise.
     */
    bool hasOption(const std::string& key) const;

    /**
     * @brief Get a value for a named option from command line.
     * @note It may actually find a value next to any key.
     *
     * @param key A named option like "-a" or "--path".
     * @return Returns a value for this option if it was found, and empty string otherwise.
     */
    const std::string& getOptionValue(const std::string& key) const;
private:
    std::vector<std::string> m_tokens;
};

#endif //!COMMAND_LINE_PARSER_H_INCLUDED