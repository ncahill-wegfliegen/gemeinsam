#pragma once

#include <stdexcept>

namespace nhill
{

/// <summary>The path contains invalid characters.</summary>
class Invalid_path : public std::invalid_argument
{
public:
   using base = std::invalid_argument;

   using base::base;
   using base::operator=;
};

}
