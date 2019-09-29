#pragma once

#include "port.h"
#include "attribute_container.h"
#include <string>
#include <ostream>

namespace nhill
{
namespace xml
{

class NHILL_XML_PORT_CLASS OStream
{
public:
   OStream( std::ostream& out );
   OStream( const OStream& ) = delete;
   OStream( OStream&& ) = delete;
   ~OStream();

public:
   OStream& operator=( const OStream& ) = delete;
   OStream& operator=( OStream&& ) = delete;

public:
   OStream& indent( unsigned int indent );
   OStream& endl();
   OStream& declaration( const std::string& version = "1.0", const std::string& encoding = "UTF-8", const std::string& standalone = "yes" );
   OStream& declaration_for_basic( const std::string& version = "1.0", const std::string& encoding = "UTF-8", const std::string& standalone = "yes" );
   OStream& start_tag( const std::string& name, const Attribute_container& attributes = {}, bool is_empty = false );
   OStream& end_tag( const std::string& name );
   OStream& element( const std::string& name, const Attribute_container& attributes = {} );
   template<typename Value> OStream& element( const std::string& name, const Attribute_container& attributes, const Value& value );
   template<typename Value> OStream& element( const std::string& name, const Value& value );
   template<> OStream& element<std::string>( const std::string& name, const Attribute_container& attributes, const std::string& text );
   template<> OStream& element<std::string>( const std::string& name, const std::string& text );

private:
   std::ostream& out_;
};

}
}

template<typename Value> inline
auto nhill::xml::OStream::element( const std::string & name, const Attribute_container & attributes, const Value & value )->OStream&
{
   std::stringstream oss;
   oss << value;
   return element<std::string>( name, attributes, value.str() );
}

template<typename Value> inline
auto nhill::xml::OStream::element( const std::string & name, const Value & value )->OStream&
{
   std::stringstream oss;
   oss << value;
   return element<std::string>( name, value.str() );
}
