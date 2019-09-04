#include "pch.h"
#include "CppUnitTest.h"
#include "nhill\log.hpp"
#include "nhill\exception\message.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace logtest
{
TEST_CLASS( log_test )
{
public:

   TEST_METHOD( log_init )
   {
      using namespace nhill;
      log::initialize( log::Level::all, R"(c:\temp\hoola.log)" );

      LOG_ERROR( "Just a little problem.  Nothing to worry about." );

      log::finalize();

      const std::string& level{nhill::to_string( log::Level::error )};

      nhill::exception::Message msg;
   }
};
}
