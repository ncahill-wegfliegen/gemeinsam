#include "user.h"
#include <shlobj_core.h>

using namespace std;

filesystem::path nhill::user::local_app( const std::filesystem::path& company_name, const std::filesystem::path& product_name, const std::filesystem::path& subdir, const std::filesystem::path& file_name )
{
	filesystem::path path;

	PWSTR pwstr{ nullptr };
	::SHGetKnownFolderPath( FOLDERID_LocalAppData, KF_FLAG_DEFAULT_PATH, NULL, &pwstr );
	path = pwstr;
	::CoTaskMemFree( pwstr );

	if( !company_name.empty() )
	{
		path /= company_name;
		if( !product_name.empty() )
		{
			path /= product_name;
			if( !subdir.empty() )
			{
				path /= subdir;
			}
		}

		if( !filesystem::exists( path ) )
		{
			if( !filesystem::create_directories( path ) )
			{
				return {};
			}
		}

		if( !file_name.empty() )
		{
			path /= file_name;
		}
	}

	return path;
}
