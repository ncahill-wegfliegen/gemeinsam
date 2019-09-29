#pragma once

#include "port.h"
#include "attribute.h"
#include "attribute_container.h"
#include <string>
#include <sstream>
#include <vector>

namespace tinyxml2
{
class XMLDocument; 
class XMLElement; 
class XMLAttribute;
enum XMLError;
}

namespace nhill
{
namespace xml
{

class NHILL_XML_PORT_CLASS Builder
{
protected:
   using Element_container = std::vector<tinyxml2::XMLElement*>;

public:
   Builder();
   Builder( const Builder& ) = delete;
   Builder( Builder&& ) = delete;
   virtual ~Builder();

public:
   Builder & operator=( const Builder& ) = delete;
   Builder& operator=( Builder&& ) = delete;

public:
   void declaration( const std::string& version = "1.0", const std::string& encoding = "UTF-8", bool standalone = true );
   Builder& begin( const std::string& name, const Attribute_container& attributes = {} );
   template<typename Value> Builder& begin( const std::string& name, const Attribute_container& attributes, const Value& value );
   template<typename Value> Builder& begin( const std::string& name, const Value& value );
   template<> Builder& begin<std::string>( const std::string& name, const Attribute_container& attributes, const std::string& text );
   template<> Builder& begin<std::string>( const std::string& name, const std::string& text );
   Builder& begin( const std::string& name, const Attribute_container& attributes, const char* text );
   Builder& begin( const std::string& name, const char* text );
   Builder& end();

   tinyxml2::XMLError save( const std::string& path );

protected:
   tinyxml2::XMLDocument& doc();
   const tinyxml2::XMLDocument& doc() const;

   Element_container& elements();
   const Element_container& elements() const;

   template<typename Value> std::string value_to_string( const Value& value ) const;

private:
   tinyxml2::XMLDocument* doc_;
   Element_container* elements_;
};

}
}

#pragma region Definitions
template<typename Value> inline
auto nhill::xml::Builder::begin( const std::string & name, const Attribute_container & attributes, const Value & value )->Builder &
{
   return begin<std::string>( name, attributes, value_to_string( value ) );
}

template<typename Value> inline
auto nhill::xml::Builder::begin( const std::string & name, const Value & value )->Builder &
{
   return begin<std::string>( name, value_to_string( value ) );
}

template<typename Value> inline
std::string nhill::xml::Builder::value_to_string( const Value & value ) const
{
   std::ostringstream oss;
   oss << value;
   return oss.str();
}
#pragma endregion
