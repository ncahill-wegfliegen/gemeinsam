#pragma once

#include "prefix.h"
#include "../utility/object.h"
#include <string>
#include <sstream>
#include <type_traits>

namespace nhill
{
namespace uom
{

/// <summary>Prefixed unit of measurement.</summary>
template<typename Uom>
class Prefixed_uom : public Object
{
   static_assert(std::is_enum_v<Uom>, "The template parameter must be a strongly typed enumeration.");

public:
   using uom_type = Uom;

   Prefixed_uom( Uom uom );
   Prefixed_uom( Prefix prefix, Uom uom );

   Prefixed_uom( const Prefixed_uom& );
   Prefixed_uom& operator=( const Prefixed_uom& ) = delete;

   Prefixed_uom( Prefixed_uom&& ) noexcept;
   Prefixed_uom& operator=( Prefixed_uom&& ) noexcept = delete;

   virtual ~Prefixed_uom();

   const Prefix prefix;
   const Uom uom;

   std::string to_string() const override;
};

}
}

#pragma region Operators
namespace nhill
{
namespace uom
{

template<typename Uom>
bool operator==( const Prefixed_uom<Uom>& a, const Prefixed_uom<Uom>& b )
{
   return (a.prefix == b.prefix) && (a.uom == b.uom);
}

template<typename Uom>
bool operator!=( const Prefixed_uom<Uom>& a, const Prefixed_uom<Uom>& b )
{
   return !(a == b);
}

}
}
#pragma endregion

#pragma region Definitions
template<typename Uom> 
nhill::uom::Prefixed_uom<Uom>::Prefixed_uom( Uom uom )
   : prefix{Prefix::none}
   , uom{uom}
{
}

template<typename Uom>
nhill::uom::Prefixed_uom<Uom>::Prefixed_uom( Prefix prefix, Uom uom )
   : prefix{prefix}
   , uom{uom}
{
}

template<typename Uom>
nhill::uom::Prefixed_uom<Uom>::Prefixed_uom( const Prefixed_uom& ) = default;

template<typename Uom>
nhill::uom::Prefixed_uom<Uom>::Prefixed_uom( Prefixed_uom&& ) noexcept = default;

template<typename Uom>
nhill::uom::Prefixed_uom<Uom>::~Prefixed_uom() = default;

template<typename Uom>
std::string nhill::uom::Prefixed_uom<Uom>::to_string() const
{
   std::ostringstream oss;
   if( prefix != Prefix::none )
   {
      oss << to_label( prefix );
   }
   oss << to_label( uom );
   return oss.str();
}
#pragma endregion

