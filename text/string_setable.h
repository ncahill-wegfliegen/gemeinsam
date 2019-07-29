#pragma once

#include "port.h"
#include <string>

namespace nhill
{
namespace text
{

/// <summary>The interface for any object that has a setable string.</summary>
class NHILL_TEXT_PORT_CLASS String_setable
{
public:
   virtual ~String_setable();
   virtual void set_string( const std::string& ) = 0;
};

}
}