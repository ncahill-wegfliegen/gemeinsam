#include "core.h"
#include <algorithm>
#include <chrono>
#include <ctime>
#include <stdexcept>
#include <sstream>
#include <iomanip>
#include <gsl/gsl_assert>

using namespace std;

namespace
{
const int zday_min{ 0 };
const int zday_max{ 30 };

const int uday_min{ 1 };
const int uday_max{ 31 };

const char* const default_stime_format{ "%H:%M:%S" };
const locale default_stime_locale{ locale{""} };

}




#pragma region Day

bool nhill::is_valid_uday( int uday ) noexcept
{
   return (uday_min <= uday && uday <= uday_max);
}

bool nhill::is_valid_uday( int uday, int umonth, bool leap_year ) noexcept
{
   return (1 <= uday) && (uday <= days_in_month( umonth, leap_year ));
}

bool nhill::is_valid_uday_of_year( int uday_of_year, bool leap_year ) noexcept
{
   return (1 <= uday_of_year) && (uday_of_year <= nhill::days_in_year( leap_year ));
}

bool nhill::is_valid_zday( int zday ) noexcept
{
   return (zday_min <= zday && zday <= zday_max);
}

bool nhill::is_valid_zday( int zday, int umonth, bool leap_year ) noexcept
{
   return is_valid_uday( zday + 1, umonth, leap_year );
}

bool nhill::is_valid_zday_of_year( int zday_of_year, bool leap_year ) noexcept
{
   return is_valid_uday_of_year( zday_of_year + 1, leap_year );
}

void nhill::validate_uday( int uday, int umonth, bool leap_year )
{
   validate_umonth( umonth );

   if( !nhill::is_valid_uday( uday, umonth, leap_year ) )
   {
      ostringstream msg;
      msg << "The unit-based day " << uday << " is out of range ";
      msg << "[1," << nhill::days_in_month( umonth, leap_year ) << "].";
      msg << " The unit-based month is " << umonth;
      msg << " and the year is ";
      if( !leap_year )
      {
         msg << "not ";
      }
      msg << "a leap year.";

      throw out_of_range( msg.str().c_str() );
   }
}

void nhill::validate_zday( int zday, int umonth, bool leap_year )
{
   validate_umonth( umonth );

   if( !nhill::is_valid_zday( zday, umonth, leap_year ) )
   {
      ostringstream msg;
      msg << "The zero-based day " << zday << " is out of range ";
      msg << "[0," << nhill::days_in_month( umonth, leap_year ) - 1 << "].";
      msg << " The unit-based month is " << umonth;
      msg << " and the year is ";
      if( !leap_year )
      {
         msg << "not ";
      }
      msg << "a leap year.";

      throw out_of_range( msg.str().c_str() );
   }
}

int nhill::restrict_uday( int uday ) noexcept
{
   return (max)(uday_min, (min)(uday, uday_max));
}

int nhill::restrict_uday( int uday, int umonth, bool leap_year /*= false*/ ) noexcept
{
   validate_umonth( umonth );
   int dys_in_mn = nhill::days_in_month( umonth, leap_year );
   return (max)(1, (min)(uday, dys_in_mn));
}

int nhill::restrict_zday( int zday ) noexcept
{
   return (max)(zday_min, (min)(zday, zday_max));
}

int nhill::restrict_zday( int zday, int umonth, bool leap_year /*= false*/ ) noexcept
{
   return restrict_uday( zday + 1, umonth, leap_year ) - 1;
}

int nhill::days_in_month( int umonth, bool leap_year ) noexcept
{
   switch( umonth )
   {
   case /*jan*/  1: return 31;
   case /*feb*/  2: return (leap_year ? 29 : 28);
   case /*mar*/  3: return 31;
   case /*apr*/  4: return 30;
   case /*may*/  5: return 31;
   case /*jun*/  6: return 30;
   case /*jul*/  7: return 31;
   case /*aug*/  8: return 31;
   case /*sep*/  9: return 30;
   case /*oct*/ 10: return 31;
   case /*nov*/ 11: return 30;
   case /*dec*/ 12: return 31;
   default: return -1;
   }
}

int nhill::days_in_year( bool leap_year ) noexcept
{
   return leap_year ? 366 : 365;
}

int nhill::uday_of_year( int uday_of_month, int umonth, bool leap_year )
{
   validate_uday( uday_of_month, umonth, leap_year );

   int udy_of_yr = 0;

   for( int umonth_cur = 1 ; umonth_cur <= 12 ; ++umonth_cur )
   {
      if( umonth_cur == umonth )
      {
         break;
      }

      udy_of_yr += nhill::days_in_month( umonth_cur, leap_year );
   }

   udy_of_yr += uday_of_month;

   return udy_of_yr;
}

