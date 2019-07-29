#include "segment_stepped.h"
#include "..\geometry\pnt.h"
#include "..\math\compare.h"
#include "..\utility\exception\message.h"
#include <cmath>

nhill::segment::Segment_stepped::Segment_stepped( const Key& key /*= {}*/ )
   : Segment_base{ Type::stepped, key}
   , step_{ 0 }
   , start_{ 0 }
   , y_values_{ new Value_container{} }
{
}

nhill::segment::Segment_stepped::Segment_stepped( const Key & key, float step, double start, const Value_container & y_values )
   : Segment_stepped{ key }
{
   set( step, start, y_values );
}

nhill::segment::Segment_stepped::Segment_stepped( float step, double start, const Value_container & y_values )
   : Segment_stepped{}
{
   set( step, start, y_values );
}

nhill::segment::Segment_stepped::Segment_stepped( const Segment_stepped & seg )
   : Segment_base{ seg }
   , step_{ seg.step_ }
   , start_{ seg.start_ }
   , y_values_{ new Value_container{ *seg.y_values_ } }
{
}

auto nhill::segment::Segment_stepped::operator=( const Segment_stepped& other )->Segment_stepped &
{
   Segment_base::operator=( other );

   step_ = other.step_;
   start_ = other.start_;
   *y_values_ = *other.y_values_;

   return *this;
}

nhill::segment::Segment_stepped::Segment_stepped( Segment_stepped && seg ) noexcept
   : Segment_base{ std::move( seg ) }
   , step_{ seg.step_ }
   , start_{ seg.start_ }
   , y_values_{ seg.y_values_ }
{
   seg.y_values_ = nullptr;
}

auto nhill::segment::Segment_stepped::operator=( Segment_stepped&& other ) noexcept->Segment_stepped &
{
   Segment_base::operator=( std::move( other ) );

   step_ = other.step_;
   start_ = other.start_;

   delete y_values_;
   y_values_ = other.y_values_;
   other.y_values_ = nullptr;

   return *this;
}

nhill::segment::Segment_stepped::~Segment_stepped()
{
   delete y_values_;
}

float nhill::segment::Segment_stepped::step() const
{
   return step_;
}

double nhill::segment::Segment_stepped::start() const
{
   return start_;
}

double nhill::segment::Segment_stepped::end() const
{
   double n{static_cast<double>(y_values().size() - 1)};
   return start() + n*step();
}

auto nhill::segment::Segment_stepped::y_values() const->const Value_container &
{
   return *y_values_;
}

std::size_t nhill::segment::Segment_stepped::size() const
{
   return y_values().size();
}

auto nhill::segment::Segment_stepped::at( std::size_t pos ) const->Point
{
   validate_position( pos, __FILE__, __func__, __LINE__ );
   double n{static_cast<double>(pos)};
   double x{start() + n * step()};
   return { x, y_values()[pos] };
}

int nhill::segment::Segment_stepped::pos( double x ) const
{
   validate_x( x, __FILE__, __func__, __LINE__ );
   
   double n{std::round( std::floor( (x - start()) / step() ) )};
   
   return static_cast<int>(n);
}

double nhill::segment::Segment_stepped::y( double x ) const
{
   validate_x( x, __FILE__, __func__, __LINE__ );

   int pos{this->pos( x )};
   double n{static_cast<double>(pos)};

   double x0{start() + n * step()};
   double x1{start() + (n + 1) * step()};

   double y0{y_values()[pos]};
   double y1{y_values()[pos + 1]};

   double y = y0 + (x - x0)*(y1 - y0) / (x1 - x0);

   return y;
}

auto nhill::segment::Segment_stepped::make_unique() const->Segment_base::uptr
{
   return std::make_unique<Segment_stepped>( *this );
}

void nhill::segment::Segment_stepped::set( float step, double start, const Value_container & y_values )
{
   validate( step, start, y_values, __FILE__, __func__, __LINE__ );

   step_      = step;
   start_     = start;
   *y_values_ = y_values;
}

void nhill::segment::Segment_stepped::validate( float step, double start, const Value_container& y_values, const char* file, const char* function, int line )
{
   if( math::less_or_equal<float, uint8_t>( step,  0 ) )
   {
      throw std::invalid_argument( exception::build( {file, function, line,  "Invalid step " + std::to_string( step ), "The step must be greater than zero."} ) );
   }

   double remainder = std::remainder( start, step );
   if( !math::zero( remainder ) )
   {
      throw std::invalid_argument( exception::build( {file, function, line, "Invalid start value " + std::to_string( start ) + ".", "The start value must be an integer multiple of the step " + std::to_string( step ) + "." } ) );
   }

   if( y_values.size() == 0 )
   {
      throw std::invalid_argument( exception::build( {file, function, line, "Invalid y-value size.", "There must be at least one y-value."} ) );
   }
}

auto nhill::segment::Segment_stepped::sub_segment( int pos_beg, int pos_end )->Segment_stepped
{
   // Adjust the end position if necessary
   if( pos_end == -1 )
   {
      pos_end = size() - 1;
   }

   // Determine the start value of the sub-segment
   double n{static_cast<double>(pos_beg)};
   double start = this->start() + n * step();

   // The y-values of the sub-segment
   Value_container y_values;
   y_values.reserve( pos_end - pos_beg + 1 );
   std::copy( this->y_values().begin(), this->y_values().end(), std::back_inserter( y_values ) );

   // Set the sub segment
   Segment_stepped sub_seg( step(), start, y_values );
   return sub_seg;
}
