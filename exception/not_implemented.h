#pragma once

#include <stdexcept>

namespace nhill
{

class Not_implemented : public std::logic_error
{
public:
   using base = std::logic_error;

   using base::base;
   using base::operator=;
};

}