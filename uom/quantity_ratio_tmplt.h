#pragma once

#include "quantity_ratio.h"

namespace nhill
{
namespace uom
{

template<typename Uom_numerator, typename Uom_denominator, Prefix prefix_numerator, Uom_numerator uom_numerator, Prefix prefix_denominator, Uom_denominator uom_denominator, typename T = T>
class Quantity_ratio_template : public Quantity_ratio<Uom_numerator, Uom_denominator, T>
{
public:
   using base = Quantity_ratio<Uom_numerator, Uom_denominator, T>;

   Quantity_ratio_template( T value = {} );

	/// <summary>Copy Constructor.  Performs a conversion from the source quantity type to this quantity type.</summary>
	/// <param name="src">The quantity to be copied.</param>
	Quantity_ratio_template( const base& src );

	/// <summary>Copy Constructor.  Performs a conversion from the source quantity type to this quantity type.</summary>
	/// <param name="src">The quantity to be copied.</param>
	template<Prefix prefix_numerator_src, Uom_numerator uom_numerator_src, Prefix prefix_denominator_src, Uom_denominator uom_denominator_src, typename U = double>
	Quantity_ratio_template( const Quantity_ratio_template<Uom_numerator, Uom_denominator, prefix_numerator_src, uom_numerator_src, prefix_denominator_src, uom_denominator_src, U>& src );

	/// <summary>Copy assignment operator.  Performs a conversion from the source quantity type to this quantity type.</summary>
	/// <param name="src">The quantity to be copied.</param>
	/// <returns>A reference to this instance.</returns>
	template<Prefix prefix_numerator_src, Uom_numerator uom_numerator_src, Prefix prefix_denominator_src, Uom_denominator uom_denominator_src, typename U = double>
	Quantity_ratio_template& operator=( const Quantity_ratio_template<Uom_numerator, Uom_denominator, prefix_numerator_src, uom_numerator_src, prefix_denominator_src, uom_denominator_src, U>& src );

	/// <summary>Move constructor.  Create a quantity with the same prefix and unit as the source.</summary>
   /// <param name="src">The source quantity to be moved.  The Value is simply copied into this instance.</param>
   Quantity_ratio_template( Quantity_ratio_template&& src );

	/// <summary>Move assignment operator.  Only works between instances with the same 'prefix' and 'unit'.</summary>
	/// <param name="len">The quantity to be moved.  The Value is simply copied into this instance.</param>
	/// <returns>A reference to this instance.</returns>
	Quantity_ratio_template& operator=( Quantity_ratio_template&& src );

	/// <summary>Copy assignment operator.  Performs a conversion from the source quantity type to this quantity type.</summary>
	/// <param name="src">The quantity to be copied.</param>
	/// <returns>A reference to this instance.</returns>
	Quantity_ratio_template& operator=( const base& src );

   virtual ~Quantity_ratio_template();
};

namespace ratio
{
template<typename Uom_numerator, typename Uom_denominator, Prefix prefix_numerator, Uom_numerator uom_numerator, Prefix prefix_denominator, Uom_denominator uom_denominator, typename T = double>
using Quantity_template = Quantity_ratio_template<Uom_numerator, Uom_denominator, prefix_numerator, uom_numerator, prefix_denominator, uom_denominator, T>;
}

}
}


template<typename Uom_numerator, typename Uom_denominator, nhill::uom::Prefix prefix_numerator, Uom_numerator uom_numerator, nhill::uom::Prefix prefix_denominator, Uom_denominator uom_denominator, typename T>
nhill::uom::Quantity_ratio_template<Uom_numerator, Uom_denominator, prefix_numerator, uom_numerator, prefix_denominator, uom_denominator, T>::Quantity_ratio_template( T value /*= {}*/ )
	: base{prefix_numerator, uom_numerator, prefix_denominator, uom_denominator, value}
{
}

template<typename Uom_numerator, typename Uom_denominator, nhill::uom::Prefix prefix_numerator, Uom_numerator uom_numerator, nhill::uom::Prefix prefix_denominator, Uom_denominator uom_denominator, typename T>
nhill::uom::Quantity_ratio_template<Uom_numerator, Uom_denominator, prefix_numerator, uom_numerator, prefix_denominator, uom_denominator, T>::Quantity_ratio_template( const base& src )
	: base{prefix_numerator, uom_numerator, prefix_denominator, uom_denominator}
{
	*this = src;
}

