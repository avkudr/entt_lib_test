#include <iostream>

#include "core.h"
#include "project_settings.h"
#include "serialization.h"

int main()
{
#define FROM_LIBRARY 1

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

    std::cout << bool(entt::resolve<p3d::ProjectSettings>().data(
                     P3D_ID_TYPE(p3d::p3dSetting_featuresDescType)))
              << std::endl;

    return 0;
}