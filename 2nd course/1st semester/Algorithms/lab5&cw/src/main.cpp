#include <iostream>
#include <utility>
#include <cmath>

#include "WeakHeap.hpp"
#include "BinTree.hpp"

int main () {
  BinTree bt(1);
  bt.setLeft(new BinTree(2));
//  bt.getLeft()->setLeft(new BinTree(4));
//  bt.getLeft()->setRight(new BinTree(5));
  bt.setRight(new BinTree(3));
//  bt.getRight()->setLeft(new BinTree(6));
//  bt.getRight()->setRight(new BinTree(7));
  bt.print();


  size_t size = 4;
  std::pair<int, bool> *array = new std::pair<int, bool> [size];
  array[0] = std::pair<int, bool> (1, false);
  array[1] = std::pair<int, bool> (2, false);
  array[2] = std::pair<int, bool> (3, false);
  array[2] = std::pair<int, bool> (4, false);


  return 0;
}
