#ifndef HAFFMANTREE_H_INCLUDED
#define HAFFMANTREE_H_INCLUDED

#include <string>
#include <vector>
#include <list>
#include <map>
#include <fstream>

namespace HaffmanTree {

  class HaffmanTree {

  private:
    struct Node {
       int64_t _count ;
       char _charset ;
       Node *_lhs, *_rhs;

       Node() : _lhs( nullptr), _rhs( nullptr ) {}
       Node( Node *lhs, Node *rhs ) : _lhs( lhs ), _rhs( rhs ), _count( _count = lhs->_count + rhs->_count ) {}
    };

    struct MyCompare{ bool operator()( const Node* lhs, const Node* rhs ) const { return lhs->_count < rhs->_count; } };

  private:
    Node *_pNode ;
    Node *p ;
    Node *parent ;
    std::vector<bool> _code ;
    std::map<char,std::vector<bool> > _table ;

  public:
    HaffmanTree() : _pNode( nullptr ), p( nullptr ), parent( nullptr ) {}
    HaffmanTree( const HaffmanTree &_copy) {}
    virtual ~HaffmanTree() { if( p != nullptr ) delete p ; if( parent != nullptr ) delete parent ; }

    HaffmanTree& operator=( const HaffmanTree &_other ) {}
//---------------------------------------------------------------------------------------------------------------------------------------//
    void Build_table( Node *_pNode ) {
      if ( _pNode->_lhs != nullptr ) { _code.push_back(0) ; Build_table(_pNode->_lhs) ; }
      if ( _pNode->_rhs != nullptr ) { _code.push_back(1) ; Build_table(_pNode->_rhs) ; }
      if ( _pNode->_lhs == nullptr && _pNode->_rhs == nullptr ) _table[_pNode->_charset] = _code ;
      _code.pop_back() ;
    }
//---------------------------------------------------------------------------------------------------------------------------------------//
    void Compress( std::string &filename ) {
      std::ifstream _read( filename, std::ios::out | std::ios::binary);
      setlocale(LC_ALL,"Russian");

      std::map<char,int> m;
      std::list<Node*> t;

      while ( !_read.eof() ) { char c = _read.get() ; m[c]++ ; }

      for( std::map<char,int>::iterator itr = m.begin() ; itr != m.end() ; ++itr ) {
        p = new Node() ;
        p->_charset = itr->first ;
        p->_count = itr->second ;
        t.push_back(p) ;
      }

      while ( t.size() != 1 ) {
        t.sort( MyCompare() ) ;
        Node *lhs = t.front() ;
        t.pop_front() ;
        Node *rhs = t.front() ;
        t.pop_front() ;
        parent = new Node( lhs, rhs ) ;
        t.push_back(parent);
      }

      _pNode = t.front();
      Build_table( _pNode ) ;

      _read.clear(); _read.seekg( 0 ) ;

      std::string tail = ".compress" ;
      std::ofstream _write( filename + tail, std::ios::out | std::ios::binary ) ;

      int64_t _count = 0 ; char buf = 0 ;
      while ( !_read.eof() ) { char c = _read.get() ;
        std::vector<bool> x = _table[c];
        for( int i = 0 ; i < x.size() ; i++ ) { buf = buf | x[i] << ( 7 - _count ) ; _count++ ;
          if( _count == 8 ) { _count = 0 ;   _write << buf ; buf = 0 ; }
        }
      }
      _read.close();
      _write.close();
    }
//---------------------------------------------------------------------------------------------------------------------------------------//
    void Decompress( std::string &filename ) {
      std::ifstream _write( filename, std::ios::in | std::ios::binary ) ;
      setlocale(LC_ALL,"Russian");

      Node *p = _pNode;
      int64_t _count = 0 ; char byte ;
      byte = _write.get();
      while( !_write.eof() ){
        bool b = byte & ( 1 << ( 7 - _count ) ) ;
        if ( b ) p = p->_rhs ; else p = p->_lhs ;
        if ( p->_lhs == nullptr && p->_rhs == nullptr ) { std::cout << p->_charset ; p =_pNode ; }
        _count++ ;
        if ( _count == 8 ) { _count = 0 ; byte = _write.get() ; }
      }
      _write.close();
    }
//---------------------------------------------------------------------------------------------------------------------------------------//
  } ;

} //namespace HaffmanTree



#endif // HAFFMANTREE_H_INCLUDED



двунаправлей список шаблонный
класс ветвь графа ( обход графа в ширину в глубину list )
