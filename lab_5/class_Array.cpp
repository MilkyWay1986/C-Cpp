#include <iostream>
#include <math.h>

#include "class_Array.h"

namespace Array {

/********************************class Array*********************************************************************************/
//--------------------------------------------------------------------------------------------------------------------------/
Array::Array()
  :_size(0), ptr(nullptr){}
//--------------------------------------------------------------------------------------------------------------------------/

//--------------------------------------------------------------------------------------------------------------------------/
Array::Array( int64_t n ){
  _size = n ;
  ptr= new int64_t[_size] ;
  for (size_t i = 0 ; i < sizeof(ptr)/sizeof(ptr[0]) ; i++)
    ptr[i] = 0 ;
}
//--------------------------------------------------------------------------------------------------------------------------/

//--------------------------------------------------------------------------------------------------------------------------/
Array::Array( const Array &arr ){
  _size = arr._size ;
  ptr= new int64_t[_size] ;
  for (size_t i = 0 ; i < sizeof(ptr)/sizeof(ptr[0]) ; i++)
    ptr[i] = arr.ptr[i] ;
}
//--------------------------------------------------------------------------------------------------------------------------/

//--------------------------------------------------------------------------------------------------------------------------/
Array& Array::operator=(const Array & arr ) {
  if ( &arr == this ) return *this ;
  if ( _size != arr._size ) {
    if (ptr != 0) delete []ptr ;
    _size = arr._size ;
    ptr = new int64_t[_size] ;
  }
  for( size_t i = 0 ; i < _size ; i++) ptr[i] = arr.ptr[i] ;
  return *this ;
}
//--------------------------------------------------------------------------------------------------------------------------/

//--------------------------------------------------------------------------------------------------------------------------/
Array&  Array::operator+(const Array & arr) {
  if (_size > arr._size ) _size = arr._size ;
  Array *r = new Array (_size) ;
  for ( size_t i = 0 ; i < _size ; i++) r->ptr[i] = ptr[i] + arr.ptr[i] ;
  return *r ;
}
//--------------------------------------------------------------------------------------------------------------------------/

/********************************class Array*********************************************************************************/

} ;
