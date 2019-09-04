#pragma once

#include "port.h"
#include "attribute_container.h"
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

namespace nhill
{
namespace xml
{

class OStream;

class Writer
{
public:
   Writer();
   Writer( const std::string& path );
   Writer( const Writer& ) = delete;
   Writer( Writer&& ) = delete;
   ~Writer();

public:
   Writer& operator=( const Writer& ) = delete;
   Writer& operator=( Writer&& ) = delete;

public:
   std::string path() const;
protected:
   void path( const std::string& value );

public:
   void open( const std::string& path );
   bool is_open() const;
   void close();

   void increment_indent();
   void decrement_indent();

   Writer& start_tag( const std::string& name, const Attribute_container& attributes = {} );
   Writer& end_tag( const std::string& name );

   Writer& element( const std::string& name, const Attribute_container& attributes = {} );
   template<typename Value> Writer& element( const std::string& name, const Attribute_container& attributes, const Value& value );
   template<typename Value> Writer& element( const std::string& name, const Value& value );
   template<> Writer& element<std::string>( const std::string& name, const Attribute_container& attributes, const std::string& text );
   template<> Writer& element<std::string>( const std::string& name, const std::string& text );

protected:
   OStream& indent();
   template<typename Value> std::string value_to_string( const Value& value ) const;

private:
   OStream * ostream_;
   std::string path_;
   std::ofstream out_;
   int indent_;
};

}
}

#pragma region Definitions
template<typename Value> inline 
auto nhill::xml::Writer::element( const std::string & name, const Attribute_container & attributes, const Value & value )->Writer &
{
   return element<std::string>( name, attributes, value_to_string( value ) );
}

template<typename Value> inline 
auto nhill::xml::Writer::element( const std::string & name, const Value & value )->Writer &
{
   return element<std::string>( name, value_to_string( value ) );
}

template<typename Value> inline 
std::string nhill::xml::Writer::value_to_string( const Value & value ) const
{
   std::ostringstream oss;
   oss << value;
   return oss.str();
}
#pragma endregion