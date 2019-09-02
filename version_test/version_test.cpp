#include "pch.h"
#include "CppUnitTest.h"
#include "../version/version_manager.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace nhill;

namespace versiontest
{
	TEST_CLASS(version_manager_test)
	{
	public:
		
		TEST_METHOD(ctor)
		{
			const Version_manager& inst{ Version_manager::instance() };
		}
	};
}
