#pragma once

#include "port.h"

namespace nhill
{

class NHILL_UTIL_PORT_CLASS Event_args
{
public:
    Event_args(const Event_args&);
    Event_args& operator=(const Event_args&);

    Event_args(Event_args&&) noexcept;
    Event_args& operator=(Event_args&&) noexcept;

    virtual ~Event_args();

protected:
   Event_args();
};

}
