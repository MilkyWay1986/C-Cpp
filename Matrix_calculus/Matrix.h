#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include <utility>
#include <typeinfo>
#include <iostream>
#include <cmath>
#include <cassert>



namespace Matrix {

//*********************************class Matrix**************************************************************//
template<class T, class Tstruct>
  class Matrix {

  private:
    T* pmatrix ;
    Tstruct line ;
    Tstruct column ;

  public:
    Matrix() : line(0), column(0) { this->pmatrix = nullptr ; }

    Matrix( Tstruct n_eq_m, const char* = "E" ) : line(n_eq_m), column(n_eq_m) {
      if ( !this->IsSquareMatrix() ) { std::cout << "THIS MATRIX IS NOT SQUARE!" << std::endl ; exit(1) ; }

      pmatrix = new T [this->GET_LINE() * this->GET_COLUMN()];
      AssertArrayBoundaries( n_eq_m, n_eq_m ) ;
      for ( Tstruct i = 0 ; i < this->GET_LINE() ; i++ ){
        for ( Tstruct j = 0 ; j < this->GET_COLUMN() ; j++ ) {
          if ( i == j) this->pmatrix[(i) * this->GET_COLUMN() + j] = 1 ;
          else this->pmatrix[(i) * this->GET_COLUMN() + j] = 0 ; }
      }
    }

    Matrix( Tstruct lhs, Tstruct rhs ) : line(lhs), column(rhs) {
      this->pmatrix = new T [lhs*rhs];

      AssertArrayBoundaries( lhs, rhs ) ;
      for ( Tstruct i = 0 ; i < lhs ; i++ )
        for ( Tstruct j = 0 ; j < rhs ; j++ )
          this->pmatrix[(i) * rhs + j] = 0 ;
    }

    Matrix( Tstruct lhs, Tstruct rhs, T *_array ) : line(lhs), column(rhs) {
      this->pmatrix = new T [lhs*rhs];
      //T ( *arr )[rhs] = ( T (*)[rhs] ) _array;
      AssertArrayBoundaries( lhs, rhs ) ;
      for ( Tstruct i = 0 ; i < lhs ; i++ )
        for ( Tstruct j = 0 ; j < rhs ; j++ )
          this->pmatrix[(i) * rhs + j] = _array[(i) * rhs + j] ;
    }

    Matrix( const Matrix<T, Tstruct> &matrix_copy ) : line(matrix_copy.line), column(matrix_copy.column) {
      if( !IsMatrix() ) { std::cout << "THIS IS NOT MATRIX!" << std::endl ; exit(1) ; }
      this->pmatrix = new T [matrix_copy.line * matrix_copy.column ];
      AssertArrayBoundaries( matrix_copy.line, matrix_copy.column ) ;

      for ( Tstruct i = 0 ; i < matrix_copy.line ; i++ )
        for ( Tstruct j = 0 ; j < matrix_copy.column ; j++ )
          this->pmatrix[(i) * matrix_copy.column + j] = matrix_copy.pmatrix[(i) * matrix_copy.column + j] ;
    }

    virtual ~Matrix() {
      delete[] this->pmatrix;
      //std::cout << std::endl << "MATRIX WAS BE DISTRUCT!" << std::endl ;
    }

    void AssertArrayBoundaries( Tstruct lhs, Tstruct rhs) {
      assert( lhs >= 0 && rhs <= this->GET_COLUMN() ) ;
    }


    Tstruct GET_LINE  () const { return line ; }
    Tstruct GET_COLUMN() const { return column ; }
        virtual T* GET_MATRIX() const { return pmatrix ; }


       void SET_LINE  ( Tstruct _line )   { line = _line ; }
       void SET_COLUMN( Tstruct _column ) { column = _column ; }
       void SET_PMATRIX( Tstruct _size ) { delete pmatrix ; pmatrix = new T[_size] ; }


