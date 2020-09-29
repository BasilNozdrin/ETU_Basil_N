#ifndef TEST_AAROWITER_H
#define TEST_AAROWITER_H

template <typename A_Ptr>
class AARowIter {
 public:
  using ValueType = A_Ptr;
  using PointerType = A_Ptr *;
  using ReferenceType = A_Ptr &;
 public:
  explicit AARowIter(PointerType);
  AARowIter &operator++();
  const AARowIter operator++(int);
  AARowIter &operator--();
  const AARowIter operator--(int);
  PointerType operator->();
  ReferenceType operator*();
  bool operator==(const AARowIter &other) const;
  bool operator!=(const AARowIter &other) const;

 private:
  A_Ptr *m_Ptr;
};

#endif //TEST_AAROWITER_H
