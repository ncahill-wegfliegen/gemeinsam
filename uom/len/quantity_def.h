#pragma once

#include "quantity_tmplt.h"

namespace nhill
{
namespace uom
{
namespace len
{
/// <summary>SI length: millimetre</summary>
using v_mm = Quantity_len_template<Prefix::milli, Len::m>;
/// <summary>SI length: centimetre</summary>
using v_cm = Quantity_len_template<Prefix::centi, Len::m>;
/// <summary>SI length: metre</summary>
using v_m = Quantity_len_template<Prefix::none, Len::m>;
/// <summary>SI length: kilometre</summary>
using v_km = Quantity_len_template<Prefix::kilo, Len::m>;

/// <summary>API length: inch</summary>
using v_in = Quantity_len_template<Prefix::none, Len::in>;
/// <summary>API length: foot</summary>
using v_ft = Quantity_len_template<Prefix::none, Len::ft>;
/// <summary>API length: yard</summary>
using v_yd = Quantity_len_template<Prefix::none, Len::yd>;
/// <summary>API length: mile</summary>
using v_mi = Quantity_len_template<Prefix::none, Len::mi>;
}
}
}