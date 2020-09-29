#include "Field.h"

#include "Field.h"

Field* Field::field_ = nullptr;

Field::Field() {
  xSize = 0;
  ySize = 0;
  gameField = nullptr;
}

Field* Field::getInstance() {
  if (field_ == nullptr) {
    field_ = new Field();
  }
  return field_;
}

Field::Field(Field&& other) noexcept {
  if (this != &other) {
    this->wipe();
    this->xSize = other.xSize;
    this->ySize = other.ySize;
    this->gameField = other.gameField;
    other.xSize = 0;
    other.ySize = 0;
    other.gameField = nullptr;
  }
}
Field& Field::operator=(Field&& other) noexcept {
  if (this != &other) {
    this->wipe();
    this->xSize = other.xSize;
    this->ySize = other.ySize;
    this->gameField = other.gameField;
    other.xSize = 0;
    other.ySize = 0;
    other.gameField = nullptr;
  }
  return *this;
}

Field::Iterator Field::begin() {
  return FieldIter<Cell**, Cell*>(gameField, xSize);
}
Field::Iterator Field::end() {
  return Field::Iterator(gameField+(xSize*ySize)+1, xSize);
};

void Field::show() {
  for (int i = 0; i < ySize; i++) {
    for (int j = 0; j < xSize; j++) {
      if (i == 0 && j == 0) {
        std::cout << "0";
      } else if (i == ySize - 1 && j == xSize - 1) {
        std::cout << "1";
      } else if (gameField[i][j]->isWalkThrough()) {
        std::cout << "_";
      } else {
        std::cout << "#";
      }
    }
    std::cout << "\n";
  }
}
void Field::wipe() {
  for (int i = 0; i < this->ySize; i++) {
    for (int j = 0; j < this->xSize; j++)
      delete this->gameField[i][j];
    delete this->gameField[i];
  }
  delete gameField;
  gameField = nullptr;
}
void Field::loadLevel(int) {

}
