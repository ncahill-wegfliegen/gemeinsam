#include <windows.h>
#include "ini.h"
#include "file.h"
#include "exception/Invalid_path.h"
#include <sstream>

nhill::Ini::Ini( const std::string& path /*= ""*/, const std::string& section /*= ""*/, const std::string& key /*= ""*/ )
{
   this->path( path );
   this->section( section );
   this->key( key );
}

std::string nhill::Ini::path() const
{
   return path_;
}

void nhill::Ini::path( const std::string & value )
{
   if( !file::exists( value ) )
   {
      throw Invalid_path{ value };
   }

   path_ = value;
}

std::string nhill::Ini::section() const
{
   return section_;
}

void nhill::Ini::section( const std::string & value )
{
   section_ = value;
}

std::string nhill::Ini::key() const
{
   return key_;
}

void nhill::Ini::key( const std::string & value )
{
   key_ = value;
}

template<>
std::string nhill::Ini::read( const std::string& path, const std::string& section, const std::string& key, const std::string& defalt )
{
   if( !file::exists( path ) )
   {
      throw Invalid_path{ path };
   }

   const DWORD value_size{ 2048 };
   char value[value_size]{};

   // Get the Value string out of the Ini file. 
   ::GetPrivateProfileStringA(
      section.c_str(),
      key.c_str(),
      defalt.c_str(),
      &value [0],
      value_size,
      path.c_str()
   );

   return value;
}

template<>
bool nhill::Ini::write( const std::string& path, const std::string& section, const std::string& key, const std::string& value )
{
   if( !file::exists( path ) )
   {
      throw Invalid_path{ path };
   }

   BOOL success = ::WritePrivateProfileStringA(
      section.c_str(),
      key.c_str(),
      value.c_str(),
      path.c_str()
   );

   return success != FALSE;
}

