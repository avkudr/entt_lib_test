#include "serialization.h"

#include <iostream>

namespace p3d
{
int registerTypes()
{
    std::cout << "registering: primitives" << std::endl;

    SERIALIZE_TYPE(float, "float"_hs);
    SERIALIZE_TYPE(double, "double"_hs);
    SERIALIZE_TYPE(int, "int"_hs);
    SERIALIZE_TYPE(unsigned int, "uint"_hs);
    SERIALIZE_TYPE(std::string, "std::string"_hs);

    return 0;
}

// ***** Ideally
// int dummyRegisterTypes = registerTypes()

}  // namespace p3d