int nhill::zday_of_year( int uday, int umonth, bool leap_year )
{
   return uday_of_year( uday, umonth, leap_year ) - 1;
}

void nhill::uday_of_year_to_date( int uday_of_year, int & uday_of_month, int & umonth, bool leap_year )
{
   validate_uday_of_year( uday_of_year, leap_year );

   uday_of_month = uday_of_year;

   for( int umonth_cur = 1 ; umonth_cur <= 12 ; ++umonth_cur )
   {
      int dys_in_mn = nhill::days_in_month( umonth_cur, leap_year );
      if( uday_of_month <= dys_in_mn )
      {
         umonth = umonth_cur;
         break;
      }
      else
      {
         uday_of_month -= dys_in_mn;
      }
   }
}

void nhill::zday_of_year_to_date( int zday_of_year, int & uday_of_month, int & umonth, bool leap_year )
{
   uday_of_year_to_date( zday_of_year + 1, uday_of_month, umonth, leap_year );
}

void nhill::validate_uday_of_year( int uday_of_year, bool leap_year )
{
   if( !is_valid_uday_of_year( uday_of_year, leap_year ) )
   {
      ostringstream msg;
      msg << "The unit-based day of the year " << uday_of_year;
      msg << " is out of range [1," << days_in_year( leap_year ) << "].";
      msg << " The year is ";
      if( !leap_year )
      {
         msg << "not ";
      }
      msg << "a leap year.";
   }
}

void nhill::validate_zday_of_year( int zday_of_year, bool leap_year )
{
   if( !is_valid_zday_of_year( zday_of_year, leap_year ) )
   {
      ostringstream msg;
      msg << "The zero-based day of the year " << zday_of_year;
      msg << " is out of range [0," << days_in_year( leap_year ) - 1 << "].";
      msg << " The year is ";
      if( !leap_year )
      {
         msg << "not ";
      }
      msg << "a leap year.";
   }
}

int nhill::current_uday()
{
	auto now{chrono::system_clock::now()};
	time_t tt{chrono::system_clock::to_time_t( now )};
	struct tm today{};

	errno_t err{::localtime_s( &today, &tt )};
   if( err != 0 )
   {
      throw exception( "Cannot get the current day." );
   }

   return today.tm_mday;
}

int nhill::current_zday()
{
   return current_uday() - 1;
}

int nhill::increment_uday( int uday, int umonth, bool leap_year )
{
   validate_uday( uday, umonth, leap_year );

   if( uday == days_in_month( umonth, leap_year ) ) // The current day is the last day of the current month
   {
      // The next day is the first day of the next month
      uday = 1;
   }
   {
      ++uday;
   }

   return uday;
}

int nhill::increment_zday( int zday, int umonth, bool leap_year )
{
   return increment_uday( zday + 1, umonth, leap_year) - 1;
}

int nhill::decrement_uday( int uday, int umonth, bool leap_year )
{
   validate_uday( uday, umonth, leap_year );

   if( uday == 1 ) // The current day is the first of the current month
   {
      // The next day is the last day of the previous month
      if( umonth == 1 ) // The current month is January
      {
         uday = 31; // The previous day is the last day of December in the previous year
      }
      else
      {
         --umonth; // The previous month of the current year
         uday = days_in_month( umonth, leap_year );
      }
   }
   else
   {
      --uday;
   }

   return uday;
}

int nhill::decrement_zday( int zday, int umonth, bool leap_year )
{
   return decrement_uday( zday + 1, umonth, leap_year ) - 1;
}
#pragma endregion

#pragma region Month

NHILL_DATETIME_PORT_PARAMETER const int nhill::zmonth_min{ 0 };
NHILL_DATETIME_PORT_PARAMETER const int nhill::zmonth_max{ 11 };

NHILL_DATETIME_PORT_PARAMETER const int nhill::umonth_min{ 1 };
NHILL_DATETIME_PORT_PARAMETER const int nhill::umonth_max{ 12 };

bool nhill::is_valid_zmonth( int zmonth ) noexcept
{
   return (zmonth_min <= zmonth && zmonth <= zmonth_max);
}

bool nhill::is_valid_umonth( int umonth ) noexcept
{
   return (umonth_min <= umonth && umonth <= umonth_max);
}

