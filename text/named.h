#pragma once

#include "port.h"
#include "string_getable.h"

namespace nhill
{
namespace text
{

class NHILL_TEXT_PORT_CLASS Named final : public String_getable
{
public:
   Named();
   Named( const Named& );
   Named& operator=( const Named& );
   Named( Named&& ) noexcept;
   Named& operator=( Named&& ) noexcept;
   ~Named();

   std::string value() const;

private:
   std::string get_string() const final;

#pragma warning(suppress: 4251)
   std::string value_;
};

}
}