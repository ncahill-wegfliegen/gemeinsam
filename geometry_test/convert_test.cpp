#include "pch.h"
#include "CppUnitTest.h"
#include "..\geometry\convert.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace nhill::geometry;

namespace geometry_test
{
TEST_CLASS( Convert_test )
{
public:

   //TEST_METHOD( polar_to_pntf )
   //{
   //   PolarT<double> p1{5.6, 5.34567};
   //   PntT<float> p2{to_cartesian<float,double>( p1 )};

   //}

   //TEST_METHOD( polar_to_pnti)
   //{
   //   PolarT<double> p1{5.6, 5.34567};
   //   PntT<int> p2{to_cartesian<int,double>( p1 )};
   //}

   //TEST_METHOD( pnt_to_polar )
   //{
   //   PntT<float> p1{5.6f, 5.34567f};
   //   PolarT<float> p2{to_polar<float,float>( p1 )};
   //}

   //TEST_METHOD( deg_to_rad )
   //{
   //   DegreeT<float> deg{35};
   //   RadianT<double> rad{to_radian<double, float>( deg )};
   //}
};
}
