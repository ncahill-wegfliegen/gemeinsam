#pragma once

#include "browse_iter.h"

namespace nhill
{

template<typename Container>
class Browse_container : public Browse_iter<typename Container::value_type, typename Container::iterator>
{
public:
   Browse_container( const Container& container );
   Browse_container( const Browse_container& ) = delete;
   Browse_container& operator=( const Browse_container& ) = delete;
   Browse_container( Browse_container&& ) = delete;
   Browse_container& operator=( Browse_container&& ) = delete;
   ~Browse_container();
};

}

#pragma region Definitions
template<typename Container> inline 
nhill::Browse_container<Container>::Browse_container( const Container& container )
{
}

template<typename Container>
inline nhill::Browse_container<Container>::~Browse_container()
{
}
#pragma endregion