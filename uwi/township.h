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

/// <summary>Throw an exception if the value is not a valid township [1,126].</summary>
class NHILL_UWI_PORT_CLASS Township_validator_throw final : public utility::Value_validator<uint8_t>
{
public:
   using base = utility::Value_validator<uint8_t>;
   Township_validator_throw();
   value_type operator()( value_type val ) const final;
};

/// <summary>If the value is not a valid township [1,126], then pin the value to the range for a township.</summary>
/// <remarks>If the value is less than 1, then it is set to 1. If the value is greater than 126, then it is set to 126.</remarks>
class NHILL_UWI_PORT_CLASS Township_validator_pin final : public utility::Value_validator<uint8_t>
{
public:
   using base = utility::Value_validator<uint8_t>;
   Township_validator_pin();
   value_type operator()( value_type val ) const final;
};


template<typename Validator>
class Township : public utility::Value<uint8_t, Validator>
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

NHILL_UWI_PORT_FUNCTION bool is_valid_township( int v );

}
}
}

template<typename Validator>
inline bool nhill::uwi::dls::Township<Validator>::is_valid( uint8_t val )
{
   return is_valid_township( val );
}
