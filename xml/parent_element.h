#pragma once

#include "port.h"
#include "attribute_container.h"
#include <string>
#include <sstream>
#include <ostream>
#include <vector>

namespace nhill
{
namespace xml
{

/// <summary>Instead of containing text, the parent element contains other elements.</summary>
class GS_XML_PORT_CLASS Parent_element
{
public:
   Parent_element( const std::string& name );
   Parent_element( const std::string& name, const Attribute_container& attributes );
   Parent_element( const std::string& name, std::initializer_list<Attribute> attributes );
   Parent_element( const Parent_element& other );
   Parent_element( Parent_element&& other );
   virtual ~Parent_element();

public:
   Parent_element& operator=( const Parent_element& other );
   Parent_element& operator=( Parent_element&& other );

public:
   const std::string& name() const;

   Attribute_container& attributes();
   const Attribute_container& attributes() const;
   void attributes( const Attribute_container& value );
   void attributes( std::initializer_list<Attribute> list );

public:
   virtual std::string start_tag() const;
   virtual std::string end_tag() const;

private:
   std::string name_;
   Attribute_container attributes_;
};

}
}

