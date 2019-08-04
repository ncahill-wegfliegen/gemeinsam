#include "prefix_values.h"

using namespace nhill::uom;

NHILL_UOM_PORT_FUNCTION const std::vector<Prefix> nhill::uom::prefix_values{
   Prefix::yocto,
   Prefix::zepto,
   Prefix::atto,
   Prefix::femto,
   Prefix::pico,
   Prefix::nano,
   Prefix::micro,
   Prefix::milli,
   Prefix::centi,
   Prefix::deci,
   Prefix::none,
   Prefix::deca,
   Prefix::hecto,
   Prefix::kilo,
   Prefix::mega,
   Prefix::giga,
   Prefix::tera,
   Prefix::peta,
   Prefix::exa,
   Prefix::zetta,
   Prefix::yotta,
   Prefix::e3,
   Prefix::e6,
   Prefix::e9,
   Prefix::M,
   Prefix::MM,
   Prefix::B,
};

NHILL_UOM_PORT_FUNCTION const std::vector<Prefix> nhill::uom::prefix_values_si{
   Prefix::yocto,
   Prefix::zepto,
   Prefix::atto,
   Prefix::femto,
   Prefix::pico,
   Prefix::nano,
   Prefix::micro,
   Prefix::milli,
   Prefix::centi,
   Prefix::deci,
   Prefix::deca,
   Prefix::hecto,
   Prefix::kilo,
   Prefix::mega,
   Prefix::giga,
   Prefix::tera,
   Prefix::peta,
   Prefix::exa,
   Prefix::zetta,
   Prefix::yotta,
};

NHILL_UOM_PORT_FUNCTION const std::vector<Prefix> nhill::uom::prefix_values_engineering{
   Prefix::e3,
   Prefix::e6,
   Prefix::e9,
};

NHILL_UOM_PORT_FUNCTION const std::vector<Prefix> nhill::uom::prefix_values_api{
   Prefix::M,
   Prefix::MM,
   Prefix::B,
};
