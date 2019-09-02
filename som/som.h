#pragma once

#include <cstdint>

namespace nhill
{

enum class System_of_measurement : std::int8_t
{
   none = -1,
   si = 0,  // METRIC,
   api = 1,  // API,

   metric = si,
};

}

#pragma region Alias
namespace nhill { using Som = nhill::System_of_measurement; }
#pragma endregion


