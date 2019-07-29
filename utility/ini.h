#pragma once

#include "port.h"
#include <string>
#include <sstream>
#include <cassert>


namespace nhill
{

class NHILL_UTIL_PORT_CLASS Ini
{
public:
   Ini( const std::string& path = "", const std::string& section = "", const std::string& key = "" );

public:
   std::string path() const;
   void path( const std::string& value );

   std::string section() const;
   void section( const std::string& value );

   std::string key() const;
   void key( const std::string& value );

public:
   template<typename T>
   T read( const T& defalt = {} ) const;

   template<typename T>
   T read( const std::string& key, const T& defalt = {} ) const;

   template<typename T>
   T read( const std::string& section, const std::string& key, const T& defalt = {} ) const;

   template<typename T>
   static T read( const std::string& path, const std::string& section, const std::string& key, const T& defalt = {} );

public:
   template<typename T>
   bool write( const T& value ) const;

   template<typename T>
   bool write( const std::string& key, const T& value ) const;

   template<typename T>
   bool write( const std::string& section, const std::string& key, const T& value ) const;

   template<typename T>
   static bool write( const std::string& path, const std::string& section, const std::string& key, const T& value );

private:
#pragma warning(push)
#pragma warning(disable:4251)
   std::string path_;
   std::string section_;
   std::string key_;
#pragma warning(pop)
};

}

#pragma region Template Specialization
template<> NHILL_UTIL_PORT_FUNCTION
std::string nhill::Ini::read( const std::string& path, const std::string& section, const std::string& key, const std::string& defalt );

template<> NHILL_UTIL_PORT_FUNCTION
bool nhill::Ini::write( const std::string& path, const std::string& section, const std::string& key, const std::string& value );
#pragma endregion

#pragma region Definitions
template<typename T>
T nhill::Ini::read( const T& defalt ) const
{
   return read( path, section, key, defalt );
}

template<typename T>
T nhill::Ini::read( const std::string& key, const T& defalt ) const
{
   return read( path, section, key, defalt );
}

template<typename T>
T nhill::Ini::read( const std::string& section, const std::string& key, const T& defalt ) const
{
   return read( path, section, key, defalt );
}

template<typename T>
T nhill::Ini::read( const std::string& path, const std::string& section, const std::string& key, const T& defalt )
{
   // Convert the default parameter to a string
   std::ostringstream deflt_str;
   deflt_str << defalt;

   // The value as a string
   std::string value_str = read<std::string>( path, section, key, defalt );

   // Put the Value string into a string stream
   std::stringstream value_stream;
   value_stream << value_str;

   // Convert the Value stream to a Value
   T value;
   value_stream >> value;

   return value;
}

template<typename T>
bool nhill::Ini::write( const T& value ) const
{
   return Ini::write( path, section, key, value );
}

template<typename T>
bool nhill::Ini::write( const std::string& key, const T& value ) const
{
   return Ini::write( path, section, key, value );
}

template<typename T>
bool nhill::Ini::write( const std::string& section, const std::string& key, const T& value ) const
{
   return Ini::write( path, section, key, value );
}

template<typename T>
bool nhill::Ini::write( const std::string& path, const std::string& section, const std::string& key, const T& value )
{
   // Write the Value to a string stream
   std::ostringstream value_stream;
   value_stream << value;

   return write<std::string>( path, section, key, value_stream.str() );
}
#pragma endregion 