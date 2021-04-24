#include "CommandLineParser.h"

#include <algorithm>

CommandLineParser::CommandLineParser(int argc, char* argv[])
    : m_tokens()
{
    m_tokens.reserve(argc);
    for (int i = 1; i < argc; ++i) {
        m_tokens.emplace_back(argv[i]);
    }
}


bool CommandLineParser::hasOption(const std::string& key) const {
    auto it = std::find(m_tokens.begin(), m_tokens.end(), key);
    return it != m_tokens.end();
}


const std::string& CommandLineParser::getOptionValue(const std::string& key) const {
    auto it = std::find(m_tokens.begin(), m_tokens.end(), key);
    if (it != m_tokens.end() && ++it != m_tokens.end() && (*it)[0] != '-') {
        return *it;
    }

    static const std::string EMPTY = "";
    return EMPTY;
}
