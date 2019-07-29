#pragma once

#include "average_ptr_to_array.h"

namespace gs
{
namespace math
{
namespace mean
{

template<std::size_t N, typename T, typename enable_if::is_math_type<T>* = nullptr>
double arithmetic( const T( &x )[N] )
{
   return arithmetic( &x[0], N );
}

/// <summary>Find the mean/arithmetic average subtracting a factor from each element.</summary>
/// <param name="x">A pointer to the first element of an array of values.</param>
/// <param name="N">The number of elements in the array.</param>
/// <param name="x0">A factor subtracted from each element of the array.</param>
/// <returns>The mean/arithmentic average of the elements in the array.</returns>
/// <remarks>If the observations consist of several significant figures, they can be converted
/// to smaller numbers by subtracting from each a constant quantity and restoring this at the end
/// of the computatation: X = x0 + SUM(xi-x0)/N.
/// </remarks>
template<std::size_t N, typename T, typename enable_if::is_math_type<T>* = nullptr>
double arithmetic_sub( const T( &x )[N], T x0 )
{
   return arithmetic_sub( &x[0], N, x0 );
}

/// <summary>Find the mean/arithmetic average multiplying each element by a factor.</summary>
/// <param name="x">A pointer to the first element of an array of values.</param>
/// <param name="N">The number of elements in the array.</param>
/// <param name="h">A factor multiplying each element of the array.</param>
/// <returns>The mean/arithmentic average of the elements in the array.</returns>
/// <remarks>If the numbers are decimals, they may be multiplied by a factor: X = (1/h)*SUM(h*xi)/N
/// </remarks>
template<std::size_t N, typename T, typename enable_if::is_math_type<T>* = nullptr>
double arithmetic_mult( const T( &x )[N], T h )
{
   return arithmetic_mult( &x[0], N, h );
   if( N == 0 )
   {
      throw std::invalid_argument( "Invalid size.  The size of the array must be greater than zero." );
   }

   double X{ 0 }; // The mean/arithmetic average

   for( std::size_t i = 0 ; i < N ; ++i )
   {
      X += (h*x[i]);
   }

   X /= static_cast<double>(N);
   X /= static_cast<double>(h);

   return X;
}

/// <summary>Find the mean/arithmetic average of a group of values.</summary>
/// <param name="x">A pointer to the first element of an array of group values.  Each element is the average of a group.</param>
/// <param name="n">A pointer to the first element of an array of group counts.  Each element is the number of elements in the group.</para>
/// <param name="N">The number of elements in the value and count arrays (i.e, the number of groups).</param>
/// <returns>The mean/arithmentic average of the elements in the array.</returns>
/// <remarks>When N is very large, along summarion can be avoided by groupoing the data.
/// There will be some loss of accuracy, but this will be small if the operation is done propertly.
/// The procedure is to sort the data in groups of suitable size and treat each group as though all
/// the observations in it had the value of the average of that group.  If the number of groups is
/// large enough, the inaccuracies will be negligible.  The optimum number of groups that can be used
/// safely and profitable is between 10 and 20: X = SUM(ni*xi)/N
/// </remarks>
template<std::size_t N, typename T, typename enable_if::is_math_type<T>* = nullptr>
double arithmetic_grouped( const T( &x )[N], const std::size_t(&n)[N] )
{
   return arithmetic_grouped( &x[0], &n[0], N );
}

/// <summary>Find the weighted mean/arithmetic average.</summary>
/// <param name="x">A pointer to the first element of an array of values.</param>
/// <param name="w">A pointer to the first element of an array of weights.</para>
/// <param name="N">The number of elements in the value and weight arrays.</param>
/// <returns>The mean/arithmentic average of the elements in the array.</returns>
/// <remarks>X = [SUM(wi*xi)]/[SUM(wi)]</remarks>
template<std::size_t N, typename T, typename enable_if::is_math_type<T>* = nullptr>
double arithmetic_weighted( const T( &x )[N], const T( &w )[N] )
{
   return arithmetic_weighted( &x[0], &w[0], N );
}

/// <summary>The harmonic mean is the reciprocal of the arighmetic mean of the reciprocals.</summary>
/// <param name="x">A pointer to the first element of an array of values.</param>
/// <param name="N">The number of elements in the array.</param>
/// <returns>The harmonic mean of the elements in the array.</returns>
/// <remarks>X = N / SUM(1/xi).</remarks>
template<std::size_t N, typename T, typename enable_if::is_math_type<T>* = nullptr>
double harmonic( const T( &x )[N] )
{
   return harmonic( &x[0], N );
}

template<std::size_t N, typename T, typename enable_if::is_math_type<T>* = nullptr>
double geometric( const T( &x )[N] )
{
   return geometric( &x[0], N );
}

template<std::size_t N, typename T, typename enable_if::is_math_type<T>* = nullptr>
double standard_deviation( const T( &x )[N] )
{
   standard_deviation( &x[0], N );
}

template<std::size_t N, typename T, typename enable_if::is_math_type<T>* = nullptr>
double standard_deviation( const T( &x )[N], const std::size_t( &n )[N] )
{
   return standard_deviation( &x[0], &n[0], N );
}

template<std::size_t N, typename T, typename enable_if::is_math_type<T>* = nullptr>
double coeff_of_variation( const T( &x )[N] )
{
   return coeff_of_variation( &x[0], N );
}

}
}
}

