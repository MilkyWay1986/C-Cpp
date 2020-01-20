#ifndef BAZA_FUNC_H_INCLUDED
#define BAZA_FUNC_H_INCLUDED

namespace Baza_func {

typedef double ( *f )( double ) ;

double f0 ( double x ){ return pow(x,3)-0.2*pow(x,2)+0.2*x-1.2; }
double f1 ( double x ){return ( x*x ) ; }
double f2 ( double x ){return ( cos( 4 * x ) - 0.5 * x ) ; }


} //namespace Baza_func

#endif // BAZA_FUNC_H_INCLUDED
