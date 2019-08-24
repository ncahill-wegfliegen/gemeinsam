#include "pch.h"
#include "CppUnitTest.h"
#include "../uwi/legal_subdivision.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace nhill::uwi::dls;
using namespace std;

namespace uwitest
{
TEST_CLASS( Dls_lsd_test )
{
public:

   TEST_METHOD( ctor )
   {
      Legal_subdivision<Legal_subdivision_validator_pin> lsd;
      int expected{ 1 };
      int actual{ lsd };
      Assert::AreEqual( expected, actual );
   }

   TEST_METHOD( ctor_s )
   {
      try
      {
         Legal_subdivision<Legal_subdivision_validator_throw> lsd{ "2" };
         Assert::IsTrue( true, L"should be valid" );
      }
      catch( invalid_argument )
      {
         Assert::Fail( L"should be valid" );
      }


      try
      {
         Legal_subdivision<Legal_subdivision_validator_throw> lsd{ "333" };
         Assert::Fail( L"should be invalid" );
      }
      catch( invalid_argument ex )
      {
         Assert::IsTrue( true, L"should be invalid" );
      }
   }

   //TEST_METHOD( ctor_i )
   //{
   //   try
   //   {
   //      Location_exception le{ 50 };
   //      Assert::IsTrue( true, L"should be valid" );
   //   }
   //   catch( invalid_argument )
   //   {
   //      Assert::Fail( L"should be valid" );
   //   }


   //   try
   //   {
   //      Location_exception le{ 333 };
   //      Assert::Fail( L"should be invalid" );
   //   }
   //   catch( invalid_argument ex )
   //   {
   //      Assert::IsTrue( true, L"should be invalid" );
   //   }
   //}

};
}
