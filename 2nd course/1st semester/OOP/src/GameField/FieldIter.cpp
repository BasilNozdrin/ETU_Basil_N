#include "FieldIter.h"

template <typename Row_Ptr, typename Cell_Ptr>
FieldIter<Row_Ptr, Cell_Ptr>::FieldIter(Row_Ptr* ptr, int rowSize)
    : row_Ptr(ptr), rowSize(rowSize), it(begin()) {}

template <typename Row_Ptr, typename Cell_Ptr>
FieldIter<Row_Ptr, Cell_Ptr> &FieldIter<Row_Ptr, Cell_Ptr>::operator++() {
  if (++it == end()) {
    row_Ptr++;
    delete it;
    it = begin();
  }
  return *this;
}

template <typename Row_Ptr, typename Cell_Ptr>
const FieldIter<Row_Ptr, Cell_Ptr> FieldIter<Row_Ptr, Cell_Ptr>::operator++(int) {
  FieldIter copy = *this;
  ++(*this);
  return copy;
}

template <typename Row_Ptr, typename Cell_Ptr>
FieldIter<Row_Ptr, Cell_Ptr> &FieldIter<Row_Ptr, Cell_Ptr>::operator--() {
  if (--it == end()) {
    row_Ptr--;
    delete it;
    it = begin();
  }
  return *this;
}

template <typename Row_Ptr, typename Cell_Ptr>
const FieldIter<Row_Ptr, Cell_Ptr> FieldIter<Row_Ptr, Cell_Ptr>::operator--(int) {
  FieldIter copy = *this;
  --(*this);
  return copy;
}

template <typename Row_Ptr, typename Cell_Ptr>
Cell_Ptr* FieldIter<Row_Ptr, Cell_Ptr>::operator->() {
  return it;
}

template <typename Row_Ptr, typename Cell_Ptr>
Cell_Ptr& FieldIter<Row_Ptr, Cell_Ptr>::operator*() {
  return *it;
}

template <typename Row_Ptr, typename Cell_Ptr>
bool FieldIter<Row_Ptr, Cell_Ptr>::operator==(const FieldIter &other) const {
  return it == other->it;
}

template <typename Row_Ptr, typename Cell_Ptr>
bool FieldIter<Row_Ptr, Cell_Ptr>::operator!=(const FieldIter &other) const {
  return !(*this == other);
}

template <typename Row_Ptr, typename Cell_Ptr>
FieldRowIter<Cell_Ptr> FieldIter<Row_Ptr, Cell_Ptr>::begin() {
  return new FieldRowIter<Cell_Ptr>(row_Ptr);
}

template <typename Row_Ptr, typename Cell_Ptr>
FieldRowIter<Cell_Ptr> FieldIter<Row_Ptr, Cell_Ptr>::end() {
  return new FieldRowIter<Cell_Ptr>(row_Ptr+rowSize);
}
