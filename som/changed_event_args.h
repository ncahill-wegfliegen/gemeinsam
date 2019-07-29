#pragma once

#include "port.h"
#include "som.h"

namespace nhill
{
namespace som
{

class NHILL_SOM_PORT_CLASS Changed_event_args 
{
public:
   Changed_event_args( Som som );
    ~Changed_event_args();

public:
    const Som som;
};

}
}