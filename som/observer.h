#pragma once

#include "port.h"
#include "changed_event_args.h"

namespace nhill
{
namespace som
{

class NHILL_SOM_PORT_CLASS Observer
{
protected:
   Observer() {}
public:
    virtual ~Observer() {}

public:
    virtual void on_system_of_measurement_changed( const std::string& sender, const Changed_event_args& event_args ) const = 0;
};

}
}