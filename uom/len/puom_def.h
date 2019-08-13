#pragma once

#include "../len/puom_tmplt.h"

namespace nhill
{
namespace uom
{
namespace len
{
/// <summary>SI length: millimetre</summary>
using mm = Prefixed_len_template<Prefix::milli, Len::m>;
/// <summary>SI length: centimetre</summary>
using cm = Prefixed_len_template<Prefix::centi, Len::m>;
/// <summary>SI length: metre</summary>
using m = Prefixed_len_template<Prefix::none, Len::m>;
/// <summary>SI length: kilometre</summary>
using km = Prefixed_len_template<Prefix::kilo, Len::m>;

/// <summary>API length: inch</summary>
using in = Prefixed_len_template<Prefix::none, Len::in>;
/// <summary>API length: foot</summary>
using ft = Prefixed_len_template<Prefix::none, Len::ft>;
/// <summary>API length: yard</summary>
using yd = Prefixed_len_template<Prefix::none, Len::yd>;
/// <summary>API length: mile</summary>
using mi = Prefixed_len_template<Prefix::none, Len::mi>;
}
}
}