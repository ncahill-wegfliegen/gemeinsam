#include "pch.h"
#include "CppUnitTest.h"
#include "..\geometry\interval.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace nhill::geometry;

namespace geometry_test
{
TEST_CLASS( Interval_test )
{
public:

   TEST_METHOD( ctor_test )
   {
      Interval_cc<int> i;
   }


};
}
