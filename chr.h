#pragma once

#include "enable_if.h"
#include "exception/not_implemented.h"
#include <filesystem>

namespace nhill
{
namespace chr
{

#pragma region slash
template<typename Char> inline
Char slash()
{
   throw Not_implemented("The tempalte function nhill::file::slash is not implemented. It must be specialized for each particular character type.");
}

template<> inline constexpr
char slash()
{
   return u8'/';
}

template<> inline constexpr
wchar_t slash()
{
   return L'/';
}

template<> inline constexpr
char16_t slash()
{
   return u'/';
}

template<> inline constexpr
char32_t slash()
{
   return U'/';
}
#pragma endregion

#pragma region backslash
template<typename Char> inline
Char backslash()
{
   throw Not_implemented("The tempalte function nhill::file::backslash is not implemented. It must be specialized for each particular character type.");
}

template<> inline constexpr
char backslash()
{
   return u8'\\';
}

template<> inline constexpr
wchar_t backslash()
{
   return L'\\';
}

template<> inline constexpr
char16_t backslash()
{
   return u'\\';
}

template<> inline constexpr
char32_t backslash()
{
   return U'\\';
}
#pragma endregion

#pragma region period
template<typename Char> inline
Char period()
{
   throw Not_implemented("The tempalte function nhill::file::period is not implemented. It must be specialized for each particular character type.");
}

template<> inline constexpr
char period()
{
   return u8'.';
}

template<> inline constexpr
wchar_t period()
{
   return L'.';
}

template<> inline constexpr
char16_t period()
{
   return u'.';
}

template<> inline constexpr
char32_t period()
{
   return U'.';
}
#pragma endregion

#pragma region colon
template<typename Char> inline
Char colon()
{
   throw Not_implemented("The tempalte function nhill::file::colon is not implemented. It must be specialized for each particular character type.");
}

template<> inline constexpr
char colon()
{
   return u8':';
}

template<> inline constexpr
wchar_t colon()
{
   return L':';
}

template<> inline constexpr
char16_t colon()
{
   return u':';
}

template<> inline constexpr
char32_t colon()
{
   return U':';
}
#pragma endregion

#pragma region star
template<typename Char> inline
Char star()
{
   throw Not_implemented("The tempalte function nhill::file::star is not implemented. It must be specialized for each particular character type.");
}

template<> inline constexpr
char star()
{
   return u8'*';
}

template<> inline constexpr
wchar_t star()
{
   return L'*';
}

template<> inline constexpr
char16_t star()
{
   return u'*';
}

template<> inline constexpr
char32_t star()
{
   return U'*';
}
#pragma endregion

#pragma region plus
template<typename Char> inline
Char plus()
{
   throw Not_implemented("The tempalte function nhill::file::plus is not implemented. It must be specialized for each particular character type.");
}

template<> inline constexpr
char plus()
{
   return u8'+';
}

template<> inline constexpr
wchar_t plus()
{
   return L'+';
}

template<> inline constexpr
char16_t plus()
{
   return u'+';
}

template<> inline constexpr
char32_t plus()
{
   return U'+';
}
#pragma endregion

#pragma region minus
template<typename Char> inline
Char minus()
{
   throw Not_implemented("The tempalte function nhill::file::minus is not implemented. It must be specialized for each particular character type.");
}

template<> inline constexpr
char minus()
{
   return u8'-';
}

template<> inline constexpr
wchar_t minus()
{
   return L'-';
}

template<> inline constexpr
char16_t minus()
{
   return u'-';
}

template<> inline constexpr
char32_t minus()
{
   return U'-';
}
#pragma endregion

#pragma region null
template<typename Char> inline constexpr
Char null()
{
   throw Not_implemented("The tempalte function nhill::file::null is not implemented. It must be specialized for each particular character type.");
}

template<> inline constexpr
char null()
{
   return u8'\0';
}

template<> inline constexpr
wchar_t null()
{
   return L'\0';
}

template<> inline constexpr
char16_t null()
{
   return u'\0';
}

template<> inline constexpr
char32_t null()
{
   return U'\0';
}
#pragma endregion

#pragma region tab
template<typename Char> inline
Char tab()
{
   throw Not_implemented("The tempalte function nhill::file::tab is not implemented. It must be specialized for each particular character type.");
}

template<> inline constexpr
char tab()
{
   return u8'\t';
}

template<> inline constexpr
wchar_t tab()
{
   return L'\t';
}

template<> inline constexpr
char16_t tab()
{
   return u'\t';
}

template<> inline constexpr
char32_t tab()
{
   return U'\t';
}
#pragma endregion

#pragma region comma
template<typename Char> inline
Char comma()
{
   throw Not_implemented("The tempalte function nhill::file::comma is not implemented. It must be specialized for each particular character type.");
}

template<> inline constexpr
char comma()
{
   return u8',';
}

template<> inline constexpr
wchar_t comma()
{
   return L',';
}

template<> inline constexpr
char16_t comma()
{
   return u',';
}

template<> inline constexpr
char32_t comma()
{
   return U',';
}
#pragma endregion

#pragma region space
template<typename Char> inline
Char space()
{
   throw Not_implemented("The tempalte function nhill::file::space is not implemented. It must be specialized for each particular character type.");
}

template<> inline constexpr
char space()
{
   return u8' ';
}

template<> inline constexpr
wchar_t space()
{
   return L' ';
}

template<> inline constexpr
char16_t space()
{
   return u' ';
}

template<> inline constexpr
char32_t space()
{
   return U' ';
}
#pragma endregion

#pragma region semicolon
template<typename Char> inline
Char semicolon()
{
   throw Not_implemented("The tempalte function nhill::file::semicolon is not implemented. It must be specialized for each particular character type.");
}

template<> inline constexpr
char semicolon()
{
   return u8';';
}

template<> inline constexpr
wchar_t semicolon()
{
   return L';';
}

template<> inline constexpr
char16_t semicolon()
{
   return u';';
}

template<> inline constexpr
char32_t semicolon()
{
   return U';';
}
#pragma endregion

#pragma region pipe
template<typename Char> inline
Char pipe()
{
   throw Not_implemented("The tempalte function nhill::file::pipe is not implemented. It must be specialized for each particular character type.");
}

template<> inline constexpr
char pipe()
{
   return u8'|';
}

template<> inline constexpr
wchar_t pipe()
{
   return L'|';
}

template<> inline constexpr
char16_t pipe()
{
   return u'|';
}

template<> inline constexpr
char32_t pipe()
{
   return U'|';
}
#pragma endregion

#pragma region question_mark
template<typename Char> inline
Char question_mark()
{
   throw Not_implemented("The tempalte function nhill::file::question_mark is not implemented. It must be specialized for each particular character type.");
}

template<> inline constexpr
char question_mark()
{
   return u8'?';
}

template<> inline constexpr
wchar_t question_mark()
{
   return L'?';
}

template<> inline constexpr
char16_t question_mark()
{
   return u'?';
}

template<> inline constexpr
char32_t question_mark()
{
   return U'?';
}
#pragma endregion

#pragma region asterisk
template<typename Char> inline
Char asterisk()
{
   throw Not_implemented("The tempalte function nhill::chr::asterisk is not implemented. It must be specialized for each particular character type.");
}

template<> inline constexpr
char asterisk()
{
   return u8'*';
}

template<> inline constexpr
wchar_t asterisk()
{
   return L'*';
}

template<> inline constexpr
char16_t asterisk()
{
   return u'*';
}

template<> inline constexpr
char32_t asterisk()
{
   return U'*';
}
#pragma endregion

#pragma region tilde
template<typename Char> inline
Char tilde()
{
   throw Not_implemented("The tempalte function nhill::chr::tilde is not implemented. It must be specialized for each particular character type.");
}

template<> inline constexpr
char tilde()
{
   return u8'~';
}

template<> inline constexpr
wchar_t tilde()
{
   return L'~';
}

template<> inline constexpr
char16_t tilde()
{
   return u'~';
}

template<> inline constexpr
char32_t tilde()
{
   return U'~';
}
#pragma endregion

#pragma region hash
template<typename Char> inline
Char hash()
{
   throw Not_implemented("The tempalte function nhill::chr::hash is not implemented. It must be specialized for each particular character type.");
}

template<> inline constexpr
char hash()
{
   return u8'#';
}

template<> inline constexpr
wchar_t hash()
{
   return L'#';
}

template<> inline constexpr
char16_t hash()
{
   return u'#';
}

template<> inline constexpr
char32_t hash()
{
   return U'#';
}
#pragma endregion

#pragma region preferred file separator
template<typename Char> inline constexpr
Char preferred_file_separator()
{
   namespace fs = std::filesystem;
   wchar_t pref_file_sep = fs::path::preferred_separator;

   if (pref_file_sep == nhill::chr::slash<wchar_t>())
   {
      return nhill::chr::slash<Char>();
   }
   else if (pref_file_sep == nhill::chr::backslash<wchar_t>())
   {
      return nhill::chr::backslash<Char>();
   }

   return nhill::chr::backslash<Char>();
}
#pragma endregion

#pragma region apostrophe
template<typename Char> inline
Char apostrophe()
{
   throw Not_implemented("The tempalte function nhill::chr::apostrophe is not implemented. It must be specialized for each particular character type.");
}

template<> inline constexpr
char apostrophe()
{
   return u8'\'';
}

template<> inline constexpr
wchar_t apostrophe()
{
   return L'\'';
}

template<> inline constexpr
char16_t apostrophe()
{
   return u'\'';
}

template<> inline constexpr
char32_t apostrophe()
{
   return U'\'';
}
#pragma endregion

#pragma region quote
template<typename Char> inline
Char quote()
{
   throw Not_implemented("The tempalte function nhill::chr::quote is not implemented. It must be specialized for each particular character type.");
}

template<> inline constexpr
char quote()
{
   return u8'\"';
}

template<> inline constexpr
wchar_t quote()
{
   return L'\"';
}

template<> inline constexpr
char16_t quote()
{
   return u'\"';
}

template<> inline constexpr
char32_t quote()
{
   return U'\"';
}
#pragma endregion

#pragma region underscore
template<typename Char> inline
Char underscore()
{
   throw Not_implemented("The tempalte function nhill::chr::underscore is not implemented. It must be specialized for each particular character type.");
}

template<> inline constexpr
char underscore()
{
   return u8'_';
}

template<> inline constexpr
wchar_t underscore()
{
   return L'_';
}

template<> inline constexpr
char16_t underscore()
{
   return u'_';
}

template<> inline constexpr
char32_t underscore()
{
   return U'_';
}
#pragma endregion

#pragma region angle_bra <
template<typename Char> inline
Char angle_bra()
{
   throw Not_implemented("The tempalte function nhill::chr::angle_bra is not implemented. It must be specialized for each particular character type.");
}

template<> inline constexpr
char angle_bra()
{
   return u8'<';
}

template<> inline constexpr
wchar_t angle_bra()
{
   return L'<';
}

template<> inline constexpr
char16_t angle_bra()
{
   return u'<';
}

template<> inline constexpr
char32_t angle_bra()
{
   return U'<';
}
#pragma endregion

#pragma region angle_ket >
template<typename Char> inline
Char angle_ket()
{
   throw Not_implemented("The tempalte function nhill::chr::angle_ket is not implemented. It must be specialized for each particular character type.");
}

template<> inline constexpr
char angle_ket()
{
   return u8'>';
}

template<> inline constexpr
wchar_t angle_ket()
{
   return L'>';
}

template<> inline constexpr
char16_t angle_ket()
{
   return u'>';
}

template<> inline constexpr
char32_t angle_ket()
{
   return U'>';
}
#pragma endregion

#pragma region round_bra (
template<typename Char> inline
Char round_bra()
{
   throw Not_implemented("The tempalte function nhill::chr::round_bra is not implemented. It must be specialized for each particular character type.");
}

template<> inline constexpr
char round_bra()
{
   return u8'(';
}

template<> inline constexpr
wchar_t round_bra()
{
   return L'(';
}

template<> inline constexpr
char16_t round_bra()
{
   return u'(';
}

template<> inline constexpr
char32_t round_bra()
{
   return U'(';
}
#pragma endregion

#pragma region round_ket )
template<typename Char> inline
Char round_ket()
{
   throw Not_implemented("The tempalte function nhill::chr::round_ket is not implemented. It must be specialized for each particular character type.");
}

template<> inline constexpr
char round_ket()
{
   return u8')';
}

template<> inline constexpr
wchar_t round_ket()
{
   return L')';
}

template<> inline constexpr
char16_t round_ket()
{
   return u')';
}

template<> inline constexpr
char32_t round_ket()
{
   return U')';
}
#pragma endregion

#pragma region square_bra [
template<typename Char> inline
Char square_bra()
{
   throw Not_implemented("The tempalte function nhill::chr::square_bra is not implemented. It must be specialized for each particular character type.");
}

template<> inline constexpr
char square_bra()
{
   return u8'[';
}

template<> inline constexpr
wchar_t square_bra()
{
   return L'[';
}

template<> inline constexpr
char16_t square_bra()
{
   return u'[';
}

template<> inline constexpr
char32_t square_bra()
{
   return U'[';
}
#pragma endregion

#pragma region square_ket ]
template<typename Char> inline
Char square_ket()
{
   throw Not_implemented("The tempalte function nhill::chr::square_ket is not implemented. It must be specialized for each particular character type.");
}

template<> inline constexpr
char square_ket()
{
   return u8']';
}

template<> inline constexpr
wchar_t square_ket()
{
   return L']';
}

template<> inline constexpr
char16_t square_ket()
{
   return u']';
}

template<> inline constexpr
char32_t square_ket()
{
   return U']';
}
#pragma endregion

#pragma region curly_bra {
template<typename Char> inline
Char curly_bra()
{
   throw Not_implemented("The tempalte function nhill::chr::curly_bra is not implemented. It must be specialized for each particular character type.");
}

template<> inline constexpr
char curly_bra()
{
   return u8'{';
}

template<> inline constexpr
wchar_t curly_bra()
{
   return L'{';
}

template<> inline constexpr
char16_t curly_bra()
{
   return u'{';
}

template<> inline constexpr
char32_t curly_bra()
{
   return U'{';
}
#pragma endregion

#pragma region curly_ket }
template<typename Char> inline
Char curly_ket()
{
   throw Not_implemented("The tempalte function nhill::chr::curly_ket is not implemented. It must be specialized for each particular character type.");
}

template<> inline constexpr
char curly_ket()
{
   return u8'}';
}

template<> inline constexpr
wchar_t curly_ket()
{
   return L'}';
}

template<> inline constexpr
char16_t curly_ket()
{
   return u'}';
}

template<> inline constexpr
char32_t curly_ket()
{
   return U'}';
}
#pragma endregion

#pragma region degree
template<typename Char> inline
Char degree()
{
   throw Not_implemented("The tempalte function nhill::chr::degree is not implemented. It must be specialized for each particular character type.");
}

template<> inline constexpr
char degree()
{
   return '°';
}

template<> inline constexpr
wchar_t degree()
{
   return static_cast<wchar_t>(248);// '°';
}

template<> inline constexpr
char16_t degree()
{
   return static_cast<char16_t>(248);// '°';
}

template<> inline constexpr
char32_t degree()
{
   return static_cast<char32_t>(248);// '°';
}
#pragma endregion

#pragma region arcminute
template<typename Char> inline
Char arcminute()
{
   throw Not_implemented("The tempalte function nhill::chr::arcminute is not implemented. It must be specialized for each particular character type.");
}

template<> inline constexpr
char arcminute()
{
   return u8'\'';
}

template<> inline constexpr
wchar_t arcminute()
{
   return L'\'';
}

template<> inline constexpr
char16_t arcminute()
{
   return u'\'';
}

template<> inline constexpr
char32_t arcminute()
{
   return U'\'';
}
#pragma endregion

#pragma region arcsecond
template<typename Char> inline
Char arcsecond()
{
   throw Not_implemented("The tempalte function nhill::chr::arcsecond is not implemented. It must be specialized for each particular character type.");
}

template<> inline constexpr
char arcsecond()
{
   return u8'\"';
}

template<> inline constexpr
wchar_t arcsecond()
{
   return L'\"';
}

template<> inline constexpr
char16_t arcsecond()
{
   return u'\"';
}

template<> inline constexpr
char32_t arcsecond()
{
   return U'\"';
}
#pragma endregion

}
}



#pragma region to/from char templates
namespace nhill
{

template<typename Enum, typename Char = char, typename nhill::enable_if::is_enum_type<Enum>* = nullptr>
Char to_char(Enum e)
{
   throw nhill::Not_implemented("The template function nhill::to_char is not implemented.  It must be specialized for each particular enumeration type.");
}

template<typename Enum, typename Char = char, typename nhill::enable_if::is_enum_type<Enum>* = nullptr>
Enum from_char(Char chr)
{
   throw nhill::Not_implemented("The template function nhill::from_char is not implemented.  It must be specialized for each particular enumeration type.");
}

}
#pragma endregion
