#pragma once

#include "port.h"
#include "parent_element.h"
#include <vector>

namespace nhill
{
namespace xml
{

/// <summary>A single line element.  Attributes are optional, but it must have text (value converted to text).
///   <para>&lt;note date="2018-01-01"&gt;Buy milk&lt;/note&gt;</para>
///   <para>&lt;date day="1" month="3" year="1963" /&gt;</para>
/// </summary>
class NHILL_XML_PORT_CLASS Element : public Parent_element
{
public:
   template<typename Value> Element( const std::string& name, const Value& value );
   template<typename Value> Element( const std::string& name, const Attribute_container& attributes, const Value& value );
   template<typename Value> Element( const std::string& name, std::initializer_list<Attribute>, const Value& value );
   template<> Element( const std::string& name, const std::string& text );
   template<> Element( const std::string& name, const Attribute_container& attributes, const std::string& text );
   template<> Element( const std::string& name, std::initializer_list<Attribute>, const std::string& text );
   Element( const Element& other );
   Element( Element&& other );
   ~Element() override;

public:
   Element& operator=( const Element& other );
   Element& operator=( Element&& other );

public:
   const std::string& text() const;

public:
   bool is_empty() const;
   std::string start_tag() const override;
   std::string end_tag() const override;

protected:
   template<typename Value>
   std::string value_to_text( const Value& value) const;

private:
   std::string text_;
};

using Element_container = std::vector<Element>;


NHILL_XML_PORT_FUNCTION std::ostream& operator<<( std::ostream& out, const Element& element );

}
}


template<typename Value> inline 
nhill::xml::Element::Element( const std::string & name, const Value & value )
   : Parent_element{name}
   , text_{ value_to_text( value) }
{
}

template<typename Value> inline 
nhill::xml::Element::Element( const std::string & name, const Attribute_container& attributes, const Value & value )
   : Parent_element{ name, attributes }
   , text_{ value_to_text( value ) }
{
}

template<typename Value> inline
nhill::xml::Element::Element( const std::string& name, std::initializer_list<Attribute> attributes, const Value& value )
   : Parent_element{ name, attributes }
   , text_{ value_to_text( value ) }
{

}

template<typename Value> inline 
std::string nhill::xml::Element::value_to_text( const Value & value ) const
{
   std::ostringstream oss;
   oss << value;
   return oss.str();
}
