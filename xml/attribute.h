#pragma once

#include "port.h"
#include <string>
#include <sstream>
#include <ostream>

namespace nhill
{
namespace xml
{

class NHILL_XML_PORT_CLASS Attribute 
{
protected:
   using Pair = std::pair<std::string, std::string>;

public:
   Attribute();
   template<typename Value> Attribute( const std::string& key, const Value& value );
   template<> Attribute( const std::string& key, const std::string& value );
   Attribute( const Attribute& other );
   Attribute( Attribute&& other );
   ~Attribute();

public:
   Attribute& operator=( const Attribute& other );
   Attribute& operator=( Attribute&& other );

public:
   const std::string& key() const;
   void key( const std::string& value );

   const std::string& value() const;
   template<typename Value> void value( const Value& value );
   template<> void value<std::string>( const std::string& value );

protected:
   template<typename Value>
   std::string value_to_string( const Value& value ) const;

private:
   Pair* pair_;
};

NHILL_XML_PORT_FUNCTION std::ostream& operator<<( std::ostream& out, const Attribute& attr );

}
}


#pragma region Definitions
template<typename Value>
inline nhill::xml::Attribute::Attribute( const std::string & key, const Value & value )
   : pair_{ new Pair{ key, value_to_string<Value>( value ) } }
{
}

template<typename Value> inline
void nhill::xml::Attribute::value( const Value & value )
{
   pair_->second = value_to_string<Value>( value );
}

template<typename Value> inline 
std::string nhill::xml::Attribute::value_to_string( const Value & value ) const
{
   std::ostringstream oss;
   oss << value;
   return oss.str();
}
#pragma endregion