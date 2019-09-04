#include "pch.h"
#include "CppUnitTest.h"
#include "..\geometry\vector.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace nhill::geometry;

namespace geometry_test
{
TEST_CLASS( Vector_test )
{
public:

   TEST_METHOD( ctor )
   {
      Vector<float> v(2, 3);
   }

};
}
