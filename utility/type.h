#pragma once

#include <string>

namespace nhill
{
namespace type
{

/// <summary>Get the name of a class, struct, enum, etc.</summary>
/// <returns>The name of the given object.</returns>
/// <example>
///     Use this method if you want the name of the class, struct, enum, etc.,
///     but without an instance.
///     <code>
///         std::tstring name = nhill::type::ToName&lt;nhill::Field&gt;();
///     </code>
///     This will return name='Field'.
/// </example>
template<typename T>
std::string narrow_name()
{
   const type_info& ti = typeid(T);

   // The name will look something like: class nhill::Field ([class [<namespace>::]]<classname>)
   std::string name = ti.name();

   // Strip off the "class" at the beginning if it is present.
   // Note: user defined types will have the 'class' or 'struct' or 'enum' at the beginning,
   // but built in types (e.g., int) will not have anything.
   std::string::size_type index = name.rfind( ' ' );
   if( index != std::string::npos )
      name = name.substr( index + 1 );

   // Now strip off the namespace "nhill::" if it is present.
   index = name.rfind( ':' );
   if( index != std::string::npos )
      name = name.substr( index + 1 );

   return name;
}

template<typename T, typename Char = char>
std::basic_string<Char> to_name( const T& obj )
{
   std::string name = nhill::type::narrow_name<T>();
   return std::basic_string<Char>( name.begin(), name.end() );
}

template<typename T, typename Char = char>
std::basic_string<Char> to_name()
{
   std::string name = nhill::type::narrow_name<T>();
   return std::basic_string<Char>( name.begin(), name.end() );
}


}
}