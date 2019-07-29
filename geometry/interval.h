#pragma once

#include "interval_interface.h"
#include "endpoint.h"
#include <functional>
#include <sstream>
#include <stdexcept>

namespace nhill
{
namespace geometry
{

template<typename T, template <typename, typename> class A_compare, template <typename, typename> class B_compare>
class Interval : public nhill::geometry::Interval_interface<T>
{
   static_assert(std::is_arithmetic_v<T>, "The template parameter must be an arithmetic type (i.e., either integral or floating point type).");

public:
   using base = nhill::geometry::Interval_interface<T>;
   using A_endpoint = nhill::geometry::Endpoint<T, A_compare>;
   using B_endpoint = nhill::geometry::Endpoint<T, B_compare>;

   // Constructors, Assignments, Destructor
   Interval();
   Interval( T a, T b );

   Interval( const Interval& );
   Interval& operator=( const Interval& );
   
   Interval( Interval&& );
   Interval& operator=( Interval&& );
   
   virtual ~Interval();

   // Properties
   virtual T a() const override;
   virtual T b() const override;

   // Methods
   virtual void set( T a, T b ) override;
   virtual bool is_valid( T value ) const override;

private:
   // Data Members
   A_endpoint a_;
   B_endpoint b_;
};

}
}

#pragma region Aliases
namespace nhill
{
namespace geometry
{

/// <summary>The interval is open at both ends.</summary>
template<typename T>
using Interval_oo = Interval<T, nhill::math::Compare_greater, nhill::math::Compare_less>;

/// <summary>The interval is closed at both ends.</summary>
template<typename T>
using Interval_cc = Interval<T, nhill::math::Compare_greater_or_equal, nhill::math::Compare_less_or_equal>;

/// <summary>The interval is open at the lower end and closed at the upper end.</summary>
template<typename T>
using Interval_oc = Interval<T, nhill::math::Compare_greater, nhill::math::Compare_less_or_equal>;

/// <summary>The interval is closed at the lower end and open at the upper end.</summary>
template<typename T>
using Interval_co = Interval<T, nhill::math::Compare_greater_or_equal, nhill::math::Compare_less>;



template<typename T,  template <typename, typename> class A_compare, template <typename, typename> class B_compare>
using Interval_ref = Interval<T, A_compare, B_compare> &;

template<typename T,  template <typename, typename> class A_compare, template <typename, typename> class B_compare>
using Interval_cref = Interval<T, A_compare, B_compare> const&;

template<typename T,  template <typename, typename> class A_compare, template <typename, typename> class B_compare>
using Interval_ptr = Interval<T, A_compare, B_compare>*;

template<typename T,  template <typename, typename> class A_compare, template <typename, typename> class B_compare>
using Interval_cptr = Interval<T, A_compare, B_compare> const*;

template<typename T,  template <typename, typename> class A_compare, template <typename, typename> class B_compare>
using Interval_uptr = std::unique_ptr<Interval<T, A_compare, B_compare>>;



template<typename T, template <typename, typename> class A_compare, template <typename, typename> class B_compare>
using Interval_container = std::vector< Interval<T, A_compare, B_compare> >;

template<typename T, template <typename, typename> class A_compare, template <typename, typename> class B_compare>
using Interval_ref_container = std::vector < Interval_ref<T, A_compare, B_compare>>;

template<typename T, template <typename, typename> class A_compare, template <typename, typename> class B_compare>
using Interval_cref_container = std::vector < Interval_cref<T, A_compare, B_compare>>;

template<typename T, template <typename, typename> class A_compare, template <typename, typename> class B_compare>
using Interval_ptr_container = std::vector < Interval_ptr<T, A_compare, B_compare>>;

template<typename T, template <typename, typename> class A_compare, template <typename, typename> class B_compare>
using Interval_cptr_container = std::vector < Interval_cptr<T, A_compare, B_compare>>;

template<typename T, template <typename, typename> class A_compare, template <typename, typename> class B_compare>
using Interval_uptr_container = std::vector < Interval_uptr<T, A_compare, B_compare>>;


}
}
#pragma endregion

#pragma region Definitions
template<typename T, template <typename, typename> class A_compare, template <typename, typename> class B_compare> inline
nhill::geometry::Interval<T, A_compare, B_compare >::Interval()
{
   set( 0, 0 );
}

template<typename T, template <typename, typename> class A_compare, template <typename, typename> class B_compare> inline
nhill::geometry::Interval<T, A_compare, B_compare>::Interval( T a, T b )
{
   set( a, b );
}

template<typename T, template <typename, typename> class A_compare, template <typename, typename> class B_compare> inline
nhill::geometry::Interval<T, A_compare, B_compare>::Interval( const Interval& ) = default;

template<typename T, template <typename, typename> class A_compare, template <typename, typename> class B_compare> inline
auto nhill::geometry::Interval<T, A_compare, B_compare>::operator=( const Interval& )->Interval & = default;

template<typename T, template <typename, typename> class A_compare, template <typename, typename> class B_compare> inline
nhill::geometry::Interval<T, A_compare, B_compare>::Interval( Interval&& ) = default;

template<typename T, template <typename, typename> class A_compare, template <typename, typename> class B_compare> inline
auto nhill::geometry::Interval<T, A_compare, B_compare>::operator=( Interval&& )->Interval & = default;

template<typename T, template <typename, typename> class A_compare, template <typename, typename> class B_compare> inline
nhill::geometry::Interval<T, A_compare, B_compare>::~Interval() = default;

template<typename T, template <typename, typename> class A_compare, template <typename, typename> class B_compare> inline
auto nhill::geometry::Interval<T, A_compare, B_compare>::a() const->T
{
   return a_;
}

template<typename T, template <typename, typename> class A_compare, template <typename, typename> class B_compare> inline
auto nhill::geometry::Interval<T, A_compare, B_compare>::b() const->T
{
   return b_;
}

template<typename T, template <typename, typename> class A_compare, template <typename, typename> class B_compare> inline
void nhill::geometry::Interval<T, A_compare, B_compare>::set( T a, T b )
{
   base::validate( a, b );

   a_ = a;
   b_ = b;
}

template<typename T, template <typename, typename> class A_compare, template <typename, typename> class B_compare> inline
bool nhill::geometry::Interval<T, A_compare, B_compare>::is_valid( T value ) const
{
   return a_.is_valid(value) && b_.is_valid(value);
}
#pragma endregion
