#include "pch.h"
#include "CppUnitTest.h"
#include "../uwi/dls.h"
#include "../uwi/legal_subdivision.h"
#include "../enum/core/int.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace nhill;
using namespace nhill::uwi;
using namespace nhill::uwi::dls;
using namespace std;

namespace Microsoft
{
namespace VisualStudio
{
namespace CppUnitTestFramework
{

template<>
std::wstring ToString( const nhill::uwi::Dls& dls ) 
{ 
   string s{ dls.plain( true ) };
   return { s.cbegin(), s.cend() };
}


}
}
}


namespace uwitest
{
TEST_CLASS( Dls_test )
{
public:

   TEST_METHOD( sort_test )
   {
      const char* const expected{ "078W6090313000" };
      Dls dls{ 0, 13, 3, 78, 9, 6, 0 };

      string actual{ dls.sort() };
      Assert::AreEqual( expected, actual.c_str() );
   }

   TEST_METHOD( plain_test )
   {
      const char* const expected{ "0013030780960" };
      Dls dls{ 0, 13, 3, 78, 9, 6, 0 };

      string actual{ dls.plain() };
      Assert::AreEqual( expected, actual.c_str() );
   }

   TEST_METHOD( plain_rgd_test )
   {
      const char* const expected{ "00130307809W60" };
      Dls dls{ 0, 13, 3, 78, 9, 6, 0 };

      string actual{ dls.plain(true) };
      Assert::AreEqual( expected, actual.c_str() );
   }

   TEST_METHOD( full_test )
   {
      const char* const expected{ "100130307809W600" };
      Dls dls{ 0, 13, 3, 78, 9, 6, 0 };

      string actual{ dls.full() };
      Assert::AreEqual( expected, actual.c_str() );
   }

   TEST_METHOD( plain_dressed_test )
   {
      const char* const expected{ "00/13-03-078-09W6/0" };
      Dls dls{ 0, 13, 3, 78, 9, 6, 0 };

      string actual{ dls.plain_dressed() };
      Assert::AreEqual( expected, actual.c_str() );
   }

   TEST_METHOD( plain_full_test )
   {
      const char* const expected{ "100/13-03-078-09W6/00" };
      Dls dls{ 0, 13, 3, 78, 9, 6, 0 };

      string actual{ dls.full_dressed() };
      Assert::AreEqual( expected, actual.c_str() );
   }

   TEST_METHOD( is_sort_test )
   {
      Dls expected;
      expected.le  = "0";
      expected.lsd = 13;
      expected.sc  = 3;
      expected.twp = 78;
      expected.rg  = 9;
      expected.m   = 6;
      expected.es  = 0;

      const char* const s{ "078W6090313000" };
      
      Dls actual;
      
      bool b{ is_sort( s, &actual ) };
      Assert::IsTrue( b, L"Failed to validate" );

      Assert::AreEqual( expected, actual, L"DLS" );
   }


   TEST_METHOD( is_plain_test )
   {
      const char* s{ "0003050010840" };
      Dls expected{ 0, 3, 5, 1, 8, 4, 0 };
      Dls actual;
      bool success{ is_plain( s, &actual ) };
      Assert::IsTrue( success, L"Failed to parse 0003050010840" );
      Assert::AreEqual( expected, actual, L"different 0003050010840" );

      s = "0006230471550";
      expected = { 0, 6, 23, 47, 15, 5, 0 };
      success = is_plain( s, &actual );
      Assert::IsTrue( success, L"Failed to parse 0006230471550" );
      Assert::AreEqual( expected, actual, L"different 0006230471550" );

      s = "W004130881252";
      expected = { "W0", 4, 13, 88, 12, 5, 2 };
      success = is_plain( s, &actual );
      Assert::IsTrue( success, L"Failed to parse W004130881252" );
      Assert::AreEqual( expected, actual, L"different W004130881252" );

   }


};
}
