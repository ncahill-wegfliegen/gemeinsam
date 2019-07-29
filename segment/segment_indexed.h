#pragma once

#include "port.h"
#include "segment_base.h"
#include "segment_types.h"

namespace nhill
{
namespace segment
{

/// <summary>This segment type is used when the step between the x-values is irregular.</summary>
/// <remarks>Invariants. In order to be a valid segment:
///   <para>1) There must be at least one point.</para>
///   <para>2) The start value must be less than the end value.</para>
/// </remarks>
class NHILL_SEGMENT_PORT_CLASS Segment_indexed final : public Segment_base
{
public:
   using base = Segment_base;
   using ptr = Segment_indexed *;
   using cptr = const Segment_indexed *;
   using ref = Segment_indexed &;
   using cref = const Segment_indexed &;

   Segment_indexed( const Key& key = {} );
   Segment_indexed( const Key& key, const Point_container& points );
   Segment_indexed( const Point_container& points );

   Segment_indexed( const Segment_indexed& );
   Segment_indexed& operator=( const Segment_indexed& );

   Segment_indexed( Segment_indexed&& ) noexcept;
   Segment_indexed& operator=( Segment_indexed&& ) noexcept;

   ~Segment_indexed();

   double start() const override;
   double end() const override;
   std::size_t size() const override;
   Point at( std::size_t pos ) const override;
   int pos( double x ) const override;
   double y( double x ) const override;
   Segment_base::uptr make_unique() const override;

   const Point_container& points() const;
   void points( const Point_container& value );

   /// <summary>Validate the invariants for this type of segment.</summary>
   /// <exception cref="std::invalid_argment">Throw this exception if the segment is not valid.</exception>
   static void validate( const Point_container& value, const char* file, const char* function, int line );

private:
   Point_container * points_;
};

}
}

namespace nhill
{
namespace segment
{

using Segment_indexed_container = std::vector<Segment_indexed>;
using Segment_indexed_cptr_container = std::vector<Segment_indexed::cptr>;
using Segment_indexed_uptr_container = std::vector<Segment_indexed::uptr>;


}
}