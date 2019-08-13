#include "version.h"
#include "../utility/str.h"
#include <vector>
#include <algorithm>
#include <limits>
#include <sstream>

using namespace std;

namespace
{
nhill::Version::value_type clamp( int value )
{
   auto val{static_cast<nhill::Version::value_type>(value)};
   auto zero{ nhill::Version::value_type{0} };
   constexpr auto max = numeric_limits<nhill::Version::value_type>::max();
   return (std::max)( zero, (std::min)(val, max ) );
}
}

nhill::Version::Version()
{
   clear();
}

nhill::Version::Version( int major, int minor, int build, int revision )
{
   this->major   ( major    );
   this->minor   ( minor    );
   this->build   ( build    );
   this->revision( revision );
}

nhill::Version::Version( const string& s )
{
   *this = s;
}

auto nhill::Version::major() const->int
{
   return major_;
}

void nhill::Version::major( int value )
{
   major_ = clamp( value );
}

auto nhill::Version::minor() const->int
{
   return minor_;
}

void nhill::Version::minor( int value )
{
   minor_ = clamp( value );
}

auto nhill::Version::build() const->int
{
   return build_;
}

void nhill::Version::build( int value )
{
   build_ = clamp( value );
}

auto nhill::Version::revision() const->int
{
   return revision_;
}

void nhill::Version::revision( int value )
{
   revision_ = clamp( value );
}

string nhill::Version::to_string() const
{
   ostringstream oss;
   oss << major() << '.' << minor() << '.' << build() << '.' << revision();
   return oss.str();
}

void nhill::Version::clear()
{
   major    ( 0 );
   minor    ( 0 );
   build    ( 0 );
   revision ( 0 );
}

bool nhill::Version::is_empty() const
{
   return ( major() == 0 ) && ( minor() == 0 ) && ( build() == 0 ) && ( revision() == 0 );
}

auto nhill::Version::operator=( const string& s )->Version&
{
   clear();

   if( s.empty() )
      return *this;

   // split the input string on the period
   vector<string> items = str::split<char>( s, '.' );
   auto size = items.size();

   // assign the version items.
   if( 0 < size )
      major( stoi( items[0].c_str() ) );

   if( 1 < size )
      minor( stoi( items[1].c_str() ) );

   if( 2 < size )
      build( stoi( items[2].c_str() ) );

   if( 3 < size )
      revision( stoi( items[3].c_str() ) );

   return *this;
}

bool nhill::operator==( const Version& x, const Version& y )
{
   return(
      x.major   () == y.major   () &&
      x.minor   () == y.minor   () &&
      x.build   () == y.build   () &&
      x.revision() == y.revision()
      );
}

bool nhill::operator!=( const Version& x, const Version& y )
{
   return !(x == y);
}

ostream& nhill::operator<<( ostream& os, const Version& version )
{
   return os << version.to_string();
}

istream& nhill::operator>>( istream& is, Version& version )
{
   string s;
   is >> s;
   version = s;
   return is;
}
