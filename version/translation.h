#pragma once

#include "port.h"
#include <ostream>

namespace nhill
{
namespace version
{

class NHILL_VERSION_PORT_CLASS Translation
{
public:
   Translation();
   Translation( unsigned short language, unsigned short code_page );
   Translation( const Translation& );
   Translation& operator=( const Translation& );
   Translation( Translation&& ) noexcept;
   Translation& operator=( Translation&& ) noexcept;
   ~Translation();

   unsigned short language() const;
   void language( unsigned short value );

   unsigned short code_page() const;
   void code_page( unsigned short value );

   void clear();

private:
   unsigned short language_;
   unsigned short code_page_;
};


}
}

namespace nhill
{
namespace version
{

NHILL_VERSION_PORT_FUNCTION std::ostream& operator<<( std::ostream& out, const Translation& translation );

}
}