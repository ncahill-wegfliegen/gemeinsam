#include "pch.h"
#include "CppUnitTest.h"
#include "..\geometry\line_param.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace nhill::geometry;

namespace geometry_test
{
TEST_CLASS( Line_param_test )
{
public:

   TEST_METHOD( ctor )
   {
      Line_param<float> line;

   }

   TEST_METHOD( get_point_test )
   {
      Line_param<float> line{{2,4}, {-4,6}};
      Pnt<float> pnt{line.get_point( 2.3f )};

   }
};
}
