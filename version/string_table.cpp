#include "string_table.h"
#include "translation.h"
#include "version.h"

using namespace std;

nhill::version::String_table::String_table()
   : translation_{ std::make_unique<Translation>() }
{
}

nhill::version::String_table::String_table( const String_table & other )
   : translation_{ std::make_unique<Translation>( other.translation() )}
   , collection_{ other.collection_ }
{
   *this = other;
}

auto nhill::version::String_table::operator=( const String_table& other ) -> String_table &
{
   *translation_ = *other.translation_;
   collection_ = other.collection_;

   return *this;
}

nhill::version::String_table::String_table( String_table && other ) noexcept
   : translation_{move(other.translation_)}
   , collection_{move(other.collection_)}
{
}

auto nhill::version::String_table::operator=( String_table&& other ) noexcept->String_table & = default;

nhill::version::String_table::~String_table() = default;



auto nhill::version::String_table::translation() const ->const Translation &
{
   return *translation_;
}

void nhill::version::String_table::translation( const Translation & value )
{
   *translation_ = value;
}

std::string nhill::version::String_table::comments() const
{
   return get( Info_item::comments );
}

void nhill::version::String_table::comments( const std::string & value )
{
   set(Info_item::comments, value );
}

std::string nhill::version::String_table::company_name() const
{
   return get( Info_item::company_name );
}

void nhill::version::String_table::company_name( const std::string& value )
{
   set( Info_item::company_name, value );
}

std::string nhill::version::String_table::file_description() const
{
   return get( Info_item::file_description );
}

void nhill::version::String_table::file_description( const std::string& value )
{
   set( Info_item::file_description, value );
}

nhill::Version nhill::version::String_table::file_version() const
{
   return { get( Info_item::file_version ) };
}

void nhill::version::String_table::file_version( const Version& value )
{
   set( Info_item::file_version, value.to_string() );
}

std::string nhill::version::String_table::internal_name() const
{
   return get( Info_item::internal_name );
}

void nhill::version::String_table::internal_name( const std::string& value )
{
   set( Info_item::internal_name, value );
}

std::string nhill::version::String_table::legal_copyright() const
{
   return get( Info_item::legal_copyright );
}

void nhill::version::String_table::legal_copyright( const std::string& value )
{
   set( Info_item::legal_copyright, value );
}

std::string nhill::version::String_table::legal_trademarks() const
{
   return get( Info_item::legal_trademarks );
}

void nhill::version::String_table::legal_trademarks( const std::string & value )
{
   set( Info_item::legal_trademarks, value );
}

std::string nhill::version::String_table::original_filename() const
{
   return get( Info_item::original_filename );
}

void nhill::version::String_table::original_filename( const std::string& value )
{
   set( Info_item::original_filename, value );
}

std::string nhill::version::String_table::private_build() const
{
   return get( Info_item::private_build );
}

void nhill::version::String_table::private_build( const std::string & value )
{
   set( Info_item::private_build, value );
}

std::string nhill::version::String_table::product_name() const
{
   return get( Info_item::product_name );
}

void nhill::version::String_table::product_name( const std::string& value )
{
   set( Info_item::product_name, value );
}

nhill::Version nhill::version::String_table::product_version() const
{
   return { get( Info_item::product_version ) };
}

void nhill::version::String_table::product_version( const Version& value )
{
   set( Info_item::product_version, value.to_string() );
}

std::string nhill::version::String_table::special_build() const
{
   return get( Info_item::special_build );
}

void nhill::version::String_table::special_build( const std::string & value )
{
   set( Info_item::special_build, value );
}

bool nhill::version::String_table::contains( Info_item item ) const
{
   auto itr = collection_.find( item );
   return itr != collection_.end();
}

std::string nhill::version::String_table::get( Info_item item ) const
{
   return contains( item ) ? collection_.at( item ) : "";
}

void nhill::version::String_table::set( Info_item item, const std::string & value )
{
   collection_[item] = value;
}

std::string & nhill::version::String_table::operator[]( Info_item item )
{
   return collection_[item];
}

std::string nhill::version::String_table::operator[]( Info_item item ) const
{
   return get(item);
}

