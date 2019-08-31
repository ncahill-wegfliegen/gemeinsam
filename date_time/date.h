#pragma once

#include "port.h"
#include "year.h"
#include "month.h"
#include "day.h"
#include "../utility/compare.h"
#include "../utility/str.h"
#include <locale>
#include <ctime>

namespace nhill
{

class NHILL_DATETIME_PORT_CLASS Date
{
public:
   Date();
   Date( int year, int umonth, int uday = 1 );
   Date( const Year& year, Month month, const Day& day= Day{1} );
	
	Date( const struct tm& tm );
	Date& operator=( const struct tm& tm );

   explicit Date(double value);
   Date& operator=(double value);

   Date(const Date& other);
   Date& operator=(const Date& other);

   Date(Date&& other) noexcept;
   Date& operator=(Date&& other) noexcept;

   ~Date();

   explicit operator double() const;

   const Year & year () const;
   const Month& month() const;
   const Day  & day  () const;

   static const char* const default_format;
#pragma warning(suppress:4251)
   static const std::locale default_locale;  // The environment's default locale.

   void clear();

private:
   Day   dy_;
   Month mn_;
   Year  yr_;
};

}

namespace nhill
{

NHILL_DATETIME_PORT_FUNCTION Date& operator++(Date& date); //  pre-increment by day: ++date
NHILL_DATETIME_PORT_FUNCTION Date& operator--(Date& date); //  pre-decrement by day: --date

NHILL_DATETIME_PORT_FUNCTION Date operator++(Date& date, int); // post-increment by day: date++
NHILL_DATETIME_PORT_FUNCTION Date operator--(Date& date, int); // post-decrement by day: date--

NHILL_DATETIME_PORT_FUNCTION std::tm to_tm( const Date& date);
NHILL_DATETIME_PORT_FUNCTION Date current_date();

/// <summary>Format the date as a string.</summary>
/// <param name="fmt">The date format. </param>
/// <returns>The date formated as a string.</returns>
/// <remarks>See http://en.cppreference.com/w/cpp/io/manip/put_time for details on formatting.</remarks>
NHILL_DATETIME_PORT_FUNCTION  std::string to_string(const Date& date, const std::string& format, const std::locale& locale = Date::default_locale);

/// <summary>Format the date as a string according to the locale.</summary>
/// <param name="loc">The locale.</param>
/// <returns>The date formated as a string according to the locale.</returns>
NHILL_DATETIME_PORT_FUNCTION std::string to_string(const Date& date, const std::locale& locale = Date::default_locale);

template<> inline NHILL_DATETIME_PORT_FUNCTION  
Compare compare( const Date& dt1, const Date& dt2 ) noexcept;

NHILL_DATETIME_PORT_FUNCTION bool operator==( const Date& dt1, const Date& dt2 );
NHILL_DATETIME_PORT_FUNCTION bool operator!=( const Date& dt1, const Date& dt2 );
NHILL_DATETIME_PORT_FUNCTION bool operator< ( const Date& dt1, const Date& dt2 );
NHILL_DATETIME_PORT_FUNCTION bool operator<=( const Date& dt1, const Date& dt2 );
NHILL_DATETIME_PORT_FUNCTION bool operator> ( const Date& dt1, const Date& dt2 );
NHILL_DATETIME_PORT_FUNCTION bool operator>=( const Date& dt1, const Date& dt2 );

}