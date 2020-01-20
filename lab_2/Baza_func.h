#ifndef _BAZA_FUNC_H
#define _BAZA_FUNC_H

#include<cmath>


namespace Baza_func{

typedef double ( *f )( double ) ;

double f0 ( double x ){ if ( cos(x/2) ) return ( sin(x/2) / cos(x/2) ) ; }
double f1 ( double x ){return ( x * sin(x) + cos(x) ) ; }
double f2 ( double x ){return ( -3 * x * cos(x) ) ; }
double f3 ( double x ){return ( cos(x) * x ) ; }
double f4 ( double x ){return ( exp(x/5) - x ) ; }
double f5 ( double x ){return ( x * x ) ; }
double f6 ( double x ){return ( atan(x) - 0.5 + (x-1) * (x-1) * (x-1) ) ; }

} //namespace Baza_func

#endif // BAZA_FUNC_H

