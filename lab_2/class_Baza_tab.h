#ifndef _CLASS_BAZA_TAB_H
#define _CLASS_BAZA_TAB_H

#include<cmath>
#include <iostream>

#include "../lab_1/class_Point.h"



namespace Baza_tab{

/***************************class Baza_tab*****************************************************************************/
class Baza_tab{

  private:
    double a, b ;

  protected:
    Point::Point *p ;
    Point::Point *p_in ;

    int64_t n ;
    int64_t kol_in ;

  public:
    Baza_tab();
    Baza_tab( double, double, int64_t );
   ~Baza_tab() ;

    double  A()      const ;
    double  B()      const ;
    double  KOL_IN() const ;
    int64_t N()      const ;
    void    P()      const ;

    Point::Point* Tabul( double ( *f ) ( double ) ) ;// //вычисляется динамический массив точек табуляции
           void Tabul_v( double ( *f ) ( double ) ) ;


};
/****************************class Baza_tab****************************************************************************/

} //namespace Baza_tab

#endif // _CLASS_BAZA_TAB_H
