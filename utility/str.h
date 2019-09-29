#pragma once

#include "chr.h"
#include <vector>
#include <algorithm>
#include <memory>
#include <cstdarg>
#include <locale>
#include <sstream>
#include <ostream>

namespace nhill
{
namespace str
{

template<typename Char> inline
std::vector<std::basic_string<Char>> split( std::basic_string_view<Char> s, Char delimiter )
{
   std::vector<std::basic_string<Char>> elements;
   std::basic_stringstream<Char> ss;
   std::basic_string<Char> item;

	ss << s;

   while( std::getline( ss, item, delimiter ) )
   {
      elements.push_back( item );
   }

   return elements;
}

template<typename Char> inline
std::basic_string<Char>& toupper( std::basic_string<Char>& s, const std::locale& loc = std::locale( "" ) )
{
   // Transform each character of the given bstr to uppercase
   std::transform( s.begin(), s.end(), s.begin(), [&loc]( Char c ) { return std::toupper<Char>( c, loc ); } );
   return s;
}

template<typename Char> inline
std::basic_string<Char> toupper_copy( std::basic_string<Char> s, const std::locale& loc = std::locale( "" ) )
{
   return nhill::str::toupper<Char>( s, loc );
}

template<typename Char> inline
std::basic_string<Char>& tolower( std::basic_string<Char>& s, const std::locale& loc = std::locale( "" ) )
{
   // Transform each character of the given bstr to uppercase
   std::transform( s.begin(), s.end(), s.begin(), [&loc]( Char c ) { return std::tolower<Char>( c, loc ); } );
   return s;
}

template<typename Char> inline
std::basic_string<Char> tolower_copy( std::basic_string<Char> s, const std::locale& loc = std::locale( "" ) )
{
   return nhill::str::tolower<Char>( s, loc );
}

template<typename Char> inline
std::basic_string<Char> format( std::basic_string<Char> fmt, ... )
{
   // The fmt is passed by value to conform with the requirements of va_start.

   int final_n = -1;
   int n = ((int)fmt.size()) * 2; /* Reserve two times as much as the length of the fmt */
   std::basic_string<Char> bstr;
   std::unique_ptr<Char[]> formatted;
   va_list ap;
   while( 1 )
   {
      formatted.reset( new Char[n] ); /* Wrap the plain char array into the unique_ptr */
                                       //_tcscpy_s( &formatted[ 0 ], n, fmt.c_str() );
      va_start( ap, fmt );
      final_n = _vsntprintf_s( &formatted[0], n, _TRUNCATE, fmt.c_str(), ap );
      va_end( ap );
      if( final_n < 0 || final_n >= n )
         n += abs( final_n - n + 1 );
      else
         break;
   }
   return std::basic_string<Char>( formatted.get() );
}

template<typename Char> inline
bool ends_with( const std::basic_string<Char>& bstr, const std::basic_string<Char>& ending )
{
   if( bstr.size() < ending.size() )
      return false;

   return bstr.compare( bstr.size() - ending.size(), ending.size(), ending ) == 0;
}

/// <summary>In the given text, find all occurrances of the old substring and replace them with the new substring.</summary>
/// <param name="text">The given text that contains the old substring.</param>
/// <param name="oldsubstr">The old substring to find and replace.</param>
/// <param name="newsubstr">The new substring to replace the old substring.</param>
/// <returns>The text with all occurrances of the old substring replaced by the new substring.<para>The text is returned if it does not contain the old substring.</para></returns>
template<typename Char> inline
std::basic_string<Char>& replace( std::basic_string<Char>& text, const std::basic_string<Char>& oldsubstr, const std::basic_string<Char>& newsubstr )
{
   // Make a copy of the input text so that we can manipulate it,
   // and return it when we are done.
   const size_t oldlen = oldsubstr.length();

   // do nothing if line is shorter than the bstr to find
   if( oldlen > text.length() )
      return text;

   const size_t newlen = newsubstr.length();
   for( size_t pos = 0; ; pos += newlen )
   {
      // Locate the substring to replace
      pos = text.find( oldsubstr, pos );
      if( pos == std::string::npos )
         return text;

      if( oldlen == newlen )
      {
         // if they're same size, use std::bstr::replace
         text.replace( pos, oldlen, newsubstr );
      }
      else
      {
         // if not same size, replace by erasing and inserting
         text.erase( pos, oldlen );
         text.insert( pos, newsubstr );
      }
   }

   return text;
}

/// <summary>In the given text, find all occurrances of the old substring and replace them with the new substring.</summary>
/// <param name="text">The given text that contains the old substring.</param>
/// <param name="oldsubstr">The old substring to find and replace.</param>
/// <param name="newsubstr">The new substring to replace the old substring.</param>
/// <returns>The text with all occurrances of the old substring replaced by the new substring.<para>The text is returned if it does not contain the old substring.</para></returns>
template<typename Char> inline
std::basic_string<Char> replace_copy( std::basic_string<Char> text, const std::basic_string<Char>& oldsubstr, const std::basic_string<Char>& newsubstr )
{
   return replace( text, oldsubstr, newsubstr );
}

/// <summary>(In-place) Trim all of the whitespace (space, tab, etc.) from the start of the bstr (std::bstr, std::wstring, etc.).</summary>
/// <param name="s">In/Out. The bstr to trim in-place; std::bstr, std::wstring, etc.</param>
/// <returns>A reference to the given bstr after it has been trimmed.</returns>
/// <see cref="std::isspace">The whitespace characters are determined by std::isspace.</see>
/// <example>An example of calling this method.
///   <code>
///      std::bstr s{""\t /nNow is the winter\t of our discontent.\t \n"};
///      nhill::trim_start( s );
///   </code>
///   When the function returns, the bstr 's' contains "Now is the winter\t of our discontent.\t \n".
/// </example>
template<typename Char> inline
std::basic_string<Char>& trim_start( std::basic_string<Char>& s, const std::locale& loc = std::locale( "" ) )
{
   auto end = std::find_if_not(
      s.begin(),
      s.end(),
      [&loc]( Char c ) {
         return std::isspace<Char>( c, loc );
      }
   );

   s.erase( s.begin(), end );

   return s;
}

/// <summary>(In-place) Trim all of the whitespace (space, tab, etc.) from the end of the bstr.</summary>
/// <param name="s">In/Out. The bstr to trim in-place; std::bstr, std::wstring, etc.</param>
/// <returns>A reference to the given bstr after it has been trimmed.</returns>
/// <see cref="std::isspace">The whitespace characters are determined by std::isspace.</see>
template<typename Char> inline
std::basic_string<Char>& trim_end( std::basic_string<Char>& s, const std::locale& loc = std::locale( "" ) )
{
   auto begin = std::find_if_not(
      s.rbegin(),
      s.rend(),
      [&loc]( int c ) {
         return std::isspace<Char>( c, loc );
      }
   ).base();

   s.erase( begin, s.end() );

   return s;
}

/// <summary>(In-place) Trim all of the whitespace (space, tab, etc.) from both the start and end of the bstr.</summary>
/// <param name="s">In/Out. The bstr to trim in-place; std::bstr, std::wstring, etc.</param>
/// <returns>A reference to the given bstr after it has been trimmed.</returns>
/// <see cref="std::isspace">The whitespace characters are determined by std::isspace.</see>
template<typename Char> inline
std::basic_string<Char>& trim( std::basic_string<Char>& s, const std::locale& loc = std::locale( "" ) )
{
   nhill::str::trim_end( trim_start( s, loc ), loc );
   return s;
}

template<typename Char> inline
std::basic_string<Char> trim_copy_start( std::basic_string<Char> s, const std::locale& loc = std::locale( "" ) )
{
   return nhill::str::trim_start( s, loc );
}

template<typename Char> inline
std::basic_string<Char> trim_copy_end( std::basic_string<Char> s, const std::locale& loc = std::locale( "" ) )
{
   return nhill::str::trim_end( s, loc );
}

template<typename Char> inline
std::basic_string<Char> trim_copy( std::basic_string<Char> s, const std::locale& loc = std::locale( "" ) )
{
   return nhill::str::trim( s, loc );
}

/// <summary>Erase all occurrances of the given characters from the bstr.</summary>
/// <param name="s">The bstr form which to erase the characters.</param>
/// <param name="chars_to_erase">The characters to erase.</param>
/// <returns>A reference to the given bstr.</returns>
/// <example>An example of how to call this method.
///   <code>
///      bstr phone_number = "(403) 444-1591";
///      erase_all( phone_number, "() -" );
///   </code>
///   The result should be "4034441591"
/// </example>
template<typename Char> inline
std::basic_string<Char>& erase_all( std::basic_string<Char>& s, const std::basic_string<Char>& chars_to_erase )
{
   for( size_t i = 0; i < chars_to_erase.length(); ++i )
   {
      s.erase( remove( s.begin(), s.end(), chars_to_erase[i] ), s.end() );
   }

   return s;
}

template<typename Char, size_t N> inline
std::basic_string<Char>& erase_all( std::basic_string<Char>& s, const Char( &chars_to_erase )[N] )
{
   return nhill::str::erase_all( s, std::basic_string<Char>{chars_to_erase} );
}

template<typename Char> inline
std::basic_string<Char> erase_all_copy( std::basic_string<Char> s, const std::basic_string<Char>& chars_to_erase )
{
   return nhill::str::erase_all( s, chars_to_erase );
}

template<typename Char, size_t N> inline
std::basic_string<Char> erase_all_copy( std::basic_string<Char> s, const Char( &chars_to_erase )[N] )
{
   return nhill::str::erase_all( s, std::basic_string<Char>{ chars_to_erase } );
}

template<typename Char> inline
bool contains_digit( const std::basic_string<Char>& s, const std::locale& loc = std::locale( "" ) )
{
   auto itr = std::find_if( s.begin(), s.end(), [&loc]( Char c ) { return std::isdigit<Char>( c, loc ); } );
   return itr != s.end();
}

/// <summary>Erase all of the characters after (and including) the first null character '\0'.</summary>
/// <param name="s">In/Out. The string to truncate.  The contents of this string may change.</param>
/// <returns>A reference to input string.</returns>
template<typename Char> inline
std::basic_string<Char>& truncate( std::basic_string<Char>& s )
{
   Char nullchar[1]{};
   typename std::basic_string<Char>::size_type pos = s.find( nullchar[0] );
   if( pos != std::basic_string<Char>::npos )
   {
      s.erase( s.begin() + pos, s.end() );
   }
   return s;
}

template<typename Char> inline
std::basic_string<Char> truncate_copy( std::basic_string<Char> s )
{
   return nhill::str::truncate( s );
}

/// <summary>Comapre the strings after they have been truncated.</summary>
template<typename Char> inline
int compare_truncated( std::basic_string<Char> s1, std::basic_string<Char> s2 )
{
   nhill::str::truncate( s1 );
   nhill::str::truncate( s2 );
   return s1.compare( s2 );
}

template<typename Char> inline
int compare_upper( std::basic_string<Char> s1, std::basic_string<Char> s2)
{
   nhill::str::toupper(s1);
   nhill::str::toupper(s2);
   return nhill::str::compare_truncated(s1, s2);
}

template<typename Char> inline
bool is_empty( const std::basic_string<Char>& s )
{
   if( s.size() == 0 )
      return true;

   return s[0] == nhill::chr::null<Char>();
}

template<typename Char, std::size_t N> inline
bool is_empty( const Char( &s )[N] )
{
   if( N == 0 )
      return true;

   return s[0] == nhill::chr::null<Char>();
}

template<typename Char> inline
bool contains( const std::vector<std::basic_string<Char>>& sc, const std::basic_string<Char>& s )
{
   return std::find( sc.begin(), sc.end(), s ) != sc.end();
}

template<typename Char> inline
std::basic_string<Char> quotation( const std::basic_string<Char>& s )
{
   std::basic_ostringstream<Char> oss;
   oss << nhill::chr::quote<Char>() << s << nhill::chr::quote<Char>();
   return oss.str();
}


template<typename Char> inline
std::basic_ostream<Char>& indent(std::basic_ostream<Char>& out, unsigned int indent )
{
   static const char tab = nhill::chr::tab<char>();
   static const std::basic_string<Char> tabs( 32, tab );

   if( indent < 1 )
   {
      return out;
   }

   if( indent <= tabs.size() )
   {
      out << tabs.substr(0, indent);
   }
   else
   {
      out << std::basic_string<Char>( indent, tab );
   }

   return out;
}

template<typename Char> inline
typename std::basic_string<Char>::size_type find_whitespace(const std::basic_string<Char>& s)
{
   typename std::basic_string<Char>::size_type pos{ 
      s.find(
         s.cbegin(),
         s.cend(),
         [](Char c)
         {
            return std::isspace(c) != 0;
         }
      )
   };

   return pos;
}

inline std::string to_string( const std::wstring& wstr )
{
	if( wstr.length() == 0 )
	{
		return {};
	}

	using facet_type = std::codecvt<wchar_t, char, std::mbstate_t>;

	std::locale mylocale;
	const facet_type& myfacet{ std::use_facet<facet_type>( mylocale ) };
	std::wstring::size_type length{ wstr.length() };

	// prepare objects to be filled by codecvt::out:
	char* pstr{ new char[length + 1]{} };				// the destintaiton buffer (might be too short)
	std::mbstate_t mystate{ std::mbstate_t{} };	// the shift state object
	const wchar_t* pwc{ nullptr };					// from_next
	char* pc{ nullptr };									// to_next

	// translate the characters
	facet_type::result myresult{
		myfacet.out(
			mystate,
			wstr.c_str(),
			wstr.c_str() + length + 1,
			pwc,
			pstr,
			pstr + length + 1,
			pc
		)
	};

	std::string str{ pstr };

	delete[] pstr;
	pstr = nullptr;

	return str;
}

inline std::wstring to_wstring( const std::string& str )
{
	if( str.length() == 0 )
	{
		return {};
	}

	using facet_type = std::codecvt<wchar_t, char, std::mbstate_t>;
	
	std::locale mylocale;
	const facet_type& myfacet{ std::use_facet<facet_type>( mylocale ) };
	std::string::size_type length{ str.length() };

	// prepare objects to be filled by codecvt::in:
	wchar_t* pwstr{ new wchar_t[length + 1]{} };	// the destination buffer (might be too short)
	std::mbstate_t mystate{ std::mbstate_t{} };	// the shift state object
	const char* pc{ nullptr };							// from_next
	wchar_t* pwc{ nullptr };							// to_next

	// translate the characters
	facet_type::result myresult{
		myfacet.in(
			mystate,
			str.c_str(),
			str.c_str() + length + 1,
			pc,
			pwstr,
			pwstr + length + 1,
			pwc
		)
	};

	std::wstring wstr{ pwstr };

	delete[] pwstr;
	pwstr = nullptr;

	return wstr;
}

template<typename ... Args>
std::string string_format( const std::string& format, Args ... args )
{
	size_t size = snprintf( nullptr, 0, format.c_str(), args ... ) + 1; // Extra space for '\0'
	std::unique_ptr<char[]> buf( new char[size] );
	snprintf( buf.get(), size, format.c_str(), args ... );
	return std::string( buf.get(), buf.get() + size - 1 ); // We don't want the '\0' inside
}
}
}