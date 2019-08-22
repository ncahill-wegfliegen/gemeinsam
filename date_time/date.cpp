#include "date.h"
#include "core.h"
#include "../enum/core/increment.h"
#include <sstream>
#include <chrono>
#include <iomanip>

using namespace std;

namespace // Helper methods
{
nhill::Date to_date( const nhill::SDate& dt )
{
   return { dt.uday, dt.umonth, dt.year };
}

nhill::SDate to_sdate( const nhill::Day & dy, nhill::Month mn, const nhill::Year & yr )
{
   return { static_cast<int>(dy), to_umonth( mn ), static_cast<int>(yr) };
}

nhill::SDate to_sdate( const nhill::Date& dt )
{
   return to_sdate( dt.day(), dt.month(), dt.year() );
}

}

const char* const nhill::Date::default_format{ "%Y-%b-%d" };
const locale nhill::Date::default_locale{ locale{""} };

nhill::Date::Date() = default;

nhill::Date::Date( int year, int umonth, int uday)
{
   validate_date( { uday, umonth, year } );

   yr_ = year;
   mn_ = umonth_to_month( umonth );
   dy_.value( uday, mn_, yr_ );
}

nhill::Date::Date( const Year& year, Month month, const Day& day )
{
   validate_date( to_sdate(day, month, year) );

   yr_ = year;
   mn_ = month;
   dy_.value( day.value(), mn_, yr_ );
}

nhill::Date::Date( double value )
{
   *this = value;
}

auto nhill::Date::operator=(double value)->Date &
{
   *this = to_date(double_to_date(value));
   return *this;
}

nhill::Date::Date(const Date & other) = default;
auto nhill::Date::operator=(const Date & other)->Date & = default;

nhill::Date::Date(Date && other) noexcept = default;
auto nhill::Date::operator=(Date && other) noexcept->Date & = default;

nhill::Date::~Date() = default;

nhill::Date::operator double() const
{
   return date_to_double( to_sdate(*this) );
}

const nhill::Year& nhill::Date::year() const
{
   return yr_;
}

const nhill::Month& nhill::Date::month() const
{
   return mn_;
}

const nhill::Day& nhill::Date::day() const
{
   return dy_;
}

void nhill::Date::clear()
{
   dy_.clear();
   nhill::clear( mn_ );
   yr_.clear();
}

auto nhill::operator++(Date& date)->Date &
{
   date = to_date(increment_date(to_sdate(date)));
   return date;
}

auto nhill::operator--(Date& date)->Date &
{
   date = to_date(decrement_date(to_sdate(date)));
   return date;
}

auto nhill::operator++(Date& date, int)->Date
{
   Date tmp{ date };
   ++date;
   return tmp;
}

auto nhill::operator--(Date& date, int)->Date
{
   Date tmp{ date };
   --date;
   return tmp;
}

tm nhill::to_tm(const Date & date)
{
   tm tm{};

   tm.tm_year = static_cast<int>(date.year()) - 1900;
   tm.tm_mon = nhill::to_zmonth(date.month());
   tm.tm_mday = date.day().value();

   return tm;
}

auto nhill::current_date()->Date
{
   // https://stackoverflow.com/questions/17223096/outputting-date-and-time-in-c-using-stdchrono?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa

   auto now{chrono::system_clock::now()};
   time_t tt{chrono::system_clock::to_time_t( now )};
   struct tm tm{};

   errno_t err{::localtime_s( &tm, &tt )};
   if (err != 0)
   {
      throw exception("Cannot get the current date.");
   }

   return { tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900 };
}

string nhill::to_string(const Date& date, const string & format /*= SL( "%Y-%b-%d" )*/, const locale& locale /*= std::locale( "" )*/)
{
   tm tm{ to_tm(date) };
   ostringstream oss;

   (void)oss.imbue(locale);
   oss << put_time(&tm, format.c_str());

   return oss.str();
}

string nhill::to_string(const Date& date, const locale & locale /*= default_locale*/)
{
   // https://stackoverflow.com/questions/34750954/how-do-i-get-the-current-localized-pattern-for-the-date-and-time-of-an-stdlo?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa
   tm tm{ to_tm(date) };
   ostringstream ss;

   (void)ss.imbue(locale); //set locale of the stream
   ss << put_time(&tm, "x");
   
   return ss.str();
}

template<> inline
auto nhill::compare( const Date& dt1, const Date& dt2 ) noexcept->Compare
{
   Compare cmp = compare<Year>( dt1.year(), dt2.year() );

   if( cmp == Compare::equal )
   {
      cmp = compare<Month>( dt1.month(), dt2.month() );

      if( cmp == Compare::equal )
      {
         cmp = compare<Day>( dt1.day(), dt2.day() );
      }
   }

   return cmp;
}

bool nhill::operator==( const Date & dt1, const Date & dt2 )
{
   return compare<const Date&>( dt1, dt2 ) == Compare::equal;
}

bool nhill::operator!=( const Date & dt1, const Date & dt2 )
{
   return !(dt1 == dt2);
}

bool nhill::operator<( const Date & dt1, const Date & dt2 )
{
   return compare<const Date&>( dt1, dt2 ) == Compare::less;
}

bool nhill::operator<=( const Date & dt1, const Date & dt2 )
{
   return (dt1 < dt2) || (dt1 == dt2);
}

bool nhill::operator>( const Date & dt1, const Date & dt2 )
{
   return compare<const Date&>( dt1, dt2 ) == Compare::greater;
}

bool nhill::operator>=( const Date & dt1, const Date & dt2 )
{
   return (dt1 > dt2) || (dt1 == dt2);
}
