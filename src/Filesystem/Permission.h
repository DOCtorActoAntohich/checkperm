#ifndef FILESYSTEM_PERMISSION_H_INCLUDED
#define FILESYSTEM_PERMISSION_H_INCLUDED

#include <cstdint>

// Took the idea from here:
// https://github.com/SFML/SFML/blob/master/include/SFML/Window/WindowStyle.hpp

namespace Permission {
    enum : int32_t {
        NONE    = 0,
        READ    = 1 << 2,
        WRITE   = 1 << 1,
        EXECUTE = 1 << 0,
        ALL     = READ | WRITE | EXECUTE,
    };
}
using Permission_v = int32_t;

#endif // !FILESYSTEM_PERMISSION_H_INCLUDED