#ifndef _MAIN_H
#define _MAIN_H

#include "class_Circle.h"
#include "class_Baza_tab.h"
#include "Baza_func.h"
#include "class_Interval_nul.h"
#include <iostream>


/*------------------------------------------------------------------------------------------------------------------*/
template<class T> std::string _print( T a ) ;
template<class T>
std::string _print( T a ) {
  if( a == -1  ) return  " ПЕРЕСЕКАЕТ " ;
  if( a == 0  ) return " НЕ ПЕРЕСЕКАЕТ  " ;
  if( a == 1 ) return " СОДЕРЖИТСЯ ОДНА В ДРУГОЙ " ;
}
/*------------------------------------------------------------------------------------------------------------------*/


#endif // _MAIN_H