void nhill::validate_umonth( int umonth )
{
   if( !is_valid_umonth( umonth ) )
   {
      ostringstream msg;
      msg << "The unit-based month " << umonth << " is out of range [1,12].";

      throw out_of_range( msg.str().c_str() );
   }
}

void nhill::validate_zmonth( int zmonth )
{
   if( !is_valid_zmonth( zmonth ) )
   {
      ostringstream msg;
      msg << "The zero-based month " << zmonth << " is out of range [0,11].";

      throw out_of_range( msg.str().c_str() );
   }
}

int nhill::restrict_umonth( int umonth ) noexcept
{
   return (max)(umonth_min, (min)(umonth, umonth_max));
}

int nhill::restrict_zmonth( int zmonth ) noexcept
{
   return (max)(zmonth_min, (min)(zmonth, zmonth_max));
}

int nhill::current_umonth()
{
   auto now = chrono::system_clock::now();
   time_t tt = chrono::system_clock::to_time_t( now );
	struct tm today{};

	errno_t err{::localtime_s( &today, &tt )};
   if( err != 0 )
   {
      throw exception( "Cannot get the current month." );
   }

   return today.tm_mon + 1;
}

int nhill::current_zmonth()
{
   return current_umonth() - 1;
}

int nhill::increment_umonth( int umonth )
{
   validate_umonth( umonth );
   return( umonth == umonth_max ) ? umonth_min : ++umonth;
}

#pragma endregion


#pragma region Year
int nhill::current_iyear()
{
	auto now{chrono::system_clock::now()};
	time_t tt{chrono::system_clock::to_time_t( now )};
	struct tm today{};

	errno_t err{::localtime_s( &today, &tt )};
   if( err != 0 )
   {
      throw exception( "Cannot get the current year." );
   }

   return today.tm_year + 1900;
}

bool nhill::is_leap_year( int yr ) noexcept
{
   return (yr % 4) || ((yr % 100 == 0) && (yr % 400)) ? false : true;
}
#pragma endregion


#pragma region Date
bool nhill::is_valid_date( const SDate & dt ) noexcept
{
   return is_valid_uday( dt.uday, dt.umonth, is_leap_year( dt.year ) );
}

void nhill::validate_date( const SDate & dt )
{
   validate_umonth( dt.umonth );

   bool leap_year = is_leap_year( dt.year );

   if( !nhill::is_valid_uday( dt.uday, dt.umonth, leap_year ) )
   {
      ostringstream msg;
      msg << "The unit-based day " << dt.uday << " is out of range ";
      msg << "[1," << nhill::days_in_month( dt.umonth, leap_year ) << "].";
      msg << " The unit-based month is " << dt.umonth;
      msg << " and the year " << dt.year << " is ";
      if( !leap_year )
      {
         msg << "not ";
      }
      msg << "a leap year.";

      throw out_of_range( msg.str().c_str() );
   }
}

double nhill::date_to_double( const SDate& dt )
{
   validate_date( dt );

   bool leap_year = is_leap_year( dt.year );

   double dys_in_yr = days_in_year( leap_year );
   double zdy_of_yr = zday_of_year( dt.uday, dt.umonth, leap_year );

   double fraction = zdy_of_yr / dys_in_yr;

   double value = dt.year + fraction;
   return value;
}

auto nhill::double_to_date( double value )->SDate
{
   int uday = 1;
   int umonth = 1;
   int year = static_cast<int>(value);
   bool leap_year = is_leap_year( year );

   double fraction = value - year; // fractional part of the value
   double dys_in_yr = days_in_year( leap_year );
   double dd = fraction * dys_in_yr;
   int zdy_of_yr = static_cast<int>(round( dd ));

   zday_of_year_to_date( zdy_of_yr, uday, umonth, leap_year );

   SDate dt{ uday, umonth, year };
   validate_date( dt );
   return dt;
}

auto nhill::increment_date( const SDate& dt )->SDate
{
   validate_date( dt );

   int uday = dt.uday;
   int umonth = dt.umonth;
   int year = dt.year;

   if( uday == days_in_month( umonth, is_leap_year( year ) ) ) // The current day is the last day of the current month
   {
      uday = 1; // The next day is the first day of the next month
      if( umonth == 12 )   // The current month is December of this year
      {
         umonth = 1; // The next month is January
         ++year;     // of the next year
      }
      else
      {
         ++umonth;
      }
   }
   else
   {
      ++uday;
   }

   return { uday, umonth, year };
}

