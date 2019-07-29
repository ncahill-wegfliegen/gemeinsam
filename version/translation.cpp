#include "translation.h"
#include <iomanip>

nhill::version::Translation::Translation()
{
   clear();
}

nhill::version::Translation::Translation( unsigned short language, unsigned short code_page )
   : language_{ language }
   , code_page_{ code_page }
{
}

nhill::version::Translation::Translation( const Translation& ) = default;
auto nhill::version::Translation::operator=( const Translation& ) ->Translation & = default;
nhill::version::Translation::Translation( Translation&& ) noexcept = default;
auto nhill::version::Translation::operator=( Translation&& ) noexcept->Translation & = default;
nhill::version::Translation::~Translation() = default;


unsigned short nhill::version::Translation::language() const
{
   return language_;
}

void nhill::version::Translation::language( unsigned short value )
{
   language_ = value;
}

unsigned short nhill::version::Translation::code_page() const
{
   return code_page_;
}

void nhill::version::Translation::code_page( unsigned short value )
{
   code_page_ = value;
}

void nhill::version::Translation::clear()
{
   language( 0 );
   code_page( 0 );
}

std::ostream & nhill::version::operator<<( std::ostream & out, const Translation & translation )
{
   out << std::setw( 4 ) << std::setfill( '0' ) << std::hex << translation.language();
   out << std::setw( 4 ) << std::setfill( '0' ) << std::hex << translation.code_page();

   return out;
}
