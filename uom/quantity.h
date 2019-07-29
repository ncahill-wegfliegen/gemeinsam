#pragma once

#include "..\utility\value.h"
#include "puom.h"

namespace nhill
{
namespace uom
{

template<typename T, typename Uom> inline
double convert( Prefix dst_prefix, Uom dst_uom, double src_value, Prefix src_prefix, Uom src_uom );


template<typename T, typename Uom>
class Quantity : public utility::Value<T>, Prefixed_uom<Uom>
{
public:
   using base_value = utility::Value<T>;
   using base_puom  = Prefixed_uom<Uom>;
   using uom_type = Uom;

   Quantity( Prefix prefix, Uom uom, T value = {} );
   Quantity( const Prefixed_uom<Uom>& puom, T value = {} );
   virtual Quantity& operator=( T value ); // Assign the value: no conversion

   Quantity( const Quantity& );
   virtual Quantity& operator=( const Quantity& );

   Quantity( Quantity&& );
   virtual Quantity& operator=( Quantity&& );

   ~Quantity();

   virtual std::string to_string() const;
};

}
}

#pragma region Definitions
template<typename T, typename Uom>
nhill::uom::Quantity<T, Uom>::Quantity( Prefix prefix, Uom uom, T value /*= 0*/ )
   : base_value{value}
   , base_puom{prefix, uom}
{

}

template<typename T, typename Uom>
nhill::uom::Quantity<T, Uom>::Quantity( const Prefixed_uom<Uom>& puom, T value /*= 0*/ )
   : base_value{value}
   , base_puom{puom}
{

}

template<typename T, typename Uom>
auto nhill::uom::Quantity<T, Uom>::operator=( T value )->Quantity &
{
   base_value::operator=( value );
   return *this;
}

template<typename T, typename Uom>
nhill::uom::Quantity<T, Uom>::Quantity( const Quantity& ) = default;

template<typename T, typename Uom>
auto nhill::uom::Quantity<T, Uom>::operator=( const Quantity& )->Quantity & = default;

template<typename T, typename Uom>
nhill::uom::Quantity<T, Uom>::Quantity( Quantity&& ) = default;

template<typename T, typename Uom>
auto nhill::uom::Quantity<T, Uom>::operator=( Quantity&& other )->Quantity & = default;

template<typename T, typename Uom>
nhill::uom::Quantity<T, Uom>::~Quantity() = default;

template<typename T, typename Uom>
std::string nhill::uom::Quantity<T, Uom>::to_string() const
{
   std::ostringstream oss;
   oss << base_value::to_string() << " " << base_puom::to_string();
   return oss.str();
}
#pragma endregion
