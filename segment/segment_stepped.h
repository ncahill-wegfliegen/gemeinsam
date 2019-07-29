#pragma once

#include "port.h"
#include "segment_base.h"

namespace nhill
{
namespace segment
{

/// <summary>This type of segment is used when the x values are specified by step and start values.</summary>
/// <remarks>Invariants. In order to be a valid segment:
///   <para>1) The step must be positive.</para>
///   <para>2) The start value must be in integer multiple of the step.</para>
///   <para>3) There must be at least one y value.</para>
/// </remarks>
class NHILL_SEGMENT_PORT_CLASS Segment_stepped final : public Segment_base
{
public:
   using base = Segment_base;
   using ptr = Segment_stepped *;
   using cptr = const Segment_stepped*;
   using ref = Segment_stepped &;
   using cref = const Segment_stepped &;

   Segment_stepped( const Key& key = {} );
   Segment_stepped( const Key& key, float step, double start, const Value_container& y_values );
   Segment_stepped( float step, double start, const Value_container& y_values );

   Segment_stepped( const Segment_stepped& );
   Segment_stepped& operator=( const Segment_stepped& );

   Segment_stepped( Segment_stepped&& ) noexcept;
   Segment_stepped& operator=( Segment_stepped&& ) noexcept;

   ~Segment_stepped();

   float step() const;
   double start() const override;
   double end() const override;
   const Value_container& y_values() const;

   std::size_t size() const override;
   Point at( std::size_t pos ) const override;
   int pos( double x ) const override;
   double y( double x ) const override;
   Segment_base::uptr make_unique() const override;

   void set( float step, double start, const Value_container& y_values );

   /// <summary>Validate the invariantes for this type of segment.</summary>
   /// <exception cref="std::invalid_argment">Throw this exception if the segment is not valid.</exception>
   static void validate( float step, double start, const Value_container& y_values, const char* file, const char* function, int line );

   Segment_stepped sub_segment( int pos_beg, int pos_end = -1 );
   Segment_stepped sub_segment( double x_beg );
   Segment_stepped sub_segment( double x_beg, double x_end );

private:
   float  step_;
   double start_;
   Value_container* y_values_;
};

}
}

namespace nhill
{
namespace segment
{

using Segment_stepped_container = std::vector<Segment_stepped>;
using Segment_stepped_cptr_container = std::vector<Segment_stepped::cptr>;
using Segment_stepped_uptr_container = std::vector<Segment_stepped::uptr>;


}
}