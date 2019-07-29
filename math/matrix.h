#pragma once

#include "row.h"
#include "column.h"
#include "enable_if.h"

namespace nhill
{
namespace math
{

template<typename T, typename enable_if::is_math_type<T>* = nullptr>
class Matrix
{
public:
   using value_type = T;
   using size_type = std::size_t;
   using Row = Row<T>;
   using Column = Column<T>;

   struct Index // Matrix index
   { 
      size_t r; // Row index
      size_t c; // Column index
   };

   Matrix( size_t row_count, size_t col_count, T value = 0 ) noexcept;
   Matrix( std::initializer_list<Row> il );
   Matrix( const Matrix& ) noexcept;
   Matrix( Matrix&& ) noexcept;
   ~Matrix() noexcept;

   Matrix& operator=( const Matrix& ) noexcept;
   Matrix& operator=( Matrix&& ) noexcept;

   Row operator[]( size_t r ) const;

   T& operator[]( const Index& idx );
   const T& operator[]( const Index& idx ) const;

   size_t col_count() const noexcept;
   size_t row_count() const noexcept;

   void clear() noexcept;
   
   void fill_row( size_t r, T value );
   void fill_col( size_t c, T value );
   void fill( T value ) noexcept;

   void set_row( size_t r, const Row& row );
   void set_col( size_t c, const Column& col );

   void set_rows( std::initializer_list<Row> il );
   void set_cols( std::initializer_list<Column> il );

   Column get_col( size_t col ) const;

   Matrix& operator+=( const Matrix& m );
   Matrix operator+( const Matrix& m ) const;

   Matrix& operator-=( const Matrix& m );
   Matrix operator-( const Matrix& m ) const;

   Matrix& operator*=( const Matrix& m );

   Matrix operator*( const Matrix& m ) const;

   Matrix& operator*=( T s );
   Matrix operator*( T s ) const;

   bool is_valid_row_index( size_t r ) const;
   bool is_valid_col_index( size_t c ) const;

protected:
   size_t index( size_t r, size_t c ) const;

public:
   T* m_; // The matrix of elements.
   size_t rcnt_; // The row count.
   size_t ccnt_; // The column count.
};


}
}

