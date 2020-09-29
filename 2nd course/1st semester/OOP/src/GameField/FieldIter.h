#ifndef OOP_FIELDITER_H
#define OOP_FIELDITER_H

#include "FieldRowIter.h"

template <typename Row_Ptr, typename Cell_Ptr>
class FieldIter {
 public:
  using ValueType = Row_Ptr;
  using PointerType = Row_Ptr *;
  using ReferenceType = Row_Ptr &;

  using Iterator = FieldRowIter<Cell_Ptr>;
 public:
  FieldIter(PointerType, int);
  FieldIter &operator++();
  const FieldIter operator++(int);
  FieldIter &operator--();
  const FieldIter operator--(int);
  Cell_Ptr* operator->();
  Cell_Ptr& operator*();
  bool operator==(const FieldIter &other) const;
  bool operator!=(const FieldIter &other) const;

  Iterator begin();
  Iterator end();

 private:
  Row_Ptr *row_Ptr;
  int rowSize;
  Iterator it;
};

/* Iterates over the contents of a GargantuanTable:
 *
 * GargantuanTableIterator* iter = table->NewIterator();
 * for (iter->Seek("foo"); !iter->done(); iter->Next()) {
 *   process(iter->key(), iter->value());
 * }
 * delete iter;
 * class GargantuanTableIterator {
 *   ...
 * };
 * */

#endif //OOP_FIELDITER_H
