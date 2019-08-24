#pragma once

#include <type_traits>
#include <cstdint>
#include <iterator>

#pragma region float
namespace nhill
{
namespace enable_if
{

/// <summary>SFINAE condition: is 'floating point' (i.e., float, double, long double).</summary>
template<typename ftype>
using is_float_type = typename std::enable_if< std::is_floating_point< ftype >::value >::type;

/// <summary>SFINAE condition: the collection must have a constant iterator, whose 'value_type' is 'floating point' (i.e., float, double, long double).</summary>
template<class collection>
using is_collection_of_float_type = typename std::enable_if< std::is_floating_point<typename collection::const_iterator::value_type>::value >::type;

/// <summary>SFINAE condition: the constant iterator must have a 'value_type' of 'floating point' (i.e., float, double, long double).</summary>
template<class const_iterator>
using is_citr_of_float_type = typename std::enable_if< std::is_floating_point<typename const_iterator::value_type>::value >::type;


}
}
#pragma endregion

#pragma region integer
namespace nhill
{
namespace enable_if
{

/// <summary>SFINAE condition: is 'integral': bool, char, unsigned char, signed char, wchar_t, short, unsigned short, int, unsigned int, long, and unsigned long).
///   <para>In addition, with compilers that provide them, an integral type can be one of long long, unsigned long long, __int64, and unsigned __int64.</para>
/// </summary>
template<typename itype>
using is_int_type = typename std::enable_if< std::is_integral< itype >::value >::type;

/// <summary>SFINAE condition: the collection must have a constant iterator, whose 'value_type' is 'integral':
///   <para>bool, char, unsigned char, signed char, wchar_t, short, unsigned short, int, unsigned int, long, and unsigned long).</para>
///   <para>In addition, with compilers that provide them, an integral type can be one of long long, unsigned long long, __int64, and unsigned __int64.</para>
/// </summary>
template<class collection>
using is_collection_of_int_type = typename std::enable_if< std::is_integral<typename collection::const_iterator::value_type>::value >::type;

/// <summary>SFINAE condition: the constant iterator must have a 'value_type' of 'integral'
///   <para>bool, char, unsigned char, signed char, wchar_t, short, unsigned short, int, unsigned int, long, and unsigned long).</para>
///   <para>In addition, with compilers that provide them, an integral type can be one of long long, unsigned long long, __int64, and unsigned __int64.</para>
/// </summary>
template<class const_iterator>
using is_citr_of_int_type = typename std::enable_if< std::is_integral<typename const_iterator::value_type>::value >::type;

}
}
#pragma endregion

#pragma region arithemtic
namespace nhill
{
namespace enable_if
{

/// <summary>SFINAE condition: is 'arithmetic'; an integral type or a floating-point type.</summary>
template<typename atype>
using is_arithmetic_type = typename std::enable_if< std::is_arithmetic< atype >::value >::type;

/// <summary>SFINAE condition: is 'arithmetic'; an integral type or a floating-point type.</summary>
template<typename atype>
using is_not_arithmetic_type = typename std::enable_if_t< !std::is_arithmetic_v< atype >>;

}
}
#pragma endregion

