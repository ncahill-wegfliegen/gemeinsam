#pragma once

#include "port.h"
#include "uwi.h"
#include <list>
#include <vector>
#include <string_view>

namespace nhill
{
namespace uwi
{

#pragma warning(push)
#pragma warning(disable:4251)
class NHILL_UWI_PORT_CLASS List : public std::list<Uwi>
{
public:

	int load( std::string_view path );
	void save( std::string_view path ) const;
};
#pragma warning(pop)

}
}