#include "province.h"

using namespace std;


template<>
const nhill::text::Bundle_container<nhill::Province>& nhill::text::bundle_container<nhill::Province>()
{
   static const Bundle_container<Province> bundles{
      { Province::none,{ "NA", "NA", "none", "", "None" } },
      //
      { Province::NL,{ { Text::string, "NL" }, { Text::label, "Newfoundland and Labrador" }, { Text::description, "Newfoundland and Labrador" } } },
      { Province::PE,{ { Text::string, "PE" }, { Text::label, "Prince Edward Island" }, { Text::description, "Prince Edward Island" } } },
      { Province::NS,{ { Text::string, "NS" }, { Text::label, "Nova Scotia" }, { Text::description, "Nova Scotia" } } },
      { Province::NB,{ { Text::string, "NB" }, { Text::label, "New Brunswick" }, { Text::description, "New Brunswick" } } },
      { Province::QC,{ { Text::string, "QC" }, { Text::label, "Quebec" }, { Text::description, "Quebec" } } },
      { Province::ON,{ { Text::string, "ON" }, { Text::label, "Ontario" }, { Text::description, "Ontario" } } },
      { Province::MB,{ { Text::string, "MB" }, { Text::label, "Manitoba" }, { Text::description, "Manitoba" } } },
      { Province::SK,{ { Text::string, "SK" }, { Text::label, "Saskatchewan" }, { Text::description, "Saskatchewan" } } },
      { Province::AB,{ { Text::string, "AB" }, { Text::label, "Alberta" }, { Text::description, "Alberta" } } },
      { Province::BC,{ { Text::string, "BC" }, { Text::label, "British Columnbia" }, { Text::description, "British Columnbia" } } },
      { Province::YT,{ { Text::string, "YT" }, { Text::label, "Yukon" }, { Text::description, "Yukon" } } },
      { Province::NT,{ { Text::string, "NT" }, { Text::label, "Northwest Territories" }, { Text::description, "Northwest Territories" } } },
      { Province::NU,{ { Text::string, "NU" }, { Text::label, "Nunavut" }, { Text::description, "Nunavut" } } },
      { Province::AL,{ { Text::string, "AL" }, { Text::label, "Alabama" }, { Text::description, "Alabama" } } },
      { Province::AK,{ { Text::string, "AK" }, { Text::label, "Alaska" }, { Text::description, "Alaska" } } },
      { Province::AZ,{ { Text::string, "AZ" }, { Text::label, "Arizona" }, { Text::description, "Arizona" } } },
      { Province::AR,{ { Text::string, "AR" }, { Text::label, "Arkansas" }, { Text::description, "Arkansas" } } },
      { Province::CA,{ { Text::string, "CA" }, { Text::label, "California" }, { Text::description, "California" } } },
      { Province::CO,{ { Text::string, "CO" }, { Text::label, "Colorado" }, { Text::description, "Colorado" } } },
      { Province::CT,{ { Text::string, "CT" }, { Text::label, "Connecticut" }, { Text::description, "Connecticut" } } },
      { Province::DE,{ { Text::string, "DE" }, { Text::label, "Delaware" }, { Text::description, "Delaware" } } },
      { Province::DC,{ { Text::string, "DC" }, { Text::label, "District of Columbia" }, { Text::description, "District of Columbia" } } },
      { Province::FL,{ { Text::string, "FL" }, { Text::label, "Florida" }, { Text::description, "Florida" } } },
      { Province::GA,{ { Text::string, "GA" }, { Text::label, "Georgia" }, { Text::description, "Georgia" } } },
      { Province::HI,{ { Text::string, "HI" }, { Text::label, "Hawaii" }, { Text::description, "Hawaii" } } },
      { Province::ID,{ { Text::string, "ID" }, { Text::label, "Idaho" }, { Text::description, "Idaho" } } },
      { Province::IL,{ { Text::string, "IL" }, { Text::label, "Illinois" }, { Text::description, "Illinois" } } },
      { Province::IN,{ { Text::string, "IN" }, { Text::label, "Indiana" }, { Text::description, "Indiana" } } },
      { Province::IA,{ { Text::string, "IA" }, { Text::label, "Iowa" }, { Text::description, "Iowa" } } },
      { Province::KS,{ { Text::string, "KS" }, { Text::label, "Kansas" }, { Text::description, "Kansas" } } },
      { Province::KY,{ { Text::string, "KY" }, { Text::label, "Kentucky" }, { Text::description, "Kentucky" } } },
      { Province::LA,{ { Text::string, "LA" }, { Text::label, "Louisiana" }, { Text::description, "Louisiana" } } },
      { Province::ME,{ { Text::string, "ME" }, { Text::label, "Maine" }, { Text::description, "Maine" } } },
      { Province::MD,{ { Text::string, "MD" }, { Text::label, "Maryland" }, { Text::description, "Maryland" } } },
      { Province::MA,{ { Text::string, "MA" }, { Text::label, "Massachusetts" }, { Text::description, "Massachusetts" } } },
      { Province::MI,{ { Text::string, "MI" }, { Text::label, "Michigan" }, { Text::description, "Michigan" } } },
      { Province::MN,{ { Text::string, "MN" }, { Text::label, "Minnesota" }, { Text::description, "Minnesota" } } },
      { Province::MS,{ { Text::string, "MS" }, { Text::label, "Mississippi" }, { Text::description, "Mississippi" } } },
      { Province::MO,{ { Text::string, "MO" }, { Text::label, "Missouri" }, { Text::description, "Missouri" } } },
      { Province::MT,{ { Text::string, "MT" }, { Text::label, "Montana" }, { Text::description, "Montana" } } },
      { Province::NE,{ { Text::string, "NE" }, { Text::label, "Nevada" }, { Text::description, "Nevada" } } },
      { Province::NH,{ { Text::string, "NH" }, { Text::label, "New Hampshire" }, { Text::description, "New Hampshire" } } },
      { Province::NJ,{ { Text::string, "NJ" }, { Text::label, "New Jersey" }, { Text::description, "New Jersey" } } },
      { Province::NM,{ { Text::string, "NM" }, { Text::label, "New Mexico" }, { Text::description, "New Mexico" } } },
      { Province::NY,{ { Text::string, "NY" }, { Text::label, "New York" }, { Text::description, "New York" } } },
      { Province::NC,{ { Text::string, "NC" }, { Text::label, "North Carolina" }, { Text::description, "North Carolina" } } },
      { Province::ND,{ { Text::string, "ND" }, { Text::label, "North Dakota" }, { Text::description, "North Dakota" } } },
      { Province::OH,{ { Text::string, "OH" }, { Text::label, "Ohio" }, { Text::description, "Ohio" } } },
      { Province::OK,{ { Text::string, "OK" }, { Text::label, "Oklahoma" }, { Text::description, "Oklahoma" } } },
      { Province::OR,{ { Text::string, "OR" }, { Text::label, "Oregon" }, { Text::description, "Oregon" } } },
      { Province::PA,{ { Text::string, "PA" }, { Text::label, "Pennsylvania" }, { Text::description, "Pennsylvania" } } },
      { Province::RI,{ { Text::string, "RI" }, { Text::label, "Rhode Island" }, { Text::description, "Rhode Island" } } },
      { Province::SC,{ { Text::string, "SC" }, { Text::label, "South Carolina" }, { Text::description, "South Carolina" } } },
      { Province::SD,{ { Text::string, "SD" }, { Text::label, "South Dakota" }, { Text::description, "South Dakota" } } },
      { Province::TN,{ { Text::string, "TN" }, { Text::label, "Tennessee" }, { Text::description, "Tennessee" } } },
      { Province::TX,{ { Text::string, "TX" }, { Text::label, "Texas" }, { Text::description, "Texas" } } },
      { Province::UT,{ { Text::string, "UT" }, { Text::label, "Utah" }, { Text::description, "Utah" } } },
      { Province::VT,{ { Text::string, "VT" }, { Text::label, "Vermont" }, { Text::description, "Vermont" } } },
      { Province::VA,{ { Text::string, "VA" }, { Text::label, "Virginia" }, { Text::description, "Virginia" } } },
      { Province::WA,{ { Text::string, "WA" }, { Text::label, "Washington" }, { Text::description, "Washington" } } },
      { Province::WV,{ { Text::string, "WV" }, { Text::label, "West Virginia" }, { Text::description, "West Virginia" } } },
      { Province::WI,{ { Text::string, "WI" }, { Text::label, "Wisconsin" }, { Text::description, "Wisconsin" } } },
      { Province::WY,{ { Text::string, "WY" }, { Text::label, "Wyoming" }, { Text::description, "Wyoming" } } },
   };

   return bundles;
}
