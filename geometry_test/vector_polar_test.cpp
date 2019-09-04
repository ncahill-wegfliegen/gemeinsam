#include "pch.h"
#include "CppUnitTest.h"
#include "..\geometry\vector_polar.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace nhill::geometry;

namespace geometry_test
{
TEST_CLASS( Vector_polar_test )
{
public:

   TEST_METHOD( ctor )
   {
      Vector_polar<float> v;
      v.cartesian( 2, 3 );
   }

};
}
