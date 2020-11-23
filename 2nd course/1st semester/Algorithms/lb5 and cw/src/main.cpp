#include <iostream>
#include <utility>
#include <cmath>

#include "WeakHeap.hpp"
#include "BinTree.hpp"

int main () {
  size_t size = 6;
  auto array = new std::pair<int, bool> [size];
  array[0] = std::pair<int, bool> (1, false);
  array[1] = std::pair<int, bool> (2, false);
  array[2] = std::pair<int, bool> (3, false);
  array[3] = std::pair<int, bool> (4, false);
  array[4] = std::pair<int, bool> (5, false);
  array[5] = std::pair<int, bool> (6, false);
  WeakHeap wh(array, size);
  BinTree bt(&wh);
  bt.print();



  return 0;
}