auto nhill::decrement_date( const SDate& dt )->SDate
{
   validate_date( dt );

   int uday = dt.uday;
   int umonth = dt.umonth;
   int year = dt.year;

   if( uday == 1 ) // The current day is the first day of the current month
   {
      // The previous day is the last day of the previous month
      if( umonth == 1 ) // The current month is January of this year
      {
         umonth = 12;  // The previous month is December
         --year;       // of the previous year
      }
      else
      {
         --umonth;
      }
      uday = days_in_month( umonth, is_leap_year( year ) );
   }
   else
   {
      --uday;
   }

   return { uday, umonth, year };
}
#pragma endregion

#pragma region Second
bool nhill::is_valid_second( int ss ) noexcept
{
   return (0 <= ss) && (ss < 60);
}

void nhill::validate_second( int ss )
{
   if( !is_valid_second( ss ) )
   {
      ostringstream msg;
      msg << "The second " << ss << " is out of range [0,59].";
      throw out_of_range( msg.str().c_str() );
   }
}

int nhill::increment_second( int ss )
{
   validate_second( ss );
   return ( ss == 59 ) ? 0 : ++ss;
}

int nhill::decrement_second( int ss )
{
   validate_second( ss );
   return (ss == 0) ? 59 : --ss;
}

int nhill::adjust_second(int sec, int* min /*= nullptr*/, int* hr /*= nullptr*/)
{
   if ( (sec < 0 ) || (59 < sec) )
   {
      // Adjust the minute (if required)
      if (min != nullptr)
      {
         *min += (sec / 60);
         *min = adjust_minute(*min, hr);

         // Adjust the hour (if required)
         if (hr != nullptr)
         {
            *hr = adjust_hour(*hr);
         }
      }

      // The value will be in the interval [0,60).
      sec = sec % 60;
   }

   Ensures( (0 <= sec) && (sec <= 59) );

   return sec;
}

int nhill::current_second()
{
   auto now{ chrono::system_clock::now() };
   auto tt{ chrono::system_clock::to_time_t(now) };
	struct tm today{};
	
	errno_t err{::localtime_s( &today, &tt )};
	if( err != 0 )
	{
		throw exception( "Cannot get the current second." );
	}

   return today.tm_sec;
}
#pragma endregion

#pragma region Minute
bool nhill::is_valid_minute( int mm ) noexcept
{
   return (0 <= mm) && (mm < 60);
}

void nhill::validate_minute( int mm )
{
   if( !is_valid_minute( mm ) )
   {
      ostringstream msg;
      msg << "The minute " << mm << " is out of range [0,59].";
      throw out_of_range( msg.str().c_str() );
   }
}

int nhill::increment_minute( int mm )
{
   validate_minute( mm );
   return (mm == 59) ? 0 : ++mm;
}

int nhill::decrement_minute( int mm )
{
   validate_minute( mm );
   return (mm == 0) ? 59 : --mm;
}

int nhill::adjust_minute(int min, int* hr /*= nullptr*/)
{
   if ( (min < 0) || (59 < min) )
   {
      // Set the hour (if required)
      if (hr != nullptr)
      {
         *hr += (min / 60);
         *hr = adjust_hour(*hr);
      }

      // The value will be in the interval [0,60).
      min = min % 60;
   }

   Ensures( (0 <= min) && (min <= 59) );

   return min;
}

int nhill::current_minute()
{
   auto now{ chrono::system_clock::now() };
   auto tt{ chrono::system_clock::to_time_t(now) };
   struct tm today{};

	errno_t err{::localtime_s( &today, &tt )};
	if( err != 0 )
	{
		throw exception( "Cannot get the current minute." );
	}

   return today.tm_min;
}
#pragma endregion

#pragma region Hour
bool nhill::is_valid_hour( int hh ) noexcept
{
   return (0 <= hh) && (hh < 24);
}

void nhill::validate_hour( int hh )
{
   if( !is_valid_hour( hh ) )
   {
      ostringstream msg;
      msg << "The hour " << hh << " is out of range [0,23].";
      throw out_of_range( msg.str().c_str() );
   }
}

int nhill::increment_hour( int hh )
{
   validate_hour( hh );
   return (hh == 23) ? 0 : ++hh;
}

int nhill::decrement_hour( int hh )
{
   validate_hour( hh );
   return (hh == 0) ? 23 : --hh;
}

int nhill::adjust_hour(int hr)
{
   if ( (hr < 0) || (23 < hr) )
   {
      hr = (hr % 23);
   }

   Ensures( (0 <= hr) && (hr <= 23) );

   return hr;
}

