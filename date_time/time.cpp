#include "time.h"
#include "core.h"
#include <sstream>
#include "../utility/unique_ptr.h"
#include <iomanip>
#include <ctime>

using namespace std;

const nhill::Time nhill::Time::first{ Hour{ 0}, Minute{ 0}, Second{ 0} };
const nhill::Time nhill::Time::last { Hour{23}, Minute{59}, Second{59} };
const char* const nhill::Time::default_format{ "%H:%M:%S" };
const locale nhill::Time::default_locale{ locale{""} };


nhill::Time::Time()
   : stime_{std::make_unique<STime>()}
{}

nhill::Time::Time(const Hour & hr, const Minute & min, const Second & sec)
   : stime_{ new STime{hr.value(), min.value(), sec.value()} }
{
}

nhill::Time::Time(const Time & time)
   : Time( time.hour(), time.minute(), time.second())
{
}

auto nhill::Time::operator=(const Time & time)->Time &
{
   nhill::copy<STime>(stime_, time.stime_);
   return *this;
}

nhill::Time::Time(Time &&) = default;
auto nhill::Time::operator=(Time &&)->Time & = default;

nhill::Time::Time(const STime & stime)
   :stime_{std::make_unique<STime>(stime)}
{
   adjust(*stime_);
}

auto nhill::Time::operator=(const STime & stime)->Time &
{
   *stime_ = stime;
   adjust(*stime_);
   return *this;
}

nhill::Time::Time(STime && stime)
   : stime_{std::make_unique<STime>(stime)}
{
   adjust(*stime_);
}

auto nhill::Time::operator=(STime && stime)->Time &
{
   *stime_ = std::move(stime);
   adjust(*stime_);
   return *this;
}

nhill::Time::Time(const std::tm & tm)
   : stime_{std::make_unique<STime>(STime{tm.tm_hour, tm.tm_min, tm.tm_sec})}
{
   adjust(*stime_);
}

auto nhill::Time::operator=(const std::tm &tm)->Time &
{
   stime_->hr = tm.tm_hour;
   stime_->min = tm.tm_min;
   stime_->sec = tm.tm_sec;

   adjust(*stime_);
   
   return *this;
}

nhill::Time::Time(std::tm && tm)
   : stime_{ std::make_unique<STime>(STime{tm.tm_hour, tm.tm_min, tm.tm_sec}) }
{
   adjust(*stime_);
}

auto nhill::Time::operator=(std::tm && tm)->Time &
{
   stime_->hr = tm.tm_hour;
   stime_->min = tm.tm_min;
   stime_->sec = tm.tm_sec;

   adjust(*stime_);

   return *this;
}

nhill::Time::Time(const std::string &)
{
}

auto nhill::Time::operator=(const std::string & str)->Time &
{
   convert(*stime_, str);
   return *this;
}

nhill::Time::Time(std::string && str)
{
   convert(*stime_, str);
}

auto nhill::Time::operator=(std::string && str)->Time &
{
   convert(*stime_, str);
   return *this;
}

nhill::Time::~Time() = default;

auto nhill::Time::hour() const->Hour
{
   return Hour{ stime_->hr };
}

void nhill::Time::hour(const Hour & hr)
{
   stime_->hr = hr.value();
}

auto nhill::Time::minute() const->Minute
{
   return Minute{ stime_->min };
}

void nhill::Time::minute(const Minute & min)
{
   stime_->min = min.value();
}

auto nhill::Time::second() const->Second
{
   return Second{ stime_->sec };
}

void nhill::Time::second(const Second & sec)
{
   stime_->sec = sec.value();
}

auto nhill::Time::stime() const-> const STime&
{
   return *stime_;
}

std::tm nhill::Time::tm() const
{
   std::tm tm{};
   
   tm.tm_hour = stime_->hr;
   tm.tm_min = stime_->min;
   tm.tm_sec = stime_->sec;

   return tm;
}

void nhill::Time::value(int hr, int min, int sec)
{
   stime_->hr = hr;
   stime_->min = min;
   stime_->sec = sec;

   adjust(*stime_);
}

void nhill::Time::clear()
{
   nhill::clear(*stime_);
}

auto nhill::Time::current()->Time
{
   return{ current_time() };
}


auto nhill::Time::operator++()->Time &
{
   ++(*stime_);
   return *this;
}

auto nhill::Time::operator--()->Time &
{
   --(*stime_);
   return *this;
}

auto nhill::operator++(Time& time, int)->Time
{
   Time tmp{ time };
   ++time;
   return tmp;
}

auto nhill::operator--(Time& time, int)->Time
{
   Time tmp{ time};
   --time;
   return tmp;
}

template<>
auto nhill::compare( const Time& a, const Time& b ) noexcept->Compare
{
   Compare cmp = compare<Hour>( a.hour(), b.hour() );

   if( cmp == Compare::equal )
   {
      cmp = compare<Minute>( a.minute(), b.minute() );

      if( cmp == Compare::equal )
      {
         cmp = compare<Second>( a.second(), b.second() );
      }
   }

   return cmp;
}

bool nhill::operator==( const Time& a, const Time& b ) noexcept
{
   return compare<const Time&>( a, b ) == Compare::equal;
}

bool nhill::operator!=( const Time& a, const Time& b ) noexcept
{
   return !(a == b);
}

bool nhill::operator<( const Time& a, const Time& b ) noexcept
{
   return compare<const Time&>( a, b ) == Compare::less;
}

bool nhill::operator<=( const Time& a, const Time& b ) noexcept
{
   return (a < b) || (a == b);
}

bool nhill::operator>( const Time& a, const Time& b ) noexcept
{
   return compare<const Time&>( a, b ) == Compare::greater;
}

bool nhill::operator>=( const Time& a, const Time& b ) noexcept
{
   return (a > b) || (a == b);
}
