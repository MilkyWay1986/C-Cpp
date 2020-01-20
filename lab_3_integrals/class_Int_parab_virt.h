#ifndef CLASS_INT_PARAB_VIRT_H_INCLUDED
#define CLASS_INT_PARAB_VIRT_H_INCLUDED

#include <cmath>
#include <iostream>

#include "class_Baza_Integ_virt.h"
#include "../lab_2/Baza_func.h"

namespace Int_parab_virt{
/***************************class Int_parab_virt***************************************************************/
class Int_parab_virt: public Baza_Integ_virt::Baza_Integ_virt{

  protected:
    double a, b ;
    Baza_func::f f ;
    int64_t n ;

  public:
    Int_parab_virt ():Baza_Integ_virt () { }
    Int_parab_virt ( double av, double bv, Baza_func::f ff):Baza_Integ_virt(){ a = av; b = bv; f = ff; n = 200 ; }
   ~Int_parab_virt () { std::cout << "Destruct Int_parab_virt!" << std::endl ; }

   double  A() const { return a ; }
   double  B() const { return b ; }
   int64_t N() const { return n ; }

  double Integral( double esp ) {
    double s, sp, h, x, y, d ;
    int64_t i ;

    sp = 0;
    d  = 1 ;

    while( fabs(d) > esp ){
      for( h = (b-a) / n, s = ( f(a) + f(b) ) * (h / 3), i = 1, x = a; i < n - 1; i++ ){
        x += h ;
        if( i%2 ) s += ( 2 * f(x) * (h / 3) ) ;
        else s += ( 4 * f(x) * (h / 3) ) ;
      }
      d = s - sp ; sp = s ; n *= 5 ;
    }
    //std::cout<< "Int_parab n " << n << "  s =  " << s << std::endl ;
    return s ;
  }
};
/***************************class Int_parab_virt***************************************************************/

} //namespace Int_parab_virt

#endif // CLASS_INT_PARAB_VIRT_H_INCLUDED
