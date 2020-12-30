#ifndef LB5_AND_CW_WEAKHEAPLOG_HPP
#define LB5_AND_CW_WEAKHEAPLOG_HPP

#include "WeakHeap.hpp"
#include "PrintWh.hpp"

class WeakHeapLog : public WeakHeap {
 public:
  WeakHeapLog(std::pair<int, bool> *array, size_t size) {
    m_size = size;
    m_data = new int [size];
    m_bit = new bool [size];
    for (size_t i = 0; i < size; i++) {
      m_data[i] = array[i].first;
      m_bit[i] = array[i].second;
    }
    this->BuildLog(false);
  };
  [[maybe_unused]] int JoinLog(unsigned int v, unsigned int w, bool log = false) {
    PrintWh *bt = nullptr;
    if (log)
      std::cout << "JoinLog(" << m_data[v] << "=m_data[" << v << "], " << m_data[w] << "=m_data[" << w << "])";
    if (m_data[v] < m_data[w]) { // defines min-heap
      std::swap(m_data[v], m_data[w]);
      m_bit[v] ^= true;
      if (log) {
        std::cout << " -> 1\n";
        bt = new PrintWh(this);
        bt->print();
        std::cout << "\n";
        delete bt;
      }
      return 1;
    }
    if (log) {
      std::cout << " -> 0\n";
    }
    return 0;
  };       /// проталкивает минимум из v наверх в w
  [[maybe_unused]] unsigned int UpLog(unsigned int v, bool log = false) {
    if (log)
      std::cout << "Up(" << m_data[v] << "=m_data["<< v <<"])\n";
    if ((v % 2)^(m_bit[v/2]))
      return v/2;
    return UpLog(v/2);
  };                /// returns Right parent
  [[maybe_unused]] void SiftUpLog(unsigned int v, bool log = false) {
    if (log)
      std::cout << "SiftUp(" << m_data[v] << "=m_data["<< v <<"])\n";
    unsigned int w;
    while (this->JoinLog(v,w = Up(v), log))
      v = w;
  };                    /// sifts WeakHeap
  [[maybe_unused]] int SiftDownLog(bool log = false) {
    PrintWh *bt = nullptr;
    if (log) {
      std::cout << "SiftDown\n";
      bt = new PrintWh(this);
      bt->print();
      delete bt;
    }
    int result = m_data[0]; // save min
    std::swap(m_data[0], m_data[m_size-1]);
    if (log) {
      std::cout << "Move min\n";
      bt = new PrintWh(this);
      bt->print();
      delete bt;
    }
    m_size--;               // delete min
    if (log) {
      bt = new PrintWh(this);
      bt->print();
      delete bt;
    }
    if (m_size < 2)
      return result;
    // greedy go left down
    unsigned int v = 1;
    while (2*v + m_bit[v] < m_size)
      v = 2*v + m_bit[v];
    if (log)
      std::cout << "lower_left=" << m_data[v] << "=m_data["<< v <<"]\n";
//    std::cout << "bro=" << m_data[2*(v/2)+1-m_bit[v/2]] << "=m_data["<< 2*(v/2)+1-m_bit[v/2] <<"]\n";
    while (v > 0) {
      JoinLog(v, 0, log);
      v /= 2;
      if (log && v > 0)
        std::cout << "next=" << m_data[v] << "=m_data["<< v <<"]\n";
    }
    return result;
  };                                 /// Deletes minimum
  [[maybe_unused]] void BuildLog(bool log = false){
    if (log) {
      std::cout << "Building Weak Heap\narray = [";
      for (int j = 0; j < m_size; j++)
        std::cout << m_data[j] << " ";
      std::cout << "]\n";
    }

    for (unsigned int i = m_size-1; i > 0; i--)
      this->JoinLog(i, this->Up(i), log);
  };                                    /// makes WeakHeap a correct one
  [[maybe_unused]] void heapsortLog(bool log = false){
    int size = m_size;
    for (int k = 0; k < size; k++){
      this->SiftDownLog(log);
      if (log) {
        std::cout << "array = [";
        for (int j = 0; j < m_size; j++) std::cout << m_data[j] << " ";
        std::cout << "| ";
        for (int j = m_size; j < size; j++) std::cout << m_data[j] << " ";
        std::cout << "]\n";
      }
    }
    m_size = size;
  };
};


#endif //LB5_AND_CW_WEAKHEAPLOG_HPP
