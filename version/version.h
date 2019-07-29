#pragma once

#include "port.h"
#include "..\utility\object.h"
#include <ostream>
#include <istream>
#include <cstdint>

#pragma warning(push)
#pragma warning(disable:4275)
// Suppress warning that Object is not exported.  It is okay, because it is entirely inline.

namespace nhill
{

class NHILL_VERSION_PORT_CLASS Version : public nhill::Object
{
public:
   using value_type = uint8_t;

#pragma region Constructors/Destructor
public:
   Version();
   Version( int major, int minor, int build, int revision );
   Version( const std::string& s );
   Version( const Version& ) = default;
   Version( Version&& other ) = default;
   ~Version() = default;
#pragma endregion

#pragma region Operators
public:
   Version& operator=( const std::string& s );
   Version& operator=( const Version& other ) = default;
   Version& operator=( Version&& other ) = default;
#pragma endregion

#pragma region Properties
public:
   int major() const;
   void major( int );

   int minor() const;
   void minor( int );

   int build() const;
   void build( int );

   int revision() const;
   void revision( int );
#pragma endregion

#pragma region Methods
public:
   virtual std::string to_string() const override;
   void clear();
   bool is_empty() const;
#pragma endregion

#pragma region Fields
private:
   value_type major_;
   value_type minor_;
   value_type build_;
   value_type revision_;
#pragma endregion
};

}

#pragma warning(pop)

namespace nhill
{

NHILL_VERSION_PORT_FUNCTION bool operator==( const Version& x, const Version& y );
NHILL_VERSION_PORT_FUNCTION bool operator!=( const Version& x, const Version& y );
NHILL_VERSION_PORT_FUNCTION std::ostream& operator<<( std::ostream& os, const Version& version );
NHILL_VERSION_PORT_FUNCTION std::istream& operator>>( std::istream& is, Version& version );

}