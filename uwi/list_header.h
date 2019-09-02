#pragma once

#include "port.h"
#include "format.h"
#include "../version/version.h"
#include <ostream>
#include <istream>

namespace nhill
{
namespace uwi
{

class NHILL_UWI_PORT_CLASS List_header
{
public:
	List_header();

	List_header( const List_header& );
	List_header& operator=( const List_header& );

	List_header( List_header&& ) noexcept;
	List_header& operator=( List_header&& ) noexcept;

	~List_header();

	Version version;
	Format format;
};


}
}

namespace nhill
{
NHILL_UWI_PORT_FUNCTION std::istream& operator>>( std::istream& in, uwi::List_header& hdr );
NHILL_UWI_PORT_FUNCTION std::ostream& operator<<( std::ostream& out, const uwi::List_header& hdr );
}
