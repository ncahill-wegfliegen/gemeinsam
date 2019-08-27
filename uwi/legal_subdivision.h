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

/// <summary>Throw an exception if the value is not a valid legal subdivision [1,16].</summary>
class NHILL_UWI_PORT_CLASS Legal_subdivision_validator_throw final : public utility::Value_validator<uint8_t>
{
public:
   using base = utility::Value_validator<uint8_t>;
   Legal_subdivision_validator_throw();
   value_type operator()( value_type  ) const final;
};

/// <summary>If the value is not a valid legal subdivision [1,16], then pin the value to the range for a legal subdivision.</summary>
/// <remarks>If the value is less than 1, then it is set to 1. If the value is greater than 16, then it is set to 16.</remarks>
class NHILL_UWI_PORT_CLASS Legal_subdivision_validator_pin final : public utility::Value_validator<uint8_t>
{
public:
   using base = utility::Value_validator<uint8_t>;
   Legal_subdivision_validator_pin();
   value_type operator()( value_type val ) const final;
};


template<typename Validator>
class Legal_subdivision : public utility::Value<uint8_t, Validator>
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

NHILL_UWI_PORT_FUNCTION bool is_valid_legal_subdivision( int i );

template<typename Validator>
std::ostream& operator<<( std::ostream& out, const Legal_subdivision<Validator>& lsd )
{
   return out << std::setfill( '0' ) << std::setw( 2 ) << static_cast<int>(lsd);
}

}
}
}

template<typename Validator>
inline bool nhill::uwi::dls::Legal_subdivision<Validator>::is_valid( int i)
{
   return is_valid_legal_subdivision( i );
}
