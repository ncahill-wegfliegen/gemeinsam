#pragma once

#include "../a2d/puom_tmplt.h"

namespace nhill
{
namespace uom
{
namespace a2d
{

/// <summary>SI area: millimetre squared</summary>
using mm2 = Prefixed_a2d_template<Prefix::milli, A2d::m2>;
/// <summary>SI area: centimetre sqaured</summary>
using cm2 = Prefixed_a2d_template<Prefix::centi, A2d::m2>;
/// <summary>SI area: metre sqaured</summary>
using m2 = Prefixed_a2d_template<Prefix::none, A2d::m2>;
/// <summary>SI area: kilometre squared</summary>
using km2 = Prefixed_a2d_template<Prefix::kilo, A2d::m2>;

/// <summary>API area: square feet</summary>
using sqft = Prefixed_a2d_template<Prefix::none, A2d::sqft>;
/// <summary>SI area: hectare</summary>
using ha = Prefixed_a2d_template<Prefix::none, A2d::ha>;
/// <summary>API area: acre</summary>
using ac = Prefixed_a2d_template<Prefix::none, A2d::ac>;

}
}
}