namespace nhill
{
namespace math
{

template<typename T, typename nhill::enable_if::is_math_type<T>* = nullptr> inline
auto operator*( const Matrix<T>& matrix, const Column<T>& col ) noexcept ->Column<T>
{
   using size_type = typename Matrix<T>::size_type;

   Column<T> rcol; // Return column
   rcol.fill( 0 );

   for( size_type r = 0; r < matrix.row_count(); ++r )
   {
      for( size_type c = 0; c < matrix.col_count(); ++c )
      {
         rcol[r] += matrix[r][c] * col[c];
      }
   }

   return rcol;
}

template<typename T, typename enable_if::is_math_type<T>* = nullptr> inline
auto operator*( const Row<T>& row, const Matrix<T>& matrix ) noexcept->Row<T>
{
   using size_type = typename Matrix<T>::size_type;

   Column<T> rrow; // Return row
   rrow.fill( 0 );

   for( size_type r = 0; r < matrix.row_count(); ++r )
   {
      for( size_type c = 0; c < matrix.col_count(); ++c )
      {
         rrow[c] += row[r] * matrix[r][c];
      }
   }

   return rrow;
}



template<typename T, typename nhill::enable_if::is_math_type<T>* ef> inline
auto transpose( const nhill::math::Matrix<T, ef>& m ) noexcept -> nhill::math::Matrix<T, ef>
{
   using size_type = typename nhill::math::Matrix<T, ef>::size_type;

   nhill::math::Matrix<T, ef> mt; // Transposed matrix

   for( size_type r = 0; r < m.row_count(); ++r )
   {
      for( size_type c = 0; c < m.col_count(); ++c )
      {
         mt[c][r] = m[r][c];
      }
   }

   return mt;
}

template<typename T, typename nhill::enable_if::is_math_type<T>* ef> inline
auto minor( const nhill::math::Matrix<T, ef>& m, size_t row, size_t col ) noexcept-> nhill::math::Matrix<T, ef>
{
   using size_type = typename nhill::math::Matrix<T, ef>::size_type;

   nhill::math::Matrix<T - 1 - 1, ef> minor;
   size_type mr = 0; // Row of minor matrix
   size_type mc = 0; // Col of minor matrix 

   for( size_type r = 0; r < m.row_count(); ++r )
   {
      if( r == row )
      {
         continue;
      }

      mc = 0;
      for( size_type c = 0; c < m.col_count(); ++c )
      {
         if( c == col )
         {
            continue;
         }

         minor[mr][mc] = m[r][c];
         ++mc;
      }

      ++mr;
   }

   return minor;
}

template<typename T, std::size_t N, typename nhill::enable_if::is_math_type<T>* = nullptr>
auto lu_decomposition( const nhill::math::Matrix<T> & m, int( &indx )[N], T & d )->nhill::math::Matrix<T>
{
   nhill::math::Matrix<double> a{m};
   int i, imax, j, k;
   T big, dum, sum, temp;
   T vv[N]{};

   d = 1.0;
   for( i = 0; i < N; i++ )
   {
      big = 0.0;
      for( j = 0; j < N; j++ )
         if( (temp = std::abs( a[i][j] )) > big ) big = temp;
      if( big == 0.0 ) throw std::exception( "Singular matrix in routine ludcmp" );
      vv[i] = 1.0f / big;
   }
   for( j = 0; j < N; j++ )
   {
      for( i = 0; i < j; i++ )
      {
         sum = a[i][j];
         for( k = 0; k < i; k++ ) sum -= a[i][k] * a[k][j];
         a[i][j] = sum;
      }
      big = 0.0;
      for( i = j; i < N; i++ )
      {
         sum = a[i][j];
         for( k = 0; k < j; k++ )
            sum -= a[i][k] * a[k][j];
         a[i][j] = sum;
         if( (dum = vv[i] * std::abs( sum )) >= big )
         {
            big = dum;
            imax = i;
         }
      }
      if( j != imax )
      {
         for( k = 0; k < N; k++ )
         {
            dum = a[imax][k];
            a[imax][k] = a[j][k];
            a[j][k] = dum;
         }
         d = -(d);
         vv[imax] = vv[j];
      }
      indx[j] = imax;
      if( a[j][j] == 0.0f ) a[j][j] = (std::numeric_limits<T>::min)();
      if( j != N )
      {
         dum = 1.0f / (a[j][j]);
         for( i = j + 1; i < N; i++ ) a[i][j] *= dum;
      }
   }
   return a;
}

template<typename T, std::size_t N, typename nhill::enable_if::is_math_type<T>* = nullptr>
auto lu_backsubstitution( const nhill::math::Matrix<T> & a, int( &indx )[N], const nhill::math::Column<T> & b )->nhill::math::Column<T>
{
   nhill::math::Column<T> x{b};

   int i, ii = -1, ip, j;
   T sum;

   for( i = 0; i < N; i++ )
   {
      ip = indx[i];
      sum = x[ip];
      x[ip] = x[i];
      if( -1 < ii )
         for( j = ii; j <= i - 1; j++ ) sum -= a[i][j] * x[j];
      else if( sum ) ii = i;
      x[i] = sum;
   }
   for( i = N - 1; i >= 0; i-- )
   {
      sum = x[i];
      for( j = i + 1; j < N; j++ ) sum -= a[i][j] * x[j];
      x[i] = sum / a[i][i];
   }

   return x;
}

template<typename T, std::size_t N, typename nhill::enable_if::is_math_type<T>* ef>
auto det( const nhill::math::Matrix<T, ef>& m )->T
{
   T d{};
   int indx[N]{};

   nhill::math::Matrix<T> a = lu_decomposition<T, N>( m, indx, d );  // This returns d as +1 or -1.

   for( int j = 0; j < N; ++j )
   {
      d *= a[j][j];
   }

   return d;
}

template<typename T, std::size_t N, typename nhill::enable_if::is_math_type<T>* ef>
auto inverse( const nhill::math::Matrix<T>& m )->nhill::math::Matrix<T>
{
   nhill::math::Matrix<T, N, N> inv;
   nhill::math::Column<T, N> col;
   nhill::math::Column<T, N> x;
   T d{};
   int indx[N]{};
   int i, j;

   nhill::math::Matrix<T, N, N> lu = lu_decomposition<T, N>( m, indx, d );

   for( j = 0; j < N; ++j )
   {
      col.fill( 0 );
      col[j] = 1;

      x = lu_backsubstitution<T, N>( lu, indx, col );

      for( i = 0; i < N; ++i )
      {
         inv[i][j] = x[i];
      }
   }

   return inv;
}

template<typename T, std::size_t N, typename nhill::enable_if::is_math_type<T>* ef> inline
auto solve( nhill::math::Matrix<T> m, const nhill::math::Column<T>& b )->nhill::math::Column<T>
{
   T d{};
   int indx[N]{};

   nhill::math::Matrix<T> tmp{lu_decomposition<T,N>( m, indx, d )};
   nhill::math::Column<T> x{lu_backsubstitution<T,N>( tmp, indx, b )};

   return x;
}

template<typename T, std::size_t N, typename nhill::enable_if::is_math_type<T>* ef> inline
auto transform( const nhill::math::Matrix<T>& m, const nhill::math::Column<T>& v, const nhill::math::Column<T>& b ) noexcept->nhill::math::Column<T>
{
   nhill::math::Column<T> trans{(m * v) + b};
   return trans;
}

}
}



