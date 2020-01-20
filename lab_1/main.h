#ifndef _MAIN_H
#define _MAIN_H

#include <cmath>
#include <iostream>
#include <string>
#include "class_Line.h"
#include "class_Point.h"

/*------------------------------------------------------------------------------------------------------------------*/
template<class T> std::string _print( T a ) ;
template<class T>
std::string _print( T a ) {
  if( a == 1  ) return  " ПЕРЕСЕКАЕТ " ;
  if( a == 0  ) return " НЕ ПЕРЕСЕКАЕТ ( ПАРАЛЛЕЛЬНЫЕ ) " ;
  if( a == -1 ) return " РАВНЫ " ;
}
/*------------------------------------------------------------------------------------------------------------------*/




#endif // _MAIN_H


