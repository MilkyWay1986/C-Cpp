#include <iostream>
#include <math.h>

#include "class_Array.h"

int main () {

Array::Array a1[10] ;

for ( size_t i = 0 ; i < ( sizeof(a1)/sizeof(a1[0]) ) ; i++ )
  std::cout << "#" << i+1 << " равно "<< ( a1[i].PTR() ) << std::endl ;



return 0 ;
}