#pragma region mathematical
namespace nhill
{
namespace enable_if
{

/// <summary>Signed interger mathematical types.</summary>
template<typename T> struct Is_math_sint : std::false_type{};
template<> struct Is_math_sint<int8_t >  : std::true_type {};
template<> struct Is_math_sint<int16_t>  : std::true_type {};
template<> struct Is_math_sint<int32_t>  : std::true_type {};
template<> struct Is_math_sint<int64_t>  : std::true_type {};
template<typename T> struct is_math_sint : Is_math_sint<std::remove_cv_t<T>>::type {};
template<typename mtype> using is_math_sint_type = typename std::enable_if< is_math_sint< mtype >::value >::type;

/// <summary>Unsigned interger mathematical types.</summary>
template<typename T> struct Is_math_uint : std::false_type{};
template<> struct Is_math_uint<uint8_t > : std::true_type {};
template<> struct Is_math_uint<uint16_t> : std::true_type {};
template<> struct Is_math_uint<uint32_t> : std::true_type {};
template<> struct Is_math_uint<uint64_t> : std::true_type {};
template<typename T> struct is_math_uint : Is_math_uint<std::remove_cv_t<T>>::type {};
template<typename mtype> using is_math_uint_type = typename std::enable_if< is_math_uint< mtype >::value >::type;

/// <summary>Signed and unsigned interger mathematical types.</summary>
template<typename T> struct Is_math_int : std::false_type{};
template<> struct Is_math_int<int8_t  > : std::true_type {};
template<> struct Is_math_int<int16_t > : std::true_type {};
template<> struct Is_math_int<int32_t > : std::true_type {};
template<> struct Is_math_int<int64_t > : std::true_type {};
template<> struct Is_math_int<uint8_t > : std::true_type {};
template<> struct Is_math_int<uint16_t> : std::true_type {};
template<> struct Is_math_int<uint32_t> : std::true_type {};
template<> struct Is_math_int<uint64_t> : std::true_type {};
template<typename T> struct is_math_int : Is_math_int<std::remove_cv_t<T>>::type {};
template<typename mtype> using is_math_int_type = typename std::enable_if< is_math_int< mtype >::value >::type;

/// <summary>Floating point mathematical types.</summary>
template<typename T> struct Is_math_fp    : std::false_type{};
template<> struct Is_math_fp<float      > : std::true_type {};
template<> struct Is_math_fp<double     > : std::true_type {};
template<> struct Is_math_fp<long double> : std::true_type {};
template<typename T> struct is_math_fp : Is_math_fp<std::remove_cv_t<T>>::type {};
template<typename mtype> using is_math_fp_type = typename std::enable_if< is_math_fp< mtype >::value >::type;

/// <summary>Floating point and (un)signed integer mathematical types.</summary>
template<typename T> struct Is_math    : std::false_type{};
template<> struct Is_math<int8_t     > : std::true_type {};
template<> struct Is_math<int16_t    > : std::true_type {};
template<> struct Is_math<int32_t    > : std::true_type {};
template<> struct Is_math<int64_t    > : std::true_type {};
template<> struct Is_math<uint8_t    > : std::true_type {};
template<> struct Is_math<uint16_t   > : std::true_type {};
template<> struct Is_math<uint32_t   > : std::true_type {};
template<> struct Is_math<uint64_t   > : std::true_type {};
template<> struct Is_math<float      > : std::true_type {};
template<> struct Is_math<double     > : std::true_type {};
template<> struct Is_math<long double> : std::true_type {};
template<typename T> struct is_math : Is_math<std::remove_cv_t<T>>::type {};

/// <summary>SFINAE condition: is 'math'; an integral type or a floating-point type.</summary>
template<typename mtype>
using is_math_type = typename std::enable_if< is_math< mtype >::value >::type;

template<typename mtype1, typename mtype2>
using are_2math_types = typename std::enable_if< is_math<mtype1>::value && is_math<mtype2>::value >::type;

template<typename mtype1, typename mtype2, typename mtype3>
using are_3math_types = typename std::enable_if< is_math<mtype1>::value && is_math<mtype2>::value && is_math<mtype3>::value >::type;

/// <summary>SFINAE condition: is 'not math'; neither a (un)signed integer type nor a floating-point type.</summary>
template<typename mtype>
using is_not_math_type = typename std::enable_if< !is_math< mtype >::value >::type;

template<typename mtype>
using is_math_signed_type = typename std::enable_if< is_math_sint<mtype>::value || is_math_fp<mtype>::value>::type;

template<typename mtype>
using is_math_unsigned_type = typename std::enable_if< is_math_uint<mtype>::value >::type;

}
}
#pragma endregion

#pragma region pnt collection
namespace nhill
{
namespace enable_if
{

/// <summary>SFINAE condition: the collection must have a constant iterator, whose 'value_type' is 'pnt'.</summary>
template<class pntcollection, class pnt>
using is_collection_of_pnt_type = typename std::enable_if< std::is_same<typename pntcollection::const_iterator::value_type, pnt>::value>::type;

/// <summary>SFINAE condition: the constant iterator must have a value_type of pnt.</summary>
template<class const_iterator, class pnt>
using is_citr_of_pnt_type = typename std::enable_if< std::is_same<typename const_iterator::value_type, pnt>::value>::type;

/// <summary>SFINAE condition: the constant iterator must have a value_type of pnt.</summary>
template<class const_iterator, class pnt>
using is_citr_of_citr_of_pnt_type = typename std::enable_if< std::is_same<typename const_iterator::value_type::const_iterator::value_type, pnt>::value>::type;

}
}
#pragma endregion

#pragma region enumeration
namespace nhill
{
namespace enable_if
{

template<typename enum_type>
using is_enum_type = typename std::enable_if<std::is_enum<enum_type>::value>::type;

template<typename enum_type>
using is_not_enum_type = typename std::enable_if<!std::is_enum<enum_type>::value>::type;

}
}
#pragma endregion

#pragma region is base of
namespace nhill
{
namespace enable_if
{

/// <summary>SFINAE condition: is 'floating point' (i.e., float, double, long double).</summary>
template<typename Base, typename Derived>
using is_base_of_type = typename std::enable_if< std::is_base_of< Base, Derived >::value >::type;

}
}
#pragma endregion

#pragma region character
namespace nhill
{
namespace enable_if
{

template<typename T> struct Is_char : std::false_type {};
template<> struct Is_char<char >    : std::true_type {};
template<> struct Is_char<char16_t> : std::true_type {};
template<> struct Is_char<char32_t> : std::true_type {};
template<typename T> struct is_char : Is_char<std::remove_cv_t<T>>::type {};
template<typename T> using is_char_type = typename std::enable_if< is_char<T>::value >::type;


}
}
#pragma endregion




