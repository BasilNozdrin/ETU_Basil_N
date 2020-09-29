#ifndef OOP_FIELD_H
#define OOP_FIELD_H

#include <iostream>

#include "Cell.h"
#include "FieldIter.h"
#include "FieldRowIter.h"
#include "levels.cpp"

class Field {
 public:
  using Iterator = FieldIter<Cell**, Cell*>;
 public:
  static Field* getInstance();

  Field(Field &)=delete;
  Field& operator=(const Field &)=delete;
  Field(Field&& other) noexcept;
  Field& operator=(Field&& field) noexcept;

  Iterator begin();
  Iterator end();

 private:
  Field();

  static Field* field_;
  int xSize, ySize;
  Cell ***gameField = nullptr;

  void show();
  void wipe();
  void loadLevel(int);
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

#endif //OOP_FIELD_H
