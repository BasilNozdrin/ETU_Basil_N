#include "AARowIter.h"

template<typename Cell_Ptr>
AARowIter<Cell_Ptr>::AARowIter(AARowIter::PointerType ptr)
    : m_Ptr(ptr) {}

template<typename Cell_Ptr>
AARowIter<Cell_Ptr> &AARowIter<Cell_Ptr>::operator++() {
  m_Ptr++;
  return *this;
}

template<typename Cell_Ptr>
const AARowIter<Cell_Ptr> AARowIter<Cell_Ptr>::operator++(int) {
  AARowIter copy = *this;
  ++(*this);
  return copy;
}

template<typename Cell_Ptr>
AARowIter<Cell_Ptr> &AARowIter<Cell_Ptr>::operator--() {
  m_Ptr--;
  return *this;
}

template<typename Cell_Ptr>
const AARowIter<Cell_Ptr> AARowIter<Cell_Ptr>::operator--(int) {
  AARowIter copy = *this;
  --(*this);
  return copy;
}

template<typename Cell_Ptr>
Cell_Ptr* AARowIter<Cell_Ptr>::operator->() {
  return m_Ptr;
}

template<typename Cell_Ptr>
Cell_Ptr& AARowIter<Cell_Ptr>::operator*() {
  return *m_Ptr;
}

template<typename Cell_Ptr>
bool AARowIter<Cell_Ptr>::operator==(const AARowIter &other) const {
  return m_Ptr == other->m_Ptr;
}

template<typename Cell_Ptr>
bool AARowIter<Cell_Ptr>::operator!=(const AARowIter &other) const {
  return !(*this == other);
}
