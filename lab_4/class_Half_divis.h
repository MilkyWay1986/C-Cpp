#ifndef CLASS_HALF_DIVIS_H_INCLUDED
#define CLASS_HALF_DIVIS_H_INCLUDED

#include <iostream>
#include<cmath>

#include "class_Base_poisk.h"
#include "Baza_func.h"


namespace Half_divis {

/**************************Half_divis**********************************************************************************/
class Half_divis : public Baza_poisk::Baza_poisk{

  public:
    Baza_func::f f;

  public:

  Half_divis ( double av, double bv):Baza_poisk::Baza_poisk(){ a = av; b = bv; }
 ~Half_divis(){ std::cout << "Destruct Half_divis"<< std::endl ;}

  double poisk( double ( *f ) ( double x ), double esp ){
    int64_t i = 0 ; double c = (a + b)/2 ;
    while( fabs(f(c)) > esp && fabs(b-a) > esp && i < 350 ){
      c = (a + b)/2 ;
      if ( f(a)* f(c) < 0 ) b = c ;
      else a = c ;
      i++ ;
    }
    return c ;
  }

};
/**************************Half_divis**********************************************************************************/

} //namespace Half_divis

#endif // CLASS_HALF_DIVIS_H_INCLUDED
