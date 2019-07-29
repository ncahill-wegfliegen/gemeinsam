#include "product.h"

template<> inline
const nhill::text::Bundle_container<nhill::Product>& nhill::text::bundle_container<nhill::Product>()
{
   static const Bundle_container<Product> bundles{
      { Product::none      ,{ "NA"  , "None" , "none"       , "None"       , "None"       } },
      { Product::gas       ,{ "GAS" , "Gas"  , "gas"        , "Gas"        , "Gas"        } },
      { Product::oil       ,{ "OIL" , "Oil"  , "oil"        , "Oil"        , "Oil"        } },
      { Product::water     ,{ "WTR" , "Wtr"  , "water"      , "Water"      , "Water"      } },
      { Product::condensate,{ "CND" , "Cnd"  , "condensate" , "Condensate" , "Condensate" } }
   };

   return bundles;
}

void nhill::to_color( Product product, int& r, int& g, int& b )
{
   switch( product )
   {
   case Product::gas       : r = 255; g =  74; b =  74; break; // Red
   case Product::oil       : r =   0; g = 166; b =  83; break; // Green
   case Product::water     : r =  74; g =  74; b = 255; break; // Blue
   case Product::condensate: r =   0; g = 180; b =   3; break; // Other Green
   default                 : r =   0; g =   0; b =   0;        // Black
   }
}


