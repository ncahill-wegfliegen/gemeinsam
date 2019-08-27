#include "pch.h"
#include "CppUnitTest.h"
#include "../utility/strn.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace nhill;

namespace utilitytest
{
TEST_CLASS( Strn_test )
{
public:

	TEST_METHOD( ctor )
	{
		Strn<3> s;

	}

	TEST_METHOD( ctor_s )
	{
		const char* expected{ "The rain in spain." };
		Strn<32> actual{ expected };
		int cmp{ strncmp( expected, actual.data(), 32 ) };
		Assert::AreEqual( cmp, 0 );
	}

};
}