    void PrintMatrix() const {
      for ( Tstruct i = 0 ; i < this->GET_LINE() ; i++ ) {
        std::cout << std::endl ;
        for ( Tstruct j = 0 ; j < this->GET_COLUMN() ; j++ )
          std::cout << this->pmatrix[(i) * this->GET_COLUMN() + j] << "\t"; }
      std::cout << std::endl ;std::cout << std::endl ;std::cout << std::endl ;
    }

    bool IsMatrix() {
      const std::type_info &ti = typeid( *this ) ;
      if ( ti == typeid( Matrix<T, Tstruct> ) ) return 1 ;
        return 0 ;
    }
    bool IsSquareMatrix() {
      if ( !this->IsMatrix()) { std::cout << "THIS IS NOT MATRIX!" << std::endl ; exit(1) ; }
      if ( this->GET_LINE() != this->GET_COLUMN() ) return 0 ;
      return 1;
    }


    T Determinant() {
      if ( !this->IsSquareMatrix() ) { std::cout << "THIS MATRIX IS NOT SQUARE!" << std::endl ; exit(1) ; }

      T det = 1;
      Tstruct i, j, k, r ;
      T _max, c, M, s ;
      //AssertArrayBoundaries( this->GET_LINE, this->GET_LINE ) ;

      T** a = new T *[this->GET_LINE()] ;
      for( i = 0 ; i < this->GET_LINE() ; i++ ) a[i] = new T [this->GET_LINE()] ;

      for( i = 0 ; i < this->GET_LINE() ; i++)
        for( j = 0 ; j < this->GET_LINE() ; j++ ) a[i][j] = this->pmatrix[(i) * this->GET_LINE() + j];

      for( k = 0 ; k < this->GET_LINE() ; k++ ) {
        _max = fabs( a[k][k] ) ;
        r = k ;
      for( i = k + 1 ; i < this->GET_LINE() ; i++ )
          if(fabs(a[i][k])>_max){
            _max=fabs(a[i][k]);
            r=i;
          }
          if( r != k ) det =- det;
          for( j = 0 ; j < this->GET_LINE() ; j++ ) {
            c = a[k][j] ;
            a[k][j] = a[r][j] ;
            a[r][j] = c ;
          }
          for( i = k + 1 ; i < this->GET_LINE() ; i++ )
            for( M = a[i][k] / a[k][k] , j = k ; j < this->GET_LINE() ; j++ )
              a[i][j] -= M * a[k][j] ;
       }
          for( i = 0 ; i < this->GET_LINE() ; i++ )
            det *= a[i][i] ;

/**/  for( i = 0 ; i < this->GET_LINE() ; i++ ) delete[] a[i]  ;
      delete []a;

      return det ;
    }

