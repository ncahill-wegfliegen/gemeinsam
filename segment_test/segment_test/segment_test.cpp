#include "pch.h"
#include "CppUnitTest.h"
#include "table.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace nhill::segment;

namespace segmenttest
{
TEST_CLASS( Table_test )
{
public:

   TEST_METHOD( ctor )
   {
      Table<int> table;
   }
};
}
