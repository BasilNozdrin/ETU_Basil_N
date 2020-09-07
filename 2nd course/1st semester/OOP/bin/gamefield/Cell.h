#ifndef OOP_CELL_H
#define OOP_CELL_H

class Cell {
 public:
  Cell(bool walkThrough = true): walkThrough(walkThrough){};
  ~Cell()= default;

  bool isWalkThrough() const {return this->walkThrough;};

 protected:

 private:
  bool walkThrough;
};

/*
 * Написать класс игрового поля, которое представляет из себя прямоугольник (двумерный массив).
 * Клетка должна отображать информацию о том, что на ней находится.
 * Также, на поле должны быть две особые клетки: вход и выход.
*/

#endif //OOP_CELL_H
