// Include headers in the following order:
// Related header,

// C system headers,
#include <iostream>
// C++ standard library headers,

// other libraries' headers,

// your project's headers.
#include "src/GameField/Field.h"

int main () {
  auto& game = Field::getInstance();
  std::cout << __cplusplus << "\n";
  return 0;
}
