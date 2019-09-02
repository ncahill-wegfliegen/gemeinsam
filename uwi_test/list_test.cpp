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
		const Uwi uwis[]{ "00/06-14-045-12W4/0", "00/05-14-045-12W4/2", "00/06-17-045-12W4/0", "00/06-17-045-12W4/2" };
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
