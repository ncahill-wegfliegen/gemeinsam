#pragma once

#include "port.h"
#include "string_getable.h"

namespace nhill
{
namespace text
{

class NHILL_TEXT_PORT_CLASS Coded final : public String_getable
{
public:
   Coded();
   Coded( const Coded& );
   Coded& operator=( const Coded& );
   Coded( Coded&& ) noexcept;
   Coded& operator=( Coded&& ) noexcept;
   ~Coded();

   std::string value() const;

private:
   std::string get_string() const final;

#pragma warning(suppress: 4251)
   std::string value_;
};

}
}