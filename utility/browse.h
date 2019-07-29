#pragma once

namespace nhill
{

template<typename T>
class Browse
{
public:
   using value_type = T;
   using reference = T&;
   using const_reference = const T&;

   Browse( const Browse& ) = delete;
   Browse& operator=( const Browse& ) = delete;
   Browse( Browse&& ) = delete;
   Browse& operator=( Browse&& ) = delete;
   virtual ~Browse();

   virtual reference first   () = 0;
   virtual reference previous() = 0;
   virtual reference next    () = 0;
   virtual reference last    () = 0;

   virtual const_reference cfirst   () const = 0;
   virtual const_reference cprevious() const = 0;
   virtual const_reference cnext    () const = 0;
   virtual const_reference clast    () const = 0;

   virtual bool is_first() const = 0;
   virtual bool is_last () const = 0;

protected:
   Browse();
};

}

#pragma region Definitions
template<typename T> inline
nhill::Browse<T>::Browse() = default;

template<typename T> inline
nhill::Browse<T>::~Browse() = default;
#pragma endregion