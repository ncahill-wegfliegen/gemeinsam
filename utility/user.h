#pragma once

#include "port.h"
#include <filesystem>

namespace nhill
{
namespace user
{

constexpr const char* const Bemühen{ "Bemühen" };
constexpr const char* const ab_oil_pressure_test{ "ab_oil_pressure_test" };
constexpr const char* const abopt{ "abopt" }; // Abbreviation for AB Oil Pressure Test
constexpr const char* const config{ "config" };
constexpr const char* const Datenzugriff{ "Datenzugriff" };
constexpr const char* const Benutzeroberfläche{ "Benutzeroberfläche" };

constexpr const char* const business_associate{ "business_associate" };
constexpr const char* const business_associate_abbreviation{ "ba" };

NHILL_UTIL_PORT_FUNCTION std::filesystem::path local_app( const std::filesystem::path& company_name = {}, const std::filesystem::path& product_name = {}, const std::filesystem::path& subdir = {}, const std::filesystem::path& file_name = {} );

}
}
