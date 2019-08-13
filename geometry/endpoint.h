#pragma once


namespace nhill
{
namespace geometry
{

/// <summary>The endpoint of an interval.</summary>
/// <param name="T">The arithmetic type (signed/unsigned integer or floating point).</param>
/// <param name="Compare">A functor that takes two T values and returns true/false (for exampke, use one of the Compare methods in 'nhill/math/compare.h').</param>
/// <remarks>A value 'x' is valid if it compres true relative to the the endpoint value.</remarks>
/// <example>If the endpoint is 5 and the compare function is 'greater than', then
///   a value 'x' is valid if it is greater than 5.
/// </example>
template<typename T, template<typename,typename> class Compare>
class Endpoint
{
   static_assert(std::is_arithmetic_v<T>, "The template parameter must be an arithmetic type (i.e., either integral or floating point type).");

public:
   using value_type = T;
   using compare_type = Compare<T,T>;

   Endpoint( T endpnt = 0 );
   Endpoint& operator=( T endpnt );
   Endpoint( const Endpoint& );
   Endpoint& operator=( const Endpoint& );
   Endpoint( Endpoint&& );
   Endpoint& operator=( Endpoint&& );
   ~Endpoint();

   operator T() const;

   bool is_valid( T value )  const;

private:
   T value_; // The endpoint value.
   Compare<T,T> compare_; // The compare type.
};


}
}

template<typename T, template<typename, typename> class Compare> inline
nhill::geometry::Endpoint<T, Compare>::Endpoint( T endpnt )
   : value_{endpnt}
   , compare_{Compare<T,T>{}}
{

}

template<typename T, template<typename, typename> class Compare> inline
auto nhill::geometry::Endpoint<T, Compare>::operator=( T endpnt )->Endpoint &
{
   value_ = endpnt;
   
   return *this;
}



template<typename T, template<typename, typename> class Compare> inline
nhill::geometry::Endpoint<T, Compare>::Endpoint( const Endpoint& other )
   : value_{ other.value_ }
   , compare_{other.compare_}
{
}

template<typename T, template<typename, typename> class Compare> inline
auto nhill::geometry::Endpoint<T, Compare>::operator=( const Endpoint& other)->Endpoint &
{
   value_ = other.value_;
   compare_ = other.compare_;
   return *this;
}

template<typename T, template<typename, typename> class Compare> inline
nhill::geometry::Endpoint<T, Compare>::Endpoint( Endpoint&& other )
   : value_{other.value_}
   , compare_{other.compare_}
{
}

template<typename T, template<typename, typename> class Compare> inline
auto nhill::geometry::Endpoint<T, Compare>::operator=( Endpoint&& other)->Endpoint &
{
   value_ = other.value_;
   compare_ = other.compare_;
   return *this;
}

template<typename T, template<typename, typename> class Compare> inline
nhill::geometry::Endpoint<T, Compare>::~Endpoint()
{
}

template<typename T, template<typename, typename> class Compare> inline
nhill::geometry::Endpoint<T, Compare>::operator T() const
{
   return value_;
}

template<typename T, template<typename, typename> class Compare> inline
bool nhill::geometry::Endpoint<T, Compare>::is_valid( T value ) const
{
   return compare_( value, value_ );
}
