#pragma once

#include "port.h"
#include "string_getable.h"

namespace nhill
{
namespace text
{

class NHILL_TEXT_PORT_CLASS Stringed final : public String_getable
{
public:
   Stringed();
   Stringed( const Stringed& );
   Stringed& operator=( const Stringed& );
   Stringed( Stringed&& ) noexcept;
   Stringed& operator=( Stringed&& ) noexcept;
   ~Stringed();

   std::string value() const;

private:
   std::string get_string() const final;

#pragma warning(suppress: 4251)
   std::string value_;
};

}
}