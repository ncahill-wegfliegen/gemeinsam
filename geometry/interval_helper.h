#pragma once

#include "interval.h"
#include <sstream>
#include <stdexcept>
#include <vector>
#include <algorithm>

namespace nhill
{
namespace geometry
{

enum class Relationship
{
   unkown,

   /// <summary>The two intervals are disjoint (i.e., they have no intersection).</summary>
   disjoint,

   /// <summary>Interval 1 is a proper subset of interval 2 (i.e., the intervals are not equal).</summary>
   subset12,

   /// <summary>Interval 2 is a proper subset of interval 1 (i.e., the intervals are not equal).</summary>
   subset21,

   /// <summary>The two intervals are equal.</summary>
   equal,

   /// <summary>The two intervals intersect, and neither interval is a subset of the other interval.</summary>
   overlap,
};


template<typename T>
bool less( typename Interval_interface<T>::cref i1, typename Interval_interface<T>::cref i2 )
{
   using namespace nhill::math;

   bool is_less = false;

   int cmp_aa = compare<T, T>( i1.a(), i2.a() );

   if (cmp_aa < 0)
   {
      is_less = true;
   }
   else if (cmp_aa == 0)
   {
      int cmp_bb = compare<T, T>( i1.b(), i2.b() );

      if (cmp_bb < 0)
      {
         is_less = true;
      }
   }

   return is_less;
}



template<typename T>
void sort_increasing( Interval_interface_ptr_container<T>& intervals )
{
   std::sort(
      intervals.begin(),
      intervals.end(),
      []( auto i1, auto i2 )
      {
         return less<T>( *i1, *i2 );
      }
   );
}

template<typename T>
void sort_increasing( Interval_interface_cptr_container<T>& intervals )
{
   std::sort(
      intervals.begin(),
      intervals.end(),
      []( auto i1, auto i2 )
      {
         return less<T>( *i1, *i2 );
      }
   );
}


template<typename T>
void sort_increasing( Interval_interface_uptr_container<T>& intervals )
{
   std::sort(
      intervals.begin(),
      intervals.end(),
      []( auto i1, auto i2 )
      {
         return less<T>( *i1, *i2 );
      }
   );
}




template<typename T, template <typename, typename> class A_compare, template <typename, typename> class B_compare>
void sort_increasing( Interval_container<T, A_compare, B_compare>& intervals )
{
   std::sort( intervals.begin(), intervals.end(), nhill::less<T> );
}

template<typename T, template <typename, typename> class A_compare, template <typename, typename> class B_compare>
void sort_increasing( Interval_cptr_container<T, A_compare, B_compare>& intervals )
{
   auto compare_less = less<T>;

   std::sort(
      intervals.begin(),
      intervals.end(),
      [&compare_less]( auto i1, auto i2 )
      {
         return compare_less( *i1, *i2 );
      }
   );
}


template<typename T>
bool disjoint( typename Interval_interface<T>::cref i1, typename Interval_interface<T>::cref i2 )
{
   using namespace nhill::math;

   // Are the intervals disjoint
   bool are_disjoint = false;

   // Compare 'a' of interval 1 to 'a' of interval 2
   int cmp_aa = compare<T, T>( i1.a(), i2.a() );

   if (cmp_aa < 0)
   {
      // 'a' of interval 1 is less than 'a' of interval 2

      // case            A           B           C           D               E
      // interval 1   |-----|     |-----|     |-----|     |-----|         |-----| 
      // interval 2     |--|        |---|       |-----|         |---|             |---|

      // Compare 'b' of interval 1 to 'a' of interval '2'
      int cmp_ba = compare<T, T>( i1.b(), i2.a() );
      are_disjoint = (cmp_ba < 0); // true for case E; false for cases A, B, C and D
   }
   else if (cmp_aa == 0)
   {
      // 'a' of interval 1 is equal to 'a' of interval 2

      // case            A             B                 C
      // interval 1   |-----|       |-----|           |-----|
      // interval 2   |---|         |-----|           |-------|

      are_disjoint = false;  // cannot be disjoint
   }
   else // if ( cmp_aa > 0 )
   {
      // 'a' of interval 1 is greater than 'a' of interval 2

      // case            A           B           C           D               E
      // interval 1     |--|        |---|       |-----|         |---|             |---|
      // interval 2   |-----|     |-----|     |-----|     |-----|         |-----| 

      // Compare 'a' of interval 1 to 'b' of interval 2
      int cmp_ab = compare<T, T>( i1.a(), i2.b() );
      are_disjoint = (cmp_ab > 0); // true for case E; false for cases A, B, C and D
   }

   return are_disjoint;
}

template<typename T>
bool disjoint( typename Interval_interface<T>::cptr i1, typename Interval_interface<T>::cptr i2 )
{
   return disjoint<T>( *i1, *i2 );
}

template<typename T>
bool disjoint( const Interval_interface_cref_pair<T>& pair )
{
   return disjoint<T>( interval1( pair ), interval2( pair ) );
}

template<typename T>
bool disjoint( const Interval_interface_cptr_pair<T>& pair )
{
   return disjoint<T>( *interval1( pair ), *interval2( pair ) );
}

template<typename T>
bool disjoint( const Interval_interface_uptr_pair<T>& pair )
{
   return disjoint<T>( *interval1( pair ), *interval2( pair ) );
}




template<typename T>
bool intersect( typename Interval_interface<T>::cref i1, typename Interval_interface<T>::cref i2 )
{
   return !disjoint<T>( i1, i2 );
}

template<typename T>
bool intersect( typename Interval_interface<T>::cptr i1, typename Interval_interface<T>::cptr i2 )
{
   return intersect<T>( *i1, *i2 );
}

template<typename T>
bool intersect( const Interval_interface_cref_pair<T>& pair )
{
   return intersect<T>( interval1( pair ), interval2( pair ) );
}

template<typename T>
bool intersect( const Interval_interface_cptr_pair<T>& pair )
{
   return intersect<T>( *interval1( pair ), *interval2( pair ) );
}

template<typename T>
bool intersect( const Interval_interface_uptr_pair<T>& pair )
{
   return intersect<T>( *interval1( pair ), *interval2( pair ) );
}




template<typename T>
bool overlap( typename Interval_interface<T>::cref i1, typename Interval_interface<T>::cref i2 )
{
   return intersect<T>( i1, i2 ) && !subset<T>( i1, i2 ) && !subset<T>( i2, i1 );
}

template<typename T>
bool overlap( typename Interval_interface<T>::cptr i1, typename Interval_interface<T>::cptr i2 )
{
   return overlap<T>( *i1, *i2 );
}

template<typename T>
bool overlap( const Interval_interface_cref_pair<T>& pair )
{
   return overlap<T>( interval1( pair ), interval2( pair ) );
}

template<typename T>
bool overlap( const Interval_interface_cptr_pair<T>& pair )
{
   return overlap<T>( *interval1( pair ), *interval2( pair ) );
}

template<typename T>
bool overlap( const Interval_interface_uptr_pair<T>& pair )
{
   return overlap<T>( *interval1( pair ), *interval2( pair ) );
}






template<typename T>
bool subset( typename Interval_interface<T>::cref i1, typename Interval_interface<T>::cref i2 )
{
   using namespace nhill::math;

   // Is interval 1 a subset of interval 2
   bool is_subset = false;

   // Compare 'a' of interval 1 to 'a' of interval 2
   int cmp_aa = compare<T, T>( i1.a(), i2.a() );

   // Compare 'b' of interval 1 to 'b' of interval '2'
   int cmp_bb = compare<T, T>( i1.b(), i2.b() );

   if (cmp_aa < 0)
   {
      // 'a' of interval 1 is less than 'a' of interval 2

      // case            A           B           C           D               E
      // interval 1   |-----|     |-----|     |-----|     |-----|         |-----| 
      // interval 2     |--|        |---|       |-----|         |---|             |---|

      is_subset = false; // interval 1 cannot be a subset of interval 2
   }
   else if (cmp_aa == 0)
   {
      // 'a' of interval 1 is equal to 'a' of interval 2

      // case            A             B                 C
      // interval 1   |-----|       |-----|           |-----|
      // interval 2   |---|         |-----|           |-------|

      is_subset = (cmp_bb == 0); // True for case B; false for cases A and C
   }
   else // if ( cmp_aa > 0 )
   {
      // 'a' of interval 1 is greater than 'a' of interval 2

      // case            A           B           C           D               E
      // interval 1     |--|        |---|       |-----|         |---|             |---|
      // interval 2   |-----|     |-----|     |-----|     |-----|         |-----| 

      is_subset = (cmp_bb <= 0); // true for cases A and B; false for cases C, D and E
   }

   return is_subset;
}

template<typename T>
bool subset( typename Interval_interface<T>::cptr i1, typename Interval_interface<T>::cptr i2 )
{
   return subset<T>( *i1, *i2 );
}

template<typename T>
bool subset( const Interval_interface_cref_pair<T>& pair )
{
   return subset<T>( interval1( pair ), interval2( pair ) );
}

template<typename T>
bool subset( const Interval_interface_cptr_pair<T>& pair )
{
   return subset<T>( *interval1( pair ), *interval2( pair ) );
}

template<typename T>
bool subset( const Interval_interface_uptr_pair<T>& pair )
{
   return subset<T>( *interval1( pair ), *interval2( pair ) );
}




template<typename T>
bool equal( typename Interval_interface<T>::cref i1, typename Interval_interface<T>::cref i2 )
{
   return subset<T>( i1, i2 ) && subset<T>( i2, i1 );
}

template<typename T>
bool equal( typename Interval_interface<T>::cptr i1, typename Interval_interface<T>::cptr i2 )
{
   return subset<T>( *i1, *i2 ) && subset<T>( *i2, *i1 );
}

template<typename T>
bool equal( const Interval_interface_cref_pair<T>& pair )
{
   return subset<T>( interval1( pair ), interval2( pair ) ) && subset<T>( interval2( pair ), interval1( pair ) );
}

template<typename T>
bool equal( const Interval_interface_cptr_pair<T>& pair )
{
   return subset<T>( *interval1( pair ), *interval2( pair ) ) && subset<T>( *interval2( pair ), *interval1( pair ) );
}

template<typename T>
bool equal( const Interval_interface_uptr_pair<T>& pair )
{
   return subset<T>( *interval1( pair ), *interval2( pair ) ) && subset<T>( *interval2( pair ), *interval1( pair ) );
}



template<typename T>
bool intersection( typename Interval_interface<T>::cref i1, typename Interval_interface<T>::cref i2, T & a, T & b, Relationship * relationship_param /*= nullptr*/ )
{
   if (disjoint<T>( i1, i2 ))
   {
      if (relationship_param != nullptr)
      {
         *relationship_param = Relationship::disjoint;
      }
      a = {};
      b = {};
      return false;
   }

   if (equal<T>( i1, i2 ))
   {
      if (relationship_param != nullptr)
      {
         *relationship_param = Relationship::equal;
      }
      a = i1.a();
      b = i1.b();
      return false;
   }

   if (subset<T>( i1, i2 ))
   {
      if (relationship_param != nullptr)
      {
         *relationship_param = Relationship::subset12;
      }
      a = i2.a();
      b = i2.b();
      return true;
   }

   if (subset<T>( i2, i1 ))
   {
      if (relationship_param != nullptr)
      {
         *relationship_param = Relationship::subset21;
      }
      a = i1.a();
      b = i1.b();
      return true;
   }

   // The intervals are not disjoint, they are not equal, and neither is a subset of the other

   typename Interval_interface<T>::cptr int1; // the lesser  of the two intervals
   typename Interval_interface<T>::cptr int2; // the greater of the two intervals
   if (less<T>( i1, i2 ))
   {
      int1 = &i1;
      int2 = &i2;
   }
   else
   {
      int1 = &i2;
      int2 = &i1;
   }

   // The ordered intervals must be one of the following two cases:
   // int1 |-----|        |-----|
   // int2    |-----|           |-----|

   if (relationship_param != nullptr)
   {
      *relationship_param = Relationship::overlap;
   }

   a = int2->a();
   b = int1->b();

   return true;
}


/// <summary>Merge two intervals into a single interval.</summary>
/// <param name="i1">[In] The first interval to be merged.</param>
/// <param name="i2">[In] The second interval to be merged.</param>
/// <param name="a">[Out] The first point of the merged interval.</param>
/// <param name="b">[Out] The second point of the merged interval.</param>
/// <param name="relationship">[Out, Optional] The relationship between the input intervals.<param>
/// <returns>True if the two intervals are merged into a single interval.  The output interval is the result of the merge.
///   <para>False if the two intervals are disjoint.  The output interval is unchanged.</para>
/// </returns>
template<typename T>
bool merge( typename Interval_interface<T>::cref i1, typename Interval_interface<T>::cref i2, T& a, T& b, Relationship * relationship_param /*= nullptr*/ )
{
   //////////////////////////////////////
   // Parameters
   Relationship relationship = Relationship::unkown; // Relationship between the two input intervals
   bool merged = false; // Return value
   //////////////////////////////////////

   //////////////////////////////////////
   // Merge the given intervals
   // Set the output first and second points for the merged interval
   if (disjoint( i1, i2 ))
   {
      relationship = Relationship::disjoint;
      merged = false;
      a = {};
      b = {};
   }
   else if (subset( i1, i2 ))
   {
      relationship = Relationship::subset12;
      merged = true;
      a = i2.a();
      b = i2.b();
   }
   else if (subset( i2, i1 ))
   {
      relationship = Relationship::subset21;
      merged = true;
      a = i1.a();
      b = i1.b();
   }
   else
   {
      relationship = Relationship::overlap;
      merged = true;
      a = (std::min)( i1.a(), i2.a() );
      b = (std::max)( i1.b(), i2.b() );
   }
   //////////////////////////////////////

   //////////////////////////////////////
   // Set the output relationship
   if (relationship_param != nullptr)
   {
      *relationship_param = relationship;
   }
   //////////////////////////////////////

   return merged;
}



}
}
