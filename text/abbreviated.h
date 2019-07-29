#pragma once

#include "port.h"
#include "string_getable.h"

namespace nhill
{
namespace text
{

class NHILL_TEXT_PORT_CLASS Abbreviated final : public String_getable
{
public:
   Abbreviated();
   Abbreviated( const Abbreviated& );
   Abbreviated& operator=( const Abbreviated& );
   Abbreviated( Abbreviated&& ) noexcept;
   Abbreviated& operator=( Abbreviated&& ) noexcept;
   ~Abbreviated();

   std::string value() const;

private:
   std::string get_string() const final;

#pragma warning(suppress: 4251)
   std::string value_;
};

}
}