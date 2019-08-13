#pragma once

#include "../len/quantity_tmplt.h"

namespace nhill
{
namespace uom
{
namespace len
{
/// <summary>SI length: millimetre</summary>
template<typename T = double>
using v_mm = Quantity_len_template<Prefix::milli, Len::m, T>;
/// <summary>SI length: centimetre</summary>
template<typename T = double>
using v_cm = Quantity_len_template<Prefix::centi, Len::m, T>;
/// <summary>SI length: metre</summary>
template<typename T = double>
using v_m = Quantity_len_template<Prefix::none, Len::m, T>;
/// <summary>SI length: kilometre</summary>
template<typename T = double>
using v_km = Quantity_len_template<Prefix::kilo, Len::m, T>;

/// <summary>API length: inch</summary>
template<typename T = double>
using v_in = Quantity_len_template<Prefix::none, Len::in, T>;
/// <summary>API length: foot</summary>
template<typename T = double>
using v_ft = Quantity_len_template<Prefix::none, Len::ft, T>;
/// <summary>API length: yard</summary>
template<typename T = double>
using v_yd = Quantity_len_template<Prefix::none, Len::yd, T>;
/// <summary>API length: mile</summary>
template<typename T = double>
using v_mi = Quantity_len_template<Prefix::none, Len::mi, T>;
}
}
}