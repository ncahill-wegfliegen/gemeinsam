#pragma once

#include "port.h"
#include "segment_base.h"
#include "segment_indexed.h"
#include "segment_stepped.h"
#include "segment_types.h"

namespace nhill
{
namespace segment
{

/// <summary>Contains disjoint segments.</summary>
class NHILL_SEGMENT_PORT_CLASS Curve
{

public:
   Curve();

   Curve( const Curve& );
   Curve& operator=( const Curve& );

   Curve( Curve&& ) noexcept;
   Curve& operator=( Curve&& ) noexcept;

   ~Curve();

   Segment_base& add( const Key& key, const Point_container& points );
   Segment_base& add( const Point_container& points );
   Segment_base& add( const Segment_indexed& seg );
   Segment_base& add( Segment_indexed&& seg );

   Segment_base& add( const Key& key, float step, double start, const Value_container& y_values );
   Segment_base& add( float step, double start, const Value_container& y_values );
   Segment_base& add( const Segment_stepped& seg );
   Segment_base& add( Segment_stepped&& seg );

   size_t count_indexed() const;
   size_t count_stepped() const;
   size_t count( Type type ) const;
   size_t count() const;

   const Segment_stepped_container& get_segments_stepped() const;
   const Segment_indexed_container& get_segments_indexed() const;
   Segment_base_cptr_container get_segments( Type type ) const;
   Segment_base_cptr_container get_segments() const;

   bool is_valid_stepped( double start, double end );
   bool is_valid_indexed( double start, double end );
   bool is_valid( double start, double end, Type type );
   bool is_valid( double start, double end );
   void validate( double start, double end, const char* file, const char* function, int line );

private:
#pragma warning(push)
#pragma warning(disable:4251)
   Segment_indexed_container segments_indexed_;
   Segment_stepped_container segments_stepped_;
#pragma warning(pop)
};

}
}
