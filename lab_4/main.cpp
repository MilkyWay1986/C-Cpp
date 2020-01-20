#include <iostream>

#include "class_Base_poisk.h"
#include "class_Met_xord.h"
#include "class_Met_Newton.h"
#include "class_Half_divis.h"
#include "Baza_func.h"

void _print (int i, double a, double b, double esp ){
  std::cout << "Для функции #" << i+1;
  std::cout << " на интервале (" << a << ", " << b << ") c точностью esp = " << esp ;
  std::cout << " вычисленно по методу ";
}


int main (){


  double a, b, esp ;
  a = 0.5 ;
  b = 1.5 ;
  esp = 0.001 ;

  Baza_poisk::Baza_poisk *bp[3] ;
  Baza_func::f mas_f[] = { Baza_func::f0, Baza_func::f1, Baza_func::f2} ;

  for (int64_t i = 0 ; i < (sizeof(mas_f)/sizeof(mas_f[0])) ; i++ ){

    bp[0] = new Met_xord::Met_xord( a, b ) ;
    _print (i, a, b, esp ) ;
    std::cout << " Хорд: " << bp[0]->poisk( mas_f[i], esp )<< std::endl ;

    bp[1] = new Met_Newton::Met_Newton( a, b ) ;
    _print (i, a, b, esp ) ;
    std::cout << " Ньютона: " << bp[1]->poisk(mas_f[i], esp )<< std::endl ;

    bp [2]= new Half_divis::Half_divis( a, b ) ;
    _print (i, a, b, esp ) ;
    std::cout << " Половинного деления: " << bp[2]->poisk(mas_f[i], esp )<< std::endl ;
  std::cout << std::endl ;std::cout << std::endl ;std::cout << std::endl ;
  }
  delete *bp ;

return 0 ;
}
