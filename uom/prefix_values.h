#pragma once

#include "port.h"
#include "prefix.h"
#include <vector>

namespace nhill
{
namespace uom
{
NHILL_UOM_PORT_PARAMETER extern const std::vector<Prefix> prefix_values;
NHILL_UOM_PORT_PARAMETER extern const std::vector<Prefix> prefix_values_si;
NHILL_UOM_PORT_PARAMETER extern const std::vector<Prefix> prefix_values_engineering;
NHILL_UOM_PORT_PARAMETER extern const std::vector<Prefix> prefix_values_api;
}
}