#include <iostream>

#include "core.h"
#include "serialization.h"

int main()
{
#define FROM_LIBRARY 0

#if FROM_LIBRARY == 1
    std::cout << "registering in library" << std::endl;
    p3d::registerTypes();
#else
    std::cout << "registering in app" << std::endl;
    entt::meta<float>()
        .alias("float"_hs)
        .func<&p3d::_read<float> >("_read"_hs)
        .func<&p3d::_write<float> >("_write"_hs);
#endif
    std::cout << "hello" << std::endl;

    std::cout << bool(entt::resolve("float"_hs).func("_read"_hs)) << std::endl;
    std::cout << bool(entt::resolve("float"_hs).func("_write"_hs)) << std::endl;

    std::cout << bool(entt::resolve<float>().func("_read"_hs)) << std::endl;
    std::cout << bool(entt::resolve<float>().func("_write"_hs)) << std::endl;

    return 0;
}