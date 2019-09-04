#include "builder.h"
#include "attribute.h"
#include "core\kernel.h"
#include "../../../other/TiXml2/tinyxml2.h"
#include <sstream>

using namespace std;
using namespace tinyxml2;

nhill::xml::Builder::Builder()
   : doc_{ new XMLDocument{} }
   , elements_{ new Element_container{} }
{
}

nhill::xml::Builder::~Builder()
{
   delete doc_;
   delete elements_;
}

void nhill::xml::Builder::declaration( const std::string & version /*= "1.0"*/, const std::string & encoding /*= "UTF-8"*/, bool standalone /*= true*/)
{
   ostringstream dec;
   dec << "xml version=\"" << version << "\" encoding=\"" << encoding << "\" standalone=\"" << (standalone ? "yes" : "no") << "\"";

   XMLDeclaration* xml_declaration = doc().NewDeclaration( dec.str().c_str() );
   
   doc().LinkEndChild( xml_declaration );
}

auto nhill::xml::Builder::begin( const std::string & name, const Attribute_container & attributes )->Builder&
{
   XMLElement* element = doc().NewElement( name.c_str() );
   
   for( const auto& attribute : attributes )
   {
      element->SetAttribute( attribute.key().c_str(), attribute.value().c_str() );
   }

   elements().push_back( element );

   return *this;
}

template<>
auto nhill::xml::Builder::begin( const string & name, const Attribute_container & attributes, const string & text )->Builder &
{
   XMLElement* element = doc().NewElement( name.c_str() );

   for( const auto& attribute : attributes )
   {
      element->SetAttribute( attribute.key().c_str(), attribute.value().c_str() );
   }

   if( !text.empty() )
   {
      element->SetText( text.c_str() );
   }

   elements().push_back( element );

   return *this;
}

template<>
auto nhill::xml::Builder::begin( const string & name, const string & text )->Builder &
{
   XMLElement* element = doc().NewElement( name.c_str() );

   if( !text.empty() )
   {
      element->SetText( text.c_str() );
   }

   elements().push_back( element );

   return *this;
}

auto nhill::xml::Builder::begin( const std::string & name, const Attribute_container & attributes, const char * text )->Builder &
{
   return (text != nullptr && 0 < strlen( text )) ?
      begin<std::string>( name, attributes, std::string{ text } ) :
      begin( name, attributes );
}

auto nhill::xml::Builder::begin( const std::string & name, const char * text )->Builder &
{
   return (text != nullptr && 0 < strlen( text )) ?
      begin<std::string>( name, std::string{ text } ) :
      begin( name );
}


auto nhill::xml::Builder::end()->Builder&
{
   XMLElement* element = elements().back();
   elements().pop_back();

   if( elements().size() == 0 )
   {
      doc().LinkEndChild( element );
   }
   else
   {
      XMLElement* parent = elements().back();
      parent->LinkEndChild( element );
   }

   return *this;
}

auto nhill::xml::Builder::save( const std::string & path )->XMLError
{
   return doc().SaveFile( path.c_str() );
}

auto nhill::xml::Builder::doc()->XMLDocument &
{
   return *doc_;
}

auto nhill::xml::Builder::doc() const->const XMLDocument &
{
   return *doc_;
}

auto nhill::xml::Builder::elements()->Element_container &
{
   return *elements_;
}

auto nhill::xml::Builder::elements() const->const Element_container &
{
   return *elements_;
}

