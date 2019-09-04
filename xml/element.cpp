#include "element.h"
#include "ostream.h"

using namespace std;

template<> 
nhill::xml::Element::Element( const std::string& name, const std::string& text )
   : Parent_element{name }
   , text_{ text }
{
}

template<> 
nhill::xml::Element::Element( const std::string& name, const Attribute_container& attributes, const std::string& text )
   : Parent_element{ name, attributes }
   , text_{ text }
{
}

template<> 
nhill::xml::Element::Element( const std::string& name, std::initializer_list<Attribute> attributes, const std::string& text )
   : Parent_element{ name, attributes }
   , text_{ text }
{
}


nhill::xml::Element::Element( const Element & other )
   : Parent_element{ other }
   , text_{other.text_}
{
}

nhill::xml::Element::Element( Element && other )
   : Parent_element{ std::move( other ) }
   , text_{ std::move(other.text_ ) }
{
}

nhill::xml::Element::~Element()
{
}

auto nhill::xml::Element::operator=( const Element & other )->Element &
{
   Parent_element::operator=( other );
   text_ = other.text_;

   return *this;
}

auto nhill::xml::Element::operator=( Element && other )->Element &
{
   Parent_element::operator=( std::move( other ) );
   text_ = other.text_;

   return *this;
}

const string & nhill::xml::Element::text() const
{
   return text_;
}

bool nhill::xml::Element::is_empty() const
{
   return text().empty();
}

std::string nhill::xml::Element::start_tag() const
{
   ostringstream oss;
   OStream ostream{ oss };
   ostream.start_tag( name(), attributes(), is_empty() );
   return oss.str();
}

std::string nhill::xml::Element::end_tag() const
{
   ostringstream oss;
   OStream ostream{ oss };
   ostream.end_tag( name() );
   return oss.str();
}

ostream & nhill::xml::operator<<( ostream & out, const Element & element )
{
   out << element.start_tag();
   if( !element.is_empty() )
   {
      out << element.text();
      out << element.end_tag();
   }

   return out;
}