template<typename T, typename nhill::enable_if::is_math_type<T>* ef> inline
nhill::math::Matrix<T, ef>::Matrix( size_t row_count, size_t col_count, T value ) noexcept
   : m_{new T[row_count*col_count]}
   , rcnt_{row_count}
   , ccnt_{col_count}
{
   Expects( 0 < row_count );
   Expects( 0 < col_count );

   fill(value);
}

template<typename T, typename nhill::enable_if::is_math_type<T>* ef> inline 
nhill::math::Matrix<T, ef>::Matrix( std::initializer_list<Row> il )
{
   Expects( 0 < il.size() );

   set_rows( il );

   // Clear all of the remaining rows
   size_t r = static_cast<size_t>(il.size());
   for( ; r < row_count() ; ++r )
   {
      (*this)[r].fill( 0 );
   }

}

template<typename T, typename nhill::enable_if::is_math_type<T>* ef> inline
nhill::math::Matrix<T, ef>::Matrix( const Matrix& other) noexcept
   : m_{new T[other.rcnt_ * other.ccnt_]}
   , rcnt_{other.rcnt_}
   , ccnt_{other.ccnt_}
{
   operator=( other );
}

template<typename T, typename nhill::enable_if::is_math_type<T>* ef> inline
nhill::math::Matrix<T, ef>::Matrix( Matrix&& other ) noexcept
   : m_{other.m_ }
   , rcnt_{other.rcnt_}
   , ccnt_{other.ccnt_}
{
   other.m_ = nullptr;
   other.rcnt_ = 0;
   other.ccnt_ = 0;
}

template<typename T, typename nhill::enable_if::is_math_type<T>* ef> inline
nhill::math::Matrix<T, ef>::~Matrix() noexcept
{
   delete[] m_;
   m_ = nullptr;
   rcnt_ = 0;
   ccnt_ = 0;
}

template<typename T, typename nhill::enable_if::is_math_type<T>* ef> inline
auto nhill::math::Matrix<T, ef>::operator=( const Matrix& other ) noexcept->Matrix &
{
   Expects( rcnt_ == other.rcnt_ );
   Expects( ccnt_ == other.ccnt_ );

   size_t sz{rcnt_ * ccnt_};
   std::copy( other.m_, other.m_ + sz, m_ );

   return *this;
}

template<typename T, typename nhill::enable_if::is_math_type<T>* ef> inline
auto nhill::math::Matrix<T, ef>::operator=( Matrix&& other) noexcept->Matrix&
{
   Expects( rcnt_ == other.rcnt_ );
   Expects( ccnt_ == other.ccnt_ );
   
   delete[] m_;
   m_ = other.m_;
   other.m_ = nullptr;

   return *this;
}

