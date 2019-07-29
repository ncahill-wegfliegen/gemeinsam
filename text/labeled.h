#pragma once

#include "port.h"
#include "string_getable.h"

namespace nhill
{
namespace text
{

class NHILL_TEXT_PORT_CLASS Labeled final : public String_getable
{
public:
   Labeled();
   Labeled( const Labeled& );
   Labeled& operator=( const Labeled& );
   Labeled( Labeled&& ) noexcept;
   Labeled& operator=( Labeled&& ) noexcept;
   ~Labeled();

   std::string value() const;

private:
   std::string get_string() const final;

#pragma warning(suppress: 4251)
   std::string value_;
};

}
}