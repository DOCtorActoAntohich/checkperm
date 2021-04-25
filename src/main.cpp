#include <iostream>
#include <string>
#include <filesystem>

#include "CommandLineParser.h"

static constexpr auto ARGS_REQUIRED = 7;

int main(int argc, char* argv[]) {
    if (argc != ARGS_REQUIRED) {
        std::cout <<
            "Checkperm recursively checks the write permission in the given directory.\n"
            "Usage:\n"
            "checkperm -u <username> -g <group> -p <path>\n"
            "-u <username>  -  First, checks if user can write.\n"
            "-g <group>     -  Second, checks if group can write.\n"
            "-p <path>      -  Path to check permissions in." <<
            std::endl;
        return 0; 
    }

    CommandLineParser arguments(argc, argv);
    auto& username              = arguments.getOptionValue("-u");
    auto& group                 = arguments.getOptionValue("-g");
    std::filesystem::path path  = arguments.getOptionValue("-p");

    if (username == "") {
        std::cerr << "Invalid user name: " << username << std::endl;
        return 2;
    }
    if (group == "") {
        std::cerr << "Invalid group name: " << group << std::endl;
        return 2;
    }
    if (!std::filesystem::exists(path)) {
        std::cerr << "Invalid path: " << path.string() << std::endl;
        return 2;
    }

    return 0;
}
