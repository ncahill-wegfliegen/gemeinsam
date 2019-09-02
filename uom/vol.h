#pragma once

namespace nhill
{
namespace uom
{

enum class Volume
{
   none,

   // SI
   /// <summary>metres cubed</summary>
   m3,
   /// <summary>hectare metres</summary>
   ham,

   // API
   /// <summary>cubic inch</summary>
   cuin,
   /// <summary>cubic foot</summary>
   cuft,
   /// <summary>cubic yard</summary>
   cuyd,
   /// <summary>cubic mile</summary>
   cumi,
   /// <summary>acre-foot</summary>
   acft,

   // API Oil
   /// <summary>barrel</summary>
   bbl,
   /// <summary>reservoir barrel</summary>
   rb,
   /// <summary>standard barrel</summary>
   stb,

   // API Gas
   /// <summary>barrels of oil equivalent</summary>
   boe,
   /// <summary>cubic feet</summary>
   cf,
   /// <summary>reservoir cubic feet</summary>
   rcf,
   /// <summary>standard cubic feet</summary>
   scf,
};

using Vol = nhill::uom::Volume;

}
}

#pragma region Extensions: to_code, to_abbreviation, etc.; stream operators << and >>.
#include "port.h"
#include "../enum/core/text/bundle_container.h"
#include "../enum/core/values.h"

#pragma region Specialize bundle_container: do not use directly; use text methods to_code, to_abbreviation, etc. instead.
template<> NHILL_UOM_PORT_FUNCTION
const nhill::text::Bundle_container<nhill::uom::Vol>& nhill::text::bundle_container<nhill::uom::Vol>();
#pragma endregion

#pragma region Values
template<> inline nhill::uom::Volume nhill::begin() { return uom::Volume::none; }
template<> inline nhill::uom::Volume nhill::end() { return to_enum<nhill::uom::Volume>( to_int( uom::Volume::scf ) + 1 ); }
#pragma endregion

#include "../enum/core/text/methods.h"
#include "../enum/core/text/stream_in.h"
#include "../enum/core/text/stream_out.h"
#pragma endregion

#pragma region Additional Extensions
#include "../enum/som.h"
namespace nhill
{
template<> NHILL_UOM_PORT_FUNCTION
nhill::Som to_som( nhill::uom::Vol e );
}
#pragma endregion