int nhill::current_hour()
{
   auto now{ chrono::system_clock::now() };
   auto tt { chrono::system_clock::to_time_t(now) };
   struct tm today{};

	errno_t err{::localtime_s( &today, &tt )};
	if( err != 0 )
	{
		throw exception( "Cannot get the current hour." );
	}

   return today.tm_hour;
}
#pragma endregion

#pragma region Time
void nhill::clear(STime & tm) noexcept
{
   tm.hr = 0;
   tm.min = 0;
   tm.sec = 0;
}

bool nhill::is_valid(const STime & tm) noexcept
{
   return is_valid_second(tm.sec) && is_valid_minute(tm.min) && is_valid_hour(tm.hr);
}

void nhill::validate(const STime & tm)
{
   validate_second(tm.sec);
   validate_minute(tm.min);
   validate_hour  (tm.hr );
}

bool nhill::convert(double & dst, const STime & src)
{
   dst = src.hr;
   dst += static_cast<double>(src.min) / 60;
   dst += static_cast<double>(src.sec) / 3600;
   
   return true;
}

bool nhill::convert(STime & dst, double src)
{
   dst.hr = static_cast<int>(src);
   
   double min{ src - dst.hr };
   min *= 60;
   dst.min = static_cast<int>(min);
   
   double sec{ min - dst.min };
   sec *= 60;
   dst.sec = static_cast<int>(sec);

   bool success{ is_valid(dst) };
   if (!success) 
   {
      clear(dst);
   }
   
   return success;
}

bool nhill::convert(tm & dst, const STime & src)
{
   ::memset(&dst, 0, sizeof tm);

   dst.tm_hour = src.hr;
   dst.tm_min = src.min;
   dst.tm_sec = src.sec;

   return true;
}

bool nhill::convert(STime & dst, const tm & src)
{
   dst.hr = src.tm_hour;
   dst.min = src.tm_min;
   dst.sec = src.tm_sec;

   return true;
}

bool nhill::convert(string & dst, const STime & src)
{
   return convert(dst, default_stime_format, default_stime_locale, src);
}

bool nhill::convert(string & dst, const string & fmt, const STime & src)
{
   return convert(dst, fmt, default_stime_locale, src);
}

bool nhill::convert(string & dst, const locale & loc, const STime & src)
{
   return convert(dst, default_stime_format, loc, src);
}

bool nhill::convert(string & dst, const string & fmt, const locale & loc, const STime & src)
{
   tm tm{};
   if (!convert(tm, src))
   {
      return false;
   }

   ostringstream ss;

   ss.imbue(loc);
   ss << put_time(&tm, fmt.c_str());

   dst = ss.str();

   return true;
}

bool nhill::convert(STime & dst, const string & src)
{
   return convert(dst, default_stime_format, default_stime_locale, src);
}

bool nhill::convert(STime & dst, const string & fmt, const string & src)
{
   return convert(dst, fmt, default_stime_locale, src);
}

bool nhill::convert(STime & dst, const locale & loc, const string & src)
{
   return convert(dst, default_stime_format, loc, src);
}

bool nhill::convert(STime & dst, const string & fmt, const locale & loc, const string & src)
{
   tm tm{};
   istringstream ss{ src };

   ss.imbue(loc);
   ss >> get_time(&tm, fmt.c_str());

   if (ss.fail())
   {
      return false;
   }

   return convert(dst, tm);
}


auto nhill::adjust(STime & tm)->STime &
{
   if (!is_valid(tm))
   {
      adjust_second(tm.sec, &tm.min, &tm.hr);
   }
   return tm;
}

auto nhill::adjust_copy(STime tm)->STime
{
   adjust(tm);
   return tm;
}

auto nhill::current_time()->STime
{
   auto now{ chrono::system_clock::now() };
   auto tt{ chrono::system_clock::to_time_t(now) };
   struct tm today{};

	errno_t err{::localtime_s( &today, &tt )};
	if( err != 0 )
	{
		throw exception( "Cannot get current time." );
	}

   return { today.tm_hour, today.tm_min, today.tm_sec };
}

auto nhill::operator++(STime & tm)->STime &
{
   ++tm.sec;
   adjust_second(tm.sec, &tm.min, &tm.hr);
   return tm;
}

auto nhill::operator--(STime & tm)->STime &
{
   --tm.sec;
   adjust_second(tm.sec, &tm.min, &tm.hr);
   return tm;
}

auto nhill::operator++(STime & tm, int)->STime
{
   STime tmp{ tm };
   ++tm;
   return tmp;
}

auto nhill::operator--(STime & tm, int)->STime
{
   STime tmp{ tm };
   --tm;
   return tmp;
}
#pragma endregion