template<typename Uom_numerator, typename Uom_denominator, nhill::uom::Prefix prefix_numerator, Uom_numerator uom_numerator, nhill::uom::Prefix prefix_denominator, Uom_denominator uom_denominator, typename T>
template<nhill::uom::Prefix prefix_numerator_src, Uom_numerator uom_numerator_src, nhill::uom::Prefix prefix_denominator_src, Uom_denominator uom_denominator_src, typename U>
nhill::uom::Quantity_ratio_template<Uom_numerator, Uom_denominator, prefix_numerator, uom_numerator, prefix_denominator, uom_denominator, T>::Quantity_ratio_template( const Quantity_ratio_template<Uom_numerator, Uom_denominator, prefix_numerator_src, uom_numerator_src, prefix_denominator_src, uom_denominator_src, U>& src )
	: base{prefix_numerator, uom_numerator, prefix_denominator, uom_denominator}
{
	*this = src;
}

template<typename Uom_numerator, typename Uom_denominator, nhill::uom::Prefix prefix_numerator, Uom_numerator uom_numerator, nhill::uom::Prefix prefix_denominator, Uom_denominator uom_denominator, typename T>
template<nhill::uom::Prefix prefix_numerator_src, Uom_numerator uom_numerator_src, nhill::uom::Prefix prefix_denominator_src, Uom_denominator uom_denominator_src, typename U>
auto nhill::uom::Quantity_ratio_template<Uom_numerator, Uom_denominator, prefix_numerator, uom_numerator, prefix_denominator, uom_denominator, T>::operator=( const Quantity_ratio_template<Uom_numerator, Uom_denominator, prefix_numerator_src, uom_numerator_src, prefix_denominator_src, uom_denominator_src, U>& src )->Quantity_ratio_template &
{
	base::operator=( src );
	return *this;
}

template<typename Uom_numerator, typename Uom_denominator, nhill::uom::Prefix prefix_numerator, Uom_numerator uom_numerator, nhill::uom::Prefix prefix_denominator, Uom_denominator uom_denominator, typename T>
nhill::uom::Quantity_ratio_template<Uom_numerator, Uom_denominator, prefix_numerator, uom_numerator, prefix_denominator, uom_denominator, T>::Quantity_ratio_template( Quantity_ratio_template&& src )
	: base{prefix_numerator, uom_numerator, prefix_denominator, uom_denominator, static_cast<T>(src)}
{
}

template<typename Uom_numerator, typename Uom_denominator, nhill::uom::Prefix prefix_numerator, Uom_numerator uom_numerator, nhill::uom::Prefix prefix_denominator, Uom_denominator uom_denominator, typename T>
auto nhill::uom::Quantity_ratio_template<Uom_numerator, Uom_denominator, prefix_numerator, uom_numerator, prefix_denominator, uom_denominator, T>::operator=( Quantity_ratio_template&& src )->Quantity_ratio_template &
{
	base::operator=( std::move( src ) );
	return *this;
}

template<typename Uom_numerator, typename Uom_denominator, nhill::uom::Prefix prefix_numerator, Uom_numerator uom_numerator, nhill::uom::Prefix prefix_denominator, Uom_denominator uom_denominator, typename T>
auto nhill::uom::Quantity_ratio_template<Uom_numerator, Uom_denominator, prefix_numerator, uom_numerator, prefix_denominator, uom_denominator, T>::operator=( const base& src )->Quantity_ratio_template &
{
	base::operator=( src );
	return *this;
}

template<typename Uom_numerator, typename Uom_denominator, nhill::uom::Prefix prefix_numerator, Uom_numerator uom_numerator, nhill::uom::Prefix prefix_denominator, Uom_denominator uom_denominator, typename T>
nhill::uom::Quantity_ratio_template<Uom_numerator, Uom_denominator, prefix_numerator, uom_numerator, prefix_denominator, uom_denominator, T>::~Quantity_ratio_template()
{
}




