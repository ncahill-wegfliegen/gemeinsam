#pragma once

#include "port.h"
#include "string_getable.h"
#include "string_setable.h"
#include <string_view>

namespace nhill
{
namespace text
{


class NHILL_TEXT_PORT_CLASS Code final : public String_getable, String_setable
{
public:
   Code();
   Code( std::string_view value );
   Code( const Code& );
   Code& operator=( const Code& );
   Code( Code&& ) noexcept;
   Code& operator=( Code&& ) noexcept;
   ~Code();

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