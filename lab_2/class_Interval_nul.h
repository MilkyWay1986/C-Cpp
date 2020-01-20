#ifndef CLASS_INTERVAL_NUL_H_INCLUDED
#define CLASS_INTERVAL_NUL_H_INCLUDED

#include "class_Baza_tab.h"
#include "../lab_1/class_Point.h"


namespace Interval_null{

/***************************class Interval_null********************************************************************/
class Interval_null:public Baza_tab::Baza_tab{

  private:
    int64_t kol_in ;
    Point::Point *p_in ;

  public:
    Interval_null():Baza_tab::Baza_tab(){};
    Interval_null( double av, double bv, int64_t nv ):Baza_tab::Baza_tab( av, bv, nv ){ kol_in = 0; p_in = 0 ;}
    void Destroy() { if (p_in && kol_in > 0){ delete [] p_in; kol_in = 0; } }
   ~Interval_null(){
      Destroy () ;
      //Baza_tab::~Baza_tab();
    }

    Point::Point *P_IN() const { return p_in ; }
    int64_t     KOL_IN() const { return kol_in ; }
    void             P() const ;


    Point::Point* Interwal_nul() ;


} ;
/***************************class Interval_null********************************************************************/

} //namespace Interval_null

#endif // CLASS_INTERVAL_NUL_H_INCLUDED
