#include "writer.h"
#include "ostream.h"
#include "attribute.h"
#include <sstream>
#include "../utility/chr.h"
#include "../utility/file.h"
#include <filesystem>

using namespace std;

nhill::xml::Writer::Writer()
   : ostream_{nullptr}
   , path_{}
   , indent_{0}
{
   out_.exceptions( ofstream::failbit | ofstream::badbit );
}

nhill::xml::Writer::Writer( const string& path )
   : ostream_{nullptr}
   , indent_{ 0 }
{
   out_.exceptions( ofstream::failbit | ofstream::badbit );
   open( path );
}

nhill::xml::Writer::~Writer()
{
   close();
}

string nhill::xml::Writer::path() const
{
   return path_;
}

void nhill::xml::Writer::path( const string & value )
{
   namespace fs = experimental::filesystem::v1;

   // Check to make sure that the path has valid format

   string invalid_char(1, '\0' );
   if( file::contains_invalid_char( value, &invalid_char[0] ) )
   {
      ostringstream msg;
      msg << "The path " << value << " contains an invalid character: " << invalid_char << '.';
      throw invalid_argument( msg.str() );
   }

   fs::path fs_path{ value };
   if( !fs_path.has_parent_path() )
   {
      ostringstream msg;
      msg << "The path " << fs_path.string() << " does not contain a directory.";
      throw invalid_argument( msg.str() );
   }

   fs::path fs_dir{ fs_path.parent_path() };
   error_code error_code;
   if( !fs::exists( fs_dir, error_code ) )
   {
      ostringstream msg;
      msg << "Invalid directory " << fs_dir.string() << ". " << error_code.message();
      throw invalid_argument( msg.str() );
   }

   if( !fs_path.has_filename() )
   { 
      ostringstream msg;
      msg << "The path " << fs_path.string() << " does not contain a file name.";
      throw invalid_argument( msg.str() );
   }

   
   path_ = value;
}

void nhill::xml::Writer::open( const string & path )
{
   close();

   this->path( path );
   out_.open( this->path() );

   ostream_ = new OStream{ out_ };
   ostream_->declaration().endl();
}

bool nhill::xml::Writer::is_open() const
{
   return out_.is_open();
}

void nhill::xml::Writer::close()
{
   if( out_.is_open() )
   {
      delete ostream_;
      ostream_ = nullptr;

      out_.close();
      path_.clear();
   }
}

void nhill::xml::Writer::increment_indent()
{
   ++indent_;
}

void nhill::xml::Writer::decrement_indent()
{
   --indent_;
}

auto nhill::xml::Writer::start_tag( const string & name, const Attribute_container & attributes )->Writer &
{
   indent().start_tag( name, attributes ).endl();
   return *this;
}

auto nhill::xml::Writer::end_tag( const string & name )->Writer &
{
   indent().end_tag( name ).endl();
   return *this;
}

auto nhill::xml::Writer::element( const string & name, const Attribute_container & attributes )->Writer &
{
   indent().element( name, attributes ).endl();
   return *this;
}

template<>
auto nhill::xml::Writer::element( const string & name, const Attribute_container & attributes, const string & text )->Writer &
{
   indent().element( name, attributes, text ).endl();
   return *this;
}

template<>
auto nhill::xml::Writer::element( const string & name, const string & text )->Writer &
{
   indent().element( name, text ).endl();
   return *this;
}

auto nhill::xml::Writer::indent()->OStream&
{
   ostream_->indent( indent_ );
   return *ostream_;
}

