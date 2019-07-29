#include "subject.h"
#include "observer.h"
#include "changed_event_args.h"
#include <algorithm>

nhill::som::Subject::Subject()
{
   current_ = Som::si;
}

nhill::som::Subject::~Subject()
{
}

nhill::Som nhill::som::Subject::current() const
{
   return current_;
}

void nhill::som::Subject::current( System_of_measurement value )
{
   if( current_ == value )
   {
      // There is no change
      return;
   }

   current_ = value;
   notify_system_of_measurement_changed( "nhill::som::Subject", {value} );
}

bool nhill::som::Subject::is_metric() const
{
   return current_ == Som::metric;
}

bool nhill::som::Subject::is_api() const
{
   return current_ == Som::api;
}

void nhill::som::Subject::attach( Observer* observer )
{
   if( observer == nullptr )
   {
      return;
   }

   // Look for this observer in the container?
   auto itr = std::find( observers_.begin(), observers_.end(), observer );
   if( itr != observers_.end() )
   {
      // This observer is already attached
      return;
   }

   observers_.push_back( observer );
}

void nhill::som::Subject::detach( Observer* observer )
{
   if( observer == nullptr )
   {
      return;
   }

   observers_.erase( std::remove( observers_.begin(), observers_.end(), observer ) );
}

void nhill::som::Subject::notify_system_of_measurement_changed( const std::string& sender, const Changed_event_args& event_args ) const
{
   for( auto& observer : observers_ )
   {
      if( observer != nullptr )
      {
         observer->on_system_of_measurement_changed( sender, event_args );
      }
   }
}
