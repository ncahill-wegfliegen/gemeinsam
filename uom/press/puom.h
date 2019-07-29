#pragma once

#include "..\puom.h"
#include "..\press.h"

namespace nhill
{
namespace uom
{
using Prefixed_press = Prefixed_uom<Pressure>;

namespace press
{
using puom = Prefixed_press;
}

}
}