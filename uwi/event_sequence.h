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

class NHILL_UWI_PORT_CLASS Event_sequence : protected Strn<1>
{
public:
   using base = Strn<1>;

   Event_sequence();

   Event_sequence( const char* );
   Event_sequence& operator=( const char* );

   Event_sequence( int );
   Event_sequence& operator=( int );

   Event_sequence( const Event_sequence& );
   Event_sequence& operator=( const Event_sequence& );

   Event_sequence( Event_sequence&& ) noexcept;
   Event_sequence& operator=( Event_sequence&& ) noexcept;

   ~Event_sequence();

   operator const char* () const;
   operator int() const;
   /// <summary>Includes null terminator.</summary>
   constexpr size_t size() const;

   void clear();

   bool is_valid( const char* s, std::string* error_msg = nullptr ) override;
   bool is_valid( int i, std::string* error_msg = nullptr );
};

}
}
}

