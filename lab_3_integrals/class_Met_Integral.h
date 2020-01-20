#ifndef CLASS_MET_INTEGRAL_H_INCLUDED
#define CLASS_MET_INTEGRAL_H_INCLUDED

#include "class_Baza_Integ_virt.h"

namespace Met_Integral{

/***************************class Met_Integral****************************************************************/
class Met_Integral{

  public:
    Baza_Integ_virt::Baza_Integ_virt *p ;


    Met_Integral( Baza_Integ_virt::Baza_Integ_virt *comp){ p = comp ; }
   ~Met_Integral(){ delete p ; }

    double Integral ( double eps ) { return p-> Integral( eps ) ; }
};
/***************************class Met_Integral****************************************************************/

} //namespace Met_Integral

#endif // CLASS_MET_INTEGRAL_H_INCLUDED
