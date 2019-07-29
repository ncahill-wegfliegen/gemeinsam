#pragma once

#include "quantity.h"

namespace nhill
{
namespace uom
{

template<typename Uom, Prefix prefix_, Uom uom_>
class Quantity_template : public Quantity<Uom>
{
   static_assert(std::is_enum_v<Uom>, "The template parameter must be a strongly typed enumeration.");

public:
   using base = Quantity<Uom>;

   Quantity_template( double value = {} );
   Quantity_template( const Quantity_template& other );
   Quantity_template( Quantity_template&& other );
   virtual ~Quantity_template();

   virtual Quantity_template& operator=( const Quantity_template& other );
   virtual Quantity_template& operator=( Quantity_template&& other );
   virtual Quantity_template& operator=( double value ); // Assign the value: no conversion
};

}
}

#pragma region Definitions
template<typename Uom, nhill::uom::Prefix prefix_, Uom uom_>
nhill::uom::Quantity_template<Uom, prefix_, uom_>::Quantity_template( double value /*= {}*/ )
   : base{prefix_, uom_, value}
{
}

template<typename Uom, nhill::uom::Prefix prefix_, Uom uom_>
nhill::uom::Quantity_template<Uom, prefix_, uom_>::Quantity_template( const Quantity_template& other )
   : base{other}
{
}

template<typename Uom, nhill::uom::Prefix prefix_, Uom uom_>
nhill::uom::Quantity_template<Uom, prefix_, uom_>::Quantity_template( Quantity_template&& other )
   : base{std::move(other)}
{
}

template<typename Uom, nhill::uom::Prefix prefix_, Uom uom_>
nhill::uom::Quantity_template<Uom, prefix_, uom_>::~Quantity_template()
{
}

template<typename Uom, nhill::uom::Prefix prefix_, Uom uom_>
auto nhill::uom::Quantity_template<Uom, prefix_, uom_>::operator=( const Quantity_template& other )->Quantity_template&
{
   base::operator=( other );
   return *this;
}

template<typename Uom, nhill::uom::Prefix prefix_, Uom uom_>
auto nhill::uom::Quantity_template<Uom, prefix_, uom_>::operator=( Quantity_template&& other )->Quantity_template&
{
   base::operator=( std::move(other) );
   return *this;
}

template<typename Uom, nhill::uom::Prefix prefix_, Uom uom_>
auto nhill::uom::Quantity_template<Uom, prefix_, uom_>::operator=( double value )->Quantity_template&
{
   base::operator=( value );
   return *this;
}

#pragma endregion
