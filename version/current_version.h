#pragma once

#include "version.h"

namespace nhill
{

class Version_manager final
{
public:
	static Version_manager& instance();

	~Version_manager();

private:
	Version_manager();

	Version version_;

};

}

