#ifndef LB5_AND_CW_BINTREE_HPP
#define LB5_AND_CW_BINTREE_HPP

#ifndef LAB5_CW_BINTREE_HPP
#define LAB5_CW_BINTREE_HPP

#define MAX(a, b) ((a < b) ? b : a)

#include <iostream>
#include <cmath>
#include "Queue.hpp"
#include "WeakHeap.hpp"

class BinTree {
 public:
  BinTree(): m_data(0), m_empty(false), m_left(nullptr), m_right(nullptr) {};
  explicit BinTree(int data): m_data(data), m_empty(false), m_left(nullptr), m_right(nullptr) {};
//  explicit BinTree(WeakHeap *wh) : m_data(wh->getData()[0]), m_empty(false), m_left(nullptr), m_right(nullptr) {
//    int size = wh->getSize();
//    auto tmp = new BinTree*[size];
//    for (int i = 1; i < size; i++)
//      tmp[i] = new BinTree(wh->getData()[i]);
//    tmp[0] = this;
//    for (int i = 0; i < size; i++) {
//      int bit = wh->getBit()[i];
//      if (2*i+bit < size && i != 0)
//        tmp[i]->m_left = tmp[2*i+bit];
//      if (2*i+1-bit < size)
//        tmp[i]->m_right = tmp[2*i+1-bit];
//    }
//    delete [] tmp;
//  };
  ~BinTree(){
    delete m_left;
    delete m_right;
  };
  [[maybe_unused]] int height() {
    if (this->m_left == nullptr) {
      if (this->m_right == nullptr) { return 0;
      } else { return 1 + this->m_right->height(); }
    } else {
      if (this->m_right == nullptr) { return 1 + this->m_left->height();
      } else { return 1 + MAX(this->m_left->height(), this->m_right->height()); }
    }
  };
  [[maybe_unused]] void complete(){
    int h = this->height();
    Queue<BinTree*> queue;
    queue.push(this);
    while (h > 0) {
      Queue<BinTree *> new_queue;
      while (queue.top()) {
        if (queue.top()->m_data->m_left == nullptr) {
          queue.top()->m_data->m_left = new BinTree;
          queue.top()->m_data->m_left->m_empty = true;
        }
        if (queue.top()->m_data->m_right == nullptr) {
          queue.top()->m_data->m_right = new BinTree;
          queue.top()->m_data->m_right->m_empty = true;
        }
        new_queue.push(queue.top()->m_data->m_left);
        new_queue.push(queue.top()->m_data->m_right);
        queue.pop();
      }
      queue = new_queue;
      h--;
    }
  };
  [[maybe_unused]] void print(){
    this->complete();

    Queue<BinTree*> queue;
    queue.push(this);
    int level = 0;
    int height = this->height();
    while (queue.top()) {
      Queue<BinTree*> new_queue;
      for (int i = 0; i < pow(2, height - level) - 1 ; i++) printf("     ");
      while (queue.top()) {
        if (queue.top()->m_data->m_empty)
          printf("     ");
        else
          printf("%5d", queue.top()->m_data->m_data);
        for (int i = 0; i < pow(2, height - level + 1) - 1 ; i++) printf("     ");
        if (queue.top()->m_data->m_left)
          new_queue.push(queue.top()->m_data->m_left);
        if (queue.top()->m_data->m_right)
          new_queue.push(queue.top()->m_data->m_right);
        queue.pop();
      }
      printf("\n");
      queue = new_queue;
      level++;
    }

  };
  [[maybe_unused]] void setData(int data)        { m_data = data;  };
  [[maybe_unused]] void setLeft(BinTree* node)   { m_left = node;  };
  [[maybe_unused]] void setRight(BinTree* node)  { m_right = node; };
  [[maybe_unused]] [[nodiscard]] int getData() const  { return m_data;  };
  [[maybe_unused]] BinTree*  getLeft()  { return m_left;  };
  [[maybe_unused]] BinTree*  getRight() { return m_right; };
 public:
  int m_data;
  bool m_empty;
  BinTree* m_right;
  BinTree* m_left;
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

#endif //LB5_AND_CW_BINTREE_HPP
