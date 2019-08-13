#include "segment_indexed.h"
#include "../geometry/pnt.h"
#include "../math/compare.h"
#include "../utility/exception/message.h"

nhill::segment::Segment_indexed::Segment_indexed( const Key& key )
   : Segment_base( Type::indexed, key )
   , points_{ new Point_container{} }
{
}

nhill::segment::Segment_indexed::Segment_indexed( const Key& key, const Point_container & points )
   : Segment_indexed{ key }
{
   this->points( points );
}

nhill::segment::Segment_indexed::Segment_indexed( const Point_container & points )
   : Segment_indexed{}
{
   this->points( points );
}

nhill::segment::Segment_indexed::Segment_indexed( const Segment_indexed & seg )
   : Segment_base{ seg }
   , points_{ new Point_container{ *seg.points_ } }
{
}

auto nhill::segment::Segment_indexed::operator=( const Segment_indexed& other )->Segment_indexed &
{
   *points_ = *other.points_;

   return *this;
}

nhill::segment::Segment_indexed::Segment_indexed( Segment_indexed && seg ) noexcept
   : Segment_base{ std::move( seg ) }
   , points_{ seg.points_ }
{
   seg.points_ = nullptr;
}

auto nhill::segment::Segment_indexed::operator=( Segment_indexed&& other ) noexcept->Segment_indexed &
{
   delete points_;
   points_ = other.points_;
   other.points_ = nullptr;

   return *this;
}

nhill::segment::Segment_indexed::~Segment_indexed()
{
   delete points_;
}

double nhill::segment::Segment_indexed::start() const
{
   return points_->front().x;
}

double nhill::segment::Segment_indexed::end() const
{
   return points_->back().x;
}

std::size_t nhill::segment::Segment_indexed::size() const
{
   return points_->size();
}

auto nhill::segment::Segment_indexed::at( std::size_t pos ) const->Point
{
   validate_position( pos, __FILE__, __func__, __LINE__ );
   return points()[pos];
}

int nhill::segment::Segment_indexed::pos( double x ) const
{
   return 0;
}

double nhill::segment::Segment_indexed::y( double x ) const
{
   return 0.0;
}

auto nhill::segment::Segment_indexed::make_unique() const->Segment_base::uptr
{
   return std::make_unique<Segment_indexed>(*this);
}

auto nhill::segment::Segment_indexed::points() const->const Point_container &
{
   return *points_;
}

void nhill::segment::Segment_indexed::points( const Point_container & value )
{
   validate( value, __FILE__, __func__, __LINE__ );
   *points_ = value;
}

void nhill::segment::Segment_indexed::validate( const Point_container & value, const char* file, const char* function, int line )
{
	auto cnt{value.size()};
   if( cnt == 0 )
   {
      throw std::invalid_argument( exception::build( {file, function, line,  "Message: Invalid size.", "There must be at least one point."} ) );
   }

   if( cnt == 1 )
   {
      return;
   }
   
   double start = value.front().x;
   double end = value.back().x;
   if( math::greater_or_equal( start, end ) )
   {
      throw std::invalid_argument( exception::build( {file, function, line, "Invalid stepped( start, end ) = (" + std::to_string( start ) + ", " + std::to_string( end ) + ").", "The start value must be less than the end value."} ) );
   }
}
