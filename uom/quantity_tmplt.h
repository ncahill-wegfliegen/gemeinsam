#pragma once

#include "quantity.h"

namespace nhill
{
namespace uom
{

template<typename Uom, Prefix prefix_, Uom uom_, typename T = double>
class Quantity_template : public Quantity<Uom, T>
{
public:
   using base = Quantity<Uom, T>;

   Quantity_template( T value = {} );
   Quantity_template( const Quantity_template& other );
   Quantity_template( Quantity_template&& other );
   virtual ~Quantity_template();

   virtual Quantity_template& operator=( const Quantity_template& other );
   virtual Quantity_template& operator=( Quantity_template&& other );
   virtual Quantity_template& operator=( T value ); // Assign the value: no conversion
};

}
}

#pragma region Definitions
template<typename Uom, nhill::uom::Prefix prefix_, Uom uom_, typename T>
nhill::uom::Quantity_template<Uom, prefix_, uom_, T>::Quantity_template( T value /*= {}*/ )
   : base{prefix_, uom_, value}
{
}

template<typename Uom, nhill::uom::Prefix prefix_, Uom uom_, typename T>
nhill::uom::Quantity_template<Uom, prefix_, uom_, T>::Quantity_template( const Quantity_template& other )
   : base{other}
{
}

template<typename Uom, nhill::uom::Prefix prefix_, Uom uom_, typename T>
nhill::uom::Quantity_template<Uom, prefix_, uom_, T>::Quantity_template( Quantity_template&& other )
   : base{std::move(other)}
{
}

template<typename Uom, nhill::uom::Prefix prefix_, Uom uom_, typename T>
nhill::uom::Quantity_template<Uom, prefix_, uom_, T>::~Quantity_template()
{
}

template<typename Uom, nhill::uom::Prefix prefix_, Uom uom_, typename T>
auto nhill::uom::Quantity_template<Uom, prefix_, uom_, T>::operator=( const Quantity_template& other )->Quantity_template&
{
   base::operator=( other );
   return *this;
}

template<typename Uom, nhill::uom::Prefix prefix_, Uom uom_, typename T>
auto nhill::uom::Quantity_template<Uom, prefix_, uom_, T>::operator=( Quantity_template&& other )->Quantity_template&
{
   base::operator=( std::move(other) );
   return *this;
}

template<typename Uom, nhill::uom::Prefix prefix_, Uom uom_, typename T>
auto nhill::uom::Quantity_template<Uom, prefix_, uom_, T>::operator=( T value )->Quantity_template&
{
   base::operator=( value );
   return *this;
}

#pragma endregion
