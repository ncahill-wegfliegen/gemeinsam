#include "attribute.h"

nhill::xml::Attribute::Attribute()
   : pair_{ new Pair{  "", "" } }
{
}

template<> 
nhill::xml::Attribute::Attribute( const std::string & key, const std::string & value )
   : pair_{ new Pair{ key, value  } }
{
}



nhill::xml::Attribute::Attribute( const Attribute & other )
   : pair_{ new Pair{ *other.pair_ } }
{
}

nhill::xml::Attribute::Attribute( Attribute && other )
   : pair_{ other.pair_ }
{
   other.pair_ = nullptr;
}

nhill::xml::Attribute::~Attribute()
{
   delete pair_;
}

auto nhill::xml::Attribute::operator=( const Attribute & other ) -> Attribute &
{
   *pair_ = *other.pair_;
  
   return *this;
}

auto nhill::xml::Attribute::operator=( Attribute && other ) -> Attribute &
{
   delete pair_;
   pair_ = other.pair_;
   other.pair_ = nullptr;

   return *this;
}

const std::string & nhill::xml::Attribute::key() const
{
   return pair_->first;
}

void nhill::xml::Attribute::key( const std::string & value )
{
   pair_->first = value;
}

const std::string & nhill::xml::Attribute::value() const
{
   return pair_->second;
}

template<>
void nhill::xml::Attribute::value<std::string>( const std::string & value )
{
   pair_->second = value;
}

std::ostream& nhill::xml::operator<<( std::ostream& out, const Attribute& attr )
{
   std::string value;
   char quote{ '\"' };

   // If the value contains double quotes, then replace them 
   auto pos = attr.value().find( quote );
   if( pos == std::string::npos )
   {
      value = attr.value();
   }
   else
   {
      value.reserve( 2 * attr.value().size() );
      for( auto c = attr.value().begin() ; c != attr.value().end() ; ++c )
      {
         if( *c == quote )
         {
            value += "&quot;";
         }
         else
         {
            value.push_back( *c );
         }
      }
   }

   return out << attr.key() << '=' << quote << value << quote;
}
