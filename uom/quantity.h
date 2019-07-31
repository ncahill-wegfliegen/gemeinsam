#pragma once

#include "..\utility\value.h"
#include "puom.h"

namespace nhill
{
namespace uom
{

template<typename Uom> inline
double convert( Prefix dst_prefix, Uom dst_uom, double src_value, Prefix src_prefix, Uom src_uom );


template<typename Uom, typename T = double>
class Quantity : public utility::Value<T>, Prefixed_uom<Uom>
{
public:
   using base_value = utility::Value<T>;
   using base_puom  = Prefixed_uom<Uom>;

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
template<typename Uom, typename T>
nhill::uom::Quantity<Uom, T>::Quantity( Prefix prefix, Uom uom, T value /*= 0*/ )
   : base_value{value}
   , base_puom{prefix, uom}
{

}

template<typename Uom, typename T>
nhill::uom::Quantity<Uom, T>::Quantity( const Prefixed_uom<Uom>& puom, T value /*= 0*/ )
   : base_value{value}
   , base_puom{puom}
{

}

template<typename Uom, typename T>
auto nhill::uom::Quantity<Uom, T>::operator=( T value )->Quantity &
{
   base_value::operator=( value );
   return *this;
}

template<typename Uom, typename T>
nhill::uom::Quantity<Uom, T>::Quantity( const Quantity& ) = default;

template<typename Uom, typename T>
auto nhill::uom::Quantity<Uom, T>::operator=( const Quantity& other)->Quantity &
{
   double other_value{static_cast<double>(other.value())};
   double value{nhill::uom::convert( prefix, uom, other_value, other.prefix, other.uom )};
   base_value::operator=( static_cast<T>(value) );
   return *this;
}

template<typename Uom, typename T>
nhill::uom::Quantity<Uom, T>::Quantity( Quantity&& ) = default;

template<typename Uom, typename T>
auto nhill::uom::Quantity<Uom, T>::operator=( Quantity&& other )->Quantity & 
{
   double other_value{static_cast<double>(other.value())};
   double value{nhill::uom::convert( prefix, uom, other_value, other.prefix, other.uom )};
   base_value::operator=( static_cast<T>(value) );
   return *this;
}

template<typename Uom, typename T>
nhill::uom::Quantity<Uom, T>::~Quantity() = default;

template<typename Uom, typename T>
std::string nhill::uom::Quantity<Uom, T>::to_string() const
{
   std::ostringstream oss;
   oss << base_value::to_string() << " " << base_puom::to_string();
   return oss.str();
}
#pragma endregion
