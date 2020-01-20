#include <cmath>
#include <iostream>


#include "class_Int_trap_virt.h"
#include "class_Baza_Integ_virt.h"
#include "class_Int_parab_virt.h"
#include "class_Met_Integral.h"
#include "Baza_func.h"


int main(){

  int64_t i, j, n, m, k, j1 ;
  int64_t a = -1 ;
  int64_t b =  1 ;
  m = 2 ;
  double s, xp ;
  Baza_func_integral::f mas_f[] = { Baza_func_integral ::f0, Baza_func_integral::f1, Baza_func_integral::f2, Baza_func_integral::f3 } ;
  Baza_Integ_virt::Baza_Integ_virt *pf[m] ;

  for (int64_t i = 0 ; i < (sizeof(mas_f)/sizeof(mas_f[0])) ; i++ ){

      pf[0] = new Int_trap_virt::Int_trap_virt  ( a,  b, mas_f[i] ) ;
      std::cout <<"Площадь функции #" << i+1 << " на интервале (" << a <<", " << b << " )";
      std::cout << " вычисленной по методу Трапеций равно " ;
      std::cout << fabs( pf[0]->Integral ( 0.001 ) ) ;std::cout<<";  " ;
      std::cout << "n = " ;
      std::cout << pf[0]->N() ;
      std::cout<<std::endl;

      pf[1] = new Int_parab_virt::Int_parab_virt( a,  b, mas_f[i] ) ;
      std::cout <<"Площадь функции #" << i+1 << " на интервале (" << a <<", " << b << " )";
      std::cout << " вычисленной по методу Парабол равно " ;
      std::cout << fabs( pf[1]->Integral ( 0.001 ) );std::cout<<";  " ;
      std::cout << "n = " ;
      std::cout << pf[1]->N() ;
      std::cout<<std::endl;std::cout<<std::endl;std::cout<<std::endl;

  }
  delete *pf ;

/*


  Met_Integral::Met_Integral *p[3] ;
  for ( i = 0 ; i < m; i++)
    p[i] = new Met_Integral::Met_Integral( pf[i]) ;


  for ( i = 0 ; i < m ; i++ ){
    std::cout << p[i]->Integral ( 0.00001 ) << std::endl ;
    std::cout << p[i]->p->N() << std::endl ;
  }
*/
return 0 ;
}
