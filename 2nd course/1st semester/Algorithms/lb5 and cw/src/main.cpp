#include <iostream>
#include <utility>
#include <cmath>
#include <fstream>

#include "WeakHeap.hpp"
#include "BinTree.hpp"

void heapsort(WeakHeap &wh){
  int size = wh.getSize();
  for (int i = 0; i < size; i++){
    wh.Build();
    std::swap(wh.getData()[0], wh.getData()[wh.getSize()-1]);
    wh.setSize(wh.getSize()-1);
    BinTree bt(&wh);
    bt.print();
    std::cout << "=======================================\n";
  }
  wh.setSize(size);
};


int main () {
  std::ifstream input("../input.txt");
  for (std::string line; getline(input, line); ) {
    size_t size = 1000;
    auto array = new std::pair<int, bool>[size];
    int i = 0;
    size = 0;
    std::cout << "array  = [";
    for (int j = i; j < line.length(); j++) {
      if (line[j] == ' ' || j + 1 == line.length()) {
        array[size++] = std::pair<int, bool>(stoi(line.substr(i, j)), false);
        std::cout << array[size - 1].first << " ";
        i = j + 1;
      }
    }
    std::cout << "]\n";
    WeakHeap wh(array, size);
    wh.Build();

    heapsort(wh);
    auto result = wh.getData();

    std::cout << "sorted = [";
    for (int j = 0; j < size; j++)
      std::cout << result[j] << " ";
    std::cout << "]\n";
    delete [] array;
  }
  return 0;
}
