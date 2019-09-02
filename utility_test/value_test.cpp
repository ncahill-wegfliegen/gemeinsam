#include "pch.h"
#include "CppUnitTest.h"
#include "../utility/value_base.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace nhill;
using namespace nhill::utility;

namespace utilitytest
{
TEST_CLASS( Value_test )
{
public:

   TEST_METHOD( compare_test )
   {
      Value_base<int> v1{ 5 };
      Value_base<double> v2{ 11.5 };

      Compare expected{ Compare::less };
      Compare actual{ compare( v1,v2 ) };
      Assert::AreEqual( to_int( expected ), to_int( actual ) );
   }

   TEST_METHOD( equal_test )
   {
      Value_base<int> v1{ 5 };
      Value_base<double> v2{ 11.5 };

      bool expected{ false };
      bool actual{ v1 == v2 };
      Assert::AreEqual( expected, actual, L"should be unequal" );

      v2 = 5;
      expected = true;
      actual = (v1 == v2);
      Assert::AreEqual( expected, actual, L"should be equal" );
   }
};
}
