#pragma once

#include "prefix.h"
#include "..\utility\exception\not_implemented.h"

namespace nhill
{
namespace uom
{

template<typename Uom> inline
double convert( Prefix dst_prefix, Uom dst_uom, double src_value, Prefix src_prefix, Uom src_uom )
{
   static_assert(std::is_empty_v<Uom>, "The template parameter must be a strongly typed enumeration.");
   throw nhill::Not_implemented{"nhill::uom::convert.  This template must be specialized for each particular unit of measurement."};
}

}
}
