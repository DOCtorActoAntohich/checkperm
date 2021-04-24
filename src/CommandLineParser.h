#ifndef COMMAND_LINE_PARSER_H_INCLUDED
#define COMMAND_LINE_PARSER_H_INCLUDED

#include <vector>
#include <string>

// Thanks to this answer for an idea:
// https://stackoverflow.com/questions/865668/parsing-command-line-arguments-in-c

class CommandLineParser {
public:
    CommandLineParser(int argc, char* argv[]);

    bool hasOption(const std::string& key) const;
    const std::string& getOptionValue(const std::string& key) const;
private:
    std::vector<std::string> m_tokens;
};

#endif //!COMMAND_LINE_PARSER_H_INCLUDED