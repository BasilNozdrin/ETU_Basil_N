#include "Cell.h"

Cell::Cell(bool walkThrough, Buff *onCell) {
  this->walkThrough = walkThrough;
  this->onCell = onCell;
}
Cell::~Cell() {
  delete onCell;
};

bool Cell::isWalkThrough() const {
  return this->walkThrough;
};
void Cell::setBuff(Buff *buff) {
  delete onCell;
  this->onCell = buff;
}
Buff* Cell::getBuff() {
  return onCell;
};

