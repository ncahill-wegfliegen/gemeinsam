#pragma once

#include "port.h"
#include "string_getable.h"

namespace nhill
{
namespace text
{

class NHILL_TEXT_PORT_CLASS Described final : public String_getable
{
public:
   Described();
   Described( const Described& );
   Described& operator=( const Described& );
   Described( Described&& ) noexcept;
   Described& operator=( Described&& ) noexcept;
   ~Described();

   std::string value() const;

private:
   std::string get_string() const final;

#pragma warning(suppress: 4251)
   std::string value_;
};

}
}