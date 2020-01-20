#ifndef CLASS_MET_NEWTON_H_INCLUDED
#define CLASS_MET_NEWTON_H_INCLUDED

#include <iostream>
#include<cmath>

#include "class_Base_poisk.h"
#include "Baza_func.h"

namespace Met_Newton{

/***************************Met_Newton***********************************************************************************/
class Met_Newton : public Baza_poisk::Baza_poisk{

  public:
    Baza_func::f f;

  public:

  Met_Newton ( double av, double bv):Baza_poisk::Baza_poisk(){ a = av; b = bv; }
 ~Met_Newton(){ std::cout << "Destruct Met_Newton"<< std::endl ;}

  double poisk( double ( *f ) ( double x ), double esp ){
    double xp, xt, d, h, fp, pfa, pfb ;
    int64_t i = 0;
    h =0.1e-11 ;
    d = 1 ; xp = a ;
    while( ( fabs(d) > esp ) && ( i < 50 ) ){
      fp = ( f(xp+h) - f(xp) ) / h ;
        if(fabs(fp) > 0.1e-11)
          xt = xp -f(xp) / fp ;
        else break ;
      d =(xt-xp); xp=xt ; //std::cout <<i++ <<std::endl ;
      i++;
    }

  }
};
/***************************Met_Newton***********************************************************************************/

} //namespace Met_Newton

#endif // CLASS_MET_NEWTON_H_INCLUDED
