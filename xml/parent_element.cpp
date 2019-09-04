#include "parent_element.h"
#include "attribute.h"
#include "ostream.h"

using namespace std;

nhill::xml::Parent_element::Parent_element( const std::string & name )
   : name_{name}
   , attributes_{}
{
}

nhill::xml::Parent_element::Parent_element( const std::string & name, const Attribute_container & attributes )
   : name_{ name }
   , attributes_{ attributes }
{
}

nhill::xml::Parent_element::Parent_element( const std::string & name, std::initializer_list<Attribute> attributes /*={}*/ )
   : name_{ name }
   , attributes_{ attributes }
{
}

nhill::xml::Parent_element::Parent_element( const Parent_element & other )
{
   *this = other;
}

nhill::xml::Parent_element::Parent_element( Parent_element && other )
{
   *this = move( other );
}

nhill::xml::Parent_element::~Parent_element()
{
}

auto nhill::xml::Parent_element::operator=( const Parent_element & other )->Parent_element &
{
   name_ = other.name_;
   attributes_ = other.attributes_;

   return *this;
}

auto nhill::xml::Parent_element::operator=( Parent_element && other )->Parent_element &
{
   name_ = other.name_;
   attributes_ = other.attributes_;

   return *this;
}

const string & nhill::xml::Parent_element::name() const
{
   return name_;
}

auto nhill::xml::Parent_element::attributes()->Attribute_container &
{
   return attributes_;
}

auto nhill::xml::Parent_element::attributes() const->const Attribute_container &
{
   return attributes_;
}

void nhill::xml::Parent_element::attributes( const Attribute_container & value )
{
   attributes_ = value;
}

void nhill::xml::Parent_element::attributes( initializer_list<Attribute> list )
{
   attributes_ = list;
}

std::string nhill::xml::Parent_element::start_tag() const
{
   ostringstream oss;
   OStream ostream{ oss };
   ostream.start_tag( name(), attributes() );
   return oss.str();
}

std::string nhill::xml::Parent_element::end_tag() const
{
   ostringstream oss;
   OStream ostream{ oss };
   ostream.end_tag( name() );
   return oss.str();
}

