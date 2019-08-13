#pragma once

#include "../../port.h"
#include "../text.h"
#include <string_view>
#include <map>
#include <initializer_list>

namespace nhill
{
namespace text
{

class NHILL_ENUM_PORT_CLASS Bundle
{
public:
   Bundle( std::string_view string );
   Bundle( std::string_view code, std::string_view abbreviation, std::string_view string, std::string_view label, std::string_view description ); 
   Bundle( std::initializer_list<std::pair<const Text, std::string>> init_list );
   Bundle( const Bundle& );
   Bundle& operator=( const Bundle& );
   Bundle( Bundle&& ) noexcept;
   Bundle& operator=( Bundle&& ) noexcept;
   ~Bundle();

   const std::string& code() const;
   void code( std::string_view );

   const std::string& abbreviation() const;
   void abbreviation( std::string_view );

   const std::string& string() const;
   void string( std::string_view );

   const std::string& label() const;
   void label( std::string_view );

   const std::string& description() const;
   void description( std::string_view );

   const std::string& text( Text type ) const;
   void text( Text type, std::string_view text );

   bool contains( Text type ) const;

private:
#pragma warning(suppress: 4251)
   std::map<Text, std::string> bundle_;

#pragma warning(suppress: 4251)
   static const std::string empty_string_;
};

}
}
