#pragma once

namespace nhill
{

template<typename Iter>
class Range
{
public:
   Range() = default;
   Range( const Iter& begin, const Iter& end );
   Range( const Range& ) = default;
   Range( Range&& ) = default;
   ~Range() = default;

public:
   Range& operator=( const Range& ) = default;
   Range& operator=( Range&& ) = default;

public:
   Iter& begin() noexcept;
   const Iter& begin() const noexcept;
   void begin( const Iter& );

   Iter& end() noexcept;
   const Iter& end() const noexcept;
   void end( const Iter& );

private:
   Iter begin_;
   Iter end_;
};

}

template<typename Iter> inline 
nhill::Range<Iter>::Range( const Iter & begin, const Iter & end )
   : begin_{begin}
   , end_{end}
{
}

template<typename Iter> inline 
Iter& nhill::Range<Iter>::begin() noexcept
{
   return begin_;
}

template<typename Iter> inline
const Iter& nhill::Range<Iter>::begin() const noexcept
{
   return begin_;
}

template<typename Iter> inline 
void nhill::Range<Iter>::begin( const Iter & iter)
{
   begin_ = iter;
}

template<typename Iter> inline 
Iter& nhill::Range<Iter>::end() noexcept
{
   return end_;
}

template<typename Iter> inline
const Iter& nhill::Range<Iter>::end() const noexcept
{
   return end_;
}

template<typename Iter> inline 
void nhill::Range<Iter>::end( const Iter & iter)
{
   end_ = iter;
}

