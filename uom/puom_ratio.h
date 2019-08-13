#pragma once

#include "puom.h"
#include "prefix.h"
#include "../utility/object.h"
#include <string>
#include <sstream>
#include <type_traits>

namespace nhill
{
namespace uom
{

template<typename Uom_numerator, typename Uom_denominator>
class Prefixed_uom_ratio : public virtual nhill::Object
{
public:
	static_assert(std::is_enum_v<Uom_numerator  >, "The template parameter for the numerator must be a stronly typed enumeration.");
	static_assert(std::is_enum_v<Uom_denominator>, "The template parameter for the demoniator must be a stronly typed enumeration.");

	using puom_num = Prefixed_uom<Uom_numerator>;
   using puom_den = Prefixed_uom<Uom_denominator>;

   Prefixed_uom_ratio();
   Prefixed_uom_ratio( const puom_num& num, const puom_den& den );
	Prefixed_uom_ratio( Prefix prefix_num, Uom_numerator uom_num, Prefix prefix_den, Uom_denominator uom_den );

   Prefixed_uom_ratio( const Prefixed_uom_ratio& src );
	Prefixed_uom_ratio& operator=( const Prefixed_uom_ratio& src ) = delete;
	
	Prefixed_uom_ratio( Prefixed_uom_ratio&& src );
	Prefixed_uom_ratio& operator=( Prefixed_uom_ratio&& src ) = delete;
	
	virtual ~Prefixed_uom_ratio();

   puom_num & numerator();
   const puom_num& numerator() const;
   void numerator( const puom_num& value );

   puom_den& denominator();
   const puom_den& denominator() const;
   void denominator( const puom_den& value );

   bool operator==( const Prefixed_uom_ratio& rhs ) const;
   bool operator!=( const Prefixed_uom_ratio& rhs ) const;

   virtual std::string to_string() const override;

private:
   puom_num num;
   puom_den den;
};

namespace ratio
{
template<typename Uom_numerator, typename Uom_denominator>
using puom = Prefixed_uom_ratio<Uom_numerator, Uom_denominator>;
}
}
}


#pragma region Definitions
template<typename Uom_numerator, typename Uom_denominator>
nhill::uom::Prefixed_uom_ratio<Uom_numerator, Uom_denominator>::Prefixed_uom_ratio()
   : num{ Prefix::none, Uom_numerator::none }
   , den( Prefix::none, Uom_denominator::none )
{
}

template<typename Uom_numerator, typename Uom_denominator>
nhill::uom::Prefixed_uom_ratio<Uom_numerator, Uom_denominator>::Prefixed_uom_ratio( const puom_num& num, const puom_den& den )
   : num( num )
   , den( den )
{
}

template<typename Uom_numerator, typename Uom_denominator>
nhill::uom::Prefixed_uom_ratio<Uom_numerator, Uom_denominator>::Prefixed_uom_ratio( Prefix prefix_num, Uom_numerator uom_num, Prefix prefix_den, Uom_denominator uom_den )
   : num( prefix_num, uom_num )
   , den( prefix_den, uom_den )
{
}

template<typename Uom_numerator, typename Uom_denominator>
nhill::uom::Prefixed_uom_ratio<Uom_numerator, Uom_denominator>::Prefixed_uom_ratio( const Prefixed_uom_ratio& src )
   : num( src.num )
   , den( src.den )
{
}

template<typename Uom_numerator, typename Uom_denominator>
nhill::uom::Prefixed_uom_ratio<Uom_numerator, Uom_denominator>::Prefixed_uom_ratio( Prefixed_uom_ratio&& src )
   : num( src.num )
   , den( src.den )
{
}

template<typename Uom_numerator, typename Uom_denominator>
nhill::uom::Prefixed_uom_ratio<Uom_numerator, Uom_denominator>::~Prefixed_uom_ratio()
{
}

template<typename Uom_numerator, typename Uom_denominator>
auto nhill::uom::Prefixed_uom_ratio<Uom_numerator, Uom_denominator>::numerator()->puom_num &
{
   return num;
}

template<typename Uom_numerator, typename Uom_denominator>
auto nhill::uom::Prefixed_uom_ratio<Uom_numerator, Uom_denominator>::numerator() const->const puom_num&
{
   return num;
}

template<typename Uom_numerator, typename Uom_denominator>
void nhill::uom::Prefixed_uom_ratio<Uom_numerator, Uom_denominator>::numerator( const puom_num& value )
{
   num = value;
}

template<typename Uom_numerator, typename Uom_denominator>
auto nhill::uom::Prefixed_uom_ratio<Uom_numerator, Uom_denominator>::denominator()->puom_den&
{
   return den;
}

template<typename Uom_numerator, typename Uom_denominator>
auto nhill::uom::Prefixed_uom_ratio<Uom_numerator, Uom_denominator>::denominator() const->const puom_den&
{
   return den;
}

template<typename Uom_numerator, typename Uom_denominator>
void nhill::uom::Prefixed_uom_ratio<Uom_numerator, Uom_denominator>::denominator( const puom_den& value )
{
   den = value;
}

template<typename Uom_numerator, typename Uom_denominator>
bool nhill::uom::Prefixed_uom_ratio<Uom_numerator, Uom_denominator>::operator==( const Prefixed_uom_ratio& rhs ) const
{
   return(numerator() == rhs.numerator()) && (denominator() == rhs.denominator());
}

template<typename Uom_numerator, typename Uom_denominator>
bool nhill::uom::Prefixed_uom_ratio<Uom_numerator, Uom_denominator>::operator!=( const Prefixed_uom_ratio& rhs ) const
{
   return(numerator() != rhs.numerator()) || (denominator() != rhs.denominator());
}

template<typename Uom_numerator, typename Uom_denominator>
std::string nhill::uom::Prefixed_uom_ratio<Uom_numerator, Uom_denominator>::to_string() const
{
   std::ostringstream oss;
   oss << numerator().to_string() << '/' << denominator().to_string();
   return oss.str();
}
#pragma endregion
