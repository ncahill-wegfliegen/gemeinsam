#include "convert.h"
#include "..\utility\chr.h"
#include <sstream>
#include <gsl\gsl_assert>

using namespace std;

string nhill::geometry::angle_to_string( char sign, unsigned int arcdeg, unsigned int arcmin, unsigned int arcsec, unsigned int milliarcsec )
{
   Expects( (sign == chr::null<char>() || sign == chr::plus<char>() || sign == chr::minus<char>() || sign == 'N' || sign == 'S' || sign == 'E' || sign == 'W') );

   ostringstream oss;
   constexpr char space{chr::space<char>()};

   if( sign == chr::plus<char>() || sign == chr::minus<char>() )
   {
      oss << sign;
   }

   oss << arcdeg << chr::degree<char>() << space;
   oss << arcmin << chr::arcminute<char>() << space;
   oss << arcsec + milliarcsec / 1000.0f;

   if( sign == 'N' || sign == 'S' || sign == 'E' || sign == 'W' )
   {
      oss << space << sign;
   }

   return oss.str();
}
