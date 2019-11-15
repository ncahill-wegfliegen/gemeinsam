#pragma once

#include "../../enum/core/values.h"
#include "../chr.h"
#include <string_view>
#include <string>
#include <ostream>
#include <sstream>
#include <map>
#include <algorithm>

namespace nhill
{
namespace exception
{

class Message
{
public:
   enum class Type 
   {
      file,
      function,
      line,
      message,
      condition,
   };

   Message();
   Message( std::string_view file, std::string_view function, int line, std::string_view message, std::string_view condition );
   Message( std::initializer_list<std::pair<Type, std::string>> il );
   Message( const Message& );
   Message& operator=( const Message& );
   Message( Message&& ) noexcept;
   Message& operator=( Message&& ) noexcept;
   ~Message();

   std::string& operator[]( Type type );
   const std::string& operator[]( Type type ) const;

   static std::string to_label( Type type );
   bool contains( Type type ) const;

   std::string to_string() const;

private:
#pragma warning(suppress: 4251)
   std::map<Type, std::string> values_;
};

}
}

#pragma region Values
namespace nhill
{
template<> inline nhill::exception::Message::Type nhill::begin() 
{
	return  exception::Message::Type::file; 
}
template<> inline nhill::exception::Message::Type nhill::end()
{
	int i{ to_int( exception::Message::Type::condition ) };
	++i;
	return to_enum<exception::Message::Type>(i);
};
}
#pragma endregion

#pragma region Exception Message Macro
namespace nhill
{
namespace exception
{

inline size_t max_label_width( const Message& msg )
{
   size_t w{0};

   for( auto type : nhill::Values<Message::Type>() )
   {
      if( msg.contains( type ) )
      {
         w = std::max( w, Message::to_label( type ).size() );
      }
   }

   return w;
}

inline std::ostream& write_line( std::ostream& out, size_t w1, Message::Type type, const std::string& value )
{
   constexpr char colon{nhill::chr::colon<char>()};
   constexpr char space{nhill::chr::space<char>()};

   if( value.empty() )
   {
      return out;
   }

   out << std::setw( w1 ) << Message::to_label( type ) << colon << space << value << std::endl;

   return out;
}

inline std::string build( const Message& msg )
{
   return msg.to_string();
}

}
}

#define NHILL_EXCEPTION_MESSAGE( MESSAGE, CONDITION ) nhill::exception::build( {__FILE__, __func__, __LINE__, MESSAGE, CONDITION} )

#pragma endregion

#pragma region Definitions
inline nhill::exception::Message::Message() = default;

inline nhill::exception::Message::Message( std::string_view file, std::string_view function, int line, std::string_view message, std::string_view condition )
   : values_{
      { Type::file      , std::string(file) },
      { Type::function  , std::string(function) },
      { Type::line      , std::to_string( line ) },
      { Type::message   , std::string(message) },
      { Type::condition , std::string(condition) },
}
{
}

inline nhill::exception::Message::Message( std::initializer_list<std::pair<Type, std::string>> il )
{
   for( const auto& [type, text] : il )
   {
      operator[]( type ) = text;
   }
}

inline nhill::exception::Message::Message( const Message& ) = default;

inline auto nhill::exception::Message::operator=( const Message& )->Message & = default;

inline nhill::exception::Message::Message( Message&& other ) noexcept
   : values_{ move( other.values_ ) }
{
}

inline auto nhill::exception::Message::operator=( Message&& )noexcept->Message & = default;

inline nhill::exception::Message::~Message() = default;

inline std::string& nhill::exception::Message::operator[]( Type type )
{
   return values_[type];
}

inline const std::string& nhill::exception::Message::operator[]( Type type ) const
{
   return values_.at( type );
}

inline std::string nhill::exception::Message::to_label( Type type )
{
   switch( type )
   {
   case Message::Type::file:      return "File";
   case Message::Type::function:  return "Function";
   case Message::Type::line:      return "Line";
   case Message::Type::message:   return "Message";
   case Message::Type::condition: return "Condition";
   default:                       return "";
   }
}

inline bool nhill::exception::Message::contains( Type type ) const
{
   auto itr = values_.find( type );
   return itr != values_.end();
}

inline std::string nhill::exception::Message::to_string() const
{
   std::ostringstream out;
   size_t w{ max_label_width(*this) };

   for( auto type : nhill::Values<Message::Type>() )
   {
      if( contains( type ) )
      {
         write_line( out, w, type, operator[]( type ) );
      }
   }

   return out.str();
}
#pragma endregion