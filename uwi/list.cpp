#include "list.h"
#include <memory>
#include <fstream>

using namespace std;

nhill::uwi::List::List() = default;

nhill::uwi::List::List( const List& ) = default;
auto nhill::uwi::List::operator=( const List& )->List & = default;

nhill::uwi::List::List( List&& other) noexcept
	: base{move(other)}
	, hdr_{}
{
}

auto nhill::uwi::List::operator=( List&& other ) noexcept->List &
{
	base::operator=( move( other ) );
	hdr_ = move( other.hdr_ );
	return *this;
}

nhill::uwi::List::~List() = default;

auto nhill::uwi::List::header() const->const List_header &
{
	return hdr_;
}

size_t nhill::uwi::List::load( const std::filesystem::path& path )
{
	ifstream in{ path };
	if( !in.is_open() )
	{
		return 0;
	}

	in >> hdr_;

	// This will go much faster if the uwis are already in sort format
	if( hdr_.format == Format::sort )
	{
		Uwi uwi;
		string line;
		while( getline( in, line ) )
		{
			uwi.set_unchecked( line );
			base::emplace( uwi );
		}
	}
	else
	{
		string line;
		while( getline( in, line ) )
		{
			base::emplace( Uwi{ line } );
		}
	}

	return base::size();
}

bool nhill::uwi::List::save( const std::filesystem::path& path ) const
{
	ofstream out( path );
	if( !out.is_open() )
	{
		return false;
	}

	out << header();

	for( const auto& uwi : *this )
	{
		out << uwi << endl;
	}

	out.close();

	return true;
}
