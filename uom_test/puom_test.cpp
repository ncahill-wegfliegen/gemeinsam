#include "pch.h"
#include "CppUnitTest.h"
#include "../uom/puom.h"
#include "../uom/temp.h"
#include "../uom/ratio/cnd_gas/quantity_def.h"
#include "../uom/ratio/gas_fld/quantity_def.h"
#include "../uom/ratio/gas_oil/quantity_def.h"
#include "../uom/ratio/wtr_gas/quantity_def.h"
#include "../uom/ratio/wtr_oil/quantity_def.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace nhill::uom;

namespace uomtest
{
TEST_CLASS( Puom_test )
{
public:

	TEST_METHOD( ctor )
	{
		Prefixed_uom<Temp> degF{Temp::degF};

		cgr::v_m3_per_e6m3<> cnd_gas;
		gfr::v_m3_per_m3<> gfr;
		gor::v_m3_per_m3<> gor;
		wgr::v_m3_per_e6m3<> wgr;
		wor::v_m3_per_m3<> wor;
	}
};
}
