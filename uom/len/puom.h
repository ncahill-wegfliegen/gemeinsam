#pragma once

#include "../puom.h"
#include "../len.h"

namespace nhill
{
namespace uom
{
using Prefixed_len = Prefixed_uom<Length>;

namespace len
{
using puom = Prefixed_len;
}

}
}
