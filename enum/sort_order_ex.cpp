#include "sort_order_ex.h"

template<>
const nhill::text::Bundle_container<nhill::Sort_order>& nhill::text::bundle_container<nhill::Sort_order>()
{
   static const Bundle_container<Sort_order> bundles{
      { Sort_order::none,{ "NA", "NA", "none", "", "None" } },
      //
      { Sort_order::ascending ,{ "ASC", "Asc", "ascending" , "Ascending" , "Ascending"  } },
      { Sort_order::descending,{ "DSC", "Dsc", "descending", "Descending", "Descending" } },
   };


   return bundles;
}
