#include "pch.h"
#include "CppUnitTest.h"
#include "../uwi/list_header.h"
#include "../uwi/format_ex.h"
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace nhill;
using namespace nhill::uwi;
using namespace std;

//namespace Microsoft
//{
//namespace VisualStudio
//{
//namespace CppUnitTestFramework
//{
//template<>
//std::wstring ToString( const Format& fmt )
//{
//	string s{ nhill::to_string( fmt ) };
//	return { s.cbegin(), s.cend() };
//}
//}
//}
//}

//ostream& operator<<( ostream& out, const List_header& hdr )
//{
//	out << "version=" << hdr.version << endl;
//	out << "format=" << hdr.format << endl;
//	return out;
//}

namespace uwitest
{
TEST_CLASS(uwi_format_test )
{
public:

	TEST_METHOD( out_stream_test )
	{
		ostringstream oss;
		oss << Format::sort << endl;
	}

	TEST_METHOD( in_stream_test )
	{
	}
};
}
