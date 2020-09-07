#ifndef OOP_FIELD_H
#define OOP_FIELD_H

#include "Cell.h"

class Field {
 public:
  Cell **getInstance(){
    if (field == nullptr)
      Field(10, 10);
    return this->field;
  };


 protected:

 private:
  Field(int n, int m){
    this->field = new Cell*[n];
    for (int i = 0; i < n; i++)
      this->field[i] = new Cell[m];
  };
  Cell **field;
};

/* Iterates over the contents of a GargantuanTable.
 * Example:
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
