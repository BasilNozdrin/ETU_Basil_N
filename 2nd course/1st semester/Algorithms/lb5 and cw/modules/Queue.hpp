#ifndef LB5_AND_CW_QUEUE_HPP
#define LB5_AND_CW_QUEUE_HPP

template <class T>
class Queue {
 public:
  /*!--------Queue Element--------*/
  class Element {
   public:
    Element(T data) : m_data(data),  m_prev(nullptr), m_next(nullptr) {};
    T m_data;
    Element *m_prev, *m_next;
  };
  /*!-----------------------------*/

 public:
  Queue() : m_first(nullptr), m_last(nullptr) {};
  Element*  top() { return m_last; };
  void      pop() {
    if (m_last) {
      m_last = m_last->m_prev;
      if (m_last) {
        delete m_last->m_next;
        m_last->m_next = nullptr;
      }
    }
  };
  void      push(T data) {
    auto *elem = new Element(data);
    if (m_first) {
      elem->m_next = m_first;
      m_first->m_prev = elem;
      m_first = elem;
    } else {
      m_first = elem;
      m_last = elem;
    }
  };
 private:
  Element *m_first, *m_last;
};

#endif //LB5_AND_CW_QUEUE_HPP
