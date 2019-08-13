#include "uangle.h"
#include "../utility/chr.h"
#include <string_view>

using namespace std;

auto nhill::geometry::to_uangle(  std::string_view str, char* sign_sym_param /*= nullptr*/ )->UAngle
{
   using Sign      = nhill::math::Sign; // sign type
   using Arcdeg_t  = unsigned int; // arcdegree type
   using Arcmin_t  = unsigned int; // arcminute type
   using Arcsec_t  = unsigned int; // arcsecond type
   using Marcsec_t = unsigned int; // milliarcsecond type

   constexpr auto period{chr::period<char>()}; // Period
   constexpr auto plus {chr::plus <char>()}; // Plus sign
   constexpr auto minus{chr::minus<char>()}; // Minus sign
   constexpr auto N{ 'N' }; // North latitude
   constexpr auto S{ 'S' }; // South latitude
   constexpr auto E{ 'E' }; // East longitude
   constexpr auto W{ 'W' }; // West longitude

   constexpr auto arcdeg_sym{chr::degree   <char>()}; // arcdegree symbol
   constexpr auto arcmin_sym{chr::arcminute<char>()}; // arcminute symbol
   constexpr auto arcsec_sym{chr::arcsecond<char>()}; // arcsecond symbol

   Sign      sign   {Sign::pos}; // sign value
   Arcdeg_t  arcdeg {0}; // arcdegree value
   Arcmin_t  arcmin {0}; // arcminute value
   Arcsec_t  arcsec {0}; // arcsecond value
   Marcsec_t marcsec{0}; // milliarcsecond value

   if (sign_sym_param != nullptr) // Initialize the sign symbol output parameter
   {
      *sign_sym_param = chr::null<char>();
   }

   ///////////////////////////////////////////////////////////////
   // Find the position of the symbol for each part of the angle
   ///////////////////////////////////////////////////////////////
   // Find the position of the sign
   constexpr char sign_syms[]{ plus, minus, N, S, E, W}; // All possible symbols that can represent the sign
   auto sign_pos = str.find_first_of( sign_syms );

   // Find the position of the arcdegree symbol
   auto arcdeg_pos = str.find( arcdeg_sym );

   // Find the position of the arcminute symbol
   auto arcmin_pos = str.find( arcmin_sym );

   // Find the position of the arcsecond symbol
   auto arcsec_pos = str.find( arcsec_sym );

   ///////////////////////////////////
   // Extract each part of the angle
   ///////////////////////////////////
   // Extract the sign
   if (sign_pos != string::npos)
   {
      auto sign_sym{str[sign_pos]}; // The symbol that represents the sign of the angle
      if (sign_sym == minus || sign_sym == W || sign_sym == S)
      {
         sign = Sign::neg;
      }

      // Set the sign symbol output parameter (if necessary)
      if (sign_sym_param != nullptr)
      {
         *sign_sym_param = sign_sym;
      }
   }

   // Extract the arcdegree value
   if (arcdeg_pos != string::npos)
   {
      string value{str.substr( 0, arcdeg_pos )};
      arcdeg = static_cast<Arcdeg_t>(abs( atoi( value.c_str() ) ));

      // Extract the arcminute value
      if (arcmin_pos != string::npos)
      {
         value = str.substr( arcdeg_pos + 1, arcmin_pos - arcdeg_pos - 1 );
         arcmin = static_cast<Arcmin_t>(atoi( value.c_str() ));

         // Extract the arcsecond 
         if (arcsec_pos != string::npos)
         {
            value = str.substr( arcmin_pos + 1, arcsec_pos - arcmin_pos - 1 );
            auto period_pos = value.find( period );
            if (period_pos == string::npos)
            {
               // The arcsecond is not a floating point (no milliarcseconds)
               arcsec = static_cast<Arcsec_t>(atoi( value.c_str() ));
            }
            else
            {
               // The arcsecond is a floating point value
               auto valuef{atof( value.c_str() )};
               // The interger part of the arcsecond floating point value
               arcsec = static_cast<Arcsec_t>(std::floor( valuef ));
               // The decimal part of the arcsecond floating point value
               valuef -= arcsec;
               // Extract the milliarcsecond value
               marcsec = static_cast<Marcsec_t>(std::round( valuef * 1000 ));
            }
         }
      }
   }

   //////////////////
   // Set the angle
   //////////////////
   return {sign, arcdeg, arcmin, arcsec};
}
