#pragma once

#include "puom_ratio.h"
#include "quantity.h"
#include "../utility/value_base.h"
#include <memory>
#include <string>
#include <sstream>

namespace nhill
{
namespace uom
{

template<typename Uom_numerator, typename Uom_denominator, typename T = double>
class Quantity_ratio : public nhill::utility::Value_base<T>, public Prefixed_uom_ratio<Uom_numerator, Uom_denominator>
{
public:
   using base_value = nhill::utility::Value_base<T>;
   using base_puom  = Prefixed_uom_ratio<Uom_numerator, Uom_denominator>;

   Quantity_ratio( const Prefixed_uom_ratio<Uom_numerator, Uom_denominator>& puom, T value = {} );
   Quantity_ratio( const Prefixed_uom<Uom_numerator>& num, const Prefixed_uom<Uom_denominator>& den, T value = {} );
   Quantity_ratio( Prefix prefixNum, Uom_numerator uomNum, Prefix prefixDen, Uom_denominator uomDen, T value = {} );
   Quantity_ratio& operator=( double value );

   Quantity_ratio( const Quantity_ratio& );
   Quantity_ratio& operator=( const Quantity_ratio& );

   Quantity_ratio( Quantity_ratio&& );
   Quantity_ratio& operator=( Quantity_ratio&& );

   virtual ~Quantity_ratio();

   virtual std::string to_string_value() const;
   virtual std::string to_string_puom() const;
   virtual std::string to_string() const;
};

namespace ratio
{
template<typename Uom_numerator, typename Uom_denominator, typename T>
using quantity = Quantity_ratio<Uom_numerator, Uom_denominator, T>;
}
}
}

#pragma region Definitions
template<typename Uom_numerator, typename Uom_denominator, typename T>
nhill::uom::Quantity_ratio<Uom_numerator, Uom_denominator, T>::Quantity_ratio( const Prefixed_uom_ratio<Uom_numerator, Uom_denominator>& puom, T value /*= {}*/ )
   : base_value( value )
   , base_puom( puom )
{
}

template<typename Uom_numerator, typename Uom_denominator, typename T>
nhill::uom::Quantity_ratio<Uom_numerator, Uom_denominator, T>::Quantity_ratio( const Prefixed_uom<Uom_numerator>& num, const Prefixed_uom<Uom_denominator>& den, T value /*= {}*/ )
   : base_value( value )
   , base_puom( num, den )
{
}

template<typename Uom_numerator, typename Uom_denominator, typename T>
nhill::uom::Quantity_ratio<Uom_numerator, Uom_denominator, T>::Quantity_ratio( Prefix prefixNum, Uom_numerator uomNum, Prefix prefixDen, Uom_denominator uomDen, T value /*= {}*/ )
   : base_value( value )
   , base_puom( prefixNum, uomNum, prefixDen, uomDen )
{
}

template<typename Uom_numerator, typename Uom_denominator, typename T>
nhill::uom::Quantity_ratio<Uom_numerator, Uom_denominator, T>::Quantity_ratio( Quantity_ratio&& other )
   : base_value( other )
   , base_puom( other.numerator(), other.denominator() )
{
}

template<typename Uom_numerator, typename Uom_denominator, typename T>
nhill::uom::Quantity_ratio<Uom_numerator, Uom_denominator, T>::Quantity_ratio( const Quantity_ratio& other )
   : base_value( other )
   , base_puom( other.numerator(), other.denominator() )
{
}

template<typename Uom_numerator, typename Uom_denominator, typename T>
nhill::uom::Quantity_ratio<Uom_numerator, Uom_denominator, T>::~Quantity_ratio()
{
}

template<typename Uom_numerator, typename Uom_denominator, typename T>
auto nhill::uom::Quantity_ratio<Uom_numerator, Uom_denominator, T>::operator=( Quantity_ratio&& other )->Quantity_ratio &
{
   return Quantity_ratio::operator = ( dynamic_cast<const Quantity_ratio&>(other) );
}

template<typename Uom_numerator, typename Uom_denominator, typename T>
auto nhill::uom::Quantity_ratio<Uom_numerator, Uom_denominator, T>::operator=( const Quantity_ratio& other )->Quantity_ratio&
{
   // The numerator and denominator quantities of this.
   Quantity<Uom_numerator> qnum( numerator() );
   Quantity<Uom_denominator> qden( denominator() );

   // The numerator and denominaotr quantities of other.
   Quantity<Uom_numerator> other_qnum( other.numerator(), other );
   Quantity<Uom_denominator> other_qden( other.denominator(), 1 );

   // Convert other to this.
   qnum = other_qnum;
   qden = other_qden;

   // Calculate the new Value.
   double value = qnum / qden;
   // Assign the new Value to this.
   base_value::operator=( value );

   return *this;
}

template<typename Uom_numerator, typename Uom_denominator, typename T>
auto nhill::uom::Quantity_ratio<Uom_numerator, Uom_denominator, T>::operator=( double value )->Quantity_ratio&
{
   base_value::operator=( value );
   return *this;
}

template<typename Uom_numerator, typename Uom_denominator, typename T>
std::string nhill::uom::Quantity_ratio<Uom_numerator, Uom_denominator, T>::to_string_value() const
{
   return base_value::string();
}

template<typename Uom_numerator, typename Uom_denominator, typename T>
std::string nhill::uom::Quantity_ratio<Uom_numerator, Uom_denominator, T>::to_string_puom() const
{
   return base_puom::to_string();
}

template<typename Uom_numerator, typename Uom_denominator, typename T>
std::string nhill::uom::Quantity_ratio<Uom_numerator, Uom_denominator, T>::to_string() const
{
   std::ostringstream oss;
   oss << to_string_value() << ' ' << to_string_puom();
   return oss.str();
}
#pragma endregion