#ifndef OOP_CONTROLS_H
#define OOP_CONTROLS_H

#include <iostream>
#include <string>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

class Controls {
  Controls () {
    int key = getchar();
    int value = key;

    while (value != 0)
    {
      switch (getchar()) {
        case KEY_UP:
          std::cout << "Up ";
          break;
        case KEY_DOWN:
          std::cout << "Up ";
          break;
        case KEY_LEFT:
          std::cout << "Up ";
          break;
        case KEY_RIGHT:
          std::cout << "Up ";
          break;
        default:
          value = 0;
      }
    }
  }

};




#endif //OOP_CONTROLS_H
