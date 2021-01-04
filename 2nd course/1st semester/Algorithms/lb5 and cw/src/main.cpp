#include <iostream>
#include <utility>
#include <cmath>
#include <fstream>

#include "WeakHeap.hpp"
#include "PrintWh.hpp"
#include "WeakHeapLog.hpp"

void heapsort(WeakHeapLog &wh, bool log=false);

int main () {
  std::ifstream input("../input.txt");
  for (std::string line; getline(input, line); ) {
    size_t size = 1000;
    auto array = new std::pair<int, bool>[size];
    int i = 0;
    size = 0;
    std::cout << "array = [";
    for (int j = i; j < line.length(); j++) {
      if (line[j] == ' ' || j + 1 == line.length()) {
        array[size++] = std::pair<int, bool>(stoi(line.substr(i, j)), false);
        i = j + 1;
        std::cout << array[size - 1].first << " ";
      }
    }
    std::cout << "]\n";

    WeakHeapLog wh(array, size);
    auto bt = new PrintWh(&wh);
    bt->print();
    delete bt;

    wh.heapsortLog(true);

    /*
    auto result = wh.getData();
    std::cout << "sorted = [";
    for (int j = 0; j < size; j++)
      std::cout << result[j] << " ";
    std::cout << "]\n";
     */
    delete [] array;
  }
  return 0;
}

void heapsort(WeakHeapLog &wh, bool log){
  int size = wh.getSize();
  auto bt = new PrintWh(&wh);
  if (log) {
    std::cout << "sorting array\narray = [";
    for (int i = 0; i < size; i++) std::cout << wh.getData()[i] << " ";
    std::cout << "]\n";
    bt->print();
  }
  delete bt;

  for (int k = 0; k < size; k++) {
    wh.SiftDownLog(log);

    if (log) {
      bt = new PrintWh(&wh); bt->print(); delete bt;
      std::cout << "array = [";
      for (int j = 0; j < wh.getSize(); j++)    std::cout << wh.getData()[j] << " "; std::cout << "| ";
      for (int j = wh.getSize(); j < size; j++) std::cout << wh.getData()[j] << " "; std::cout << "]\n";
      std::cout << "\n\n";
    }
  }
  wh.setSize(size);
};
