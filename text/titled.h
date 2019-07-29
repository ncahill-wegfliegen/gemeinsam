#pragma once

#include "port.h"
#include "string_getable.h"

namespace nhill
{
namespace text
{

class NHILL_TEXT_PORT_CLASS Titled final : public String_getable
{
public:
   Titled();
   Titled( const Titled& );
   Titled& operator=( const Titled& );
   Titled( Titled&& ) noexcept;
   Titled& operator=( Titled&& ) noexcept;
   ~Titled();

   std::string value() const;

private:
   std::string get_string() const final;

#pragma warning(suppress: 4251)
   std::string value_;
};

}
}