    Matrix<T, Tstruct>& InverseMatrix() {
      if( !this->IsSquareMatrix() ) { std::cout << "THIS MATRIX IS NOT SQUARE!" << std::endl ; exit(1) ; }
      else if ( this->Determinant() <= 0 ) { std::cout << "DETERMINANT THIS MATRIX IS SO BAD, NO SOLUTIONS!" << std::endl ; exit(1) ; }
        T temp;
        T** E = new T* [this->GET_LINE()];
        for( Tstruct i = 0; i < this->GET_LINE() ; i++ ) E[i] = new T [this->GET_LINE()] ;

        for( Tstruct i = 0 ; i < this->GET_LINE() ; i++ ){
          for( Tstruct j = 0 ; j < this->GET_LINE() ; j++ ) {
            if( i == j ) E[i][j] = 1 ;
            else E[i][j] = 0 ; }
        }

        for( Tstruct k = 0 ; k < this->GET_LINE() ; k++ ) {
          temp = this->pmatrix[(k) * this->GET_LINE() + k] ;
          for( Tstruct j = 0 ; j < this->GET_LINE() ; j++ ) {
            this->pmatrix[(k) * this->GET_LINE() + j] /= temp ;
            E[k][j] /= temp ; }

          for( Tstruct i = k + 1 ; i < this->GET_LINE() ; i++ ) {
            temp = this->pmatrix[(i) * this->GET_LINE() + k] ;
            for( Tstruct j = 0 ; j < this->GET_LINE() ; j++ ) {
              this->pmatrix[(i) * this->GET_LINE() + j] -=  this->pmatrix[(k) * this->GET_LINE() + j] * temp ;
              E[i][j] -= E[k][j] * temp ; }
          }
        }

        for( Tstruct k = this->GET_LINE() - 1 ; k > 0 ; k-- ) {
          for( Tstruct i = k - 1 ; i >= 0 ; i-- ) {
           temp = this->pmatrix[(i) * this->GET_LINE() + k] ;
            for( Tstruct j = 0 ; j < this->GET_LINE() ; j++ ) {
              this->pmatrix[(i) * this->GET_LINE() + j] -=  this->pmatrix[(k) * this->GET_LINE() + j] * temp ;
              E[i][j] -= E[k][j] * temp ; }
          }
        }

        for( Tstruct i = 0 ; i < this->GET_LINE() ; i++ )
          for( Tstruct j = 0 ; j < this->GET_LINE() ; j++ )
            this->pmatrix[(i) * this->GET_LINE() + j] = E[i][j] ;

/**/  for( Tstruct i = 0 ; i < this->GET_LINE() ; i++ ) delete [] E[i] ;
      delete [] E;

      return *this ;
    }

    Matrix<T, Tstruct>& Transpose() {
      if( !this->IsMatrix() ) { std::cout << "THIS IS NOT MATRIX!" << std::endl ; exit(1) ; }

      Matrix<T, Tstruct> *pmatrix_transpose =  new Matrix<T, Tstruct>( this->column, this->line ) ;
      for ( Tstruct i = 0 ; i < this->GET_COLUMN() ; i++ ) {
        std::cout << std::endl ;
         for ( Tstruct j = 0 ; j < this->GET_LINE() ; j++ ){
          pmatrix_transpose->pmatrix[(i) * this->GET_COLUMN() + j] =  this->pmatrix[(j) * this->GET_COLUMN() + i]  ;
         }
      }

/**/
      return *pmatrix_transpose ;
    }


    Matrix<T, Tstruct>& operator*( T &number ) {
      number = static_cast<T>(number) ;
      AssertArrayBoundaries( this->GET_LINE(), this->GET_COLUMN() ) ;
      for( Tstruct i = 0 ; i < this->GET_LINE() ; i++ ){
        for( Tstruct j = 0 ; j < this->GET_COLUMN() ; j++ ){
          this->pmatrix[(i) * this->GET_COLUMN() + j] = this->pmatrix[(i) * this->GET_COLUMN() + j] * number ;
        }
      }
      return *this ;
    }

    Matrix<T, Tstruct>& operator*( Matrix<T, Tstruct> &other ) {
      if( !other.IsMatrix() ) { std::cout << "THIS IS NOT MATRIX!" << std::endl ; exit(1) ; }
      else if( this->GET_COLUMN() != other.GET_LINE() ) {
        std::cout << "THE NUMBER OF COLUMNS OF THE FIRST MATRIX WILL BE SIMILAR\n"
                     "TO THE NUMBER OF ROWS OF THE SECOND MATRIX" << std::endl ; exit(1) ; }

        Matrix<T, Tstruct> *result = new Matrix<T, Tstruct>(this->GET_LINE(), other.GET_COLUMN()) ;
        //AssertArrayBoundaries( this->GET_LINE, this->GET_COLUMN ) ;
        for( Tstruct i = 0 ; i < this->GET_LINE() ; i++ )
          for( Tstruct j = 0; j < other.GET_COLUMN() ; j++ ) {
            T Sum = 0 ;
          for ( Tstruct n = 0; n < other.GET_LINE() ; n++ ){
            Sum += this->pmatrix[(i) * this->GET_COLUMN() + n] * other.pmatrix[(n) * this->GET_COLUMN() + j];
          }
          result->pmatrix[(i) * this->GET_COLUMN() + j] = Sum ;
         }
/**/
      return *result  ;
    }

