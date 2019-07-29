#pragma once

#include "puom.h"

namespace nhill
{
namespace uom
{

/// <summary>Prefixed unit of measurement definition.</summary>
template<typename Uom, Prefix prefix_, Uom uom_>
class Prefixed_uom_template : public Prefixed_uom<Uom>
{
   static_assert(std::is_enum_v<Uom>, "The template parameter must be a strongly typed enumeration.");

public:
   using base = Prefixed_uom<Uom>;

   Prefixed_uom_template();

   Prefixed_uom_template( const Prefixed_uom_template& other ) = delete;
   Prefixed_uom_template& operator=( const Prefixed_uom_template& other ) = delete;

   Prefixed_uom_template( Prefixed_uom_template&& other ) = delete;
   Prefixed_uom_template& operator=( Prefixed_uom_template&& other ) = delete;

   ~Prefixed_uom_template();
};

}
}

#pragma region Definitions
template<typename Uom, nhill::uom::Prefix prefix_, Uom uom_>
nhill::uom::Prefixed_uom_template<Uom, prefix_, uom_>::Prefixed_uom_template()
   : base{ prefix_, uom_}
{
}

template<typename Uom, nhill::uom::Prefix prefix_, Uom uom_>
nhill::uom::Prefixed_uom_template<Uom, prefix_, uom_>::~Prefixed_uom_template() = default;
#pragma endregion