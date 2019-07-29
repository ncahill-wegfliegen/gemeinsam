#include "curve.h"
#include "..\geometry\pnt.h"
#include "..\geometry\interval_helper.h"
#include "..\utility\exception\message.h"
#include "..\utility\unique_ptr.h"

using namespace std;

nhill::segment::Curve::Curve() = default;

nhill::segment::Curve::Curve( const Curve& other )
{
   *this = other;
}

auto nhill::segment::Curve::operator=( const Curve& other )->Curve &
{
   return *this;
}

nhill::segment::Curve::Curve( Curve&& other ) noexcept = default;
auto nhill::segment::Curve::operator=( Curve&& other ) noexcept->Curve & = default;

nhill::segment::Curve::~Curve() = default;

auto nhill::segment::Curve::add( const Key & key, const Point_container & points )->Segment_base &
{
   validate( points.front().x, points.back().x, __FILE__, __func__, __LINE__ );

   segments_indexed_.push_back( {key, points} );
   return segments_indexed_.back();
}

auto nhill::segment::Curve::add( const Point_container & points )->Segment_base &
{
   validate( points.front().x, points.back().x, __FILE__, __func__, __LINE__ );

   segments_indexed_.push_back( {points} );
   return segments_indexed_.back();
}

auto nhill::segment::Curve::add( const Segment_indexed & seg )->Segment_base &
{
   return add( seg.key(), seg.points() );
}

auto nhill::segment::Curve::add( Segment_indexed && seg )->Segment_base &
{
   return add( seg.key(), seg.points() );
}

auto nhill::segment::Curve::add( const Key& key, float step, double start, const Value_container& y_values )->Segment_base &
{
   double n{static_cast<double>(y_values.size())};
   double end = start + n * step;
   validate( start, end, __FILE__, __func__, __LINE__ );

   segments_stepped_.push_back( {key, step, start, y_values} );
   return segments_stepped_.back();
}

auto nhill::segment::Curve::add( float step, double start, const Value_container& y_values )->Segment_base &
{
   double n{static_cast<double>(y_values.size())};
   double end = start + n * step;
   validate( start, end, __FILE__, __func__, __LINE__ );

   segments_stepped_.push_back( {step, start, y_values} );
   return segments_stepped_.back();
}

auto nhill::segment::Curve::add( const Segment_stepped& seg )->Segment_base &
{
   return add( seg.key(), seg.step(), seg.start(), seg.y_values() );
}

auto nhill::segment::Curve::add( Segment_stepped&& seg )->Segment_base &
{
   return add( seg.key(), seg.step(), seg.start(), seg.y_values() );
}

size_t nhill::segment::Curve::count_indexed() const
{
   return segments_indexed_.size();
}

size_t nhill::segment::Curve::count_stepped() const
{
   return segments_stepped_.size();
}

size_t nhill::segment::Curve::count( Type type ) const
{
   switch( type )
   {
   case nhill::segment::Type::indexed: return count_indexed();
   case nhill::segment::Type::stepped: return count_stepped();
   default: return 0;
   }
}

size_t nhill::segment::Curve::count() const
{
   return count_stepped() + count_indexed();
}

auto nhill::segment::Curve::get_segments_indexed() const->const Segment_indexed_container &
{
   return segments_indexed_;
}

auto nhill::segment::Curve::get_segments_stepped() const-> const Segment_stepped_container &
{
   return segments_stepped_;
}

auto nhill::segment::Curve::get_segments( Type type ) const->Segment_base_cptr_container
{
   Segment_base_cptr_container segs;

   switch( type )
   {
   case nhill::segment::Type::stepped:
   {
      segs.resize( count_stepped() );
      transform( segments_stepped_.cbegin(), segments_stepped_.cend(), segs.begin(), []( const auto& seg ) { return &seg; } );
      break;
   }

   case nhill::segment::Type::indexed:
   {
      segs.resize( count_indexed());
      transform( segments_indexed_.cbegin(), segments_indexed_.cend(), segs.begin(), []( const auto& seg ) { return &seg; } );
      break;
   }
   }
   
   return segs;
}

auto nhill::segment::Curve::get_segments() const->Segment_base_cptr_container
{
   Segment_base_cptr_container segs;
   segs.reserve( count() );

   transform( segments_stepped_.cbegin(), segments_stepped_.cend(), back_inserter(segs), []( const auto& seg ) { return &seg; } );
   transform( segments_indexed_.cbegin(), segments_indexed_.cend(), back_inserter(segs), []( const auto& seg ) { return &seg; } );

   return segs;
}

bool nhill::segment::Curve::is_valid_indexed( double start, double end )
{
   auto interval = Segment_base::base{start, end};
   auto itr = std::find_if(
      segments_indexed_.cbegin(),
      segments_indexed_.cend(),
      [&interval]( const auto& seg )
      {
         return nhill::geometry::intersect<double>( interval, seg );
      }
   );
   return itr == segments_indexed_.end();
}

bool nhill::segment::Curve::is_valid_stepped( double start, double end )
{
   auto interval = Segment_base::base{start, end};
   auto itr = std::find_if(
      segments_stepped_.cbegin(),
      segments_stepped_.cend(),
      [&interval]( const auto& seg )
      {
         return nhill::geometry::intersect<double>( interval, seg );
      }
   );
   return itr == segments_stepped_.end();
}

bool nhill::segment::Curve::is_valid( double start, double end, Type type )
{
   switch( type )
   {
   case nhill::segment::Type::indexed: return is_valid_indexed( start, end );
   case nhill::segment::Type::stepped: return is_valid_stepped( start, end );
   default: return false;
   }
}

bool nhill::segment::Curve::is_valid( double start, double end )
{
   return is_valid_stepped( start, end ) && is_valid_indexed( start, end );
}

void nhill::segment::Curve::validate( double start, double end, const char * file, const char * function, int line )
{
   if( !is_valid( start, end ) )
   {
      throw std::logic_error( NHILL_EXCEPTION_MESSAGE( "Invalid segment: [start, end] = [" + std::to_string( start ) + ", " + std::to_string( end ) + "].", "The segment must not intersect any segment already in this curve." ) );
   }
}