template<typename T, typename nhill::enable_if::is_math_type<T>* ef> inline 
auto nhill::math::Matrix<T, ef>::operator[]( size_t r ) const->Row
{
   Expects( r < rcnt_ );

   Row row(ccnt_);
   size_t idx{index(r,0)};

   for( size_t c{0}; c < ccnt_; c++ )
   {
      row[c] = m_[idx++];
   }
   
   return row;
}

template<typename T, typename nhill::enable_if::is_math_type<T>* ef> inline 
auto nhill::math::Matrix<T, ef>::operator[]( const Index& idx )->T &
{
   Expects( idx.r < rcnt_ );
   Expects( idx.c < ccnt_ );

   size_t idx{index( idx.r, idx.c )};

   return m_[idx];
}

template<typename T, typename nhill::enable_if::is_math_type<T>* ef> inline 
auto nhill::math::Matrix<T, ef>::operator[]( const Index& idx ) const->const T &
{
   Expects( idx.r < rcnt_ );
   Expects( idx.c < ccnt_ );

   size_t idx{index( idx.r, idx.c )};
   
   return m_[idx];
}

template<typename T, typename nhill::enable_if::is_math_type<T>* ef> inline
size_t nhill::math::Matrix<T, ef>::col_count() const noexcept
{
   return rcnt_;
}

template<typename T, typename nhill::enable_if::is_math_type<T>* ef> inline
size_t nhill::math::Matrix<T, ef>::row_count() const noexcept
{
   return ccnt_;
}

template<typename T, typename nhill::enable_if::is_math_type<T>* ef> inline 
void nhill::math::Matrix<T, ef>::clear() noexcept
{
   fill( 0 );
}

template<typename T, typename nhill::enable_if::is_math_type<T>* ef> inline 
void nhill::math::Matrix<T, ef>::fill_row( size_t r, T value )
{
   Expects( r < rcnt_ );

   for( size_t idx{index( r, 0 )}, c{0}; c < ccnt_; idx++, c++ )
   {
      m_[idx] = value;
   }
}

template<typename T, typename nhill::enable_if::is_math_type<T>* ef> inline 
void nhill::math::Matrix<T, ef>::fill_col( size_t c, T value )
{
   Expects( c < ccnt_ );

   size_t idx{0};
   for( size_t r{0}; r < rcnt_; r++ )
   {
      idx = index( r, c );
      m_[idx] = value;
   }
}

template<typename T, typename nhill::enable_if::is_math_type<T>* ef> inline
void nhill::math::Matrix<T, ef>::fill( T value ) noexcept
{
   size_t sz{rcnt_ * ccnt_};
   std::for_each( m_, m_ + sz, [&value]( T& x ) { x = value; } );
}

template<typename T, typename nhill::enable_if::is_math_type<T>* ef> inline 
void nhill::math::Matrix<T, ef>::set_row( size_t r, const Row& row )
{
   Expects( r < rcnt_ );
   Expects( row.size() == ccnt_ );

   size_type idx{index( r, 0 )};
   for( const auto& value : row )
   {
      m_[idx++] = value;
   }
}

template<typename T, typename nhill::enable_if::is_math_type<T>* ef> inline
void nhill::math::Matrix<T, ef>::set_col( size_t c, const Column& col )
{
   Expects( c < ccnt_ );
   Expects( col.size() == rcnt_ );

   size_t r{0};
   size_t idx{index( r, c )};
   for( const auto& value : col )
   {
      m_[idx] = value;
      r++;
      idx = index( r, c );
   }
}

template<typename T, typename nhill::enable_if::is_math_type<T>* ef> inline 
void nhill::math::Matrix<T, ef>::set_rows( std::initializer_list<Row> il )
{
   Expects( il.size() == rcnt_ );

   size_t r{0};
   for( const auto& row : il)
   {
      set_row( r++, row );
   }
}

template<typename T, typename nhill::enable_if::is_math_type<T>* ef> inline 
void nhill::math::Matrix<T, ef>::set_cols( std::initializer_list<Column> il ) 
{
   Expects( il.size() == ccnt_ );

   size_t c{0};
   for( const auto& col: il )
   {
      set_col( c++, col );
   }
}

