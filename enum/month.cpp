#include "month.h"
#include "core\int.h"
#include "..\utility\str.h"
#include <ctime>
#include <locale>

using namespace std;

namespace
{

using namespace nhill;

string label( Month month )
{
   tm tm;
   tm.tm_year = 1900;
   tm.tm_mon  = nhill::to_zmonth( month );
   tm.tm_mday = 1;

   char label[12]{};
   ::_strftime_l( &label[0], sizeof label,"%b", &tm, ::_get_current_locale() );

   return &label[0];
}

string code( Month month )
{
   string code = label( month );
   str::toupper( code );
   return code;
}

string description( Month month )
{
   tm tm;
   tm.tm_year = 1900;
   tm.tm_mon  = to_zmonth( month );
   tm.tm_mday = 1;

   char desc[32]{};
   ::_strftime_l( &desc[0], sizeof desc, "%B", &tm, ::_get_current_locale() );

   return &desc[0];
}

}

template<>
const nhill::text::Bundle_container<nhill::Month>& nhill::text::bundle_container<nhill::Month>()
{
   static const Bundle_container<nhill::Month> bundles{
      { Month::jan,{ { Text::code, code( Month::jan ) },{ Text::string, "jan" },{ Text::label, label( Month::jan ) },{ Text::description, description( Month::jan ) } } },
      { Month::feb,{ { Text::code, code( Month::feb ) },{ Text::string, "feb" },{ Text::label, label( Month::feb ) },{ Text::description, description( Month::feb ) } } },
      { Month::mar,{ { Text::code, code( Month::mar ) },{ Text::string, "mar" },{ Text::label, label( Month::mar ) },{ Text::description, description( Month::mar ) } } },
      { Month::apr,{ { Text::code, code( Month::apr ) },{ Text::string, "apr" },{ Text::label, label( Month::apr ) },{ Text::description, description( Month::apr ) } } },
      { Month::may,{ { Text::code, code( Month::may ) },{ Text::string, "may" },{ Text::label, label( Month::may ) },{ Text::description, description( Month::may ) } } },
      { Month::jun,{ { Text::code, code( Month::jun ) },{ Text::string, "jun" },{ Text::label, label( Month::jun ) },{ Text::description, description( Month::jun ) } } },
      { Month::jul,{ { Text::code, code( Month::jul ) },{ Text::string, "jul" },{ Text::label, label( Month::jul ) },{ Text::description, description( Month::jul ) } } },
      { Month::aug,{ { Text::code, code( Month::aug ) },{ Text::string, "aug" },{ Text::label, label( Month::aug ) },{ Text::description, description( Month::aug ) } } },
      { Month::sep,{ { Text::code, code( Month::sep ) },{ Text::string, "sep" },{ Text::label, label( Month::sep ) },{ Text::description, description( Month::sep ) } } },
      { Month::oct,{ { Text::code, code( Month::oct ) },{ Text::string, "oct" },{ Text::label, label( Month::oct ) },{ Text::description, description( Month::oct ) } } },
      { Month::nov,{ { Text::code, code( Month::nov ) },{ Text::string, "nov" },{ Text::label, label( Month::nov ) },{ Text::description, description( Month::nov ) } } },
      { Month::dec,{ { Text::code, code( Month::dec ) },{ Text::string, "dec" },{ Text::label, label( Month::dec ) },{ Text::description, description( Month::dec ) } } },
   };

   return bundles;
}


using namespace std;

int nhill::to_zmonth( Month em )
{
   return to_int( em ) - 1;
}

int nhill::to_umonth( Month em )
{
   return to_int( em );
}

nhill::Month nhill::from_zmonth( int zmonth )
{
   return nhill::to_enum<Month>( zmonth + 1 );
}

nhill::Month nhill::from_umonth( int umonth )
{
   return nhill::to_enum<Month>( umonth );
}

nhill::Month nhill::current_month()
{
   std::time_t tt{ std::time( nullptr ) }; // Get time now
   struct tm today;

   errno_t err{ ::localtime_s( &today, &tt ) };
   if( err != 0 )
   {
      throw std::exception( "Cannot get the current month." );
   }

   return from_umonth(today.tm_mon + 1 );
}

template<>
int nhill::compare<nhill::Month>( Month mn1, Month mn2 ) noexcept
{
   return compare<int>( to_int( mn1 ), to_int( mn2 ) );
}

bool nhill::operator==( Month mn1, Month mn2 )
{
   return compare( mn1, mn2 ) == 0;
}

bool nhill::operator!=( Month mn1, Month mn2 )
{
   return compare( mn1, mn2 ) != 0;
}

bool nhill::operator<( Month mn1, Month mn2 )
{
   return compare( mn1, mn2 ) < 0;
}

bool nhill::operator<=( Month mn1, Month mn2 )
{
   return compare( mn1, mn2 ) <= 0;
}

bool nhill::operator>( Month mn1, Month mn2 )
{
   return compare( mn1, mn2 ) > 0;
}

bool nhill::operator>=( Month mn1, Month mn2 )
{
   return compare( mn1, mn2 ) >= 0;
}

