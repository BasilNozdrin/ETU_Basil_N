#ifndef LB5_AND_CW_WEAKHEAP_HPP
#define LB5_AND_CW_WEAKHEAP_HPP

#include <utility>

/* * * * * * * * * * * * * * * * * * * * */
/*! 31. Слабая куча. Weak heap.          *
 * Дан массив пар типа «число – бит».    *
 * Предполагая, что этот массив          *
 * представляет слабую кучу, вывести     *
 * её на экран в наглядном виде.         */
/* * * * * * * * * * * * * * * * * * * * */
/*! Сортировка слабой кучей. Демонстрация*/
/* * * * * * * * * * * * * * * * * * * * */

/*! i -> 2i + bit[i]        // left
 *  i -> 2i + 1 - bit[i]    // right
 *  i -> i div 2            // parent
 */

class WeakHeap{
 public:
  WeakHeap(): m_size(0), m_data(nullptr), m_bit(nullptr) {};
  WeakHeap(std::pair<int, bool> *array, size_t size) {
    m_size = size;
    m_data = new int [size];
    m_bit = new bool [size];
    for (size_t i = 0; i < size; i++) {
      m_data[i] = array[i].first;
      m_bit[i] = array[i].second;
    }
  };
  ~WeakHeap() {
    delete [] m_data;
    delete [] m_bit;
  };

  int getSize() { return m_size; };
  int* getData() { return m_data; };
  bool* getBit() { return m_bit; };

  int Join(int v, int w) {
    if (m_data[v] < m_data[w]) {
      std::swap(m_data[v], m_data[w]);
      m_bit[v] ^= 1;
      return 1;
    }
    return 0;
  };       /// ???
  int Up(int v) {
    if ((v % 2)^(m_bit[v/2]))
      return v/2;
    return Up(v/2);
  };                /// returns Right parent
  void SiftUp(int v) {
    int w;
    while (Join(v,w=Up(v)))
      v = w;
  };           /// sifts WeakHeap
 protected:
  int   m_size;
  int   *m_data;
  bool  *m_bit;
 private:
};

#endif //LB5_AND_CW_WEAKHEAP_HPP
