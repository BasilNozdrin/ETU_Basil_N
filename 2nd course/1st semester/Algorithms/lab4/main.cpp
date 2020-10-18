#include <iostream>
#include <fstream>
#include <string>

/* 13. Сортировка массивов слиянием – простое слияние, итеративная реализация. */

/* обязательное описание авлгоритма в отчете
 * выводить состояние данных на каждом шаге алгоритма
 * сравнить результат с std::sort (опционально)
 * делать template функции */


template <class T>
class Queue {
 public:
  Queue(){};
}

template <class T>
void func() {}

int main() {
  std::ifstream input("input.txt");
  for (std::string line; getline(input, line); ) {
    std::cout << line << "\n";
  }
  return 0;
}
