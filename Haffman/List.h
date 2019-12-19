#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <iostream>

namespace LinkedList {

template <class Tdata>
  class LinkedList  {

    private:
      struct Node {
        Tdata    data ;
        Node    *pNext    = nullptr ;
        int64_t counter  = 0 ;

        Node( Tdata _data, Node *_pNext = nullptr ) { data = _data ; pNext = _pNext ; counter++ ; }
        virtual ~Node() { if( pNext != nullptr ) delete pNext ; }

        Tdata    GET_DATA   () const { return data    ; }
        int64_t  GET_COUNTER() const { return counter ; }
      } ;

    private:
      Node *pNode = nullptr ;
      int64_t size_of_list = 0 ;

    public:
//-------------------------------------------------------------------------------------------------------------------------------------------------------//
      LinkedList() {}
      LinkedList( Tdata &data ) {}
      LinkedList( const LinkedList &_copy ) {}

      virtual ~LinkedList() { if( pNode != nullptr ) delete pNode ; }
//-------------------------------------------------------------------------------------------------------------------------------------------------------//
      int64_t  GET_SIZE_OF_LIST() const { return size_of_list ; }
      Node&    GET_pNODE       () const { return *pNode ; }
//-------------------------------------------------------------------------------------------------------------------------------------------------------//
      LinkedList<Tdata>& operator=( LinkedList<Tdata> &other ) {}

      Tdata& operator[]( const int64_t idx ) {
        Node *current = this->pNode ;
        int64_t counter_ = 0 ;
        while( current != nullptr ) {
          if( counter_ == idx ) return current->data ;
          current = current->pNext ;
          counter_++ ; }
      }
//-------------------------------------------------------------------------------------------------------------------------------------------------------//
 friend std::ostream& operator<<( std::ostream &os,  const LinkedList<Tdata> &other ) ;
//-------------------------------------------------------------------------------------------------------------------------------------------------------//
      void PushBack( Tdata &_data ) {
        if( pNode == nullptr ) {
          pNode = new Node( _data ) ;
          size_of_list++ ;
        } else {
          Node *current = pNode ;
          bool flag = false ;
          Node *flag_addr = nullptr ;
          while( current->pNext != nullptr ) {
            if( current->data == _data ) { flag = true ; flag_addr = current ; }
            current = current->pNext ;
          }
          if(flag) flag_addr->counter++ ;
          else { current->pNext = new Node( _data ) ; size_of_list++ ; }
        }
      }
//-------------------------------------------------------------------------------------------------------------------------------------------------------//
} ;

template <class Tdata>
  std::ostream& operator<<( std::ostream &os,  const LinkedList<Tdata> &other ) {
    os << other.pNode->data ;
    return os ;
}
} //namespace LinkedList

#endif // LIST_H_INCLUDED
