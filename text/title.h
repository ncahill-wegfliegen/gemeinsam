#pragma once

#include "port.h"
#include "string_getable.h"
#include "string_setable.h"
#include <string_view>

namespace nhill
{
namespace text
{

class NHILL_TEXT_PORT_CLASS Title final : public String_getable, String_setable
{
public:
   Title();
   Title( std::string_view value );
   Title( const Title& );
   Title& operator=( const Title& );
   Title( Title&& ) noexcept;
   Title& operator=( Title&& ) noexcept;
   ~Title();

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