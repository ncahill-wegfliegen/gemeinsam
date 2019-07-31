#include "pch.h"
#include "CppUnitTest.h"
#include "..\uom\puom.h"
#include "..\uom\temp.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace nhill::uom;

namespace uomtest
{
TEST_CLASS( Puom_test )
{
public:

	TEST_METHOD( ctor )
	{
		Prefixed_uom<Temp> degF{Temp::degF};
	}
};
}
