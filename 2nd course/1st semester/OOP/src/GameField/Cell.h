#ifndef OOP_CELL_H
#define OOP_CELL_H

#include "../Buffs/Buff.h"

class Cell {
 public:
  explicit Cell(bool walkThrough, Buff *onCell=nullptr);
  ~Cell();

  [[nodiscard]] bool isWalkThrough() const;
  Buff *getBuff();
  void setBuff(Buff *buff);

 private:
  bool walkThrough;
  Buff *onCell;
};

/*
 * Написать класс игрового поля, которое представляет из себя прямоугольник (двумерный массив).
 * Клетка должна отображать информацию о том, что на ней находится.
 * Также, на поле должны быть две особые клетки: вход и выход.
*/

#endif //OOP_CELL_H

