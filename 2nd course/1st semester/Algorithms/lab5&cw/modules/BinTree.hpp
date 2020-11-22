#ifndef LAB5_CW_BINTREE_HPP
#define LAB5_CW_BINTREE_HPP

#define MAX(a, b) ((a < b) ? b : a)

#include <iostream>
#include <cmath>
#include "Queue.hpp"
#include "WeakHeap.hpp"

class BinTree {
 public:
  BinTree(): m_data(0), m_left(nullptr), m_right(nullptr) {};
  BinTree(int data): m_data(data), m_left(nullptr), m_right(nullptr) {};
  BinTree(WeakHeap wh) {

  }

  int height() {
    if (this->m_left == nullptr) {
      if (this->m_right == nullptr) { return 0;
      } else { return 1 + this->m_right->height(); }
    } else {
      if (this->m_right == nullptr) { return 1 + this->m_left->height();
      } else { return 1 + MAX(this->m_left->height(), this->m_right->height()); }
    }
  };
  void print(){
    Queue<BinTree*> queue;
    queue.push(this);
    int level = 0;
    int height = this->height();
    while (queue.top()) {
      Queue<BinTree*> new_queue;
      for (int i = 0; i < pow(2, height - level) - 1 ; i++) printf("     ");
      while (queue.top()) {
        printf("%5d", queue.top()->m_data->m_data);
        for (int i = 0; i < pow(2, height - level + 1) - 1 ; i++) printf("     ");

        if (queue.top()->m_data->m_left)
          new_queue.push(queue.top()->m_data->m_left);
        if (queue.top()->m_data->m_right)
          new_queue.push(queue.top()->m_data->m_right);

        queue.pop();
      };
      printf("\n");
      queue = new_queue;
      level++;
    };

  };

  void setData(int data)        { m_data = data;  };
  void setLeft(BinTree* node)   { m_left = node;  };
  void setRight(BinTree* node)  { m_right = node; };
  int       getData()  { return m_data;  };
  BinTree*  getLeft()  { return m_left;  };
  BinTree*  getRight() { return m_right; };

 protected:
  int m_data;
  BinTree* m_left;
  BinTree* m_right;
};

#endif //LAB5_CW_BINTREE_HPP
/*
BinTree bt(1);
bt.setLeft(new BinTree(2));
bt.getLeft()->setLeft(new BinTree(4));
bt.getLeft()->setRight(new BinTree(5));
bt.setRight(new BinTree(3));
bt.getRight()->setLeft(new BinTree(6));
bt.getRight()->setRight(new BinTree(7));
bt.print();
*/
