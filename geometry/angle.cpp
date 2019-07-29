#include "angle.h"
#include "uangle.h"
#include <sstream>
#include <algorithm>

using namespace std;

nhill::Angle::Angle( const Arcdegree& arcdeg, const Arcminute& arcmin, const Arcsecond& arcsec, const Milliarcsecond& marcsec /*= {}*/ )
   : sign_   {Sign::pos}
   , arcdeg_ {arcdeg}
   , arcmin_ {arcmin}
   , arcsec_ {arcsec}
   , marcsec_{marcsec}
{
}

nhill::Angle::Angle( Sign sign, const Arcdegree& arcdeg, const Arcminute& arcmin, const Arcsecond& arcsec, const Milliarcsecond& marcsec /*= {}*/)
   : sign_{ sign }
   , arcdeg_{ arcdeg }
   , arcmin_{ arcmin }
   , arcsec_{ arcsec }
   , marcsec_{ marcsec }
{
}

nhill::Angle::Angle( const Angle & ) = default;
nhill::Angle::Angle( Angle && ) = default;
nhill::Angle::~Angle() = default;

auto nhill::Angle::sign() const->const Sign &
{
   return sign_;
}

auto nhill::Angle::arcdegree() const->const Arcdegree&
{
   return arcdeg_;
}

auto nhill::Angle::arcminute() const->const Arcminute&
{
   return arcmin_;
}

auto nhill::Angle::arcsecond() const->const Arcsecond&
{
   return arcsec_;
}

auto nhill::operator+(const Angle & a, const Angle & b) noexcept->Angle
{
   return { 0,0,0,0 };
}

auto nhill::operator-(const Angle & a, const Angle & b) noexcept->Angle
{
   return { 0,0,0,0 };
}

bool nhill::operator==( const Angle & a, const Angle & b ) noexcept
{
   return bool();
}

bool nhill::operator!=( const Angle & a, const Angle & b ) noexcept
{
   return bool();
}

bool nhill::operator>( const Angle & a, const Angle & b ) noexcept
{
   return bool();
}

bool nhill::operator<( const Angle & a, const Angle & b ) noexcept
{
   return bool();
}

bool nhill::operator>=( const Angle & a, const Angle & b ) noexcept
{
   return bool();
}

bool nhill::operator<=( const Angle & a, const Angle & b ) noexcept
{
   return bool();
}

auto nhill::to_angle(unsigned arcdeg, unsigned arcmin, unsigned arcsec)->Angle
{
   arcsec = adjust_arcsecond<unsigned>(arcsec, &arcmin, &arcdeg);
   arcmin = adjust_arcminute<unsigned>(arcmin, &arcdeg);

   return { static_cast<uint16_t>(arcdeg), static_cast<uint8_t>(arcmin), static_cast<uint8_t>(arcsec) };
}

auto nhill::to_angle_neg(unsigned arcdeg, unsigned arcmin, unsigned arcsec)->Angle
{
   Angle angle{ to_angle(arcdeg, arcmin, arcsec) };
   return Angle{ Angle::Sign::neg, 0U, 0U, 0U };
}

auto nhill::to_angle(const string_view & str)->Angle
{
   return Angle{ 0U, 0U, 0U };
}


