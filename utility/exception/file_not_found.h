#pragma once

#include <stdexcept>

namespace nhill
{

class File_not_found : public std::invalid_argument
{
public:
   using base = std::invalid_argument;

   using base::base;
   using base::operator=;
};

}

