#pragma once

#include <string>

namespace nhill
{

class Object
{
public:
    virtual std::string to_string() const = 0;
};

}

#pragma region Definitions
inline
std::string nhill::Object::to_string() const
{
   return "Object";
}
#pragma endregion

