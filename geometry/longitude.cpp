#include "longitude.h"
#include "uangle.h"
#include "convert.h"

using namespace std;

nhill::Longitude::Longitude()
   : dir_{Direction::E}
   , arcdeg_{}
   , arcmin_{}
   , arcsec_{}
   , marcsec_{}
{
}

nhill::Longitude::Longitude( Direction dir, const Arcdegree & arcdeg, const Arcminute & arcmin, const Arcsecond & arcsec, const Milliarcsecond& marcsec )
{
   set( dir, arcdeg, arcmin, arcsec, marcsec );
}

nhill::Longitude::Longitude( const Longitude & ) = default;
auto nhill::Longitude::operator=(const Longitude &)->Longitude & = default;

nhill::Longitude::Longitude( Longitude && ) noexcept = default;
auto nhill::Longitude::operator=(Longitude &&) noexcept->Longitude & = default;

nhill::Longitude::~Longitude() = default;

auto nhill::Longitude::direction() const->const Direction &
{
   return dir_;
}

auto nhill::Longitude::arcdegree() const->const Arcdegree&
{
   return arcdeg_;
}

auto nhill::Longitude::arcminute() const->const Arcminute&
{
   return arcmin_;
}

auto nhill::Longitude::arcsecond() const->const Arcsecond&
{
   return arcsec_;
}

auto nhill::Longitude::milliarcsecond() const->const Milliarcsecond &
{
   return marcsec_;
}

void nhill::Longitude::set( Direction dir, const Arcdegree & arcdeg, const Arcminute & arcmin, const Arcsecond & arcsec, const Milliarcsecond & marcsec )
{
   unsigned d{static_cast <unsigned>(arcdeg.value())};
   unsigned m{static_cast <unsigned>(arcmin.value())};
   unsigned s{static_cast <unsigned>(arcsec.value())};
   unsigned ms{static_cast<unsigned>(marcsec.value())};

   ms = adjust_milliarcsecond( ms, &s, &m, &d );
   s = adjust_arcsecond( s, &m, &d );
   m = adjust_arcminute( m, &d );

   dir_ = dir;
   arcdeg_.value( d );
   arcmin_.value( m );
   arcsec_.value( s );
   marcsec_.value( ms );
}

void nhill::Longitude::clear()
{
   dir_ = Direction::E;
   arcdeg_.clear();
   arcmin_.clear();
   arcsec_.clear();
   marcsec_.clear();
}

std::string nhill::Longitude::to_string() const
{
   return nhill::geometry::angle_to_string(to_char(direction()), arcdegree(), arcminute(), arcsecond(), milliarcsecond());
}

auto nhill::to_longitude_w(unsigned arcdeg, unsigned arcmin, unsigned arcsec, unsigned marcsec /*= 0*/ )->Longitude
{
   using namespace nhill::math;

   marcsec = adjust_milliarcsecond<unsigned>( marcsec, &arcsec, &arcmin, &arcdeg );
   arcsec = adjust_arcsecond<unsigned>( arcsec, &arcmin, &arcdeg );
   arcmin = adjust_arcminute<unsigned>( arcmin, &arcdeg );

   return {
      Longitude::Direction::W,
      static_cast<Longitude::Arcdegree::value_type>(arcdeg), 
      static_cast<Arcminute::value_type>(arcmin), 
      static_cast<Arcsecond::value_type>(arcsec), 
      static_cast<Milliarcsecond::value_type>(marcsec)
   };
}

auto nhill::to_longitude( std::string_view str )->Longitude
{
   char sign_sym{chr::null<char>()};
   geometry::UAngle uangle{geometry::to_uangle( str, &sign_sym )};

   using Direction = Longitude::Direction;
   using Arcdeg_t = Longitude::Arcdegree::value_type;
   using Arcmin_t = Arcminute::value_type;
   using Arcsec_t = Arcsecond::value_type;
   using Marcsec_t = Milliarcsecond::value_type;

   constexpr auto minus{chr::minus<char>()};
   constexpr auto W{'W'};

   Direction dir{ ((sign_sym == minus) || (sign_sym == W)) ? Direction::W : Direction::E };
   Arcdeg_t arcdeg{ static_cast<Arcdeg_t>(uangle.arcdegree)};
   Arcmin_t arcmin{ static_cast<Arcmin_t>(uangle.arcminute)};
   Arcsec_t arcsec{ static_cast<Arcsec_t>(uangle.arcsecond)};
   Marcsec_t marcsec{ static_cast<Marcsec_t>(uangle.milliarcsecond)};

   return {dir, arcdeg, arcmin, arcsec, marcsec};
}

char nhill::to_char( Longitude::Direction dir )
{
   return (dir == Longitude::Direction::E) ? 'E' : 'W';
}

string nhill::to_string( const Longitude & lon )
{
   return nhill::geometry::angle_to_string(
      to_char( lon.direction() ), 
      lon.arcdegree(), 
      lon.arcminute(), 
      lon.arcsecond(), 
      lon.milliarcsecond() 
   );
}

auto nhill::operator+( const Longitude & a, const Longitude & b )->Longitude
{
   geometry::Degree u{to_degree<double>( a )};
   geometry::Degree v{to_degree<double>( b )};
   geometry::Degree w{u + v};
   return to_longitude<double>( w, true);
}

auto nhill::operator-( const Longitude & a, const Longitude & b )->Longitude
{
   geometry::Degree u{to_degree<double>( a )};
   geometry::Degree v{to_degree<double>( b )};
   geometry::Degree w{u - v};
   return to_longitude<double>( w, true );
}
