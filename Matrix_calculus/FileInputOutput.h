#ifndef FILEINPUTOUTPUT_H_INCLUDED
#define FILEINPUTOUTPUT_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>


#include "Matrix.h"

namespace FileInputOutput {

//********************************class FileInputOutput**************************************************//
template <class T, class Tstruct>
  class FileInputOutput {

  private:
    std::string filename ;

  public:
    FileInputOutput() {}
    virtual ~FileInputOutput() {}

    std::string GET_FILE_NAME()  const { return filename ;  }
    void SET_FILE () {
      std::string file ;
      std::cout << "Введите имя файла: \n" ; std::cin >> file ;
      this->filename = file ;

    }

    Matrix::Matrix<T, Tstruct>& Input () {
      std::string file = GET_FILE_NAME() ;
      std::ifstream in( file,  std::ios_base::in);
      if( !in.is_open() ) {	std::cout << "THIS FILE IS NOT VALID! "; exit(1) ; }
      else{
        Tstruct counter = 0 ;
        Tstruct temp ;

        while (!in.eof()) {
          in >> temp;
          counter++;
        }

        in.clear();
        in.seekg(0);

        Tstruct line = 0 ;
        Tstruct columns = 0 ;
        T _array [counter-3] ;
        Tstruct i = 0 ;
        Tstruct j = 0 ;
        while ( !in.eof() && i < counter  ) {
          if ( i == 0  ) in >> line ;
          else if ( i == 1  ) in >> columns ;
          else if ( i > 1 ){
            in >> temp ;
            _array[j] = temp ;
            j++ ;
          }
          i++ ; }

          if ( line * columns != ( counter - 3 )  ) {
            std:: cout << "SIZE OF THE MATRIX IS NOT EQUAL TO THE NUMBER OF ITS ELEMENTS" << std::endl ; exit(1); }
          Matrix::Matrix<T, Tstruct> *mtrx = new Matrix::Matrix<T, Tstruct>( line, columns, _array) ;
          return *mtrx ;
      }in.close();

    }

    void Output(  Matrix::Matrix<T, Tstruct> *matrix ) {

      T *pm = matrix->GET_MATRIX() ;
      std::ofstream out("OUT_file", std::ios::app);

      if (out.is_open()) {
        out << matrix->GET_LINE() << std::endl;
        out << matrix->GET_COLUMN() << std::endl ;
        for (Tstruct i = 0 ; i < matrix->GET_LINE() ; i++ ) {
          for (Tstruct j = 0 ; j < matrix->GET_COLUMN() ; j++ ) {
            out << pm[i * matrix->GET_COLUMN() + j] << " " ; }
            out << std::endl ;
        }
      }else{ std::cout << "PROBLEM WITH FILE" << std::endl ; exit(1) ; }
      out.close();
      std::cout << "Результат вычислений был записан в файл: OUT_file" << std::endl ;
    }


} ;
//********************************class FileInputOutput**************************************************//


} //namespace FileInputOutput

#endif // FILEINPUTOUTPUT_H_INCLUDED
