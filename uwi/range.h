#pragma once

#include "port.h"
#include "../utility/value.h"
#include <cstdint>
#include <string>
#include <ostream>
#include <iomanip>

namespace nhill
{
namespace uwi
{
namespace dls
{

/// <summary>Throw an exception if the value is not a valid range [1,30].</summary>
class NHILL_UWI_PORT_CLASS Range_validator_throw final : public utility::Value_validator<uint8_t>
{
public:
   using base = utility::Value_validator<uint8_t>;
   Range_validator_throw();
   value_type operator()( value_type val ) const final;
};

/// <summary>If the value is not a valid range [1,30], then pin the value to the range for a range.</summary>
/// <remarks>If the value is less than 1, then it is set to 1. If the value is greater than 30, then it is set to 30.</remarks>
class NHILL_UWI_PORT_CLASS Range_validator_pin final : public utility::Value_validator<uint8_t>
{
public:
   using base = utility::Value_validator<uint8_t>;
   Range_validator_pin();
   value_type operator()( value_type val ) const final;
};


template<typename Validator>
class Range : public utility::Value<uint8_t, Validator>
{
public:
   using base = utility::Value<uint8_t, Validator>;
   using base::base;
   static bool is_valid( int );
};

}
}
}

namespace nhill
{
namespace uwi
{
namespace dls
{

NHILL_UWI_PORT_FUNCTION bool is_valid_range( int i );

template<typename Validator>
std::ostream& operator<<( std::ostream& out, const Range<Validator>& rg )
{
   return out << std::setfill( '0' ) << std::setw( 2 ) << static_cast<int>(rg);
}


}
}
}

template<typename Validator>
inline bool nhill::uwi::dls::Range<Validator>::is_valid( int i )
{
   return is_valid_range( i );
}
