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
    this->Build(false);
  };
  ~WeakHeap() {
    delete [] m_data;
    delete [] m_bit;
  };

  int getSize() const { return m_size; };
  void setSize(int size) { m_size = size; };
  int* getData() { return m_data; };
  bool* getBit() { return m_bit; };

  [[maybe_unused]] int Join(unsigned int v, unsigned int w, bool log = false) {
    if (log)
      std::cout << "Join(" << m_data[v] << "=m_data[" << v << "], " << m_data[w] << "=m_data[" << w << "])";
    if (m_data[v] < m_data[w]) { // defines min-heap
      std::swap(m_data[v], m_data[w]);
      m_bit[v] ^= true;
      if (log)
        std::cout << " -> 1\n";
      return 1;
    }
    if (log)
      std::cout << " -> 0\n";
    return 0;
  };       /// проталкивает минимум из v наверх в w
  [[maybe_unused]] unsigned int Up(unsigned int v, bool log = false) {
    if (log)
      std::cout << "Up(" << m_data[v] << "=m_data["<< v <<"])\n";
    if ((v % 2)^(m_bit[v/2]))
      return v/2;
    return Up(v/2);
  };                /// returns Right parent
  [[maybe_unused]] void SiftUp(unsigned int v, bool log = false) {
    if (log)
      std::cout << "SiftUp(" << m_data[v] << "=m_data["<< v <<"])\n";
    unsigned int w;
    while (this->Join(v,w = Up(v), log))
      v = w;
  };                    /// sifts WeakHeap
  [[maybe_unused]] int SiftDown(bool log = false) {
    if (log)
      std::cout << "SiftDown\n";
    int result = m_data[0]; // save min
    std::swap(m_data[0], m_data[m_size-1]);
    m_size--;               // delete min
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
      Join(v, 0, log);
      v /= 2;
      if (log && v > 0)
        std::cout << "next=" << m_data[v] << "=m_data["<< v <<"]\n";
    }
    return result;
  };                                 /// Deletes minimum
  [[maybe_unused]] void Build(bool log = false){
    if (log) {
      std::cout << "Building Weak Heap\narray = [";
      for (int j = 0; j < m_size; j++)
        std::cout << m_data[j] << " ";
      std::cout << "]\n";
    }

    for (unsigned int i = m_size-1; i > 0; i--)
      this->Join(i, this->Up(i), log);
  };                                    /// makes WeakHeap a correct one
  [[maybe_unused]] void heapsort(bool log = false){
    int size = m_size;
    for (int k = 0; k < size; k++){
//      this->SiftDown(log);
      this->Build(log);
      m_size--;
      std::swap(m_data[0], m_data[m_size]);
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
 protected:
  int   m_size;
  int   *m_data;
  bool  *m_bit;
 private:
};

#endif //LB5_AND_CW_WEAKHEAP_HPP
