#pragma once

#include "port.h"
#include "uwi.h"
#include "list_header.h"
#include <set>
#include <string_view>
#include <filesystem>

namespace nhill
{
namespace uwi
{

#pragma warning(push)
#pragma warning(disable:4251)
class NHILL_UWI_PORT_CLASS List : public std::set<Uwi>
{
public:
	using base = std::set<Uwi>;

	List();

	List( const List& );
	List& operator=( const List& );

	List( List&& ) noexcept;
	List& operator=( List&& ) noexcept;

	~List();

	const List_header& header() const;

	size_t load( const std::filesystem::path& );
	bool save( const std::filesystem::path& ) const;

private:
	List_header hdr_;
};
#pragma warning(pop)

}
}