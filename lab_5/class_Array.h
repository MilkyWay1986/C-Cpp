#ifndef CLASS_ARRAY_H_INCLUDED
#define CLASS_ARRAY_H_INCLUDED

#include<iostream>

namespace Array {

/********************************class Array*********************************************************************************/
class Array {

  private:
    int64_t *ptr ;
    int64_t _size ;

  public:
    Array() ;
    Array( int64_t ) ;
    Array( const Array & ) ;
   ~Array(){}

    int64_t _SIZE() const {
      return _size ;
    }

    void * PTR() const {
      for (int64_t i = 0 ; i < _size ; i++)
        std::cout << ptr[i] ;
    }

    void _SET();


    Array & operator+(const Array &) ;
    Array & operator=(const Array &) ;



} ;


/********************************class Array*********************************************************************************/

} //namespace Array

#endif // CLASS_ARRAY_H_INCLUDED
