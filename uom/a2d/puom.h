#pragma once

#include "../puom.h"
#include "../a2d.h"

namespace nhill
{
namespace uom
{

using Prefixed_a2d = Prefixed_uom<Area_2d>;

namespace a2d
{
using puom = Prefixed_a2d;
}

}
}
