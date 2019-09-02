#include "pch.h"
#include "CppUnitTest.h"
#include "../enum/survey_system_ex.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace nhill;
using namespace std;

namespace Microsoft
{
namespace VisualStudio
{
namespace CppUnitTestFramework
{

template<>
std::wstring ToString( const nhill::Survey_system& ss )
{
	string s{ nhill::to_string(ss) };
	return { s.cbegin(), s.cend() };
}


}
}
}


namespace uwitest
{
TEST_CLASS( survey_system_test )
{
public:

	TEST_METHOD( begin_test )
	{
		Survey_system expected{ Survey_system::none };
		Survey_system actual{ nhill::begin<Survey_system>() };
		Assert::AreEqual( expected, actual );
	}

	TEST_METHOD( end_test )
	{
		Survey_system expected{ to_enum<Survey_system>(to_int(Survey_system::other) + 1) };
		Survey_system actual{ nhill::end<Survey_system>() };
		Assert::AreEqual( to_int(expected), to_int(actual) );
	}
};
}
