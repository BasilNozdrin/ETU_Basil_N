#include <iostream>
#include <fstream>
#include <string>

template <class T>
class Node {
 public:
  Node(T& data)
    : m_data(data), m_left(nullptr), m_right(nullptr){};
  ~Node()=default;
//   void setLeft(Node* pointer){ m_left = pointer; };
//   void setRight(Node* pointer){ m_left = pointer; };
//   Node<T>* getLeft(){ return m_left; };
//   Node<T>* getRight(){ return m_right; };
//  private:
  T& m_data;
  Node<T>* m_left;
  Node<T>* m_right;
};

template <class T>
class Element {
 public:
  Element(T& data)
    : data(m_data),  m_prev(nullptr), m_next(nullptr) {};

  T& m_data;
  Element *m_prev;
  Element *m_next;
}

template <class T>
class Queue {
 public:
  Queue()
    : m_first(nullptr), m_last(nullptr) {};
  Element<T>* top() {
    return m_last;
  }
  void pop() {
    if (m_last) {
      m_last = m_last->m_prev;
      if (m_last)
        m_last->m_next = nullptr;
    }
  };
  void push(Element<T>* elem) {
    if (m_first) {
      elem->m_next = m_first;
      m_first->m_prev = elem;
      m_first = elem;
    } else {
      m_first = elem;
      m_last = elem;
    }
  };
 private:
  Element<T>* m_first;
  Element<T>* m_last;
}

//  let this shit be a stack ||
//  let this shit be a stack ||
//  let this shit be a stack \/

template <class T>
void RLT_traversal(Node<T> **roots, Queue<T> *queue) {
  if (!queue) {                                             // first step
    queue = new Queue<T>();                                 // init queue
    queue->push(
      new Element<T>(*roots->m_data)
     );
  }
  // add data from L and R to queue
  for (auto root :: roots) {
    if (root->m_left)
      queue->push(new Element<T>(root->m_left->m_data));
    if (root->m_right)
      queue->push(new Element<T>(root->m_right->m_data));
  }
  // go recurcively to L and R
  RLT_traversal (new_roots,  queue);
}


int main() {
  std::ifstream input("input.txt");
  for (std::string line; getline(input, line); ) {
    Node<std::string> *root = nullptr;
    Queue<std::string> *queue = nullptr; 
    RLT_traversal (root, queue);
    std::cout << "depth of \"" << line << "\" is " << depth(line) << "\n";
  }
  return 0;
}

/* Root Left Right
 * 6. Задано бинарное дерево b типа ВТ с произвольным типом элементов.
 * Используя очередь, напечатать все элементы дерева b по уровням:
 * сначала из корня дерева,
 * затем из узлов, сыновних по отношению к корню,
 * затем из узлов, сыновних по отношению к этим узлам, и т.д.
 */
