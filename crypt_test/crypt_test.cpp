#include "pch.h"
#include "CppUnitTest.h"
#include "../crypt/crypt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace crypttest
{
	TEST_CLASS(crypttest)
	{
	public:
		
		TEST_METHOD(encrypt_decrypt_test)
		{
			string s{ "Nicholas C.A. Hill" };
			string e{ nhill::crypt::encrypt( s ) };
			string d{ nhill::crypt::decrypt( e ) };

			Assert::AreEqual( s.c_str(), d.c_str() );
		}
	};
}
