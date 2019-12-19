#include <iostream>
#include <string>

#include "HaffmanTree.h"

int main () {

  HaffmanTree::HaffmanTree *HT = new HaffmanTree::HaffmanTree() ;

  std::string filename = "test" ;
  HT->Compress( filename ) ;

  std::string dec_filename = "test.compress" ;
  HT->Decompress( dec_filename ) ;

  delete HT ;

return 0 ;
}
