#include <iostream>


#include "MatrixCalculus.h"



int main () {

std::cout << "ДОБРО ПОЖАЛОВАТЬ В ОПЕРАЦИИ С МАТРИЦАМИ: " << std::endl << std::endl ;
while(1){
  std::cout << " Сложить две матрицы    \t нажмите 1 и затем ENTER:" << std::endl ;
  std::cout << " Умножить две матрицы    \t нажмите 2 и затем ENTER:" << std::endl ;
  std::cout << " Умножить матрицу на число \t нажмите 3 и затем ENTER:" << std::endl ;
  std::cout << " Найти определитель матрицы \t нажмите 4 и затем ENTER:" << std::endl ;
  std::cout << " Найти обратную матрицу \t нажмите 5 и затем ENTER:" << std::endl ;
  std::cout << " Транспонировать матрицу \t нажмите 6 и затем ENTER:" << std::endl ;
  std::cout << " Выход                    \t нажмите 7 и затем ENTER:" << std::endl ;
  size_t operation = 0 ;
  size_t operation_2 = 0 ;
  std::cout <<": " ;std::cin >> operation ;
  std::cout <<  std::endl ;
  if( operation == 7 ) exit(1) ;
  switch ( static_cast<size_t>(operation) ) {

    case 1 :
      {
        std::cout << "Вести первую матрицу с клавиатуры \t нажмите 1 и затем ENTER:" << std::endl ;
        std::cout << "Вести первую матрицу из файла     \t нажмите 2 и затем ENTER:" << std::endl ;
        std::cout <<": " ; std::cin >> operation_2 ;
        std::cout <<  std::endl ;
        MatrixCalculus::MatrixCalculus<double, int64_t> *MC ;
        Matrix::Matrix<double, int64_t> mtrx1 = Matrix::Matrix<double, int64_t>() ;
        Matrix::Matrix<double, int64_t> mtrx2 = Matrix::Matrix<double, int64_t>() ;

        if( operation_2 == 1 ){
          MC = new MatrixCalculus::MatrixCalculus<double, int64_t> (1,0,0,0) ;
          mtrx1 = MC->GET_MATRIX() ;
          mtrx1.PrintMatrix() ;
        }
        else if( operation_2 == 2 ){
          MC = new MatrixCalculus::MatrixCalculus<double, int64_t> (0,0,1,0) ;
          mtrx1 = MC->GET_MATRIX() ;
          mtrx1.PrintMatrix() ;
        }
        else { std::cout << "Ошибка ввода!" << std::endl ; exit(1) ; }

        std::cout << "Вести вторую матрицу с клавиатуры \t нажмите 1 и затем ENTER:" << std::endl ;
        std::cout << "Вести вторую матрицу из файла     \t нажмите 2 и затем ENTER:" << std::endl ;
        std::cout <<": " ; std::cin >> operation_2 ;
        std::cout <<  std::endl ;
        if( operation_2 == 1 ){
          MC = new MatrixCalculus::MatrixCalculus<double, int64_t> (1,0,0,0) ;
          mtrx2 = MC->GET_MATRIX() ;
          mtrx2.PrintMatrix() ;
        }
        else if( operation_2 == 2 ){
          MC = new MatrixCalculus::MatrixCalculus<double, int64_t> (0,0,1,0) ;
          mtrx2 = MC->GET_MATRIX() ;
          mtrx2.PrintMatrix() ;
        }
        else { std::cout << "Ошибка ввода!" << std::endl ; exit(1) ; }

        Matrix::Matrix<double, int64_t>  c = Matrix::Matrix<double, int64_t>();
        c = ( mtrx1 + mtrx2 ) ;

        std::cout << "Вывести результат в файл \t нажмите 1 и затем ENTER:" << std::endl ;
        std::cout << "Вывести результат в консоль \t нажмите 2 и затем ENTER:" << std::endl ;
        std::cout <<": " ; std::cin >> operation_2 ;
        std::cout <<  std::endl ;
        if( operation_2 == 1 ) {
          MC = new MatrixCalculus::MatrixCalculus<double, int64_t> (0,0,0,1) ;
          MC->SET_MATRIX(c) ;
          MC->FileInputOutput::Output( &MC->GET_MATRIX() ) ;
        }else if ( operation_2 == 2 ){
          std::cout << "Результат сложения матриц: " << std::endl << "\t"; c.PrintMatrix();
        }else { std::cout << "Не выбрано!" ; exit(1); }
        delete MC ;
      } break;
    case 2 :
      {
        std::cout << "Вести первую матрицу с клавиатуры \t нажмите 1 и затем ENTER:" << std::endl ;
        std::cout << "Вести первую матрицу из файла     \t нажмите 2 и затем ENTER:" << std::endl ;
        std::cout <<": " ; std::cin >> operation_2 ;
        std::cout <<  std::endl ;
        MatrixCalculus::MatrixCalculus<double, int64_t> *MC ;
        Matrix::Matrix<double, int64_t> mtrx1 = Matrix::Matrix<double, int64_t>() ;
        Matrix::Matrix<double, int64_t> mtrx2 = Matrix::Matrix<double, int64_t>() ;

        if( operation_2 == 1 ){
          MC = new MatrixCalculus::MatrixCalculus<double, int64_t> (1,0,0,0) ;
          mtrx1 = MC->GET_MATRIX() ;
          mtrx1.PrintMatrix() ;
        }
        else if( operation_2 == 2 ){
          MC = new MatrixCalculus::MatrixCalculus<double, int64_t> (0,0,1,0) ;
          mtrx1 = MC->GET_MATRIX() ;
          mtrx1.PrintMatrix() ;
        }
        else { std::cout << "Ошибка ввода!" << std::endl ; exit(1) ; }

        std::cout << "Вести вторую матрицу с клавиатуры \t нажмите 1 и затем ENTER:" << std::endl ;
        std::cout << "Вести вторую матрицу из файла     \t нажмите 2 и затем ENTER:" << std::endl ;
        std::cout <<": " ; std::cin >> operation_2 ;
        std::cout <<  std::endl ;
        if( operation_2 == 1 ){
          MC = new MatrixCalculus::MatrixCalculus<double, int64_t> (1,0,0,0) ;
          mtrx2 = MC->GET_MATRIX() ;
          mtrx2.PrintMatrix() ;
        }
        else if( operation_2 == 2 ){
          MC = new MatrixCalculus::MatrixCalculus<double, int64_t> (0,0,1,0) ;
          mtrx2 = MC->GET_MATRIX() ;
          mtrx2.PrintMatrix() ;
        }
        else { std::cout << "Ошибка ввода!" << std::endl ; exit(1) ; }

        Matrix::Matrix<double, int64_t>  c = Matrix::Matrix<double, int64_t>();
        c = ( mtrx1 * mtrx2 ) ;

        std::cout << "Вывести результат в файл \t нажмите 1 и затем ENTER:" << std::endl ;
        std::cout << "Вывести результат в консоль \t нажмите 2 и затем ENTER:" << std::endl ;
        std::cout <<": " ; std::cin >> operation_2 ;
        std::cout <<  std::endl ;
        if( operation_2 == 1 ) {
          MC = new MatrixCalculus::MatrixCalculus<double, int64_t> (0,0,0,1) ;
          MC->SET_MATRIX(c) ;
          MC->FileInputOutput::Output( &MC->GET_MATRIX() ) ;
        }else if ( operation_2 == 2 ){
          std::cout << "Результат умножения матриц: " << std::endl << "\t"; c.PrintMatrix();
        }else { std::cout << "Не выбрано!" ; exit(1); }
        delete MC ;
      } break;
    case 3 :
      {
        std::cout << "Вести  матрицу с клавиатуры \t нажмите 1 и затем ENTER:" << std::endl ;
        std::cout << "Вести  матрицу из файла     \t нажмите 2 и затем ENTER:" << std::endl ;
        std::cout <<": " ; std::cin >> operation_2 ;
        std::cout <<  std::endl ;
        MatrixCalculus::MatrixCalculus<double, int64_t> *MC ;
        Matrix::Matrix<double, int64_t> mtrx1 = Matrix::Matrix<double, int64_t>() ;

        if( operation_2 == 1 ){
          MC = new MatrixCalculus::MatrixCalculus<double, int64_t> (1,0,0,0) ;
          mtrx1 = MC->GET_MATRIX() ;
          mtrx1.PrintMatrix() ;
        }
        else if( operation_2 == 2 ){
          MC = new MatrixCalculus::MatrixCalculus<double, int64_t> (0,0,1,0) ;
          mtrx1 = MC->GET_MATRIX() ;
          mtrx1.PrintMatrix() ;
        }
        else { std::cout << "Ошибка ввода!" << std::endl ; exit(1) ; }

        std::cout << "Введите число:     \t " << std::endl ;
        double number = 0 ;
        std::cin >> number ;
        number = static_cast<double>(number) ;

        Matrix::Matrix<double, int64_t>  c = Matrix::Matrix<double, int64_t>();
        c = ( mtrx1 * number ) ;

        std::cout << "Вывести результат в файл \t нажмите 1 и затем ENTER:" << std::endl ;
        std::cout << "Вывести результат в консоль \t нажмите 2 и затем ENTER:" << std::endl ;
        std::cout <<": " ; std::cin >> operation_2 ;
        std::cout <<  std::endl ;
        if( operation_2 == 1 ) {
          MC = new MatrixCalculus::MatrixCalculus<double, int64_t> (0,0,0,1) ;
          MC->SET_MATRIX(c) ;
          MC->FileInputOutput::Output( &MC->GET_MATRIX() ) ;
        }else if ( operation_2 == 2 ){
          std::cout << "Результат умножения матрицы на число: " << std::endl << "\t"; c.PrintMatrix();
        }else { std::cout << "Не выбрано!" ; exit(1); }
        delete MC ;
      } break;
   case 4 :
      {
        std::cout << "Вести  матрицу с клавиатуры \t нажмите 1 и затем ENTER:" << std::endl ;
        std::cout << "Вести  матрицу из файла     \t нажмите 2 и затем ENTER:" << std::endl ;
        std::cout <<": " ; std::cin >> operation_2 ;
        std::cout <<  std::endl ;
        MatrixCalculus::MatrixCalculus<double, int64_t> *MC ;
        Matrix::Matrix<double, int64_t> mtrx1 = Matrix::Matrix<double, int64_t>() ;

        if( operation_2 == 1 ){
          MC = new MatrixCalculus::MatrixCalculus<double, int64_t> (1,0,0,0) ;
          mtrx1 = MC->GET_MATRIX() ;
          mtrx1.PrintMatrix() ;
        }
        else if( operation_2 == 2 ){
          MC = new MatrixCalculus::MatrixCalculus<double, int64_t> (0,0,1,0) ;
          mtrx1 = MC->GET_MATRIX() ;
          mtrx1.PrintMatrix() ;
        }
        else { std::cout << "Ошибка ввода!" << std::endl ; exit(1) ; }

        Matrix::Matrix<double, int64_t>  c = Matrix::Matrix<double, int64_t>();
        c = ( mtrx1 ) ;

        std::cout << "Определитель матрицы равен: "  << c.Determinant() << std::endl;
        delete MC ;
      } break;
     case 5 :
      {
        std::cout << "Вести  матрицу с клавиатуры \t нажмите 1 и затем ENTER:" << std::endl ;
        std::cout << "Вести  матрицу из файла     \t нажмите 2 и затем ENTER:" << std::endl ;
        std::cout <<": " ; std::cin >> operation_2 ;
        std::cout <<  std::endl ;
        MatrixCalculus::MatrixCalculus<double, int64_t> *MC ;
        Matrix::Matrix<double, int64_t> mtrx1 = Matrix::Matrix<double, int64_t>() ;

        if( operation_2 == 1 ){
          MC = new MatrixCalculus::MatrixCalculus<double, int64_t> (1,0,0,0) ;
          mtrx1 = MC->GET_MATRIX() ;
          mtrx1.PrintMatrix() ;
        }
        else if( operation_2 == 2 ){
          MC = new MatrixCalculus::MatrixCalculus<double, int64_t> (0,0,1,0) ;
          mtrx1 = MC->GET_MATRIX() ;
          mtrx1.PrintMatrix() ;
        }
        else { std::cout << "Ошибка ввода!" << std::endl ; exit(1) ; }

        Matrix::Matrix<double, int64_t>  c = Matrix::Matrix<double, int64_t>();
        c = ( mtrx1 ) ;
        c.InverseMatrix() ;


        std::cout << "Вывести результат в файл \t нажмите 1 и затем ENTER:" << std::endl ;
        std::cout << "Вывести результат в консоль \t нажмите 2 и затем ENTER:" << std::endl ;
        std::cout <<": " ; std::cin >> operation_2 ;
        std::cout <<  std::endl ;
        if( operation_2 == 1 ) {
          MC = new MatrixCalculus::MatrixCalculus<double, int64_t> (0,0,0,1) ;
          MC->SET_MATRIX(c) ;
          MC->FileInputOutput::Output( &MC->GET_MATRIX() ) ;
        }else if ( operation_2 == 2 ){
          std::cout << "Обратная матрица равна: "  <<" \t"<< std::endl; c.PrintMatrix() ;
        }else { std::cout << "Не выбрано!" ; exit(1); }
        delete MC ;
      } break;
    case 6 :
      {
        std::cout << "Вести  матрицу с клавиатуры \t нажмите 1 и затем ENTER:" << std::endl ;
        std::cout << "Вести  матрицу из файла     \t нажмите 2 и затем ENTER:" << std::endl ;
        std::cout <<": " ; std::cin >> operation_2 ;
        std::cout <<  std::endl ;
        MatrixCalculus::MatrixCalculus<double, int64_t> *MC ;
        Matrix::Matrix<double, int64_t> mtrx1 = Matrix::Matrix<double, int64_t>() ;

        if( operation_2 == 1 ){
          MC = new MatrixCalculus::MatrixCalculus<double, int64_t> (1,0,0,0) ;
          mtrx1 = MC->GET_MATRIX() ;
          mtrx1.PrintMatrix() ;
        }
        else if( operation_2 == 2 ){
          MC = new MatrixCalculus::MatrixCalculus<double, int64_t> (0,0,1,0) ;
          mtrx1 = MC->GET_MATRIX() ;
          mtrx1.PrintMatrix() ;
        }
        else { std::cout << "Ошибка ввода!" << std::endl ; exit(1) ; }

        Matrix::Matrix<double, int64_t>  c = Matrix::Matrix<double, int64_t>();
        c = mtrx1.Transpose() ;

        std::cout << "Вывести результат в файл \t нажмите 1 и затем ENTER:" << std::endl ;
        std::cout << "Вывести результат в консоль \t нажмите 2 и затем ENTER:" << std::endl ;
        std::cout <<": " ; std::cin >> operation_2 ;
        std::cout <<  std::endl ;
        if( operation_2 == 1 ) {
          MC = new MatrixCalculus::MatrixCalculus<double, int64_t> (0,0,0,1) ;
          MC->SET_MATRIX(c) ;
          MC->FileInputOutput::Output( &MC->GET_MATRIX() ) ;
        }else if ( operation_2 == 2 ){
           std::cout << "Транспонированая матрица равна: "  <<" \t" ; c.PrintMatrix() ;
        }else { std::cout << "Не выбрано!" ; exit(1); }
        delete MC ;
      } break;
    default : std::cout << "Введите корректный номер операции! " << std::endl<< std::endl<< std::endl<< std::endl ; break;
  }
}
return 0 ;
}


