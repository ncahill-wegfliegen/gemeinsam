#pragma once

#include "port.h"
#include "info_item.h"
#include <string>
#include <map>
#include <memory>

namespace nhill
{

class Version;

namespace version
{

class Translation;

class String_table
{
public:
   String_table();
   String_table( const String_table& );
   String_table& operator=( const String_table& );
   String_table( String_table&& ) noexcept;
   String_table& operator=( String_table&& ) noexcept;
   ~String_table();

   const Translation& translation() const;
   void translation( const Translation& value );

   std::string comments() const;
   void comments( const std::string& value );

   std::string company_name() const;
   void company_name( const std::string& value );

   std::string file_description() const;
   void file_description( const std::string& value );

   Version file_version() const;
   void file_version( const Version& value );

   std::string internal_name() const;
   void internal_name( const std::string& value );

   std::string legal_copyright() const;
   void legal_copyright( const std::string& value );

   std::string legal_trademarks() const;
   void legal_trademarks( const std::string& value );

   std::string original_filename() const;
   void original_filename( const std::string& value );

   std::string private_build() const;
   void private_build( const std::string& value );

   std::string product_name() const;
   void product_name( const std::string& value );

   Version product_version() const;
   void product_version( const Version& value );

   std::string special_build() const;
   void special_build( const std::string& value );


   bool contains( Info_item item ) const;
   std::string get( Info_item item ) const;
   void set( Info_item item, const std::string& value );

   std::string& operator[]( Info_item item );
   std::string operator[]( Info_item item ) const;

private:
   std::unique_ptr<Translation> translation_;
   std::map<Info_item, std::string> collection_;
};

}
}