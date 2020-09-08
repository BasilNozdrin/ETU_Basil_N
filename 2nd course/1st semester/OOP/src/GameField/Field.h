#ifndef OOP_FIELD_H
#define OOP_FIELD_H

#include "Cell.h"


class Field {
 public:
  Field(const Field&) = delete;

  static Field& getInstance(){
    static Field fieldInstance;
    return fieldInstance;
  }

 private:
  Field() {
    this->gameField = new Cell*[ySize];
    for (int i = 0; i < ySize; i++) {
      this->gameField[i] = new Cell[xSize];
      // TODO initialize cells
      //  а надо ли? память выделили, клетки есть. Поле можно и потом разметить
    }
  }

  Cell **gameField;
  int xSize = 5;
  int ySize = 5;
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
