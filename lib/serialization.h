#pragma once

#include "core.h"

namespace p3d
{
#define SERIALIZE_TYPE(x, name)           \
    entt::meta<x>()                       \
        .alias(name)                      \
        .func<&p3d::_read<x>>("_read"_hs) \
        .func<&p3d::_write<x>>("_write"_hs)

template <typename Type>
static void _write()
{
    std::cout << "write" << std::endl;
}

template <typename Type>
static void _read()
{
    std::cout << "read" << std::endl;
}

P3D_API int registerTypes();
}  // namespace p3d
