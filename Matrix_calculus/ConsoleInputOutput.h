#ifndef CONSOLEINPUTOUTPUT_H_INCLUDED
#define CONSOLEINPUTOUTPUT_H_INCLUDED


#include "Matrix.h"

namespace ConsoleInputOutput {

//*************************class ConsoleInputOutput******************************************************//
template <class T, class Tstruct>
  class ConsoleInputOutput {

  public:
    ConsoleInputOutput() {}
    ConsoleInputOutput( const ConsoleInputOutput<T, Tstruct>& ) {}
    virtual ~ConsoleInputOutput() {}

    Matrix::Matrix<T, Tstruct>& Input() {
      Tstruct line ;
      Tstruct column ;

      std::cout << "Введите число строк в матрице и нажмите 'Enter' " << std::endl ;
      line = abs( getValue() );

      std::cout << "Введите число столбцов в матрице и нажмите 'Enter' " << std::endl ;
      column = abs( getValue() );

      std::cout << "Ввод значений матрицы: " << std::endl ;
      T a[line * column] ;
      for( Tstruct i = 0 ; i < line ; i ++)
        for ( Tstruct j = 0 ; j < column ; j ++) {
          std::cout << "Ввведите элемент и нажмите 'Enter' a[" << i << "][" << j << "]  =  " ;
          a[i * column + j] = getValue() ;
        }

      /*std::cout << "Вы ввели следующую матрицу: " << std::endl ;
      for ( Tstruct i = 0 ; i < line ; i ++ ) {
        std::cout << std::endl ;
        for (Tstruct j = 0 ; j < column ; j++ )
          std::cout << a[(i) * column + j] << "\t" ; }*/
      Matrix::Matrix<T, Tstruct> *mtrx = new Matrix::Matrix<T, Tstruct>( line, column,a ) ;
    return *mtrx ;
    }
    double getValue() {
      while ( true ) {
        std::cout << ": ";
        double a;
        std::cin >> a;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            std::cout << "Не корректный ввод, повторите попытку и нажмите 'Enter ";
        }else {
            std::cin.ignore(32767,'\n');
            return a; }
      }
    }
    void Output( const Matrix::Matrix<T, Tstruct> &matrix) const {
      std::cout <<"********************************" << std::endl ;
      std::cout << "MATRIX SIZE :" << std::endl ;
      std::cout << matrix.GET_LINE() << " x " << matrix.GET_COLUMN() << std::endl ;
      std::cout << "ARRAY INITIALIZATION: " << std::endl ;
      for ( Tstruct i = 0 ; i < matrix.GET_LINE() ; i++ ) {
        std::cout << std::endl ;
        for ( Tstruct j = 0 ; j < matrix.GET_COLUMN() ; j++ )
          std::cout << matrix[i][j] << "\t"; }
      std::cout << std::endl ;
      std::cout <<"********************************" ;
      std::cout << std::endl ;std::cout << std::endl ;
    }

} ;
//*************************class ConsoleInputOutput******************************************************//

} //namespace ConsoleInputOutput


#endif // CONSOLEINPUTOUTPUT_H_INCLUDED