template<typename T, typename nhill::enable_if::is_math_type<T>* ef> inline
auto nhill::math::Matrix<T, ef>::get_col( size_t c ) const->Column
{
   Expects( c < ccnt_ );

   Column col;
   size_t idx{0};
   
   for( size_t r{0}; r < rcnt_; r++ )
   {
      idx = index( r, c );
      col[r] = m_[idx];
   }
   
   return col;
}

template<typename T, typename nhill::enable_if::is_math_type<T>* ef> inline
auto nhill::math::Matrix<T, ef>::operator+=( const Matrix& m )->Matrix &
{
   Expects( rcnt_ == m.rcnt_ );
   Expects( ccnt_ == m.ccnt_ );

   size_t sz{rcnt_ * ccnt_};
   for( size_t i{0} ; i < sz ; i++ )
   {
      m_[i] += m.m_[i];
   }

   return *this;
}

template<typename T, typename nhill::enable_if::is_math_type<T>* ef> inline
auto nhill::math::Matrix<T, ef>::operator+( const Matrix& m ) const->Matrix
{
   Matrix tmp{*this};
   tmp += m;
   return tmp;
}

template<typename T, typename nhill::enable_if::is_math_type<T>* ef> inline
auto nhill::math::Matrix<T, ef>::operator-=( const Matrix& m )->Matrix &
{
   Expects( rcnt_ == m.rcnt_ );
   Expects( ccnt_ == m.ccnt_ );

   size_t sz{rcnt_ * ccnt_};
   for( size_t i{0}; i < sz; i++ )
   {
      m_[i] -= m.m_[i];
   }

   return *this;
}

template<typename T, typename nhill::enable_if::is_math_type<T>* ef> inline
auto nhill::math::Matrix<T, ef>::operator-( const Matrix& m ) const->Matrix
{
   Matrix tmp{*this};
   tmp -= m;
   return tmp;
}

template<typename T, typename nhill::enable_if::is_math_type<T>* ef> inline
auto nhill::math::Matrix<T, ef>::operator*=( const Matrix& m )->Matrix &
{
   Expects(ccnt_ == m.rcnt_);
   Expects(ccnt_ == m.ccnt_);

   (*this) = (*this) * m;

   return *this;
}

template<typename T, typename nhill::enable_if::is_math_type<T>* ef>
auto nhill::math::Matrix<T, ef>::operator*( const Matrix& m2 ) const->Matrix
{
   Expects(ccnt_ == m2.rcnt_);

   const Matrix<T>& m1{ *this };
   Matrix<T> m{ rcnt_, m2.ccnt_ };

   for (size_t r = 0; r < rcnt_; ++r)
   {
      for (size_t c = 0; c < m2.ccnt_; ++c)
      {
         for (size_t n = 0; n < ccnt_; ++n)
         {
            m_[index(r, c)] += m1[index(r, n)] * m2[index(n, c)];
         }
      }
   }

   return m;
}

template<typename T, typename nhill::enable_if::is_math_type<T>* ef> inline
auto nhill::math::Matrix<T, ef>::operator*=( T s )->Matrix &
{
   size_t sz{ rcnt_ * ccnt_ };

   for (size_t i{ 0 } ; i < sz ; i++)
   {
      m_[i] *= s;
   }

   return *this;
}

template<typename T, typename nhill::enable_if::is_math_type<T>* ef> inline
auto nhill::math::Matrix<T, ef>::operator*( T s ) const->Matrix
{
   Matrix tmp{*this};
   tmp *= s;
   return tmp;
}

template<typename T, typename nhill::enable_if::is_math_type<T>* ef> inline
bool nhill::math::Matrix<T, ef>::is_valid_row_index(size_t r) const
{
   return 0 <= r && r < rcnt_;
}

template<typename T, typename nhill::enable_if::is_math_type<T>* ef> inline
bool nhill::math::Matrix<T, ef>::is_valid_col_index(size_t c) const
{
   return 0 <= c && c < ccnt_;
}

template<typename T, typename nhill::enable_if::is_math_type<T>* ef> inline
size_t nhill::math::Matrix<T, ef>::index( size_t r, size_t c ) const
{
   return r * ccnt_ + c;
}
