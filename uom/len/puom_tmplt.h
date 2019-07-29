#pragma once

#include "..\len.h"
#include "..\puom_tmplt.h"

namespace nhill
{
namespace uom
{

template<Prefix prefix, Len uom>
using Prefixed_len_template = Prefixed_uom_template<Len, prefix, uom>;

}
}