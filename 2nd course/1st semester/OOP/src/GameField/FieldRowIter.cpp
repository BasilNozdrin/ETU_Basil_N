#include "FieldRowIter.h"

template<typename Cell_Ptr>
FieldRowIter<Cell_Ptr>::FieldRowIter(FieldRowIter::PointerType ptr)
    : m_Ptr(ptr) {}

template<typename Cell_Ptr>
FieldRowIter<Cell_Ptr> &FieldRowIter<Cell_Ptr>::operator++() {
  m_Ptr++;
  return *this;
}

template<typename Cell_Ptr>
const FieldRowIter<Cell_Ptr> FieldRowIter<Cell_Ptr>::operator++(int) {
  FieldRowIter copy = *this;
  ++(*this);
  return copy;
}

template<typename Cell_Ptr>
FieldRowIter<Cell_Ptr> &FieldRowIter<Cell_Ptr>::operator--() {
  m_Ptr--;
  return *this;
}

template<typename Cell_Ptr>
const FieldRowIter<Cell_Ptr> FieldRowIter<Cell_Ptr>::operator--(int) {
  FieldRowIter copy = *this;
  --(*this);
  return copy;
}

template<typename Cell_Ptr>
Cell_Ptr* FieldRowIter<Cell_Ptr>::operator->() {
  return m_Ptr;
}

template<typename Cell_Ptr>
Cell_Ptr& FieldRowIter<Cell_Ptr>::operator*() {
  return *m_Ptr;
}

template<typename Cell_Ptr>
bool FieldRowIter<Cell_Ptr>::operator==(const FieldRowIter &other) const {
  return m_Ptr == other->m_Ptr;
}

template<typename Cell_Ptr>
bool FieldRowIter<Cell_Ptr>::operator!=(const FieldRowIter &other) const {
  return !(*this == other);
}
