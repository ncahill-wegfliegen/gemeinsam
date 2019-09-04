#include "ostream.h"
#include "attribute.h"
#include <sstream>
#include "../utility/chr.h"
#include "../utility/str.h"

using namespace std;

nhill::xml::OStream::OStream( ostream& out )
   : out_{ out }
{
}

nhill::xml::OStream::~OStream()
{
}

auto nhill::xml::OStream::indent( unsigned int indent )->OStream&
{
   str::indent( out_, indent );
   return *this;
}

auto nhill::xml::OStream::endl()->OStream &
{
   out_ << std::endl;
   return *this;
}

auto nhill::xml::OStream::declaration( const string & version, const string & encoding, const string & standalone )->OStream&
{
   out_ << "<?xml version=\"" << version << "\" encoding=\"" << encoding << "\" standalone=\"" << standalone << "\" ?>";
   return *this;
}

auto nhill::xml::OStream::declaration_for_basic( const string & version, const string & encoding, const string & standalone )->OStream&
{
   out_ << "<?xml version=\"\"" << version << "\"\" encoding=\"\"" << encoding << "\"\" standalone=\"\"" << standalone << "\"\" ?>";
   return *this;
}

auto nhill::xml::OStream::start_tag( const string & name, const Attribute_container & attributes, bool is_empty )->OStream&
{
   out_ << '<' << name;
   if( 0 < attributes.size() )
   {
      out_ << ' ';
      for( const auto& attribute : attributes )
      {
         out_ << attribute << ' ';
      }
   }
   if( is_empty )
   {
      out_ << '/';
   }
   out_ << '>';

   return *this;
}

auto nhill::xml::OStream::end_tag( const string & name )->OStream&
{
   out_ << '<' << '/' << name << '>';
   return *this;
}

auto nhill::xml::OStream::element( const string & name, const Attribute_container & attributes )->OStream&
{
   return start_tag( name, attributes, true );
}

template<>
auto nhill::xml::OStream::element( const string & name, const Attribute_container & attributes, const string & text )->OStream&
{
   if( text.length() == 0 )
   {
      element( name, attributes );
   }
   else
   {
      start_tag( name, attributes );
      out_ << text;
      end_tag( name );
   }

   return *this;
}

template<>
auto nhill::xml::OStream::element( const string & name, const string & text )->OStream&
{
   if( text.length() == 0 )
   {
      element( name );
   }
   else
   {
      start_tag( name );
      out_ << text;
      end_tag( name );
   }

   return *this;
}




