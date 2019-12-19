#ifndef MATRIXCALCULUS_H_INCLUDED
#define MATRIXCALCULUS_H_INCLUDED

#include "Matrix.h"
#include "ConsoleInputOutput.h"
#include "FileInputOutput.h"


namespace MatrixCalculus {

//*********************************************class MatrixCalculus**********************************************************************************//
template <class T, class Tstruct>
  class MatrixCalculus : public Matrix::Matrix<T, Tstruct>,
                         public ConsoleInputOutput::ConsoleInputOutput<T, Tstruct>,
                         public FileInputOutput::FileInputOutput<T, Tstruct> {

  protected:
    Matrix::Matrix<T, Tstruct> *matrix ;

    bool InputConsole =  false ;
    bool OutputConsole = false ;
    bool InputFile  = false ;
    bool OutputFile = false ;


  public:
    MatrixCalculus( bool _InputConsole , bool _OutputConsole, bool _InputFile, bool _OutputFile )
      : InputConsole( _InputConsole ) , OutputConsole( _OutputConsole ), InputFile( _InputFile ), OutputFile( _OutputFile ) {
        if( InputConsole ) {
          ConsoleInputOutput::ConsoleInputOutput<T, Tstruct> *CI = new ConsoleInputOutput::ConsoleInputOutput<T, Tstruct>() ;
          this->matrix = &CI->Input() ;
        }
        else if( InputFile ) {
          FileInputOutput::FileInputOutput<T, Tstruct> *FI = new FileInputOutput::FileInputOutput<T, Tstruct>() ;
          FI->SET_FILE() ;
          this->matrix = &FI->Input() ;
        }
        else if( OutputFile ) {
          FileInputOutput::FileInputOutput<T, Tstruct> *FI = new FileInputOutput::FileInputOutput<T, Tstruct>() ;
        }
    }

    MatrixCalculus( const MatrixCalculus<T, Tstruct> &copy_matrix ) {}
    virtual ~MatrixCalculus() { std::cout << std::endl << std::endl << "Работа завершена. " <<std::endl; }

    Matrix::Matrix<T, Tstruct>& GET_MATRIX() const { return *matrix ; }
    void SET_MATRIX ( Matrix::Matrix<T, Tstruct>& m ) { matrix = &m ; }


    MatrixCalculus<T, Tstruct>& operator=( const MatrixCalculus<T, Tstruct> &rhs ) {}


} ;
//*********************************************class MatrixCalculus**********************************************************************************//

} //namespace MatrixCalculus

#endif // MATRIXCALCULUS_H_INCLUDED
