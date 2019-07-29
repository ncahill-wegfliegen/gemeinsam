#pragma once

#include "port.h"
#include "delim.h"


#pragma region Delimeter Declaration
namespace nhill
{

class NHILL_ENUM_PORT_CLASS Delimiter
{
public:
   Delimiter() noexcept;
   Delimiter( Delim enum_, char other_char = chr::pipe<char>() ) noexcept;
   Delimiter( const Delimiter& ) = default;
   Delimiter( Delimiter&& ) = default;
   ~Delimiter();

public:
   Delimiter& operator=( const Delimiter& ) = default;
   Delimiter& operator=( Delimiter&& ) = default;

public:
   Delim get_enum() const noexcept;
   void  set_enum( Delim ) noexcept;

   /// <summary>Get the character associated with the current enumeration.</summary>
   char get_char() const noexcept;
   /// <summary>Set the character.  The enumeration is set to match the character.</summary>
   void set_char( char ) noexcept;

private:
   Delim enum_;
   char other_char_;
};

}