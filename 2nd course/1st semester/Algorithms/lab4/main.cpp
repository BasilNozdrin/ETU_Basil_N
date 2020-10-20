#include <iostream>
#include <fstream>
#include <string>

/* 13. Сортировка массивов слиянием – простое слияние, итеративная реализация. */

/* обязательное описание авлгоритма в отчете
 * выводить состояние данных на каждом шаге алгоритма
 * сравнить результат с std::sort (опционально)
 * делать template функции */

template<typename T>
void MergeSort(T arr[], size_t length) {
  size_t BlockSizeIterator;
  size_t BlockIterator;
  size_t LeftBlockIterator;
  size_t RightBlockIterator;
  size_t MergeIterator;

  size_t LeftBorder;
  size_t MidBorder;
  size_t RightBorder;
  for (BlockSizeIterator = 1; BlockSizeIterator < length; BlockSizeIterator *= 2) {
    for (BlockIterator = 0; BlockIterator < length - BlockSizeIterator; BlockIterator += 2 * BlockSizeIterator) {
      //Производим слияние с сортировкой пары блоков начинающуюся с элемента BlockIterator
      //левый размером BlockSizeIterator, правый размером BlockSizeIterator или меньше
      LeftBlockIterator = 0;
      RightBlockIterator = 0;
      LeftBorder = BlockIterator;
      MidBorder = BlockIterator + BlockSizeIterator;
      RightBorder = BlockIterator + 2 * BlockSizeIterator;
      RightBorder = (RightBorder < length) ? RightBorder : length;
      int* SortedBlock = new int[RightBorder - LeftBorder];

      //Пока в обоих массивах есть элементы выбираем меньший из них и заносим в отсортированный блок
      while (LeftBorder + LeftBlockIterator < MidBorder && MidBorder + RightBlockIterator < RightBorder) {
        if (arr[LeftBorder + LeftBlockIterator] < arr[MidBorder + RightBlockIterator]) {
          SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[LeftBorder + LeftBlockIterator];
          LeftBlockIterator += 1;
        } else {
          SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[MidBorder + RightBlockIterator];
          RightBlockIterator += 1;
        }
      }
      
      //После этого заносим оставшиеся элементы из левого или правого блока
      while (LeftBorder + LeftBlockIterator < MidBorder) {
        SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[LeftBorder + LeftBlockIterator];
        LeftBlockIterator += 1;
      }
      while (MidBorder + RightBlockIterator < RightBorder) {
        SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[MidBorder + RightBlockIterator];
        RightBlockIterator += 1;
      }

      for (MergeIterator = 0; MergeIterator < LeftBlockIterator + RightBlockIterator; MergeIterator++) {
        arr[LeftBorder + MergeIterator] = SortedBlock[MergeIterator];
      }
      delete SortedBlock;
    }
  }
}

int main() {
  std::ifstream input("input.txt");
  for (std::string line; getline(input, line); ) {
    int arr[25] = {};
    int n = 0;
    int i = 0;
    std::cout << "array = [ ";
    for (int j = i; j < line.length(); j++) {
      if (line[j] == ' ' || j+1 == line.length()) {
        arr[n++] = stoi(line.substr(i,j));
        std::cout << arr[n-1] << " ";
        i = j+1;
      }
    }
    std::cout << "]\n";
  }
  return 0;
}
