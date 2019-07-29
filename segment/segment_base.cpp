#include "segment_base.h"
#include "segment_stepped.h"
#include "segment_indexed.h"
#include "..\utility\exception\message.h"
#include <exception>

using namespace std;

nhill::segment::Segment_base::Segment_base( Type type, const Key& key /*= {}*/ )
   : type_{ type }
   , key_{ key }
{
}

nhill::segment::Segment_base::Segment_base( const Segment_base& ) = default;

auto nhill::segment::Segment_base::operator=( const Segment_base & other )->Segment_base &
{
   if( type() != other.type() )
   {
      throw logic_error( NHILL_EXCEPTION_MESSAGE( "Invalid segment types.", "The segments types must be the same in order to copy." ) );
   }

   key_ = other.key_;

   return *this;
}

nhill::segment::Segment_base::Segment_base( Segment_base&& ) = default;

auto nhill::segment::Segment_base::operator=( Segment_base && other )->Segment_base &
{
   if( type() != other.type() )
   {
      throw logic_error( NHILL_EXCEPTION_MESSAGE( "Invalid segment types.", "The segments types must be the same in order to move." ) );
   }

   key_ = move( other.key_ ); 

   return *this;
}

nhill::segment::Segment_base::~Segment_base() = default;

auto nhill::segment::Segment_base::type() const->Type
{
   return type_;
}

auto nhill::segment::Segment_base::key() const->Key
{
   return key_;
}

void nhill::segment::Segment_base::key( const Key & value )
{
   key_ = value;
}

auto nhill::segment::Segment_base::make_unique( Type type )->Segment_base::uptr
{
   switch( type )
   {
   case nhill::segment::Type::stepped: return std::make_unique<Segment_stepped>();
   case nhill::segment::Type::indexed: return std::make_unique<Segment_indexed>();
   default: throw std::exception( "Invalid segment type." );
   }
}

double nhill::segment::Segment_base::a() const
{
   return start();
}

double nhill::segment::Segment_base::b() const
{
   return end();
}

bool nhill::segment::Segment_base::is_valid_position( size_t pos ) const
{
   return (0 <= pos) && (pos < size());
}

void nhill::segment::Segment_base::validate_position( size_t pos, const char * file, const char * function, int line ) const
{
   if( !is_valid_position( pos ) )
   {
      throw out_of_range( exception::build( {file, function, line, "Invalid position " + to_string( pos ) + ".", "The position must be in the range[0, " + to_string( size() - 1 ) + "]."} ) );
   }
}

bool nhill::segment::Segment_base::is_valid_x( double x ) const
{
   return !(x < start()) && !(end() < x);
}

void nhill::segment::Segment_base::validate_x( double x, const char * file, const char * function, int line ) const
{
   if( !is_valid_x( x ) )
   {
      throw out_of_range( exception::build( {file, function, line, "Invalid x value " + to_string( x ) + ".", "The x value must be in the range[" + to_string( start() ) + ", " + to_string( end() ) + "]."} ) );
   }
}




