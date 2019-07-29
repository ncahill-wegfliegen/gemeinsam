#include "latitude.h"
#include "uangle.h"
#include "convert.h"

using namespace std;

nhill::Latitude::Latitude()
   : dir_{Direction::N}
   , arcdeg_{}
   , arcmin_{}
   , arcsec_{}
   , marcsec_{}
{
}

nhill::Latitude::Latitude(Direction dir, const Arcdegree & arcdeg, const Arcminute & arcmin, const Arcsecond & arcsec, const Milliarcsecond& marcsec)
{
   set(dir, arcdeg, arcmin, arcsec, marcsec);
}

nhill::Latitude::Latitude(const Latitude &) = default;
auto nhill::Latitude::operator=(const Latitude &)->Latitude & = default;

nhill::Latitude::Latitude(Latitude &&) noexcept = default;
auto nhill::Latitude::operator=(Latitude &&) noexcept ->Latitude & = default;

nhill::Latitude::~Latitude() = default;

auto nhill::Latitude::direction() const->const Direction &
{
   return dir_;
}

auto nhill::Latitude::arcdegree() const->const Arcdegree&
{
   return arcdeg_;
}

auto nhill::Latitude::arcminute() const->const Arcminute&
{
   return arcmin_;
}

auto nhill::Latitude::arcsecond() const->const Arcsecond&
{
   return arcsec_;
}

auto nhill::Latitude::milliarcsecond() const->const Milliarcsecond &
{
   return marcsec_;
}

void nhill::Latitude::set(Direction dir, const Arcdegree & arcdeg, const Arcminute & arcmin, const Arcsecond & arcsec, const Milliarcsecond & marcsec)
{
   unsigned d{ static_cast <unsigned>(arcdeg.value()) };
   unsigned m{ static_cast <unsigned>(arcmin.value()) };
   unsigned s{ static_cast <unsigned>(arcsec.value()) };
   unsigned ms{ static_cast<unsigned>(marcsec.value()) };

   ms = adjust_milliarcsecond(ms, &s, &m, &d);
   s = adjust_arcsecond(s, &m, &d);
   m = adjust_arcminute(m, &d);

   dir_ = dir;
   arcdeg_.value(d);
   arcmin_.value(m);
   arcsec_.value(s);
   marcsec_.value(ms);
}

void nhill::Latitude::clear()
{
   dir_ = Direction::N;
   arcdeg_.clear();
   arcmin_.clear();
   arcsec_.clear();
   marcsec_.clear();
}

std::string nhill::Latitude::to_string() const
{
   return nhill::geometry::angle_to_string(to_char(direction()), arcdegree(), arcminute(), arcsecond(), milliarcsecond());
}

auto nhill::to_latitude_s(unsigned arcdeg, unsigned arcmin, unsigned arcsec, unsigned marcsec /*= 0*/)->Latitude
{
   using namespace nhill::math;

   marcsec = adjust_milliarcsecond<unsigned>(marcsec, &arcsec, &arcmin, &arcdeg);
   arcsec = adjust_arcsecond<unsigned>(arcsec, &arcmin, &arcdeg);
   arcmin = adjust_arcminute<unsigned>(arcmin, &arcdeg);

   return {
      Latitude::Direction::S,
      static_cast<Latitude::Arcdegree::value_type>(arcdeg),
      static_cast<Arcminute::value_type>(arcmin),
      static_cast<Arcsecond::value_type>(arcsec),
      static_cast<Milliarcsecond::value_type>(marcsec)
   };
}

auto nhill::to_latitude_n(unsigned arcdeg, unsigned arcmin, unsigned arcsec, unsigned marcsec)->Latitude
{
   using namespace nhill::math;

   marcsec = adjust_milliarcsecond<unsigned>(marcsec, &arcsec, &arcmin, &arcdeg);
   arcsec = adjust_arcsecond<unsigned>(arcsec, &arcmin, &arcdeg);
   arcmin = adjust_arcminute<unsigned>(arcmin, &arcdeg);

   return {
      Latitude::Direction::N,
      static_cast<Latitude::Arcdegree::value_type>(arcdeg),
      static_cast<Arcminute::value_type>(arcmin),
      static_cast<Arcsecond::value_type>(arcsec),
      static_cast<Milliarcsecond::value_type>(marcsec)
   };
}

auto nhill::to_latitude(std::string_view str)->Latitude
{
   char sign_sym{ chr::null<char>() };
   geometry::UAngle uangle{ geometry::to_uangle(str, &sign_sym) };

   using Direction = Latitude::Direction;
   using Arcdeg_t = Latitude::Arcdegree::value_type;
   using Arcmin_t = Arcminute::value_type;
   using Arcsec_t = Arcsecond::value_type;
   using Marcsec_t = Milliarcsecond::value_type;

   constexpr auto minus{ chr::minus<char>() };
   constexpr auto S{ 'S' };

   Direction dir{ ((sign_sym == minus) || (sign_sym == S)) ? Direction::S : Direction::N };
   Arcdeg_t arcdeg{ static_cast<Arcdeg_t>(uangle.arcdegree) };
   Arcmin_t arcmin{ static_cast<Arcmin_t>(uangle.arcminute) };
   Arcsec_t arcsec{ static_cast<Arcsec_t>(uangle.arcsecond) };
   Marcsec_t marcsec{ static_cast<Marcsec_t>(uangle.milliarcsecond) };

   return { dir, arcdeg, arcmin, arcsec, marcsec };
}

char nhill::to_char(Latitude::Direction dir)
{
   return (dir == Latitude::Direction::N) ? 'N' : 'S';
}

string nhill::to_string(const Latitude & lat)
{
   return nhill::geometry::angle_to_string(
      to_char(lat.direction()),
      lat.arcdegree(),
      lat.arcminute(),
      lat.arcsecond(),
      lat.milliarcsecond()
   );
}

auto nhill::operator+(const Latitude & a, const Latitude & b)->Latitude
{
   geometry::Degree u{ to_degree<double>(a) };
   geometry::Degree v{ to_degree<double>(b) };
   geometry::Degree w{ u + v };
   return to_latitude<double>(w, true);
}

auto nhill::operator-(const Latitude & a, const Latitude & b)->Latitude
{
   geometry::Degree u{ to_degree<double>(a) };
   geometry::Degree v{ to_degree<double>(b) };
   geometry::Degree w{ u - v };
   return to_latitude<double>(w, true);
}
