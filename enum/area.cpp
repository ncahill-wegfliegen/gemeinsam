#include "nhill\enum\province.h"

using namespace std;


template<> 
const nhill::text::Bundle_container<nhill::Province>& nhill::text::bundle_container<nhill::Province>()
{
   static const Bundle_container<Province> bundles{
      { Province::none,{ "NA", "NA", "none", "", "None" } },
      //
      { Province::NL,{ { Type::string, "NL" }, { Type::description, "Newfoundland and Labrador" } } },
      { Province::PE,{ { Type::string, "PE" }, { Type::description, "Prince Edward Island" } } },
      { Province::NS,{ { Type::string, "NS" }, { Type::description, "Nova Scotia" } } },
      { Province::NB,{ { Type::string, "NB" }, { Type::description, "New Brunswick" } } },
      { Province::QC,{ { Type::string, "QC" }, { Type::description, "Quebec" } } },
      { Province::ON,{ { Type::string, "ON" }, { Type::description, "Ontario" } } },
      { Province::MB,{ { Type::string, "MB" }, { Type::description, "Manitoba" } } },
      { Province::SK,{ { Type::string, "SK" }, { Type::description, "Saskatchewan" } } },
      { Province::AB,{ { Type::string, "AB" }, { Type::description, "Alberta" } } },
      { Province::BC,{ { Type::string, "BC" }, { Type::description, "British Columnbia" } } },
      { Province::YT,{ { Type::string, "YT" }, { Type::description, "Yukon" } } },
      { Province::NT,{ { Type::string, "NT" }, { Type::description, "Northwest Territories" } } },
      { Province::NU,{ { Type::string, "NU" }, { Type::description, "Nunavut" } } },
      { Province::AL,{ { Type::string, "AL" }, { Type::description, "Alabama" } } },
      { Province::AK,{ { Type::string, "AK" }, { Type::description, "Alaska" } } },
      { Province::AZ,{ { Type::string, "AZ" }, { Type::description, "Arizona" } } },
      { Province::AR,{ { Type::string, "AR" }, { Type::description, "Arkansas" } } },
      { Province::CA,{ { Type::string, "CA" }, { Type::description, "California" } } },
      { Province::CO,{ { Type::string, "CO" }, { Type::description, "Colorado" } } },
      { Province::CT,{ { Type::string, "CT" }, { Type::description, "Connecticut" } } },
      { Province::DE,{ { Type::string, "DE" }, { Type::description, "Delaware" } } },
      { Province::DC,{ { Type::string, "DC" }, { Type::description, "District of Columbia" } } },
      { Province::FL,{ { Type::string, "FL" }, { Type::description, "Florida" } } },
      { Province::GA,{ { Type::string, "GA" }, { Type::description, "Georgia" } } },
      { Province::HI,{ { Type::string, "HI" }, { Type::description, "Hawaii" } } },
      { Province::ID,{ { Type::string, "ID" }, { Type::description, "Idaho" } } },
      { Province::IL,{ { Type::string, "IL" }, { Type::description, "Illinois" } } },
      { Province::IN,{ { Type::string, "IN" }, { Type::description, "Indiana" } } },
      { Province::IA,{ { Type::string, "IA" }, { Type::description, "Iowa" } } },
      { Province::KS,{ { Type::string, "KS" }, { Type::description, "Kansas" } } },
      { Province::KY,{ { Type::string, "KY" }, { Type::description, "Kentucky" } } },
      { Province::LA,{ { Type::string, "LA" }, { Type::description, "Louisiana" } } },
      { Province::ME,{ { Type::string, "ME" }, { Type::description, "Maine" } } },
      { Province::MD,{ { Type::string, "MD" }, { Type::description, "Maryland" } } },
      { Province::MA,{ { Type::string, "MA" }, { Type::description, "Massachusetts" } } },
      { Province::MI,{ { Type::string, "MI" }, { Type::description, "Michigan" } } },
      { Province::MN,{ { Type::string, "MN" }, { Type::description, "Minnesota" } } },
      { Province::MS,{ { Type::string, "MS" }, { Type::description, "Mississippi" } } },
      { Province::MO,{ { Type::string, "MO" }, { Type::description, "Missouri" } } },
      { Province::MT,{ { Type::string, "MT" }, { Type::description, "Montana" } } },
      { Province::NE,{ { Type::string, "NE" }, { Type::description, "Nevada" } } },
      { Province::NH,{ { Type::string, "NH" }, { Type::description, "New Hampshire" } } },
      { Province::NJ,{ { Type::string, "NJ" }, { Type::description, "New Jersey" } } },
      { Province::NM,{ { Type::string, "NM" }, { Type::description, "New Mexico" } } },
      { Province::NY,{ { Type::string, "NY" }, { Type::description, "New York" } } },
      { Province::NC,{ { Type::string, "NC" }, { Type::description, "North Carolina" } } },
      { Province::ND,{ { Type::string, "ND" }, { Type::description, "North Dakota" } } },
      { Province::OH,{ { Type::string, "OH" }, { Type::description, "Ohio" } } },
      { Province::OK,{ { Type::string, "OK" }, { Type::description, "Oklahoma" } } },
      { Province::OR,{ { Type::string, "OR" }, { Type::description, "Oregon" } } },
      { Province::PA,{ { Type::string, "PA" }, { Type::description, "Pennsylvania" } } },
      { Province::RI,{ { Type::string, "RI" }, { Type::description, "Rhode Island" } } },
      { Province::SC,{ { Type::string, "SC" }, { Type::description, "South Carolina" } } },
      { Province::SD,{ { Type::string, "SD" }, { Type::description, "South Dakota" } } },
      { Province::TN,{ { Type::string, "TN" }, { Type::description, "Tennessee" } } },
      { Province::TX,{ { Type::string, "TX" }, { Type::description, "Texas" } } },
      { Province::UT,{ { Type::string, "UT" }, { Type::description, "Utah" } } },
      { Province::VT,{ { Type::string, "VT" }, { Type::description, "Vermont" } } },
      { Province::VA,{ { Type::string, "VA" }, { Type::description, "Virginia" } } },
      { Province::WA,{ { Type::string, "WA" }, { Type::description, "Washington" } } },
      { Province::WV,{ { Type::string, "WV" }, { Type::description, "West Virginia" } } },
      { Province::WI,{ { Type::string, "WI" }, { Type::description, "Wisconsin" } } },
      { Province::WY,{ { Type::string, "WY" }, { Type::description, "Wyoming" } } },
   };

   return bundles;
}
