#pragma once

#include "port.h"
#include "arcdegree.h"
#include "arcminute.h"
#include "arcsecond.h"
#include "milliarcsecond.h"
#include "degree.h"
#include "..\math\sign.h"
#include <string_view>
#include <string>
#include <cstdint>

namespace nhill
{

//struct SAngle;

class  Angle
{
public:
#pragma region Aliases
   using Arcdegree = nhill::Arcdegree<nhill::Adjust_arcdegree_c0_360o>;
   using Sign = nhill::math::Sign;
#pragma endregion

#pragma region Constructors, Assignments, Constructor
   Angle() = delete;
   Angle( const Arcdegree& deg, const Arcminute& arcmin, const Arcsecond& arcsec, const Milliarcsecond& marcsec = {} );
   Angle( Sign sign, const Arcdegree& deg, const Arcminute& arcmin, const Arcsecond& arcsec, const Milliarcsecond& marcsec = {});

   Angle( const Angle& );
   Angle& operator=( const Angle& ) = delete;

   Angle( Angle&& );
   Angle& operator=( Angle && ) = delete;

   ~Angle();
#pragma endregion

#pragma region Properties
   const      Sign& sign     () const;
   const Arcdegree& arcdegree() const;
   const Arcminute& arcminute() const;
   const Arcsecond& arcsecond() const;
#pragma endregion

#pragma region Methods
   void to_string();
#pragma endregion

private:
#pragma region Data Members
              Sign  sign_;
   const Arcdegree  arcdeg_;
   const Arcminute  arcmin_;
   const Arcsecond  arcsec_;
   const Milliarcsecond marcsec_;
#pragma endregion
};

}

#pragma region Operators
namespace nhill
{

NHILL_GMTRY_PORT_FUNCTION Angle operator+( const Angle& a, const Angle& b ) noexcept;
NHILL_GMTRY_PORT_FUNCTION Angle operator-( const Angle& a, const Angle& b ) noexcept;

NHILL_GMTRY_PORT_FUNCTION bool operator==( const Angle& a, const Angle& b ) noexcept;
NHILL_GMTRY_PORT_FUNCTION bool operator!=( const Angle& a, const Angle& b ) noexcept;

NHILL_GMTRY_PORT_FUNCTION bool operator>( const Angle& a, const Angle& b ) noexcept;
NHILL_GMTRY_PORT_FUNCTION bool operator<( const Angle& a, const Angle& b ) noexcept;

NHILL_GMTRY_PORT_FUNCTION bool operator>=( const Angle& a, const Angle& b ) noexcept;
NHILL_GMTRY_PORT_FUNCTION bool operator<=( const Angle& a, const Angle& b ) noexcept;

}
#pragma endregion

#pragma region Methods
namespace nhill
{
NHILL_GMTRY_PORT_FUNCTION Angle to_angle(unsigned arcdeg, unsigned arcmin, unsigned arcsec);
NHILL_GMTRY_PORT_FUNCTION Angle to_angle_neg(unsigned arcdeg, unsigned arcmin, unsigned arcsec);
NHILL_GMTRY_PORT_FUNCTION Angle to_angle(const std::string_view& str);

template<typename T, enable_if::is_math_fp_type<T>* = nullptr>
Angle to_angle(geometry::Degree<T> deg)
{
   using Arcdeg_t = typename Angle::Arcdegree::value_type;
   using Arcmin_t = typename Arcminute::value_type;
   using Arcsec_t = typename Arcsecond::value_type;
   using Marcsec_t = typename Milliarcsecond::value_type;

   typename Angle::Arcdegree::adjust_type adjust;

   Arcdeg_t arcdeg{ 0 };
   Arcmin_t arcmin{ 0 };
   Arcsec_t arcsec{ 0 };
   Marcsec_t marcsec{ 0 };

   // The value of the floating point degree,
   // adjusted to be in the interval [0,360).
   geometry::adjust_c0_o360(deg);
   T value{ deg.value() };

   // Determine the arcdegree
   // The integer part
   uint64_t valuei{ static_cast<uint64_t>(std::floor(value)) };
   arcdeg = static_cast<Arcdeg_t>(adjust(valuei));

   // Determine the arcminutes
   // The fractional part
   value -= static_cast<T>(valuei);
   // The value as decimal arcminutes
   value *= static_cast<T>(60);
   // The arminutes
   arcmin = static_cast<Arcmin_t>(std::floor(value));

   // Determine the arcseconds
   // The fractional part
   value -= static_cast<T>(arcmin);
   // The value as decimal arcseconds
   value *= static_cast<T>(60);
   // The arcseconds
   arcsec = static_cast<Arcsec_t>(std::floor(value));

   // Determine the milliarcseconds
   // The fractional part
   value -= static_cast<T>(arcsec);
   // The value as decimal milliarcseconds
   value *= static_cast<T>(1000);
   // The milliarcseconds
   marcsec = static_cast<Marcsec_t>(std::round(value));

   // The longitude
   return { arcdeg, arcmin, arcsec, marcsec };
}

}
#pragma endregion



