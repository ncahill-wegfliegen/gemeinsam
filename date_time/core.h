#pragma once

#include "port.h"
#include <string>

namespace nhill
{

#pragma region Day
NHILL_DATETIME_PORT_FUNCTION bool is_valid_uday( int uday ) noexcept;
NHILL_DATETIME_PORT_FUNCTION bool is_valid_uday( int uday, int umonth, bool leap_year = false ) noexcept;
NHILL_DATETIME_PORT_FUNCTION bool is_valid_uday_of_year( int uday_of_year, bool leap_year = false ) noexcept;

NHILL_DATETIME_PORT_FUNCTION bool is_valid_zday( int zday ) noexcept;
NHILL_DATETIME_PORT_FUNCTION bool is_valid_zday( int zday, int umonth, bool leap_year = false ) noexcept;
NHILL_DATETIME_PORT_FUNCTION bool is_valid_zday_of_year( int zday_of_year, bool leap_year = false ) noexcept;

NHILL_DATETIME_PORT_FUNCTION void validate_uday( int uday, int umonth, bool leap_year = false );
NHILL_DATETIME_PORT_FUNCTION void validate_zday( int zday, int umonth, bool leap_year = false );

NHILL_DATETIME_PORT_FUNCTION int restrict_uday( int uday ) noexcept;
NHILL_DATETIME_PORT_FUNCTION int restrict_uday( int uday, int umonth, bool leap_year = false ) noexcept;

NHILL_DATETIME_PORT_FUNCTION int restrict_zday( int zday ) noexcept;
NHILL_DATETIME_PORT_FUNCTION int restrict_zday( int zday, int umonth, bool leap_year = false ) noexcept;

NHILL_DATETIME_PORT_FUNCTION int days_in_month( int umonth, bool leap_year = false ) noexcept;
NHILL_DATETIME_PORT_FUNCTION int days_in_year( bool leap_year = false ) noexcept;

NHILL_DATETIME_PORT_FUNCTION int uday_of_year( int uday_of_month, int umonth, bool leap_year = false );
NHILL_DATETIME_PORT_FUNCTION int zday_of_year( int uday_of_month, int umonth, bool leap_year = false );

NHILL_DATETIME_PORT_FUNCTION void uday_of_year_to_date( int uday_of_year, int& uday_of_month, int& umonth, bool leap_year = false );
NHILL_DATETIME_PORT_FUNCTION void zday_of_year_to_date( int zday_of_year, int& uday_of_month, int& umonth, bool leap_year = false );

NHILL_DATETIME_PORT_FUNCTION void validate_uday_of_year( int uday_of_year, bool leap_year = false );
NHILL_DATETIME_PORT_FUNCTION void validate_zday_of_year( int zday_of_year, bool leap_year = false );

NHILL_DATETIME_PORT_FUNCTION int current_uday();
NHILL_DATETIME_PORT_FUNCTION int current_zday();

NHILL_DATETIME_PORT_FUNCTION int increment_uday( int uday, int umonth, bool leap_year = false );
NHILL_DATETIME_PORT_FUNCTION int increment_zday( int zday, int umonth, bool leap_year = false );

NHILL_DATETIME_PORT_FUNCTION int decrement_uday( int uday, int umonth, bool leap_year = false );
NHILL_DATETIME_PORT_FUNCTION int decrement_zday( int zday, int umonth, bool leap_year = false );
#pragma endregion

#pragma region Month
NHILL_DATETIME_PORT_PARAMETER extern const int zmonth_min;
NHILL_DATETIME_PORT_PARAMETER extern const int zmonth_max;

NHILL_DATETIME_PORT_PARAMETER extern const int umonth_min;
NHILL_DATETIME_PORT_PARAMETER extern const int umonth_max;

NHILL_DATETIME_PORT_FUNCTION bool is_valid_zmonth( int zmonth ) noexcept;
NHILL_DATETIME_PORT_FUNCTION bool is_valid_umonth( int umonth ) noexcept;

NHILL_DATETIME_PORT_FUNCTION void validate_umonth( int umonth );
NHILL_DATETIME_PORT_FUNCTION void validate_zmonth( int umonth );

NHILL_DATETIME_PORT_FUNCTION int restrict_umonth( int umonth ) noexcept;
NHILL_DATETIME_PORT_FUNCTION int restrict_zmonth( int zmonth ) noexcept;

NHILL_DATETIME_PORT_FUNCTION int current_umonth();
NHILL_DATETIME_PORT_FUNCTION int current_zmonth();

NHILL_DATETIME_PORT_FUNCTION int increment_umonth( int umonth );
#pragma endregion

#pragma region Year
NHILL_DATETIME_PORT_FUNCTION int current_iyear();
NHILL_DATETIME_PORT_FUNCTION bool is_leap_year( int year ) noexcept;
#pragma endregion

#pragma region Date
struct SDate
{
   int uday;   // [1,28-31] depends on month and (leap) year
   int umonth; // [1,12]
   int year;   // no restriction
};

NHILL_DATETIME_PORT_FUNCTION bool is_valid_date( const SDate& dt ) noexcept;
NHILL_DATETIME_PORT_FUNCTION void validate_date( const SDate& dt );

NHILL_DATETIME_PORT_FUNCTION double date_to_double( const SDate& dt );

NHILL_DATETIME_PORT_FUNCTION SDate double_to_date( double value );

NHILL_DATETIME_PORT_CLASS SDate increment_date( const SDate& dt );
NHILL_DATETIME_PORT_CLASS SDate decrement_date( const SDate& dt );
#pragma endregion

#pragma region Second
NHILL_DATETIME_PORT_FUNCTION bool is_valid_second( int ss ) noexcept;
NHILL_DATETIME_PORT_FUNCTION void validate_second( int ss );

NHILL_DATETIME_PORT_FUNCTION int increment_second( int ss );
NHILL_DATETIME_PORT_FUNCTION int decrement_second( int ss );

NHILL_DATETIME_PORT_FUNCTION int adjust_second(int sec, int* min = nullptr, int* hr = nullptr);

NHILL_DATETIME_PORT_FUNCTION int current_second();
#pragma endregion

#pragma region Minute
NHILL_DATETIME_PORT_FUNCTION bool is_valid_minute( int mm ) noexcept;
NHILL_DATETIME_PORT_FUNCTION void validate_minute( int mm );

NHILL_DATETIME_PORT_FUNCTION int increment_minute( int mm );
NHILL_DATETIME_PORT_FUNCTION int decrement_minute( int mm );

NHILL_DATETIME_PORT_FUNCTION int adjust_minute(int min, int* hr = nullptr);

NHILL_DATETIME_PORT_FUNCTION int current_minute();
#pragma endregion

#pragma region Hour
NHILL_DATETIME_PORT_FUNCTION bool is_valid_hour( int hh ) noexcept;
NHILL_DATETIME_PORT_FUNCTION void validate_hour( int hh );

NHILL_DATETIME_PORT_FUNCTION int increment_hour( int hh );
NHILL_DATETIME_PORT_FUNCTION int decrement_hour( int hh );

NHILL_DATETIME_PORT_FUNCTION int adjust_hour(int hr);

NHILL_DATETIME_PORT_FUNCTION int current_hour();
#pragma endregion

#pragma region Time
struct STime 
{
   int hr;
   int min;
   int sec;
};

NHILL_DATETIME_PORT_FUNCTION void clear(STime& tm) noexcept;
NHILL_DATETIME_PORT_FUNCTION bool is_valid(const STime& tm) noexcept;
NHILL_DATETIME_PORT_FUNCTION void validate(const STime& tm);

NHILL_DATETIME_PORT_FUNCTION bool convert(double& dst, const STime& src);
NHILL_DATETIME_PORT_FUNCTION bool convert(STime& dst, double src);

NHILL_DATETIME_PORT_FUNCTION bool convert(std::tm& dst, const STime& src);
NHILL_DATETIME_PORT_FUNCTION bool convert(STime& dst, const std::tm& src);

NHILL_DATETIME_PORT_FUNCTION bool convert(std::string& dst, const STime& src);
NHILL_DATETIME_PORT_FUNCTION bool convert(std::string& dst, const std::string& fmt, const STime& src);
NHILL_DATETIME_PORT_FUNCTION bool convert(std::string& dst, const std::locale& loc, const STime& src);
NHILL_DATETIME_PORT_FUNCTION bool convert(std::string& dst, const std::string& fmt, const std::locale& loc, const STime& src);

NHILL_DATETIME_PORT_FUNCTION bool convert(STime& dst, const std::string& src);
NHILL_DATETIME_PORT_FUNCTION bool convert(STime& dst, const std::string& fmt, const std::string& src);
NHILL_DATETIME_PORT_FUNCTION bool convert(STime& dst, const std::locale & loc, const std::string& src);
NHILL_DATETIME_PORT_FUNCTION bool convert(STime& dst, const std::string& fmt, const std::locale& loc, const std::string& src);

NHILL_DATETIME_PORT_FUNCTION STime& adjust(STime& tm);
NHILL_DATETIME_PORT_FUNCTION STime adjust_copy(STime tm);

NHILL_DATETIME_PORT_FUNCTION STime current_time();

NHILL_DATETIME_PORT_FUNCTION STime& operator++(STime& tm); // pre-increment by seconds: ++tm
NHILL_DATETIME_PORT_FUNCTION STime& operator--(STime& tm); // pre-decrement by seconds: --tm

NHILL_DATETIME_PORT_FUNCTION STime operator++(STime& tm, int); // post-increment by seconds: tm++
NHILL_DATETIME_PORT_FUNCTION STime operator--(STime& tm, int); // post-decrement by seconds: tm--
#pragma endregion

}

