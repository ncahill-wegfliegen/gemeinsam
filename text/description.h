#pragma once

#include "port.h"
#include "string_getable.h"
#include "string_setable.h"
#include <string_view>

namespace nhill
{
namespace text
{

class NHILL_TEXT_PORT_CLASS Description final : public String_getable, String_setable
{
public:
   Description();
   Description( std::string_view value );
   Description( const Description& );
   Description& operator=( const Description& );
   Description( Description&& ) noexcept;
   Description& operator=( Description&& ) noexcept;
   ~Description();

   std::string value() const;
   void value( std::string_view );

private:
   std::string get_string() const final;
   void set_string( const std::string& ) final;

#pragma warning(suppress: 4251)
   std::string value_;
};

}
}