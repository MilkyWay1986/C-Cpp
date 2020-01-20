#ifndef BAZA_FUNC_H_INCLUDED
#define BAZA_FUNC_H_INCLUDED

namespace Baza_func_integral {

typedef double ( *f )( double ) ;

double f0 ( double x ){ if ( cos(x/2) ) return ( sin(x/2) / cos(x/2) - x ) ; }
double f1 ( double x ){return ( x * sin(x) + cos(x) ) ; }
double f2 ( double x ){return ( -3 * x * cos(x) ) ; }
double f3 ( double x ){return ( cos(x) * x ) ; }

} //namespace Baza_func_integral

#endif // BAZA_FUNC_H_INCLUDED
