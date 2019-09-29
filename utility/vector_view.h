#pragma once

#include <algorithm>

namespace nhill
{

template<typename T>
class Vector
{
public:
	using index_type = unsigned short;

	Vector( index_type count = 0 );
	
	Vector( const Vector& );
	Vector& operator=( const Vector& );

	Vector( Vector&& ) noexcept;
	Vector& operator=( Vector&& ) noexcept;

	~Vector();

	T& operator[]( index_type index );
	const T& operator[]( index_type index ) const;

	index_type count() const;
	void resize( index_type count );
	friend void copy( Vector& dst, const Vector& src );

private:
	T* elms_;
	index_type cnt_;
};


}

template<typename T> inline
nhill::Vector<T>::Vector( index_type count )
	: elms_{nullptr}
	, cnt_{count}
{
	resize( count );
}

template<typename T> inline
nhill::Vector<T>::Vector( const Vector& other )
	: elms_{ nullptr }
	, cnt_{ 0 }
{
	copy( *this, other );
}

template<typename T> inline
auto nhill::Vector<T>::operator=( const Vector& other )->Vector &
{
	copy( *this, other );
	return *this;
}


template<typename T> inline
nhill::Vector<T>::Vector( Vector&& other ) noexcept
	: elms_{ other.elms_ }
	, cnt_{ other.cnt_ }
{
	delete[] other.elms_;
	other.elms_ = nullptr;
	other.cnt_ = 0;
}

template<typename T> inline
auto nhill::Vector<T>::operator=( Vector&& other) noexcept->Vector &
{
	delete[] elms_;

	elms_ = other.elms_;
	cnt_ = other.cnt_;

	delete[] other.elms_;
	other.elms_ = nullptr;
	other.cnt_ = 0;

	return *this;
}

template<typename T> inline
nhill::Vector<T>::~Vector()
{
	delete[] elms_;
}

template<typename T> inline 
auto nhill::Vector<T>::operator[]( index_type index )->T &
{
	return elms_[index];
}

template<typename T> inline 
auto nhill::Vector<T>::operator[]( index_type index ) const->const T &
{
	return elms_[index];
}

template<typename T> inline
auto nhill::Vector<T>::count() const->index_type
{
	return cnt_;
}

template<typename T> inline 
void nhill::Vector<T>::resize( index_type count )
{
	delete[] elms_;
	elms_ = nullptr;
	cnt_ = 0;

	if( 0 < count )
	{
		cnt_ = count;
		elms_ = new T[cnt_]{};
	}
}

template<typename T> inline 
void nhill::copy( Vector& dst, const Vector& src )
{
	if( dst.cnt_ != src.cnt_ )
	{
		dst.resize( src.cnt_ );
	}

	if( 0 < src.cnt_ )
	{
		std::copy( src.elms_, src.elms_ + src.cnt_, dst.elms_ );
	}
}

