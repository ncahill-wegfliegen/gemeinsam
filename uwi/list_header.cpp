#include "list_header.h"
#include "../version/version_manager.h"
#include "../enum/format_ex.h"

using namespace std;

nhill::uwi::List_header::List_header()
	: version{Version_manager::instance().current()}
	, format{Format::sort}
{
}

nhill::uwi::List_header::List_header( const List_header& ) = default;
auto nhill::uwi::List_header::operator=( const List_header& )->List_header & = default;

nhill::uwi::List_header::List_header( List_header&& ) noexcept = default;
auto nhill::uwi::List_header::operator=( List_header&& ) noexcept->List_header & = default;

nhill::uwi::List_header::~List_header() = default;


istream& nhill::operator>>( istream& in, uwi::List_header& hdr )
{
	string s;

	getline( in, s, '=' );
	in >> hdr.version;
	getline( in, s ); // read the end of line

	getline( in, s, '=' );
	in >> hdr.format;
	getline( in, s ); // read the end of line

	return in;
}

ostream& nhill::operator<<( ostream& out, const uwi::List_header& hdr )
{
	out << "version=" << hdr.version << endl;
	out << "format=" << hdr.format << endl;
	return out;
}
