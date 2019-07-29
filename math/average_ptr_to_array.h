#pragma once

#include "gs\util\enable_if.h"
#include <cmath>

namespace gs
{
namespace math
{
namespace mean
{

/// <summary>Find the arithmetic mean.</summary>
/// <param name="x">A pointer to the first element of an array of values.</param>
/// <param name="N">The number of elements in the array.</param>
/// <returns>The arithmentic mean of the elements in the array.</returns>
template<typename T, typename enable_if::is_math_type<T>* = nullptr>
double arithmetic( const T* x, std::size_t N )
{
   if( N == 0 )
   {
      throw std::invalid_argument( "Invalid size.  The size of the array must be greater than zero." );
   }

   double X{ 0 }; // The mean/arithmetic average

   for( std::size_t i = 0 ; i < N ; ++i )
   {
      X += x[i];
   }

   X /= static_cast<double>(N);

   return X;
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
template<typename T, typename enable_if::is_math_type<T>* = nullptr>
double arithmetic_sub( const T* x, std::size_t N, T x0 )
{
   if( N == 0 )
   {
      throw std::invalid_argument( "Invalid size.  The size of the array must be greater than zero." );
   }

   double X{ 0 }; // The mean/arithmetic average

   for( std::size_t i = 0 ; i < N ; ++i )
   {
      X += (x[i] - x0);
   }

   X /= static_cast<double>(N);
   X += x0;

   return X;
}

/// <summary>Find the mean/arithmetic average multiplying each element by a factor.</summary>
/// <param name="x">A pointer to the first element of an array of values.</param>
/// <param name="N">The number of elements in the array.</param>
/// <param name="h">A factor multiplying each element of the array.</param>
/// <returns>The mean/arithmentic average of the elements in the array.</returns>
/// <remarks>If the numbers are decimals, they may be multiplied by a factor: X = (1/h)*SUM(h*xi)/N
/// </remarks>
template<typename T, typename enable_if::is_math_type<T>* = nullptr>
double arithmetic_mult( const T* x, std::size_t N, T h )
{
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
template<typename T, typename enable_if::is_math_type<T>* = nullptr>
double arithmetic_grouped( const T* x, const std::size_t* n, std::size_t N )
{
   if( N == 0 )
   {
      throw std::invalid_argument( "Invalid size.  The size of the array must be greater than zero." );
   }

   double X{ 0 }; // The mean/arithmetic average
   double T{ 0 }; // The total number of points

   for( std::size_t i = 0 ; i < N ; ++i )
   {
      X += (n[i]*x[i]);
      T += n[i];
   }

   X /= T;

   return X;
}

/// <summary>Find the weighted mean/arithmetic average.</summary>
/// <param name="x">A pointer to the first element of an array of values.</param>
/// <param name="w">A pointer to the first element of an array of weights.</para>
/// <param name="N">The number of elements in the value and weight arrays.</param>
/// <returns>The mean/arithmentic average of the elements in the array.</returns>
/// <remarks>X = [SUM(wi*xi)]/[SUM(wi)]</remarks>
template<typename T, typename enable_if::is_math_type<T>* = nullptr>
double arithmetic_weighted( const T* x, const T* w, std::size_t N )
{
   if( N == 0 )
   {
      throw std::invalid_argument( "Invalid size.  The size of the array must be greater than zero." );
   }

   double X{ 0 }; // The mean/arithmetic average
   double W{ 0 }; // The sum of the weights

   for( std::size_t i = 0 ; i < N ; ++i )
   {
      X += (w[i] * x[i]);
      W += w[i];
   }

   X /= W;

   return X;
}

/// <summary>The harmonic mean is the reciprocal of the arighmetic mean of the reciprocals.</summary>
/// <param name="x">A pointer to the first element of an array of values.</param>
/// <param name="N">The number of elements in the array.</param>
/// <returns>The harmonic mean of the elements in the array.</returns>
/// <remarks>X = N / SUM(1/xi).</remarks>
template<typename T, typename enable_if::is_math_type<T>* = nullptr>
double harmonic( const T* x, std::size_t N )
{
   if( N == 0 )
   {
      throw std::invalid_argument( "Invalid size.  The size of the array must be greater than zero." );
   }

   double X{ 0 }; // The mean/arithmetic average

   for( std::size_t i = 0 ; i < N ; ++i )
   {
      X += (1.0/x[i]);
   }

   X /= static_cast<double>(N);
   X = 1 / X;

   return X;
}

template<typename T, typename enable_if::is_math_type<T>* = nullptr>
double geometric( const T* x, std::size_t N )
{
   if( N == 0 )
   {
      throw std::invalid_argument( "Invalid size.  The size of the array must be greater than zero." );
   }

   double X{ 0 }; // The mean/arithmetic average

   for( std::size_t i = 0 ; i < N ; ++i )
   {
      X += std::log( x[i] );
   }

   X /= static_cast<double>(N);
   X = std::exp( X );

   return X;
}

template<typename T, typename enable_if::is_math_type<T>* = nullptr>
double standard_deviation( const T* x, std::size_t N )
{
   if( N < 2 )
   {
      throw std::invalid_argument( "Invalid size.  The size of the array must be greater than one." );
   }

   double s{ 0 };    // The standard deviation
   double sxx{ 0 };  // The summ of x squared: SUM(xi*xi);
   double sx{ 0 };   // The sum of x: SUM(xi)

   for( std::size_t i = 0 ; i < N ; ++i )
   {
      sxx += x[i] * x[i];
      sx += x[i];
   }

   s = sxx - (sx*sx)/N;
   s /= (N-1);
   s = std::sqrt( s );

   return s;
}

template<typename T, typename enable_if::is_math_type<T>* = nullptr>
double standard_deviation( const T* x, const std::size_t* n, std::size_t N )
{
   if( N < 2 )
   {
      throw std::invalid_argument( "Invalid size.  The size of the array must be greater than one." );
   }

   double s{ 0 };    // The standard deviation
   double sxx{ 0 };  // The summ of x squared: SUM(xi*xi);
   double sx{ 0 };   // The sum of x: SUM(xi)

   for( std::size_t i = 0 ; i < N ; ++i )
   {
      sxx += n[i]*x[i] * x[i];
      sx += n[i]*x[i];
   }

   s = sxx - (sx*sx) / N;
   s /= (N - 1);
   s = std::sqrt( s );

   return s;
}

template<typename T, typename enable_if::is_math_type<T>* = nullptr>
double coeff_of_variation( const T* x, std::size_t N )
{
   if( N == 0 )
   {
      throw std::invalid_argument( "Invalid size.  The size of the array must be greater than zero." );
   }

   double s{ standard_deviation( x,N ) };
   double X{ mean( x,N ) };

}

}
}
}

