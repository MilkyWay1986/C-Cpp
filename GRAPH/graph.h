#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include<iostream>

#include "queue.h"

namespace GRAPH {

class Graph {

  private:
  //-------------------------------------------------------------------------------------------------------//
  int64_t _counter_vertex = 100 ;
  int64_t _n = 0 ;
  //-------------------------------------------------------------------------------------------------------//
  struct _adj_list {
    int64_t _vertex_adj ;
    int64_t _weight ;
  } ;
  _adj_list **_graph          = nullptr ;
  int64_t    *_counter_submas = nullptr ;
  //-------------------------------------------------------------------------------------------------------//
  QUEUE::Queue *_queue = nullptr ;
  //-------------------------------------------------------------------------------------------------------//

  public:
  //-------------------------------------------------------------------------------------------------------//
  Graph () {
    std::cout << "Введите количество вершин графа: " ; std::cin >>  _counter_vertex ;

    int64_t counter_for_queue = 0 ;

    _graph          = new _adj_list* [_counter_vertex] ;
    _counter_submas = new int64_t    [_counter_vertex] ;

    for( int64_t i = 0 ; i < _counter_vertex ; i++ ){
      std::cout << "Введите количество смежных вершин для вершины " << i ; std::cin >> _n ; std::cout << "\n" ;
      counter_for_queue = counter_for_queue + _n ;  _counter_submas [i] = _n ;
      _graph[i] = new _adj_list[_n] ;
        for( int64_t j = 0 ; j < _n ; j++ ) {
          std::cout << "\n" ;
          std::cout << "Введите номер смежной вершины " << j <<" для вершины " << i << " "; std::cin >> _graph[i][j]._vertex_adj ;
          std::cout << "\n" ;
          std::cout << "Введите вес смежной вершины "   << j <<"  для вершины " << i << " "; std::cin >> _graph[i][j]._weight    ;  std::cout << "\n" ; }
    }

    _queue = new QUEUE::Queue( counter_for_queue ) ;
  }
  //-------------------------------------------------------------------------------------------------------//
  Graph ( const Graph &_copy )           = delete ;
  Graph& operator=( const Graph &other ) = delete ;
  //-------------------------------------------------------------------------------------------------------//
  ~Graph () {
    if( _graph != nullptr ) {
  /**/for( int64_t i = 0 ; i < _counter_vertex ; i++ ) delete _graph[i] ;
      delete []_graph ;
    }
    if( _counter_submas != nullptr ) { delete _counter_submas ; }
  }
  //-------------------------------------------------------------------------------------------------------//

  void BFS( int64_t &start_vertex ) {
    _queue->_push_back( start_vertex ) ;

    bool    *used     = new bool   [_counter_vertex] ;
    int64_t *distance = new int64_t[_counter_vertex] ;
    int64_t *predok   = new int64_t[_counter_vertex] ;
    int64_t *way      = new int64_t[_counter_vertex] ;

    used  [start_vertex] = true ;
    predok[start_vertex] = -1   ;

    while( !_queue->isEmpty() ) {
      int64_t vertex = _queue->_front() ;
      _queue->_pop_front() ;

      int64_t i ;
      while( i < _counter_submas[vertex] ) {
        int64_t to = _graph[vertex][i]._vertex_adj ;
        if( !used[to] ) {
          used[to] = true ;
          _queue->_push_back( to ) ;
          distance[to] = distance[vertex] + 1 ;
          predok[to]   = vertex ;
        } /*else {
          int64_t j,k ;
          for( j = to, k = 0 ; j != -1, k < _counter_vertex ; j = predok[j], k++ ) way[k] = j ;
          for( _counter_vertex ; ; _counter_vertex-- ) { std::cout << way[_counter_vertex]  <<  " -> " ; }
        }*/
        i++ ;
      }
    }

   delete way ; delete predok ; delete distance ; delete used ;
  }

  void DFS ( int64_t &start_vertex ) {
    bool *used = new bool[_counter_vertex] ;
    used[start_vertex] = true ;
    for( int64_t i = 0 ; i <_counter_vertex ; i++ ) {
      if( !used[i] ) DFS( i ) ;
    }
    delete used ;
  }

} ;

} //namespace GRAPH

#endif // GRAPH_H_INCLUDED
