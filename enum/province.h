#pragma once

namespace nhill
{
/// <summary>Area Enumeration</summary>
enum class Province
{
   none,

   NL, // Newfoundland and Labrador
   PE, // Prince Edward Island
   NS, // Nova Scotia
   NB, // New Brunswick
   QC, // Quebec
   ON, // Ontario
   MB, // Manitoba
   SK, // Saskatchewan
   AB, // Alberta
   BC, // British Columnbia
   YT, // Yukon
   NT, // Northwest Territories
   NU, // Nunavut
   AL, // Alabama
   AK, // Alaska
   AZ, // Arizona
   AR, // Arkansas
   CA, // California
   CO, // Colorado
   CT, // Connecticut
   DE, // Delaware
   DC, // District of Columbia
   FL, // Florida
   GA, // Georgia
   HI, // Hawaii
   ID, // Idaho
   IL, // Illinois
   IN, // Indiana
   IA, // Iowa
   KS, // Kansas
   KY, // Kentucky
   LA, // Louisiana
   ME, // Maine
   MD, // Maryland
   MA, // Massachusetts
   MI, // Michigan
   MN, // Minnesota
   MS, // Mississippi
   MO, // Missouri
   MT, // Montana
   NE, // Nevada
   NH, // New Hampshire
   NJ, // New Jersey
   NM, // New Mexico
   NY, // New York
   NC, // North Carolina
   ND, // North Dakota
   OH, // Ohio
   OK, // Oklahoma
   OR, // Oregon
   PA, // Pennsylvania
   RI, // Rhode Island
   SC, // South Carolina
   SD, // South Dakota
   TN, // Tennessee
   TX, // Texas
   UT, // Utah
   VT, // Vermont
   VA, // Virginia
   WA, // Washington
   WV, // West Virginia
   WI, // Wisconsin
   WY, // Wyoming
};

}


#pragma region Extensions: to_code, to_abbreviation, etc.; stream operators << and >>.
#include "port.h"
#include "core/text/bundle_container.h"
#include "core/values.h"

#pragma region Specialize bundle_container: do not use directly; use text methods to_code, to_abbreviation, etc. instead.
template<> NHILL_ENUM_PORT_FUNCTION
const nhill::text::Bundle_container<nhill::Province>& nhill::text::bundle_container<nhill::Province>();
#pragma endregion

#pragma region Values
template<> inline nhill::Province nhill::begin() { return Province::none; }
template<> inline nhill::Province nhill::end() { return to_enum<nhill::Province>( to_int( Province::WY ) + 1 ); }
#pragma endregion


#include "core/text/methods.h"
#include "core/text/stream_in.h"
#include "core/text/stream_out.h"
#pragma endregion

