#include "pch.h"
#include "CppUnitTest.h"
#include "..\geometry\rect.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace nhill::geometry;

namespace geometry_test
{
TEST_CLASS(Rect_test )
{
public:

   TEST_METHOD( left_bottom_test )
   {
      Pnt<int> actuali{get_left_bottom( recti_ )};
      Assert::AreEqual( recti_.left  , actuali.x, L"int left"   );
      Assert::AreEqual( recti_.bottom, actuali.y, L"int bottom" );

      Pnt<float> actualf{get_left_bottom( rectf_ )};
      Assert::AreEqual( rectf_.left  , actualf.x, L"float left" );
      Assert::AreEqual( rectf_.bottom, actualf.y, L"float bottom" );
   }

   TEST_METHOD( right_top_test )
   {
      Pnt<int> actuali( get_right_top( recti_ ) );
      Assert::AreEqual( recti_.right, actuali.x,  L"int right" );
      Assert::AreEqual( recti_.top  , actuali.y,  L"int top"  );

      Pnt<float> actualf( get_right_top( rectf_ ) );
      Assert::AreEqual( rectf_.right, actualf.x, L"float right" );
      Assert::AreEqual( rectf_.top  , actualf.y, L"float top" );
   }

   TEST_METHOD( width_test )
   {
      int actuali{get_width( recti_ )};
      Assert::AreEqual( 64 - 32, actuali, L"int" );

      float actualf{get_width( rectf_ )};
      Assert::AreEqual( 64.0f - 32.0f, actualf, L"float" );
   }

   TEST_METHOD( height_test )
   {
      int actuali{get_height( recti_ )};
      Assert::AreEqual( 20 - 10, actuali, L"int" );

      float actualf{get_height( rectf_ )};
      Assert::AreEqual( 20.0f - 10.0f, actualf, L"float" );
   }

   TEST_METHOD( size_test )
   {
      Pnt<int> actuali{get_size( recti_ )};
      Assert::AreEqual( 64 - 32, actuali.x, L"int width" );
      Assert::AreEqual( 20 - 10, actuali.y, L"int height" );

      Pnt<float> actualf{get_size( rectf_ )};
      Assert::AreEqual( 64.0f - 32.0f, actualf.x, L"float width" );
      Assert::AreEqual( 20.0f - 10.0f, actualf.y, L"float height" );
   }

private:
   Rect<int> recti_{32, 10, 64, 20};
   Rect<float> rectf_{32, 10, 64, 20};
};
}
