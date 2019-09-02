#pragma once

#include <type_traits>
// http://stackoverflow.com/questions/11421432/how-can-i-output-the-value-of-an-enum-class-in-c11
// In Visual Studio 2015 we can use:
// constexpr int ToInt( Enum e)



namespace nhill
{

/// <summary>Convert the strongly typed enumeration to its underlying integer value.</summary>
/// <param name="e">The stronly typed enumeration to be converted.</param>
/// <returns>The integer value underlying to the given strongly typed enumeration.</returns>
template<typename Enum, std::enable_if_t<std::is_enum_v<Enum>>* = nullptr> inline
constexpr int to_int( Enum e ) noexcept
{
   // underlying type
   using Under = std::underlying_type_t<Enum>;
   // underlying type value
   Under val = static_cast <Under>(e);
   // integer value
   int i = static_cast<int>(val);
   return i;
}

/// <summary>Convert an integer to the corresponding strongly typed enumeration.</summary>
/// <param name="i">The integer to be converted.</param>
/// <returns>The stronly typed enumeration corresponding to the given integer.</returns>
template<typename Enum, std::enable_if_t<std::is_enum_v<Enum>>* = nullptr> inline
constexpr Enum to_enum( int i ) noexcept
{
   // underlying type
   using Under = std::underlying_type_t<Enum>;
   // underlying type value
   Under val = static_cast <Under>(i);
   // enumeration 
   Enum e = static_cast<Enum>(val);
   return e;
}

/// <summary>Convert the strongly typed enumeration to its corresponding geoSCOUT integer value.</summary>
/// <param name="e">The stronly typed enumeration to be converted.</param>
/// <returns>The geoSCOUT integer value corresponding to the given strongly typed enumeration.</returns>
template<typename Enum, std::enable_if_t<std::is_enum_v<Enum>>* = nullptr>
int to_gs_int( Enum e )
{
   return nhill::to_int( e );
}

/// <summary>Convert a geoSCOUT integer value to the corresponding strongly typed enumeration.</summary>
/// <param name="i">The geoSCOUT integer value to be converted.</para>
/// <returns>The stronly typed enumeration corresponding to the given geoSCOUT integer value.</returns>
template<typename Enum, std::enable_if_t<std::is_enum_v<Enum>>* = nullptr>
Enum from_gs_int( int i )
{
   return nhill::to_enum<Enum>( i );
}

}
