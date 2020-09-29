#ifndef TEST_A_H
#define TEST_A_H

#include <iostream>

class A {
 public:
  int data;
  explicit A(int x=0): data(x){
//    std::cout << "A constructed\n";
  };
  ~A(){
//    std::cout << "A destructed\n";
  }
};


#endif //TEST_A_H
