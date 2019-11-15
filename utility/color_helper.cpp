#include "color_helper.h"
#include "../str.h"
#include <sstream>
#include <cmath>

using namespace std;

void nhill::clear( Color& c )
{
   c.r = 0x00;
   c.g = 0x00;
   c.b = 0x00;
}

string nhill::to_string( const Color & c)
{
   ostringstream oss;

   oss << c.r << "," << c.g << "," << c.b;

   return oss.str();
}

bool nhill::parse( Color& c,  std::string_view s )
{
   clear( c );

   auto comp{ str::split( s, ',' ) }; // The color components
   auto sz{ comp.size() }; // The size of the color component container

   if( sz == 0 )
   {
      return false;
   }

   if( 0 < sz )
   {
      c.r = static_cast<uint8_t>( stoi( comp[0] ) );
   }

   if( 1 < sz )
   {
      c.g = static_cast<uint8_t>(stoi( comp[1] ));
   }

   if( 2 < sz )
   {
      c.b = static_cast<uint8_t>(stoi( comp[2] ));
   }

   return true;
}

uint32_t nhill::to_rgb( const Color & c)
{
   uint32_t rgb{ 0x00'00'00'FF };  // The return value: a single rgb quantity

   uint32_t r{ static_cast<uint32_t>(c.r) };
   uint32_t g{ static_cast<uint32_t>(c.g) };
   uint32_t b{ static_cast<uint32_t>(c.b) };

   rgb |= r << 24;
   rgb |= g << 16;
   rgb |= b << 8;

   return rgb;
}

bool nhill::from_rgb( Color& c,  uint32_t rgb )
{
   uint32_t r{ (rgb & 0xFF000000) >> 24 }; // red component
   uint32_t g{ (rgb & 0x00FF0000) >> 16 }; // green component
   uint32_t b{ (rgb & 0x0000FF00) >> 8 }; // blue component

   c.r = static_cast<uint8_t>(r);
   c.g = static_cast<uint8_t>(g);
   c.b = static_cast<uint8_t>(b);

   return true;
};


bool nhill::is_valid_color_component( int x )
{
   return -1 < x && x < 256;
}

double nhill::distance( const Color& c1, const Color& c2 )
{
   double dr2 = static_cast<double>(c2.r) - static_cast<double>(c1.r);
   double dg2 = static_cast<double>(c2.g) - static_cast<double>(c1.g);
   double db2 = static_cast<double>(c2.b) - static_cast<double>(c1.b);

   dr2 *= dr2;
   dg2 *= dg2;
   db2 *= db2;

   double d = std::sqrt( dr2 + dg2 + db2 );

   return d;
}
