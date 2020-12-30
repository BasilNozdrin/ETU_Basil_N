#ifndef LB5_AND_CW_PRINTWH_HPP
#define LB5_AND_CW_PRINTWH_HPP

#include "WeakHeap.hpp"
#include "BinTree.hpp"

class PrintWh : public BinTree {
 public:
  explicit PrintWh(WeakHeap *wh) {
    m_data = wh->getData()[0];
    int size = wh->getSize();
    auto tmp = new BinTree*[size];
    for (int i = 1; i < size; i++)
      tmp[i] = new BinTree(wh->getData()[i]);
    tmp[0] = this;
    for (int i = 0; i < size; i++) {
      int bit = wh->getBit()[i];
      if (2*i+bit < size && i != 0)
        tmp[i]->m_left = tmp[2*i+bit];
      if (2*i+1-bit < size)
        tmp[i]->m_right = tmp[2*i+1-bit];
    }
    delete [] tmp;
  }
};


#endif //LB5_AND_CW_PRINTWH_HPP
