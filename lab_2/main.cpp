#include "main.h"



int main(){
/*------------------------------------------------------------------------------------------------------------------*/
  double xc[] = {7,8,9,12,3,4,5,9,15,57} ;
  double yc[] = {11,23,2,4,5,16,7,18,19,4} ;
  double bc[] = {12,23,12,4,5,16,7,18,19,9} ;

  size_t n = 5 ;

  Point::Point   *b1 = new Point::Point [n]  ;
  Circle::Circle *b2 = new Circle::Circle [n] ;

  std::cout << "Инициализация окружностей: " << std::endl ;
  for ( size_t i = 0 ; i < n ; i++ ){

    b1[i] = Point::Point ( xc[i], yc[i] ) ;
    b2[i] = Circle::Circle ( b1[i], bc[i] ) ;
    std::cout << " Окружность # " << i+1 << " с координатами: ( " << xc[i] << ", " << yc[i] << " )" ;
    std::cout << " и радиусом равным " << bc[i] << std::endl ;
  }std::cout << std::endl ;

  std::cout << "Проверка на пересечение окружностей: " << std::endl ;
  for ( size_t i = 0 ; i < n -1 ; i++ )
   for ( size_t j = i + 1 ; j < n ; j++ ) {
    std::cout << " Окружность # " ;
    std::cout << i+1 << " и окружность # " << j+1 << _print( b2[i].Prov(b2[j]) ) << std::endl;
   } std::cout << std::endl;std::cout << std::endl;std::cout << std::endl;

  delete []b1 ;
  delete []b2 ;


  Baza_func::f mas_f[] = { Baza_func::f0, Baza_func::f1, Baza_func::f2, Baza_func::f3,
                           Baza_func::f4, Baza_func::f5, Baza_func::f5 } ;
  Baza_tab::Baza_tab *fv = new Baza_tab::Baza_tab ( 0, 80, 10 ) ;
//
//  fv->P() ;

  for (int64_t i = 0 ; i < (sizeof(mas_f) / sizeof(mas_f[0])) ; i++){
    std::cout << "Инициализация функции #" << i+1 << std::endl ;
    fv->Tabul_v(mas_f[i]) ;
    Point::Point *tv = fv->Tabul(mas_f[i]) ;
    for ( int64_t j = 0 ; j < fv->N() ; j++ ){
      std::cout << " Координаты точки #" << j+1 ;
      std::cout << "  ("<< tv[j].X() << ",  " << tv[j].Y() << " )"<< std::endl ;
    }std::cout << std::endl;std::cout << std::endl;std::cout << std::endl ;

  }
std::cout << "Деструкторо для Baza_tab()  " ;  fv->~Baza_tab();
std::cout << std::endl;std::cout << std::endl;std::cout << std::endl ;


size_t m = 1 ;
Interval_null::Interval_null **bf ;
bf = new Interval_null::Interval_null *[m] ;
Point::Point *tv ;
for( size_t k = 0 ; k < (sizeof(mas_f) / sizeof(mas_f[0])) ; k++ ){
  for( size_t i = 0 ; i < m ; i++ ) {
    bf[i] = new Interval_null::Interval_null( -1, 80, 10 ) ;
    bf[i]->Tabul_v( mas_f[k] ) ;
    tv  = bf[i]->Interwal_nul() ;
    std::cout << "Для функции #" << k+1 ;
    std::cout <<" количество интервалов нулей: "<< bf[i]->KOL_IN() << std::endl ;
    for ( size_t j = 0  ; j < bf[i]->KOL_IN(); j ++ ){
      std::cout <<"(" << tv[j].X() << ", " << tv[j].Y() <<")" << std::endl ;
    }
  }
  delete *bf ;
  std::cout << std::endl;std::cout << std::endl;std::cout << std::endl ;
}

return 0;
}
