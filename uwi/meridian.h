#pragma once

#include "port.h"
#include "../utility/value.h"
#include <cstdint>
#include <string>

namespace nhill
{
namespace uwi
{
namespace dls
{

/// <summary>Throw an exception if the value is not a valid meridian [1,6].</summary>
class NHILL_UWI_PORT_CLASS Meridian_validator_throw final : public utility::Value_validator<uint8_t>
{
public:
   using base = utility::Value_validator<uint8_t>;
   Meridian_validator_throw();
   value_type operator()( value_type val ) const final;
};

/// <summary>If the value is not a valid meridian [1,6], then pin the value to the range for a meridian.</summary>
/// <remarks>If the value is less than 1, then it is set to 1. If the value is greater than 6, then it is set to 6.</remarks>
class NHILL_UWI_PORT_CLASS Meridian_validator_pin final : public utility::Value_validator<uint8_t>
{
public:
   using base = utility::Value_validator<uint8_t>;
   Meridian_validator_pin();
   value_type operator()( value_type val ) const final;
};


template<typename Validator>
class Meridian : public utility::Value<uint8_t, Validator>
{
public:
   using base = utility::Value<uint8_t, Validator>;
   using base::base;
   static bool is_valid( uint8_t );
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

NHILL_UWI_PORT_FUNCTION bool is_valid_meridian( int v );

}
}
}

template<typename Validator>
inline bool nhill::uwi::dls::Meridian<Validator>::is_valid( uint8_t val )
{
   return is_valid_meridian( val );
}
