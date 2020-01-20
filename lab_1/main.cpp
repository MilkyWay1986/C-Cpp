#include "main.h"


int main(){

    double xc[] = {7,8,9,12,3,4,5,9,15,57} ;
    double yc[] = {11,23,2,4,5,16,7,18,19,4} ;
    double kc[] = {1,8,1,12,3,4,5,9,15,57} ;
    double bc[] = {12,23,12,4,5,16,7,18,19,9} ;

    int n = 5;

    Point::Point *p = new Point::Point[n] ;
    Line ::Line  *l = new Line::Line [n] ;

    double x, y, k, b ;

    for ( size_t i = 0 ; i < n ;  i++ ){
      p[i] = Point::Point( xc[i], yc[i] );
      l[i] = Line ::Line ( kc[i], bc[i] );
    }

for( size_t i = 0 ; i < n ; i++ ){
  std::cout << "Координаты "; std::cout << i+1;
  std::cout << " точки " << "(" << p[i].X() << ", " << p[i].Y() << ")" << std::endl;
} std::cout << std::endl;


for ( size_t i = 0 ; i < n - 1 ; i++ )
   for ( size_t j = i + 1 ; j < n ; j++ ) {
      std::cout << "Расстояние между ";
      std::cout << i+1 << " и " << j+1 <<" точкой равно " << p[i].Rast_t(p[j]) << std::endl;
   } std::cout << std::endl;std::cout << std::endl;

for ( size_t i = 0 ; i < n ; i++ ) {
  std::cout << "Уравнение " << i+1 << " прямой, задано: y = " << l[i].K() << " * x + " << l[i].B() << std::endl;
} std::cout << std::endl;


for ( size_t i = 0 ; i < n ; i++ )
   for ( size_t j = 0 ; j < n ; j++ ) {
    std::cout << "Проверка пересечения:  " ;
    std::cout << i+1 << " точки и " << j+1 << " линии: "  << _print( p[i].Prov(l[j]) ) << std::endl;
} std::cout << std::endl;


for ( size_t i = 0 ; i < n -1 ; i++ )
   for ( size_t j = i + 1 ; j < n ; j++ ) {
    std::cout << "Проверка пересечения:  " ;
    std::cout << i+1 << " прямой и " << j+1 << "  прямой: "  << _print( l[i].Prov(l[j]) ) << std::endl;
} std::cout << std::endl;

delete []p ;
delete []l ;
return 0;
}
