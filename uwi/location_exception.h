#pragma once

#include "port.h"
#include "../utility/strn.h"
#include <string>

namespace nhill
{
namespace uwi
{
namespace dls
{

class NHILL_UWI_PORT_CLASS Location_exception : protected Strn<2>
{
public:
   using base = Strn<2>;

   Location_exception();

   Location_exception( const char* );
   Location_exception& operator=( const char* );

   Location_exception( int );
   Location_exception& operator=( int );

   Location_exception( const Location_exception& );
   Location_exception& operator=( const Location_exception& );

   Location_exception( Location_exception&& ) noexcept;
   Location_exception& operator=( Location_exception&& ) noexcept;

   ~Location_exception();

   operator const char* () const;
   operator int() const;
   /// <summary>Includes null terminator.</summary>
   constexpr size_t size() const; 

   void clear();

   bool is_valid( const char* s, std::string* error_msg = nullptr) override;
   bool is_valid( int i, std::string* error_msg = nullptr );
};

}
}
}