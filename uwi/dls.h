#pragma once

#include "port.h"
#include "uwi.h"
#include "location_exception.h"
#include "legal_subdivision.h"
#include "section.h"
#include "township.h"
#include "range.h"
#include "meridian.h"
#include "event_sequence.h"
#include "../utility/compare.h"
#include <cstdint>
#include <string>
#include <string_view>

namespace nhill
{
namespace uwi
{
enum class Format;
namespace dls
{
enum class Range_direction;
}

class NHILL_UWI_PORT_CLASS Dls /*: public Uwi*/
{
public:
   using Location_exception = dls::Location_exception;
   using Legal_subdivision = dls::Legal_subdivision<dls::Legal_subdivision_validator_throw>;
   using Section = dls::Section<dls::Section_validator_throw>;
   using Township = dls::Township<dls::Township_validator_throw>;
   using Range = dls::Range<dls::Range_validator_throw>;
   using Meridian  = dls::Meridian<dls::Meridian_validator_throw>;
   using Event_sequence = dls::Event_sequence;
   using Range_direction = dls::Range_direction;

   Dls();
   Dls( const Location_exception& le, const Legal_subdivision& lsd, const Section& sc, const Township& twp, const Range& rg, const Meridian& m, const Event_sequence& es );

   Dls( const Dls& );
   Dls& operator=( const Dls& );

   Dls( Dls&& ) noexcept;
   Dls& operator=( Dls&& ) noexcept;

   ~Dls();

#pragma warning(push)
#pragma warning(disable:4251)
   Location_exception le;
   Legal_subdivision lsd;
   Section sc;
   Township twp;
   Range rg;
   Meridian m;
   Event_sequence es;
#pragma warning(pop)

   //Uwi_type type() const override;
   void clear();

   // 1=survey_system, XX=location_exception, LL=legal_subdivision, SS=section, TTT=township, RR=range, D=range_direction (either 'W' or 'E'), M=meridian, 0=padding, E=event_sequence
   
   // 1DMRRTTTSSLLXXE  BC > AB > SK > ...
   std::string sort() const;
   // XXLLSSTTTRRME or XXLLSSTTTRRDME
   std::string plain( bool range_direction = true ) const;
   // 1XXLLSSTTTRRDM0E
   std::string full() const;
   // XX/LL-SS-TTT-RRDM/E
   std::string plain_dressed() const;
   // 1XX/LL-SS-TTT-RRDM/0E
   std::string full_dressed() const;

   std::string to_string( Format ) const;

   Range_direction range_direction() const;

protected:
   char rgd() const; // The character that represents the range direction
};

}
}


namespace nhill
{

template<> NHILL_UWI_PORT_CLASS inline
Compare compare( const uwi::Dls& a, const uwi::Dls& b ) noexcept;

namespace uwi
{

NHILL_UWI_PORT_CLASS bool operator==( const Dls& a, const Dls& b );
NHILL_UWI_PORT_CLASS bool operator!=( const Dls& a, const Dls& b );

NHILL_UWI_PORT_CLASS bool operator<( const Dls& a, const Dls& b );
NHILL_UWI_PORT_CLASS bool operator>( const Dls& a, const Dls& b );

NHILL_UWI_PORT_CLASS bool operator<=( const Dls& a, const Dls& b );
NHILL_UWI_PORT_CLASS bool operator>=( const Dls& a, const Dls& b );

namespace dls
{

constexpr uint8_t len_sort{ 15 };
constexpr uint8_t len_plain{ 13 }; // without range direction
constexpr uint8_t len_plain_rgd{ 14 }; // with range direction
constexpr uint8_t len_full{ 16 };
constexpr uint8_t len_plain_dressed{ 19 };
constexpr uint8_t len_full_dressed{ 21 };

NHILL_UWI_PORT_FUNCTION bool is_sort( std::string_view str, Dls* dls = nullptr );
NHILL_UWI_PORT_FUNCTION bool is_plain( std::string_view str, Dls* dls = nullptr );
NHILL_UWI_PORT_FUNCTION bool is_full( std::string_view str, Dls* dls = nullptr );
NHILL_UWI_PORT_FUNCTION bool is_plain_dressed( std::string_view str, Dls* dls = nullptr );
NHILL_UWI_PORT_FUNCTION bool is_full_dressed( std::string_view str, Dls* dls = nullptr );
NHILL_UWI_PORT_FUNCTION bool is_valid_dls( std::string_view str, Dls* dls = nullptr );

NHILL_UWI_PORT_FUNCTION Dls parse_sort( std::string_view s ); // Beware: minimal validation and checking
NHILL_UWI_PORT_FUNCTION Dls parse_plain( std::string_view s ); // Beware: minimal validation and checking

}
}
}