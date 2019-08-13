#pragma once

#include "bundle.h"
#include "../../../utility/exception/not_implemented.h"
#include <map>
#include <initializer_list>
#include <string_view>

namespace nhill
{
namespace text
{

template<typename Enum, std::enable_if_t<std::is_enum_v<Enum>>* = nullptr>
class Bundle_container
{
public:
   using Inner_container = std::map<Enum, nhill::text::Bundle>;

   
   Bundle_container();
   Bundle_container( Enum e, std::string_view string );
   Bundle_container( std::initializer_list<std::pair<const Enum, nhill::text::Bundle>> init_list );
   Bundle_container( const Bundle_container& );
   Bundle_container& operator=( const Bundle_container& );
   Bundle_container( Bundle_container&& ) noexcept;
   Bundle_container& operator=( Bundle_container&& ) noexcept;
   ~Bundle_container();

   const std::string& code( Enum e ) const;
   const std::string& abbreviation( Enum e ) const;
   const std::string& string( Enum e ) const;
   const std::string& label( Enum e ) const;
   const std::string& description( Enum e ) const;

   const std::string& text( Enum e, Text type );

   bool contains( Enum e ) const;

   typename Inner_container::const_iterator cbegin() const noexcept;
   typename Inner_container::const_iterator cend() const noexcept;

private:
   static const std::string empty_string_;

   Inner_container cont_; // Inner Container
};

}
}

template<typename Enum, std::enable_if_t<std::is_enum_v<Enum>>* ef> inline
const std::string nhill::text::Bundle_container<Enum, ef>::empty_string_{ "" };

template<typename Enum, std::enable_if_t<std::is_enum_v<Enum>>* ef> inline
nhill::text::Bundle_container<Enum, ef>::Bundle_container() = default;

template<typename Enum, std::enable_if_t<std::is_enum_v<Enum>>* ef> inline 
nhill::text::Bundle_container<Enum, ef>::Bundle_container( Enum e, std::string_view string )
   : cont_{ {{e, string}} }
{
}

template<typename Enum, std::enable_if_t<std::is_enum_v<Enum>>* ef> inline
nhill::text::Bundle_container<Enum, ef>::Bundle_container( std::initializer_list<std::pair<const Enum, nhill::text::Bundle>> init_list )
   : cont_{init_list}
{

}

template<typename Enum, std::enable_if_t<std::is_enum_v<Enum>>* ef> inline
nhill::text::Bundle_container<Enum, ef>::Bundle_container( const Bundle_container& ) = default;

template<typename Enum, std::enable_if_t<std::is_enum_v<Enum>>* ef> inline
auto nhill::text::Bundle_container<Enum, ef>::operator=( const Bundle_container& )->Bundle_container & = default;

template<typename Enum, std::enable_if_t<std::is_enum_v<Enum>>* ef> inline
nhill::text::Bundle_container<Enum, ef>::Bundle_container( Bundle_container&& ) noexcept = default;

template<typename Enum, std::enable_if_t<std::is_enum_v<Enum>>* ef> inline
auto nhill::text::Bundle_container<Enum, ef>::operator=( Bundle_container&& ) noexcept->Bundle_container & = default;

template<typename Enum, std::enable_if_t<std::is_enum_v<Enum>>* ef> inline
nhill::text::Bundle_container<Enum, ef>::~Bundle_container() = default;

template<typename Enum, std::enable_if_t<std::is_enum_v<Enum>>* ef> inline
const std::string& nhill::text::Bundle_container<Enum, ef>::code( Enum e ) const
{
   return contains( e ) ? cont_.at( e ).code() : empty_string_;
}

template<typename Enum, std::enable_if_t<std::is_enum_v<Enum>>* ef> inline
const std::string& nhill::text::Bundle_container<Enum, ef>::abbreviation( Enum e ) const
{
   return contains( e ) ? cont_.at( e ).abbreviation() : empty_string_;
}

template<typename Enum, std::enable_if_t<std::is_enum_v<Enum>>* ef> inline
const std::string& nhill::text::Bundle_container<Enum, ef>::string( Enum e ) const
{
   return contains( e ) ? cont_.at( e ).string() : empty_string_;
}

template<typename Enum, std::enable_if_t<std::is_enum_v<Enum>>* ef> inline
const std::string& nhill::text::Bundle_container<Enum, ef>::label( Enum e ) const
{
   return contains( e ) ? cont_.at( e ).label() : empty_string_;
}

template<typename Enum, std::enable_if_t<std::is_enum_v<Enum>>* ef> inline
const std::string& nhill::text::Bundle_container<Enum, ef>::description( Enum e ) const
{
   return contains( e ) ? cont_.at( e ).description() : empty_string_;
}

template<typename Enum, std::enable_if_t<std::is_enum_v<Enum>>* ef> inline
const std::string& nhill::text::Bundle_container<Enum, ef>::text( Enum e, Text type )
{
   return contains( e ) ? cont_.at( e ).text( type ) : empty_string_;
}

template<typename Enum, std::enable_if_t<std::is_enum_v<Enum>>* ef> inline
bool nhill::text::Bundle_container<Enum, ef>::contains( Enum e ) const
{
   return cont_.find( e ) != cont_.end();
}

template<typename Enum, std::enable_if_t<std::is_enum_v<Enum>>* ef> inline
auto nhill::text::Bundle_container<Enum, ef>::cbegin() const noexcept->typename Inner_container::const_iterator
{
   return cont_.cbegin();
}

template<typename Enum, std::enable_if_t<std::is_enum_v<Enum>>* ef> inline
auto nhill::text::Bundle_container<Enum, ef>::cend() const noexcept->typename Inner_container::const_iterator
{
   return cont_.cend();
}


namespace nhill
{
namespace text
{

/// <summary>Get the bundle_container for a particular enumeration type.</summary>
/// <see cref="http://stackoverflow.com/questions/27090975/c-template-specialization-in-different-dll-produces-linker-errors"/>
/// <see cref="https://social.msdn.microsoft.com/Forums/vstudio/en-US/6fa7b447-5cfe-4d9c-9047-94bfae4606a8/exporting-a-template-specialization-from-a-dll?forum=vclanguage"/>
template<typename Enum, std::enable_if_t<std::is_enum_v<Enum>>* = nullptr>
const nhill::text::Bundle_container<Enum>& bundle_container()
{
   throw nhill::Not_implemented( "The nhill::text::bundle_container template is not implemented.  It must be specialized for each enumeration type." );
}

}
}
