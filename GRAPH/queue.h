#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

namespace QUEUE {

  struct Queue {
  //----------------------------------------------------------------------------------------------------------------//
    int64_t  _size_of_queue = 1000    ;
    int64_t *_pQueue        = nullptr ;
  //----------------------------------------------------------------------------------------------------------------//
    struct _number_of_elements_current_element_of_queue {
      int64_t  _number_of_elements = 0 ;
    } ;

    _number_of_elements_current_element_of_queue *_pNumber_of_elements_current_element_of_queue = nullptr ;
  //----------------------------------------------------------------------------------------------------------------//
    Queue( int64_t size_of_queue ) : _size_of_queue ( size_of_queue ), _pQueue( nullptr ) { _pQueue = new int64_t[size_of_queue] ; }

    Queue( const Queue &_copy )            = delete ;
    Queue& operator=( const Queue &other ) = delete ;

   ~Queue() { if( _pQueue != nullptr ) delete _pQueue ; }
  //----------------------------------------------------------------------------------------------------------------//
    void _push_back ( const int64_t &element ) {

      if( _pNumber_of_elements_current_element_of_queue->_number_of_elements++ < _size_of_queue ){

        _pQueue[_pNumber_of_elements_current_element_of_queue->_number_of_elements++] = element ;

      }else{

        int64_t *new_pQueue = new int64_t[_pNumber_of_elements_current_element_of_queue->_number_of_elements * 2] ;
        for( int64_t i = 0 ; i < _pNumber_of_elements_current_element_of_queue->_number_of_elements ; i++ )
          new_pQueue[i] = _pQueue[i] ;

        delete _pQueue ; _pQueue = new_pQueue ; delete new_pQueue ;

        _pQueue[_pNumber_of_elements_current_element_of_queue->_number_of_elements++] = element ;
      }
    }
  //----------------------------------------------------------------------------------------------------------------//
    int64_t& _pop_front () {
      if( _pNumber_of_elements_current_element_of_queue->_number_of_elements > 0 ){

        int64_t *new_pQueue = new int64_t[_pNumber_of_elements_current_element_of_queue->_number_of_elements - 1] ;
        int64_t result = _pQueue[0] ;
        for( int64_t i = 1 ; i < _pNumber_of_elements_current_element_of_queue->_number_of_elements ; i++ )
          new_pQueue[i] = _pQueue[i] ;

        delete _pQueue ; _pQueue = new_pQueue ; delete new_pQueue ;
        return result ;

      }else { std::cout << "QUEUE_IS_EMPTY" << "\n" ; exit(1) ; }
    }
  //----------------------------------------------------------------------------------------------------------------//
    int64_t& _front () const { return _pQueue[0] ; }
  //----------------------------------------------------------------------------------------------------------------//
    int64_t& _back  () const { return _pQueue[_pNumber_of_elements_current_element_of_queue->_number_of_elements] ; }
  //----------------------------------------------------------------------------------------------------------------//
    bool isEmpty () {
      return _pNumber_of_elements_current_element_of_queue->_number_of_elements ? true : false ;
    }


  } ;
} // namespace QUEUE

#endif // QUEUE_H_INCLUDED
