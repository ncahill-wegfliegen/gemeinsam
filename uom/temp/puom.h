#pragma once

#include "..\puom.h"
#include "..\temp.h"

namespace nhill
{
namespace uom
{
using Prefixed_temp = Prefixed_uom<Temperature>;

namespace temp
{
using puom = Prefixed_temp;
}

}
}