#include "pch.h"
#include "CppUnitTest.h"
#include "../uom/temp/quantity_def.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace nhill::uom::temp;

namespace uomtest
{
	TEST_CLASS(Temp_test)
	{
	public:
		
		TEST_METHOD(DegF)
		{
			v_degF<> f{100.0f};

		}
	};
}
