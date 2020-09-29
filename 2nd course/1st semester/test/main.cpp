#include <iostream>

#include "A.h"
#include "AARowIter.h"

int main() {
  std::cout << "Hello, World!" << std::endl;
  A** row = new A*[3];
  row[0] = new A(0);
  row[1] = new A(1);
  row[2] = new A(2);

  AARowIter<A*>(row);

  return 0;
}
