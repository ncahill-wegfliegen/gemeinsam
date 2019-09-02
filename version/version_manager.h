#pragma once

#include "port.h"
#include "version.h"

namespace nhill
{

class NHILL_VERSION_PORT_CLASS Version_manager final
{
public:
	static const Version_manager& instance();

	~Version_manager();

	const Version& current() const;

private:
	Version_manager();

	Version current_;
	static const char* const path_;
};

}

