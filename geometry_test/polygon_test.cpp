#include "pch.h"
#include "CppUnitTest.h"
#include "..\geometry\polygon.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace nhill::geometry;

namespace geometry_test
{
TEST_CLASS( Polygon_test )
{
public:

   TEST_METHOD( ctor )
   {
      Polygon<float> polygon;
   }

   TEST_METHOD( ctor_init_list )
   {
      Polygon<float> polygon{{1,2},{2,4}, {3,6}};
   }

   TEST_METHOD( operator_assignment_init_list )
   {
      Polygon<float> polygon;
      polygon = { { 1, 2 }, {2,4}, {3,6} };
   }

   TEST_METHOD( close_test )
   {
      Polygon<float> polygon{{1,2},{2,4}, {3,6}};
      close( polygon );
   }


};
}
