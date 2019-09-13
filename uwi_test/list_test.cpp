#include "pch.h"
#include "CppUnitTest.h"
#include "../uwi/list.h"
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace nhill;
using namespace nhill::uwi;
using namespace std;

namespace uwitest
{
TEST_CLASS( list_test )
{
public:

	TEST_METHOD( save_test )
	{
		const Uwi uwis[]{ 
			"A0/03-05-001-16W4/0",  // 353
			"00/07-06-001-16W4/0",  // 432
			"02/12-03-001-17W4/0",	// 962
			"00/15-04-001-17W4/0"	// 1037
		};
		List list;
		list.emplace( uwis[0]);
		list.emplace( uwis[1] );
		list.emplace( uwis[2] );
		list.emplace( uwis[3] );

		list.save( R"(c:\temp\uwilist.bwl)" );

	}

	TEST_METHOD( load_test )
	{
		List list;

		list.load( R"(c:\temp\uwilist.bwl)" );

	}
};
}
