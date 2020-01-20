#ifndef CLASS_MET_XORD_H_INCLUDED
#define CLASS_MET_XORD_H_INCLUDED

#include<cmath>

#include "class_Base_poisk.h"
#include "Baza_func.h"

namespace Met_xord{

/**************************Met_xord***********************************************************************************/
class Met_xord:public Baza_poisk::Baza_poisk{

  public:
    Baza_func::f f;

  Met_xord ( double av, double bv ):Baza_poisk(){ a = av; b = bv; }
 ~Met_xord(){ std::cout <<"Destruct Met_xord"<< std::endl ;}


  double poisk( double (*f) (double x), double eps ){
   double d, xt, xp, fa, fb, fx ;
   int64_t n ;

    fa = f(a) ;
    fb = f(b) ;
    xp = a - fa * ( (b-a) / (fb-fa) ) ;
    d = 1 ; n = 0; fx = f(xp) ;
    while( ( fabs(fx) > eps ) && n < 100 && fabs(d)> eps ){
      if( fa*fx < 0 ){
       b = xp ; fb = fx ;
      }else{ a = xp ; fa = fx ; }
      xt = a - fa *((b-a)/(fb-fa));
      fx = f(xt); d = xt-xp ; xp = xt ;
      n++ ;
    }
    return xp ;
  }

};
/**************************Met_xord***********************************************************************************/

}//namespace Met_xord


#endif // CLASS_MET_XORD_H_INCLUDED
