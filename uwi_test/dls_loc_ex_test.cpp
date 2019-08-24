#include "pch.h"
#include "CppUnitTest.h"
#include "../uwi/location_exception.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace nhill::uwi::dls;
using namespace std;

namespace uwitest
{
   TEST_CLASS(Dls_loc_ex_test)
   {
   public:
      
      TEST_METHOD(ctor)
      {
         Location_exception le;
         const char* const expected{ "00" };
         const char* const actual{ le };
         Assert::AreEqual( expected, actual );
      }

      TEST_METHOD( ctor_s )
      {
         try
         {
            Location_exception le{ "50" };
            Assert::IsTrue( true, L"should be valid" );
         }
         catch( invalid_argument )
         {
            Assert::Fail(L"should be valid");
         }


         try
         {
            Location_exception le{ "ZZ" };
            Assert::Fail( L"should be invalid" );
         }
         catch( invalid_argument ex )
         {
            Assert::IsTrue( true, L"should be invalid" );
         }
      }

      TEST_METHOD( ctor_i )
      {
         try
         {
            Location_exception le{ 50 };
            Assert::IsTrue( true, L"should be valid" );
         }
         catch( invalid_argument )
         {
            Assert::Fail( L"should be valid" );
         }


         try
         {
            Location_exception le{ 333 };
            Assert::Fail( L"should be invalid" );
         }
         catch( invalid_argument ex )
         {
            Assert::IsTrue( true, L"should be invalid" );
         }
      }

   };
}
