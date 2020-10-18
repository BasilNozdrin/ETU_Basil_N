#include <iostream>
#include <fstream>
#include <string>

template <class T>
class Node {                                                // +Node(data) +m_data +*m_left +*m_right
 public:
  Node(T data)
    : m_data(data), m_left(nullptr), m_right(nullptr){};
  ~Node()=default;
  T m_data;
  Node<T>* m_left;
  Node<T>* m_right;
};
template <class T>
class Queue {
 public:
   /*--------Queue Element--------*/
  class Element {
   public:
    Element(T data)
    : m_data(data),  m_prev(nullptr), m_next(nullptr) {};
    T m_data;
    Element *m_prev;
    Element *m_next;
  };
  /*-----------------------------*/
 public:
  Queue()
    : m_first(nullptr), m_last(nullptr) {};
  Element *top() {                                          // top
    return m_last;
  }
  void pop() {                                              // pop
    if (m_last) {
      m_last = m_last->m_prev;
      if (m_last) {
        delete m_last->m_next;
        m_last->m_next = nullptr;
      }
    }
  };
  void push(T data) {                             // push
    auto *elem = new Element(data);
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
  Element *m_first;
  Element *m_last;
};

template <class T>
void rLR_traversal(Queue<Node<T>*> *currentLevel, Queue<T> *printQueue) {
  auto nextLevel = new Queue<Node<T>*>();
  while (currentLevel->top()) {
    // add data to printQueue
    printQueue->push(currentLevel->top()->m_data->m_data);
    // add left node to nextLevel
    if (currentLevel->top()->m_data->m_left)
      nextLevel->push(
        currentLevel->top()->m_data->m_left
      );
    // add right node to nextLevel
    if (currentLevel->top()->m_data->m_right)
      nextLevel->push(
        currentLevel->top()->m_data->m_right
      );
    
    currentLevel->pop();
  };
  
  if (nextLevel->top())
    rLR_traversal(nextLevel, printQueue);
  delete nextLevel;
};

Node<int>* readIntTree (std::fstream *input) {
  std::string line;
  getline(*input, line);
  int size = line.size();
  auto node = new Node<int>(std::stoi(line));
  if (line[size-3] - '0' ==  1)
    node->m_left = readIntTree(input);
  if (line[size-1] - '0' ==  1)
    node->m_right = readIntTree(input);
  return node;
}
Node<std::string>* readStringTree (std::fstream *input) {
  std::string line;
  getline(*input, line);
  int size = line.size();
  auto node = new Node<std::string>(line.substr(0, size-4));
  if (line[size-3] - '0' ==  1)
    node->m_left = readStringTree(input);
  if (line[size-1] - '0' ==  1)
    node->m_right = readStringTree(input);
  return node;
}

int main() {
  auto input = new std::fstream("binTree.txt");
  
  auto printQueue   = new Queue<std::string>();
  auto currentLevel = new Queue<Node<std::string>*>();
  auto root         = readStringTree(input);
  
  currentLevel->push(root);
  
  rLR_traversal<std::string>(currentLevel, printQueue);
  
  // print result
  while (printQueue->top()) {
    std::cout << printQueue->top()->m_data <<  " ";
    printQueue->pop();
  };
  
  return 0;
}

/* root-Left-Right tree traversal
 * 6. Задано бинарное дерево b типа ВТ с произвольным типом элементов.
 * Используя очередь, напечатать все элементы дерева b по уровням:
 * сначала из корня дерева,
 * затем из узлов, сыновних по отношению к корню,
 * затем из узлов, сыновних по отношению к этим узлам, и т.д.
 */
