#include "version_manager.h"
#include <fstream>
#include <string>

using namespace std;

const char* const nhill::Version_manager::path_{ R"(..\..\..\..\..\bemühen.config)" };

auto nhill::Version_manager::instance()-> const Version_manager &
{
	static const Version_manager instance;
	return instance;
}

nhill::Version_manager::~Version_manager()
{
}

auto nhill::Version_manager::current() const->const Version &
{
	return current_;
}


nhill::Version_manager::Version_manager()
{
	// open the config file
	ifstream in{ path_ };

	// first line
	string line;
	if( getline( in, line, '=' ) )
	{
		in >> current_;
	}

}
