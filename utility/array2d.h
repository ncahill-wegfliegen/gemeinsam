#pragma once

#include <vector>

namespace nhill
{

template<typename T> class Row2D;
template<typename T> class Col2D;

template<typename T>
class Array2D
{
public:
	using index_type = unsigned short;

	Array2D();
	Array2D( index_type row_count, index_type col_count );

	Array2D( const Array2D& );
	Array2D& operator=( const Array2D& );

	Array2D( Array2D&& ) noexcept;
	Array2D& operator=( Array2D&& ) noexcept;

	~Array2D();

	Row2D<T> operator[]( index_type row );

	index_type row_count() const;
	index_type col_count() const;

	void resize( index_type row_count, index_type col_count );


	friend class Row2D<T>;
	friend class Col2D<T>;

protected:
	void copy( const Array2D<T>& other );

private:
	T* elms_;
	index_type row_cnt_;
	index_type col_cnt_;
};

template<typename T>
class Row2D
{
public:
	using index_type = typename Array2D<T>::index_type;

	Row2D( Array2D<T>& arr, index_type row );

	T& operator[]( index_type col );
	const T& operator[]( index_type col ) const;

	index_type col_count() const;

private:
	Array2D<T>& arr_;
	index_type row_;
};

template<typename T>
class Col2D
{
public:
	using index_type = typename Array2D<T>::index_type;

	Col2D( Array2D<T>& arr, index_type col );

	T& operator[]( index_type row );
	const T& operator[]( index_type row ) const;

	index_type row_count() const;

private:
	Array2D<T>& arr_;
	index_type col_;
};


}

#pragma region Array2D Definitions
template<typename T> inline
nhill::Array2D<T>::Array2D()
	: elms_{ nullptr }
	, row_cnt_{ 0 }
	, col_cnt_{ 0 }
{
}

template<typename T> inline
nhill::Array2D<T>::Array2D( index_type row_count, index_type col_count )
	: Array2D{}
{
	resize( row_count, col_count );
}

template<typename T> inline 
nhill::Array2D<T>::Array2D( const Array2D& other )
	: Array2D{}
{
	copy( other );
}

template<typename T> inline 
auto nhill::Array2D<T>::operator=( const Array2D& other )->Array2D &
{
	copy( other );
	return *this;
}

template<typename T> inline
nhill::Array2D<T>::Array2D( Array2D&& other ) noexcept
	: elms_{other.elms_}
	, row_cnt_{other.row_cnt_}
	, col_cnt_{other.col_cnt_}
{
	other.elms_ = nullptr;
	other.row_cnt_ = 0;
	other.col_cnt_ = 0;
}

template<typename T> inline 
auto nhill::Array2D<T>::operator=( Array2D&& other ) noexcept->Array2D &
{
	delete[] elms_;

	elms_ = other.elms_;
	row_cnt_ = other.row_cnt_;
	col_cnt_ = other.col_cnt_;

	other.elms_ = nullptr;
	other.row_cnt_ = 0;
	other.col_cnt_ = 0;

	return *this;
}

template<typename T> inline 
nhill::Array2D<T>::~Array2D()
{
	delete[] elms_;
}

template<typename T> inline
auto nhill::Array2D<T>::operator[]( index_type row )->Row2D<T>
{
	return { *this, row };
}

template<typename T> inline
auto nhill::Array2D<T>::row_count() const->index_type
{
	return row_cnt_;
}

template<typename T> inline 
auto nhill::Array2D<T>::col_count() const->index_type
{
	return col_cnt_;
}

template<typename T> inline
void nhill::Array2D<T>::resize( index_type row_count, index_type col_count )
{
	delete[] elms_;
	row_cnt_ = 0;
	col_cnt_ = 0;

	if( 0 < row_count && 0 < col_count )
	{
		row_cnt_ = row_count;
		col_cnt_ = col_count;

		elms_ = new T[row_cnt_ * col_cnt_]{};
	}
}

template<typename T> inline
void nhill::Array2D<T>::copy( const Array2D& other )
{
	if( row_cnt_ * col_cnt_!= other.row_cnt_ * other.col_cnt_ )
	{
		resize( other.row_cnt_, other.col_cnt_ );
	}

	index_type pos{ 0 };
	for( index_type r{ 0 }; r < row_cnt_; ++r )
	{
		for( index_type c{ 0 }; c < col_cnt_; ++c )
		{
			pos = r * col_cnt_ + c;
			elms_[pos] = other.elms_[pos];
		}
	}
}
#pragma endregion

#pragma region Row2D Definitions
template<typename T> inline 
nhill::Row2D<T>::Row2D( Array2D<T>& arr, index_type row )
	: arr_{arr}
	, row_{row}
{
}

template<typename T> inline
auto nhill::Row2D<T>::operator[]( index_type col )->T &
{
	return arr_.elms_[row_ * (arr_.col_cnt_) + col];
}

template<typename T> inline
auto nhill::Row2D<T>::operator[]( index_type col ) const->const T &
{
	return arr_.elms_[row_ * (arr_.col_cnt_) + col];
}

template<typename T> inline
auto nhill::Row2D<T>::col_count() const->index_type
{
	return arr_.col_count();
}
#pragma endregion

#pragma region Col2D Definitions
template<typename T> inline
nhill::Col2D<T>::Col2D( Array2D<T>& arr, index_type col )
	: arr_{ arr }
	, col_{ col }
{
}

template<typename T> inline
auto nhill::Col2D<T>::operator[]( index_type row )->T &
{
	return arr_.elms_[row * (arr_.col_cnt_) + col_];
}

template<typename T> inline
auto nhill::Col2D<T>::operator[]( index_type row ) const->const T &
{
	return arr_.elms_[row * (arr_.col_cnt_) + col_];
}


template<typename T> inline
auto nhill::Col2D<T>::row_count() const->index_type
{
	return arr_.row_count();
}
#pragma endregion 

