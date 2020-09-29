#ifndef OOP_FIELDROWITER_H
#define OOP_FIELDROWITER_H

template <typename Cell_Ptr>
class FieldRowIter {
 public:
  using ValueType = Cell_Ptr;
  using PointerType = Cell_Ptr *;
  using ReferenceType = Cell_Ptr &;
 public:
  explicit FieldRowIter(PointerType);
  FieldRowIter &operator++();
  const FieldRowIter operator++(int);
  FieldRowIter &operator--();
  const FieldRowIter operator--(int);
  PointerType operator->();
  ReferenceType operator*();
  bool operator==(const FieldRowIter &other) const;
  bool operator!=(const FieldRowIter &other) const;

 private:
  Cell_Ptr *m_Ptr;
};

#endif //OOP_FIELDROWITER_H
