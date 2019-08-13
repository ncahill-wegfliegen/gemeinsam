#pragma once

#include "port.h"
#include "segment_types.h"
#include "../geometry/interval.h"
#include "../geometry/pnt_container.h"
#include "../math/compare.h"

#pragma warning(push)
#pragma warning(disable: 4251)

namespace nhill
{
namespace segment
{

/// <summary>The base class for segments, which can be either 'stepped' or 'indexed'.</summary>
/// <see cref="nhill::segment::Stepped"/>
/// <see cref="nhill::segment::Indexed"/>
class NHILL_SEGMENT_PORT_CLASS Segment_base : public geometry::Interval<double, math::Compare_greater_or_equal, math::Compare_less_or_equal>
{
public:
   using base = Interval<double, math::Compare_greater_or_equal, math::Compare_less_or_equal>;
   using ptr = Segment_base *;
   using cptr = const Segment_base*;
   using uptr = std::unique_ptr<Segment_base>;
   using ref = Segment_base &;
   using cref = const Segment_base &;
   using wref = std::reference_wrapper<Segment_base>;
   using cwref = std::reference_wrapper<const Segment_base>;

   Segment_base( Type type, const Key& key = {} );

   Segment_base( const Segment_base& );
   Segment_base& operator=( const Segment_base& );

   Segment_base( Segment_base&& );
   Segment_base& operator=( Segment_base&& );

   ~Segment_base();

   Type type() const;
   
   Key key() const;
   void key( const Key& value );

   virtual double start() const = 0;
   virtual double end  () const = 0;
   virtual std::size_t size() const = 0;
   virtual Point at( std::size_t pos ) const = 0;
   virtual int pos( double x ) const = 0;
   virtual double y( double x ) const = 0;
   virtual Segment_base::uptr make_unique() const = 0;

   double a() const final;
   double b() const final;

   static Segment_base::uptr make_unique( Type type );

   bool is_valid_position( std::size_t pos ) const;
   void validate_position( std::size_t pos, const char* file, const char* function, int line ) const;

   bool is_valid_x( double x ) const;
   void validate_x( double x, const char* file, const char* function, int line ) const;

private:
   Type type_;
   Key key_;
};

}
}

#pragma warning(pop)

namespace nhill
{
namespace segment
{


using Segment_base_cptr_container = std::vector<Segment_base::cptr>;
using Segment_base_uptr_container = std::vector<Segment_base::uptr>;
using Segment_base_cwref_container = std::vector<Segment_base::cwref>;


}
}