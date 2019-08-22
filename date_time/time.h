#pragma once

#include "port.h"
#include "hour.h"
#include "minute.h"
#include "second.h"
#include "../utility/compare.h"
#include <locale>
#include <memory>

// For format rules see:
// https://en.cppreference.com/w/cpp/io/manip/get_time

namespace nhill { struct STime; }

namespace nhill
{

class NHILL_DATETIME_PORT_CLASS Time
{
public:
   Time();
   Time(const Hour& hr, const Minute& min, const Second& sec);

   Time(const Time&);
   Time& operator=(const Time&);

   Time(Time&&);
   Time& operator=(Time&&);

   Time(const STime&);
   Time& operator=(const STime&);

   Time(STime&&);
   Time& operator=(STime&&);

   Time(const std::tm&);
   Time& operator=(const std::tm&);

   Time(std::tm&&);
   Time& operator=(std::tm&&);

   Time(const std::string&);
   Time& operator=(const std::string&);

   Time(std::string&&);
   Time& operator=(std::string&&);

   ~Time();

   Hour hour() const;
   void hour(const Hour&);

   Minute minute() const;
     void minute(const Minute&);

   Second second() const;
     void second(const Second&);

   const STime& stime() const;
   std::tm tm() const;

   void value(int hr, int min, int sec);

   static const Time first; // 0h 0m 0s
   static const Time last;  // 23h 59m 59s
   static const char* const default_format; // hh:mm::ss
#pragma warning(suppress:4251)
   static const std::locale default_locale;  // The environment's default locale.

   void clear();
   static Time current();

   Time& operator++(); // pre-increment by seconds: ++x
   Time& operator--(); // pre-decrement by seconds: --x

private:
#pragma warning(suppress:4251)
   std::unique_ptr<STime> stime_;
};

}

namespace nhill
{

NHILL_DATETIME_PORT_FUNCTION Time operator++(Time&, int); // post-increment by seconds: x++
NHILL_DATETIME_PORT_FUNCTION Time operator--(Time&, int); // post-decrement by seconds: x--

template<> NHILL_DATETIME_PORT_FUNCTION
Compare compare( const Time&, const Time& ) noexcept;

NHILL_DATETIME_PORT_FUNCTION bool operator==( const Time&, const Time& ) noexcept;
NHILL_DATETIME_PORT_FUNCTION bool operator!=( const Time&, const Time& ) noexcept;
NHILL_DATETIME_PORT_FUNCTION bool operator< ( const Time&, const Time& ) noexcept;
NHILL_DATETIME_PORT_FUNCTION bool operator<=( const Time&, const Time& ) noexcept;
NHILL_DATETIME_PORT_FUNCTION bool operator> ( const Time&, const Time& ) noexcept;
NHILL_DATETIME_PORT_FUNCTION bool operator>=( const Time&, const Time& ) noexcept;


}
