#pragma once

#include "port.h"
#include "arcdegree.h"
#include "arcminute.h"
#include "arcsecond.h"
#include "milliarcsecond.h"
#include "degree.h"
#include <string>


namespace nhill
{

class NHILL_GMTRY_PORT_CLASS Longitude
{
public:
#pragma region Aliases
   using Sign = nhill::math::Sign;
   using Arcdegree = nhill::Arcdegree<Adjust_arcdegree_c0_180c>;
   //template<typename T> using Degree = nhill::geometry::Degree<T>;
#pragma endregion

#pragma region Enumerations
   enum class Direction : int8_t
   { 
      W = -1, // West
      E = +1, // East
   };
#pragma endregion

#pragma region Constructors, Assignments, Constructor
   Longitude();
   Longitude( Direction dir, const Arcdegree& arcdeg, const Arcminute& arcmin, const Arcsecond& arcsec, const Milliarcsecond& marcsec = {} );

   Longitude( const Longitude& );
   Longitude& operator=( const Longitude& );

   Longitude( Longitude&& ) noexcept;
   Longitude& operator=( Longitude && ) noexcept;

   ~Longitude();
#pragma endregion

#pragma region Properties
   const      Direction& direction     () const;
   const      Arcdegree& arcdegree     () const;
   const      Arcminute& arcminute     () const;
   const      Arcsecond& arcsecond     () const;
   const Milliarcsecond& milliarcsecond() const;
#pragma endregion

#pragma region Methods
   void set( Direction dir, const Arcdegree& arcdeg, const Arcminute& arcmin, const Arcsecond& arcsec, const Milliarcsecond& marcsec = {} );
   void clear();
   template<typename T> nhill::geometry::Degree<T> to_degree() const;
   std::string to_string() const;
#pragma endregion

private:
#pragma region Data Members
        Direction dir_;
#pragma warning(suppress:4251)
        Arcdegree arcdeg_;
        Arcminute arcmin_;
        Arcsecond arcsec_;
   Milliarcsecond marcsec_;
#pragma endregion
};

}

namespace nhill
{

NHILL_GMTRY_PORT_FUNCTION Longitude operator+( const Longitude& a, const Longitude& b );
NHILL_GMTRY_PORT_FUNCTION Longitude operator-( const Longitude& a, const Longitude& b );

}

namespace nhill
{

NHILL_GMTRY_PORT_FUNCTION Longitude to_longitude_w( unsigned arcdeg, unsigned arcmin, unsigned arcsec, unsigned marcsec = 0 );
NHILL_GMTRY_PORT_FUNCTION Longitude to_longitude_e(unsigned arcdeg, unsigned arcmin, unsigned arcsec, unsigned marcsec = 0);
NHILL_GMTRY_PORT_FUNCTION Longitude to_longitude( std::string_view str );
template<typename T> Longitude to_longitude( const nhill::geometry::Degree<T>& deg, bool calc_marcsec = true )
{
   using Direction = Longitude::Direction;
   using Arcdeg_t = Longitude::Arcdegree::value_type;
   using Arcmin_t = Arcminute::value_type;
   using Arcsec_t = Arcsecond::value_type;
   using Marcsec_t = Milliarcsecond::value_type;

   Longitude::Arcdegree::adjust_type adjust;

   Direction dir{Longitude::Direction::E};
   Arcdeg_t arcdeg{0};
   Arcmin_t arcmin{0};
   Arcsec_t arcsec{0};
   Marcsec_t marcsec{0};

   // Determine the direction
   T value{static_cast<T>(deg.value())};
   if (math::less<T, uint8_t>( value, 0 ))
   {
      dir = Longitude::Direction::W;
   }
   value = std::abs( value );

   // Determine the arcdegree
   // The integer part
   uint64_t valuei{static_cast<uint64_t>(std::floor( value ))};
   arcdeg = static_cast<Arcdeg_t>(adjust( valuei ));
   
   // Determine the arcminutes
   // The fractional part
   value -= static_cast<T>(valuei);
   // The value as decimal arcminutes
   value *= static_cast<T>(60);
   // The arminutes
   arcmin = static_cast<Arcmin_t>(std::floor( value ));

   // Determine the arcseconds
   // The fractional part
   value -= static_cast<T>(arcmin);
   // The value as decimal arcseconds
   value *= static_cast<T>(60);
   // The arcseconds
   if (calc_marcsec)
   {
      arcsec = static_cast<Arcsec_t>(std::floor( value ));
   }
   else
   {
      arcsec = static_cast<Arcsec_t>(std::round( value ));
   }

   if (calc_marcsec)
   {
      // Determine the milliarcseconds
      // The fractional part
      value -= static_cast<T>(arcsec);
      // The value as decimal milliarcseconds
      value *= static_cast<T>(1000);
      // The milliarcseconds
      marcsec = static_cast<Marcsec_t>(std::round( value ));
   }

   // The longitude
   return {dir, arcdeg, arcmin, arcsec, marcsec};
}
template<typename T> nhill::geometry::Degree<T> to_degree( const Longitude& lon )
{
   T arcdeg{static_cast<T> ( lon.arcdegree     ().value() )};
   T arcmin{static_cast<T> ( lon.arcminute     ().value() )};
   T arcsec{static_cast<T> ( lon.arcsecond     ().value() )};
   T arcmsec{static_cast<T>( lon.milliarcsecond().value() )};

   T div_arcmin{static_cast<T>(60)};
   T div_arcsec{div_arcmin*static_cast<T>(60)};
   T div_marcsec{div_arcsec*static_cast<T>(1000)};

   T deg{arcdeg + arcmin / div_arcmin + arcsec / div_arcsec + arcmsec / div_marcsec};

   if (lon.direction() == Longitude::Direction::W)
   {
      deg *= static_cast<T>(-1);
   }

   return geometry::Degree<T>{deg};
}
NHILL_GMTRY_PORT_FUNCTION char to_char( Longitude::Direction dir );
NHILL_GMTRY_PORT_FUNCTION std::string to_string( const Longitude& lon );

}

template<typename T> inline 
auto nhill::Longitude::to_degree() const->nhill::geometry::Degree<T>
{
   return nhill::to_degree<T>(*this);
}