    Matrix<T, Tstruct>& operator+( Matrix<T, Tstruct> &other ) {
      if( !other.IsMatrix() ) { std::cout << "THIS IS NOT MATRIX!" << std::endl ; exit(1) ; }
      else if( this->GET_LINE() != other.GET_LINE() || this->GET_COLUMN() != other.GET_COLUMN() ){
        std::cout << "MATRIX'S WILL BE ONE SIZE!" ; exit(1) ; }

        Matrix<T, Tstruct> *ptemp_matrix = new Matrix<T, Tstruct>( other.line, other.column ) ;

        AssertArrayBoundaries(other.GET_LINE(), other.GET_COLUMN() ) ;
        for( Tstruct i = 0 ; i < ptemp_matrix->GET_LINE() ; i++ )
          for( Tstruct j = 0 ; j < ptemp_matrix->GET_COLUMN() ; j++ )
           ptemp_matrix->pmatrix[(i) * ptemp_matrix->GET_COLUMN() + j] = this->pmatrix[(i) * ptemp_matrix->GET_COLUMN() + j] +
                                                                other.pmatrix[(i) * ptemp_matrix->GET_COLUMN() + j] ;
      return *ptemp_matrix ;
    }

    Matrix<T, Tstruct>& operator=( Matrix<T, Tstruct> &other ) {
      if( !other.IsMatrix() ) { std::cout << "THIS IS NOT MATRIX!" << std::endl ; exit(1) ; }
      else if( this != &other ) {

        delete this->pmatrix ;
        //AssertArrayBoundaries( this->GET_LINE, this->GET_COLUMN ) ;

        this->pmatrix = new T [other.line * other.column] ;
        this->SET_LINE( other.line ) ;
        this->SET_COLUMN( other.column ) ;


        //AssertArrayBoundaries( this->GET_LINE, this->GET_COLUMN ) ;
        for( Tstruct i = 0 ; i < this->GET_LINE() ; i++ )
          for( Tstruct j = 0 ; j < this->GET_COLUMN() ; j++ )
            this->pmatrix[(i) * this->GET_COLUMN() + j] = other.pmatrix[(i) * this->GET_COLUMN() + j] ;

      return *this ;
      } else {
        //AssertArrayBoundaries( this->GET_LINE, this->GET_COLUMN ) ;
        for( Tstruct i = 0 ; i < this->GET_LINE() ; i++ )
          for( Tstruct j = 0 ; j < this->GET_COLUMN() ; j++ )
            this->pmatrix[(i) * this->GET_COLUMN() + j] = other.pmatrix[(i) * this->GET_COLUMN() + j] ;

      return *this ;
      }
    }


  friend std::ostream& operator<<( std::ostream&, const Matrix<T, Tstruct>& ) ;


} ;
//*********************************class Matrix**************************************************************//

template<class T, class Tstruct>
  std::ostream& operator<<( std::ostream &os, const Matrix<T, Tstruct> &other ) {
  if( !other.IsMatrix() ) { std::cout << "THIS IS NOT MATRIX!" << std::endl ; exit(1) ; }

  //AssertArrayBoundaries( other.GET_LINE, other.GET_COLUMN ) ;
  for( Tstruct i = 0 ; i < other.GET_LINE() ; i++ ){
    std::cout << std::endl ;
    for( Tstruct j = 0 ; j < other.GET_COLUMN() ; j++ )
      os << other.pmatrix[(i - 1) * other.GET_COLUMN() + j] << "\t"; }
  return os ;
}


} //namespace Matrix

#endif // MATRIX_H_INCLUDED
