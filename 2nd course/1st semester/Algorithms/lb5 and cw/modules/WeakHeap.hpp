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

  int getSize() const { return m_size; };
  void setSize(int size) { m_size = size; };
  int* getData() { return m_data; };
  bool* getBit() { return m_bit; };

  [[maybe_unused]] int Join(unsigned int v, unsigned int w) {
    if (m_data[v] < m_data[w]) { // defines min-heap
      std::swap(m_data[v], m_data[w]);
      m_bit[v] ^= true;
      return 1;
    }
    return 0;
  };       /// проталкивает минимум из v наверх в w
  [[maybe_unused]] unsigned int Up(unsigned int v) {
    if ((v % 2)^(m_bit[v/2]))
      return v/2;
    return Up(v/2);
  };                /// returns Right parent
  [[maybe_unused]] void SiftUp(unsigned int v) {
    unsigned int w;
    while (this->Join(v,w = Up(v)))
      v = w;
  };                    /// sifts WeakHeap
  [[maybe_unused]] int SiftDown() {
    // save min
    int result = m_data[0];
    // delete min
    m_size--;
    std::swap(m_data[0], m_data[m_size]);
    // go left
    unsigned int v = 1;
    while (2*v + m_bit[v] < m_size - 1)
      v = 2*v + m_bit[v];
    while (v > 0) {
      Join(v, 0);
      v /= 2;
    }
    return result;
  };                                 /// Deletes minimum
  [[maybe_unused]] void Build(){
    for (unsigned int i = m_size-1; i > 0; i--)
      this->Join(i, this->Up(i));
  };                                    /// makes WeakHeap a correct one
  [[maybe_unused]] void heapsort(){
    int size = m_size;
    for (int i = 0; i < size; i++){
      this->Build();
      std::swap(m_data[0], m_data[m_size-1]);
      m_size--;
    }
    m_size = size;
  };
 protected:
  int   m_size;
  int   *m_data;
  bool  *m_bit;
 private:
};

#endif //LB5_AND_CW_WEAKHEAP_HPP
